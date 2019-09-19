/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[17];
    char stringdata0[282];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 15), // "on_play_clicked"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 15), // "on_mute_clicked"
QT_MOC_LITERAL(4, 40, 17), // "on_voladd_clicked"
QT_MOC_LITERAL(5, 58, 17), // "on_volsub_clicked"
QT_MOC_LITERAL(6, 76, 16), // "on_close_clicked"
QT_MOC_LITERAL(7, 93, 26), // "on_Progress_sliderReleased"
QT_MOC_LITERAL(8, 120, 25), // "on_Progress_sliderPressed"
QT_MOC_LITERAL(9, 146, 24), // "on_Songslist_itemClicked"
QT_MOC_LITERAL(10, 171, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(11, 188, 4), // "item"
QT_MOC_LITERAL(12, 193, 15), // "on_mode_clicked"
QT_MOC_LITERAL(13, 209, 15), // "on_last_clicked"
QT_MOC_LITERAL(14, 225, 15), // "on_next_clicked"
QT_MOC_LITERAL(15, 241, 18), // "on_Refresh_clicked"
QT_MOC_LITERAL(16, 260, 21) // "on_background_clicked"

    },
    "Widget\0on_play_clicked\0\0on_mute_clicked\0"
    "on_voladd_clicked\0on_volsub_clicked\0"
    "on_close_clicked\0on_Progress_sliderReleased\0"
    "on_Progress_sliderPressed\0"
    "on_Songslist_itemClicked\0QListWidgetItem*\0"
    "item\0on_mode_clicked\0on_last_clicked\0"
    "on_next_clicked\0on_Refresh_clicked\0"
    "on_background_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    1,   86,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,
      15,    0,   92,    2, 0x08 /* Private */,
      16,    0,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_play_clicked(); break;
        case 1: _t->on_mute_clicked(); break;
        case 2: _t->on_voladd_clicked(); break;
        case 3: _t->on_volsub_clicked(); break;
        case 4: _t->on_close_clicked(); break;
        case 5: _t->on_Progress_sliderReleased(); break;
        case 6: _t->on_Progress_sliderPressed(); break;
        case 7: _t->on_Songslist_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 8: _t->on_mode_clicked(); break;
        case 9: _t->on_last_clicked(); break;
        case 10: _t->on_next_clicked(); break;
        case 11: _t->on_Refresh_clicked(); break;
        case 12: _t->on_background_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget.data,
      qt_meta_data_Widget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
