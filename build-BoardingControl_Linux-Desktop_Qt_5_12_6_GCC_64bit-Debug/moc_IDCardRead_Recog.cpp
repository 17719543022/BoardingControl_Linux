/****************************************************************************
** Meta object code from reading C++ file 'IDCardRead_Recog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BoardingControl_Linux/ServerInterface/IDCardRead_Recog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IDCardRead_Recog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IDCardLoader_t {
    QByteArrayData data[10];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IDCardLoader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IDCardLoader_t qt_meta_stringdata_IDCardLoader = {
    {
QT_MOC_LITERAL(0, 0, 12), // "IDCardLoader"
QT_MOC_LITERAL(1, 13, 16), // "IDCardReaderstat"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 4), // "stat"
QT_MOC_LITERAL(4, 36, 18), // "PassportReaderstat"
QT_MOC_LITERAL(5, 55, 6), // "readOK"
QT_MOC_LITERAL(6, 62, 6), // "cardID"
QT_MOC_LITERAL(7, 69, 6), // "nameZh"
QT_MOC_LITERAL(8, 76, 7), // "faceImg"
QT_MOC_LITERAL(9, 84, 16) // "crtfDateInvalide"

    },
    "IDCardLoader\0IDCardReaderstat\0\0stat\0"
    "PassportReaderstat\0readOK\0cardID\0"
    "nameZh\0faceImg\0crtfDateInvalide"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IDCardLoader[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       5,    3,   40,    2, 0x06 /* Public */,
       9,    0,   47,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QByteArray,    6,    7,    8,
    QMetaType::Void,

       0        // eod
};

void IDCardLoader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<IDCardLoader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->IDCardReaderstat((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->PassportReaderstat((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->readOK((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        case 3: _t->crtfDateInvalide(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (IDCardLoader::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IDCardLoader::IDCardReaderstat)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (IDCardLoader::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IDCardLoader::PassportReaderstat)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (IDCardLoader::*)(QString , QString , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IDCardLoader::readOK)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (IDCardLoader::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IDCardLoader::crtfDateInvalide)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject IDCardLoader::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_IDCardLoader.data,
    qt_meta_data_IDCardLoader,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *IDCardLoader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IDCardLoader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IDCardLoader.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int IDCardLoader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void IDCardLoader::IDCardReaderstat(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void IDCardLoader::PassportReaderstat(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void IDCardLoader::readOK(QString _t1, QString _t2, QByteArray _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void IDCardLoader::crtfDateInvalide()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
