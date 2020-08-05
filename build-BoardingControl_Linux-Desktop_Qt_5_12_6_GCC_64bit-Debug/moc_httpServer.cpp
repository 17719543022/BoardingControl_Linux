/****************************************************************************
** Meta object code from reading C++ file 'httpServer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BoardingControl_Linux/ServerInterface/httpServer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'httpServer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HttpServer_t {
    QByteArrayData data[32];
    char stringdata0[356];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HttpServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HttpServer_t qt_meta_stringdata_HttpServer = {
    {
QT_MOC_LITERAL(0, 0, 10), // "HttpServer"
QT_MOC_LITERAL(1, 11, 11), // "GateNetStat"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5), // "title"
QT_MOC_LITERAL(4, 30, 3), // "msg"
QT_MOC_LITERAL(5, 34, 11), // "recheckInfo"
QT_MOC_LITERAL(6, 46, 4), // "json"
QT_MOC_LITERAL(7, 51, 11), // "collectInfo"
QT_MOC_LITERAL(8, 63, 7), // "channel"
QT_MOC_LITERAL(9, 71, 17), // "sendDepartureInfo"
QT_MOC_LITERAL(10, 89, 18), // "BoardingTicketInfo"
QT_MOC_LITERAL(11, 108, 10), // "ticketInfo"
QT_MOC_LITERAL(12, 119, 18), // "showBoardingResult"
QT_MOC_LITERAL(13, 138, 17), // "isManualOperation"
QT_MOC_LITERAL(14, 156, 6), // "result"
QT_MOC_LITERAL(15, 163, 12), // "transferType"
QT_MOC_LITERAL(16, 176, 15), // "hasSecurityInfo"
QT_MOC_LITERAL(17, 192, 9), // "seatLabel"
QT_MOC_LITERAL(18, 202, 7), // "hasBaby"
QT_MOC_LITERAL(19, 210, 10), // "moreTicket"
QT_MOC_LITERAL(20, 221, 8), // "isMarked"
QT_MOC_LITERAL(21, 230, 4), // "name"
QT_MOC_LITERAL(22, 235, 6), // "cardId"
QT_MOC_LITERAL(23, 242, 10), // "ticketinfo"
QT_MOC_LITERAL(24, 253, 9), // "faceImage"
QT_MOC_LITERAL(25, 263, 33), // "boardingInfo_to_updateBoardin..."
QT_MOC_LITERAL(26, 297, 8), // "flightNo"
QT_MOC_LITERAL(27, 306, 9), // "FlightDay"
QT_MOC_LITERAL(28, 316, 7), // "faceImg"
QT_MOC_LITERAL(29, 324, 11), // "recheckType"
QT_MOC_LITERAL(30, 336, 8), // "userInfo"
QT_MOC_LITERAL(31, 345, 10) // "manualInfo"

    },
    "HttpServer\0GateNetStat\0\0title\0msg\0"
    "recheckInfo\0json\0collectInfo\0channel\0"
    "sendDepartureInfo\0BoardingTicketInfo\0"
    "ticketInfo\0showBoardingResult\0"
    "isManualOperation\0result\0transferType\0"
    "hasSecurityInfo\0seatLabel\0hasBaby\0"
    "moreTicket\0isMarked\0name\0cardId\0"
    "ticketinfo\0faceImage\0"
    "boardingInfo_to_updateBoardingNum\0"
    "flightNo\0FlightDay\0faceImg\0recheckType\0"
    "userInfo\0manualInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HttpServer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,
       1,    1,   59,    2, 0x26 /* Public | MethodCloned */,
       1,    0,   62,    2, 0x26 /* Public | MethodCloned */,
       5,    1,   63,    2, 0x06 /* Public */,
       7,    2,   66,    2, 0x06 /* Public */,
       9,    1,   71,    2, 0x06 /* Public */,
      12,   13,   74,    2, 0x06 /* Public */,
      25,    6,  101,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::QJsonObject,    8,    6,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::Int, QMetaType::Int, QMetaType::Bool, QMetaType::Int, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::QString, QMetaType::QString, 0x80000000 | 10, QMetaType::QByteArray,    8,   13,   14,   15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QByteArray, QMetaType::Int, QMetaType::QJsonObject, QMetaType::QJsonObject,   26,   27,   28,   29,   30,   31,

       0        // eod
};

void HttpServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HttpServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->GateNetStat((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->GateNetStat((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->GateNetStat(); break;
        case 3: _t->recheckInfo((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 4: _t->collectInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2]))); break;
        case 5: _t->sendDepartureInfo((*reinterpret_cast< BoardingTicketInfo(*)>(_a[1]))); break;
        case 6: _t->showBoardingResult((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< bool(*)>(_a[7])),(*reinterpret_cast< bool(*)>(_a[8])),(*reinterpret_cast< bool(*)>(_a[9])),(*reinterpret_cast< const QString(*)>(_a[10])),(*reinterpret_cast< const QString(*)>(_a[11])),(*reinterpret_cast< const BoardingTicketInfo(*)>(_a[12])),(*reinterpret_cast< const QByteArray(*)>(_a[13]))); break;
        case 7: _t->boardingInfo_to_updateBoardingNum((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QJsonObject(*)>(_a[5])),(*reinterpret_cast< QJsonObject(*)>(_a[6]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HttpServer::*)(const QString , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HttpServer::GateNetStat)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HttpServer::*)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HttpServer::recheckInfo)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (HttpServer::*)(int , QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HttpServer::collectInfo)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (HttpServer::*)(BoardingTicketInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HttpServer::sendDepartureInfo)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (HttpServer::*)(int , bool , int , int , bool , int , bool , bool , bool , const QString , const QString , const BoardingTicketInfo , const QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HttpServer::showBoardingResult)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (HttpServer::*)(QString , QString , QByteArray , int , QJsonObject , QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HttpServer::boardingInfo_to_updateBoardingNum)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HttpServer::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_HttpServer.data,
    qt_meta_data_HttpServer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HttpServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HttpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HttpServer.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "RequstListener"))
        return static_cast< RequstListener*>(this);
    return QObject::qt_metacast(_clname);
}

int HttpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void HttpServer::GateNetStat(const QString _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 3
void HttpServer::recheckInfo(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void HttpServer::collectInfo(int _t1, QJsonObject _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void HttpServer::sendDepartureInfo(BoardingTicketInfo _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void HttpServer::showBoardingResult(int _t1, bool _t2, int _t3, int _t4, bool _t5, int _t6, bool _t7, bool _t8, bool _t9, const QString _t10, const QString _t11, const BoardingTicketInfo _t12, const QByteArray _t13)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)), const_cast<void*>(reinterpret_cast<const void*>(&_t9)), const_cast<void*>(reinterpret_cast<const void*>(&_t10)), const_cast<void*>(reinterpret_cast<const void*>(&_t11)), const_cast<void*>(reinterpret_cast<const void*>(&_t12)), const_cast<void*>(reinterpret_cast<const void*>(&_t13)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void HttpServer::boardingInfo_to_updateBoardingNum(QString _t1, QString _t2, QByteArray _t3, int _t4, QJsonObject _t5, QJsonObject _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
