/****************************************************************************
** Meta object code from reading C++ file 'workanotherthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BoardingControl_Linux/ServerInterface/workanotherthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'workanotherthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WorkAnotherThread_t {
    QByteArrayData data[13];
    char stringdata0[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WorkAnotherThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WorkAnotherThread_t qt_meta_stringdata_WorkAnotherThread = {
    {
QT_MOC_LITERAL(0, 0, 17), // "WorkAnotherThread"
QT_MOC_LITERAL(1, 18, 19), // "results_flightPlane"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 14), // "API_PARAM_TYPE"
QT_MOC_LITERAL(4, 54, 4), // "type"
QT_MOC_LITERAL(5, 59, 8), // "userData"
QT_MOC_LITERAL(6, 68, 17), // "on_getFlightPlane"
QT_MOC_LITERAL(7, 86, 11), // "on_GateCtrl"
QT_MOC_LITERAL(8, 98, 13), // "GateChannelNO"
QT_MOC_LITERAL(9, 112, 14), // "gateWorkStatus"
QT_MOC_LITERAL(10, 127, 8), // "workStat"
QT_MOC_LITERAL(11, 136, 14), // "gateDoorStatus"
QT_MOC_LITERAL(12, 151, 8) // "doorStat"

    },
    "WorkAnotherThread\0results_flightPlane\0"
    "\0API_PARAM_TYPE\0type\0userData\0"
    "on_getFlightPlane\0on_GateCtrl\0"
    "GateChannelNO\0gateWorkStatus\0workStat\0"
    "gateDoorStatus\0doorStat"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WorkAnotherThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   34,    2, 0x0a /* Public */,
       7,    3,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::VoidStar,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 9, 0x80000000 | 11,    8,   10,   12,

       0        // eod
};

void WorkAnotherThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WorkAnotherThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->results_flightPlane((*reinterpret_cast< API_PARAM_TYPE(*)>(_a[1])),(*reinterpret_cast< void*(*)>(_a[2]))); break;
        case 1: _t->on_getFlightPlane(); break;
        case 2: _t->on_GateCtrl((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< gateWorkStatus(*)>(_a[2])),(*reinterpret_cast< gateDoorStatus(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WorkAnotherThread::*)(API_PARAM_TYPE , void * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkAnotherThread::results_flightPlane)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WorkAnotherThread::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_WorkAnotherThread.data,
    qt_meta_data_WorkAnotherThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WorkAnotherThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WorkAnotherThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WorkAnotherThread.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int WorkAnotherThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void WorkAnotherThread::results_flightPlane(API_PARAM_TYPE _t1, void * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
