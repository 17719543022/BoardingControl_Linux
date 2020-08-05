/****************************************************************************
** Meta object code from reading C++ file 'workflowrecording.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BoardingControl_Linux/UI_Classes/workflowrecording.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'workflowrecording.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WorkflowRecording_t {
    QByteArrayData data[14];
    char stringdata0[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WorkflowRecording_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WorkflowRecording_t qt_meta_stringdata_WorkflowRecording = {
    {
QT_MOC_LITERAL(0, 0, 17), // "WorkflowRecording"
QT_MOC_LITERAL(1, 18, 11), // "networkStat"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 7), // "netStat"
QT_MOC_LITERAL(4, 39, 5), // "title"
QT_MOC_LITERAL(5, 45, 3), // "msg"
QT_MOC_LITERAL(6, 49, 30), // "on_flowQueryPushButton_clicked"
QT_MOC_LITERAL(7, 80, 17), // "on_ReadDataResult"
QT_MOC_LITERAL(8, 98, 18), // "BoardingTicketInfo"
QT_MOC_LITERAL(9, 117, 10), // "ticketINfo"
QT_MOC_LITERAL(10, 128, 17), // "on_IDCardReadInfo"
QT_MOC_LITERAL(11, 146, 6), // "cardID"
QT_MOC_LITERAL(12, 153, 6), // "nameZh"
QT_MOC_LITERAL(13, 160, 3) // "img"

    },
    "WorkflowRecording\0networkStat\0\0netStat\0"
    "title\0msg\0on_flowQueryPushButton_clicked\0"
    "on_ReadDataResult\0BoardingTicketInfo\0"
    "ticketINfo\0on_IDCardReadInfo\0cardID\0"
    "nameZh\0img"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WorkflowRecording[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   44,    2, 0x06 /* Public */,
       1,    2,   51,    2, 0x26 /* Public | MethodCloned */,
       1,    1,   56,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   59,    2, 0x08 /* Private */,
       7,    1,   60,    2, 0x08 /* Private */,
      10,    3,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::QString, QMetaType::QString,    3,    4,    5,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QByteArray,   11,   12,   13,

       0        // eod
};

void WorkflowRecording::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WorkflowRecording *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->networkStat((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 1: _t->networkStat((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->networkStat((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_flowQueryPushButton_clicked(); break;
        case 4: _t->on_ReadDataResult((*reinterpret_cast< const BoardingTicketInfo(*)>(_a[1]))); break;
        case 5: _t->on_IDCardReadInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WorkflowRecording::*)(bool , const QString , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WorkflowRecording::networkStat)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WorkflowRecording::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_WorkflowRecording.data,
    qt_meta_data_WorkflowRecording,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WorkflowRecording::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WorkflowRecording::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WorkflowRecording.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WorkflowRecording::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void WorkflowRecording::networkStat(bool _t1, const QString _t2, const QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
