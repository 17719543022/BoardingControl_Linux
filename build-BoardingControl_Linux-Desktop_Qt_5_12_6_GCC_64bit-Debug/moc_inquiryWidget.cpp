/****************************************************************************
** Meta object code from reading C++ file 'inquiryWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BoardingControl_Linux/UI_Classes/inquiryWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'inquiryWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_inquiryWidget_t {
    QByteArrayData data[21];
    char stringdata0[431];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_inquiryWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_inquiryWidget_t qt_meta_stringdata_inquiryWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "inquiryWidget"
QT_MOC_LITERAL(1, 14, 17), // "on_IDCardReadInfo"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 6), // "cardID"
QT_MOC_LITERAL(4, 40, 6), // "nameZh"
QT_MOC_LITERAL(5, 47, 3), // "img"
QT_MOC_LITERAL(6, 51, 19), // "on_ReadTicketResult"
QT_MOC_LITERAL(7, 71, 18), // "BoardingTicketInfo"
QT_MOC_LITERAL(8, 90, 10), // "ticketINfo"
QT_MOC_LITERAL(9, 101, 16), // "on_replyFinished"
QT_MOC_LITERAL(10, 118, 14), // "QNetworkReply*"
QT_MOC_LITERAL(11, 133, 5), // "reply"
QT_MOC_LITERAL(12, 139, 29), // "on_pushButton_enquiry_clicked"
QT_MOC_LITERAL(13, 169, 39), // "on_pushButton_choice_ppl_comm..."
QT_MOC_LITERAL(14, 209, 26), // "on_pushButton_pass_clicked"
QT_MOC_LITERAL(15, 236, 29), // "on_pushButton_prevent_clicked"
QT_MOC_LITERAL(16, 266, 31), // "on_pushButton_channel_1_clicked"
QT_MOC_LITERAL(17, 298, 31), // "on_pushButton_channel_2_clicked"
QT_MOC_LITERAL(18, 330, 32), // "on_pushButton_cancelPass_clicked"
QT_MOC_LITERAL(19, 363, 38), // "on_pushButton_specialPassenge..."
QT_MOC_LITERAL(20, 402, 28) // "on_pushButton_return_clicked"

    },
    "inquiryWidget\0on_IDCardReadInfo\0\0"
    "cardID\0nameZh\0img\0on_ReadTicketResult\0"
    "BoardingTicketInfo\0ticketINfo\0"
    "on_replyFinished\0QNetworkReply*\0reply\0"
    "on_pushButton_enquiry_clicked\0"
    "on_pushButton_choice_ppl_commit_clicked\0"
    "on_pushButton_pass_clicked\0"
    "on_pushButton_prevent_clicked\0"
    "on_pushButton_channel_1_clicked\0"
    "on_pushButton_channel_2_clicked\0"
    "on_pushButton_cancelPass_clicked\0"
    "on_pushButton_specialPassenger_clicked\0"
    "on_pushButton_return_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_inquiryWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   74,    2, 0x08 /* Private */,
       6,    1,   81,    2, 0x08 /* Private */,
       9,    1,   84,    2, 0x08 /* Private */,
      12,    0,   87,    2, 0x08 /* Private */,
      13,    0,   88,    2, 0x08 /* Private */,
      14,    0,   89,    2, 0x08 /* Private */,
      15,    0,   90,    2, 0x08 /* Private */,
      16,    0,   91,    2, 0x08 /* Private */,
      17,    0,   92,    2, 0x08 /* Private */,
      18,    0,   93,    2, 0x08 /* Private */,
      19,    0,   94,    2, 0x08 /* Private */,
      20,    0,   95,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QByteArray,    3,    4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void inquiryWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<inquiryWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_IDCardReadInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        case 1: _t->on_ReadTicketResult((*reinterpret_cast< const BoardingTicketInfo(*)>(_a[1]))); break;
        case 2: _t->on_replyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_enquiry_clicked(); break;
        case 4: _t->on_pushButton_choice_ppl_commit_clicked(); break;
        case 5: _t->on_pushButton_pass_clicked(); break;
        case 6: _t->on_pushButton_prevent_clicked(); break;
        case 7: _t->on_pushButton_channel_1_clicked(); break;
        case 8: _t->on_pushButton_channel_2_clicked(); break;
        case 9: _t->on_pushButton_cancelPass_clicked(); break;
        case 10: _t->on_pushButton_specialPassenger_clicked(); break;
        case 11: _t->on_pushButton_return_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject inquiryWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_inquiryWidget.data,
    qt_meta_data_inquiryWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *inquiryWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *inquiryWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_inquiryWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int inquiryWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
