/****************************************************************************
** Meta object code from reading C++ file 'flightenquires.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BoardingControl_Linux/UI_Classes/flightenquires.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'flightenquires.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_InterceptPushButton_t {
    QByteArrayData data[3];
    char stringdata0[44];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InterceptPushButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InterceptPushButton_t qt_meta_stringdata_InterceptPushButton = {
    {
QT_MOC_LITERAL(0, 0, 19), // "InterceptPushButton"
QT_MOC_LITERAL(1, 20, 22), // "changeIsInterceptLabel"
QT_MOC_LITERAL(2, 43, 0) // ""

    },
    "InterceptPushButton\0changeIsInterceptLabel\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InterceptPushButton[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void InterceptPushButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<InterceptPushButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeIsInterceptLabel(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject InterceptPushButton::staticMetaObject = { {
    &QPushButton::staticMetaObject,
    qt_meta_stringdata_InterceptPushButton.data,
    qt_meta_data_InterceptPushButton,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *InterceptPushButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InterceptPushButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_InterceptPushButton.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int InterceptPushButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_FlightEnquires_t {
    QByteArrayData data[21];
    char stringdata0[371];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FlightEnquires_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FlightEnquires_t qt_meta_stringdata_FlightEnquires = {
    {
QT_MOC_LITERAL(0, 0, 14), // "FlightEnquires"
QT_MOC_LITERAL(1, 15, 11), // "networkStat"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 7), // "netStat"
QT_MOC_LITERAL(4, 36, 5), // "title"
QT_MOC_LITERAL(5, 42, 3), // "msg"
QT_MOC_LITERAL(6, 46, 26), // "on_queryPushButton_clicked"
QT_MOC_LITERAL(7, 73, 27), // "on_orgDepPushButton_clicked"
QT_MOC_LITERAL(8, 101, 29), // "on_boardingPushButton_clicked"
QT_MOC_LITERAL(9, 131, 32), // "on_notboardingPushButton_clicked"
QT_MOC_LITERAL(10, 164, 27), // "on_filterPushButton_clicked"
QT_MOC_LITERAL(11, 192, 22), // "on_orgDepSliderChanged"
QT_MOC_LITERAL(12, 215, 1), // "p"
QT_MOC_LITERAL(13, 217, 24), // "on_boardingSliderChanged"
QT_MOC_LITERAL(14, 242, 27), // "on_notBoardingSliderChanged"
QT_MOC_LITERAL(15, 270, 19), // "on_removeRowClicked"
QT_MOC_LITERAL(16, 290, 11), // "widgetIndex"
QT_MOC_LITERAL(17, 302, 19), // "on_interceptClicked"
QT_MOC_LITERAL(18, 322, 15), // "on_PhotoClicked"
QT_MOC_LITERAL(19, 338, 25), // "const FlightReviewResult*"
QT_MOC_LITERAL(20, 364, 6) // "result"

    },
    "FlightEnquires\0networkStat\0\0netStat\0"
    "title\0msg\0on_queryPushButton_clicked\0"
    "on_orgDepPushButton_clicked\0"
    "on_boardingPushButton_clicked\0"
    "on_notboardingPushButton_clicked\0"
    "on_filterPushButton_clicked\0"
    "on_orgDepSliderChanged\0p\0"
    "on_boardingSliderChanged\0"
    "on_notBoardingSliderChanged\0"
    "on_removeRowClicked\0widgetIndex\0"
    "on_interceptClicked\0on_PhotoClicked\0"
    "const FlightReviewResult*\0result"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FlightEnquires[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   84,    2, 0x06 /* Public */,
       1,    2,   91,    2, 0x26 /* Public | MethodCloned */,
       1,    1,   96,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   99,    2, 0x08 /* Private */,
       7,    0,  100,    2, 0x08 /* Private */,
       8,    0,  101,    2, 0x08 /* Private */,
       9,    0,  102,    2, 0x08 /* Private */,
      10,    0,  103,    2, 0x08 /* Private */,
      11,    1,  104,    2, 0x08 /* Private */,
      13,    1,  107,    2, 0x08 /* Private */,
      14,    1,  110,    2, 0x08 /* Private */,
      15,    1,  113,    2, 0x08 /* Private */,
      17,    1,  116,    2, 0x08 /* Private */,
      18,    1,  119,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::QString, QMetaType::QString,    3,    4,    5,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, 0x80000000 | 19,   20,

       0        // eod
};

void FlightEnquires::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FlightEnquires *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->networkStat((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 1: _t->networkStat((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->networkStat((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_queryPushButton_clicked(); break;
        case 4: _t->on_orgDepPushButton_clicked(); break;
        case 5: _t->on_boardingPushButton_clicked(); break;
        case 6: _t->on_notboardingPushButton_clicked(); break;
        case 7: _t->on_filterPushButton_clicked(); break;
        case 8: _t->on_orgDepSliderChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_boardingSliderChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_notBoardingSliderChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_removeRowClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_interceptClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_PhotoClicked((*reinterpret_cast< const FlightReviewResult*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FlightEnquires::*)(bool , const QString , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FlightEnquires::networkStat)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FlightEnquires::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_FlightEnquires.data,
    qt_meta_data_FlightEnquires,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FlightEnquires::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FlightEnquires::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FlightEnquires.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FlightEnquires::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void FlightEnquires::networkStat(bool _t1, const QString _t2, const QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
