/*
 * ***** BEGIN LICENSE BLOCK *****
 * Version: MIT
 *
 * Portions created by Alan Antonuk are Copyright (c) 2012-2013
 * Alan Antonuk. All Rights Reserved.
 *
 * Portions created by VMware are Copyright (c) 2007-2012 VMware, Inc.
 * All Rights Reserved.
 *
 * Portions created by Tony Garnock-Jones are Copyright (c) 2009-2010
 * VMware, Inc. and Tony Garnock-Jones. All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * ***** END LICENSE BLOCK *****
 */

//#include <ctype.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdint.h>

#include <stdarg.h>
#include <amqp.h>
#include <amqp_framing.h>
#include "utils.h"

void AmqpUtils::logInfo(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
}

void AmqpUtils::throw_logInfo(const char *fmt, ...)
{
    char msgBuf[1024] = {0};
    va_list ap;
    va_start(ap, fmt);
    vsprintf(msgBuf, fmt, ap);
    va_end(ap);
    throw MQException(msgBuf);
}

void AmqpUtils::throw_error(int x, char const *context)
{
    char msgBuf[1024] = {0};
    if (x < 0)
    {
        sprintf(msgBuf, "%s: %s", context, amqp_error_string2(x));
        throw MQException(msgBuf);
    }
}

void AmqpUtils::throw_amqp_error(amqp_rpc_reply_t x, char const *context)
{
    char msgBuf[1024] = {0};

    switch (x.reply_type)
    {
    case AMQP_RESPONSE_NORMAL:
        return;

    case AMQP_RESPONSE_NONE:
        sprintf(msgBuf, "%s: missing RPC reply type!", context);
        break;

    case AMQP_RESPONSE_LIBRARY_EXCEPTION:
        sprintf(msgBuf, "%s: %s", context, amqp_error_string2(x.library_error));
        break;

    case AMQP_RESPONSE_SERVER_EXCEPTION:
        switch (x.reply.id)
        {
        case AMQP_CONNECTION_CLOSE_METHOD:
        {
            amqp_connection_close_t *m = (amqp_connection_close_t *)x.reply.decoded;
            sprintf(msgBuf, "%s: server connection error %uh, message: %.*s",
                    context, m->reply_code, (int)m->reply_text.len,
                    (char *)m->reply_text.bytes);
            break;
        }
        case AMQP_CHANNEL_CLOSE_METHOD: {
            amqp_channel_close_t *m = (amqp_channel_close_t *)x.reply.decoded;
            sprintf(msgBuf, "%s: server channel error %uh, message: %.*s",
                    context, m->reply_code, (int)m->reply_text.len,
                    (char *)m->reply_text.bytes);
            break;
        }
        default:
            sprintf(msgBuf, "%s: unknown server error, method id 0x%08X", context, x.reply.id);
            break;
        }
        break;
    }

    throw MQException(msgBuf);
}
