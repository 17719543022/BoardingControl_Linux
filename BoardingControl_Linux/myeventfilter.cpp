#include "myeventfilter.h"

#include <QEvent>

myEventFilter::myEventFilter(QObject *parent) : QObject(parent)
{
}

bool myEventFilter::eventFilter(QObject* object, QEvent* event)
{
    Q_UNUSED(object)

    if(object->objectName() == "HomePageWindow" && event->type() == QEvent::MouseButtonPress) {
        emit mousePressNotify();
    }

    return false; // make it unhandled and sent to other filters.
}
