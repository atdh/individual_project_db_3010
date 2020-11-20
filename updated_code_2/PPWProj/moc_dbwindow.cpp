/****************************************************************************
** Meta object code from reading C++ file 'dbwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "dbwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dbwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DBWindow_t {
    QByteArrayData data[17];
    char stringdata0[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DBWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DBWindow_t qt_meta_stringdata_DBWindow = {
    {
QT_MOC_LITERAL(0, 0, 8), // "DBWindow"
QT_MOC_LITERAL(1, 9, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(4, 56, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(5, 80, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(6, 104, 11), // "GetRowEntry"
QT_MOC_LITERAL(7, 116, 3), // "key"
QT_MOC_LITERAL(8, 120, 12), // "HandleGetRes"
QT_MOC_LITERAL(9, 133, 8), // "Response"
QT_MOC_LITERAL(10, 142, 3), // "res"
QT_MOC_LITERAL(11, 146, 13), // "HandlePostRes"
QT_MOC_LITERAL(12, 160, 11), // "std::string"
QT_MOC_LITERAL(13, 172, 5), // "value"
QT_MOC_LITERAL(14, 178, 12), // "HandlePutRes"
QT_MOC_LITERAL(15, 191, 12), // "HandleDelRes"
QT_MOC_LITERAL(16, 204, 23) // "on_pushButton_5_clicked"

    },
    "DBWindow\0on_pushButton_clicked\0\0"
    "on_pushButton_2_clicked\0on_pushButton_3_clicked\0"
    "on_pushButton_4_clicked\0GetRowEntry\0"
    "key\0HandleGetRes\0Response\0res\0"
    "HandlePostRes\0std::string\0value\0"
    "HandlePutRes\0HandleDelRes\0"
    "on_pushButton_5_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DBWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    1,   68,    2, 0x08 /* Private */,
       8,    1,   71,    2, 0x08 /* Private */,
      11,    3,   74,    2, 0x08 /* Private */,
      14,    3,   81,    2, 0x08 /* Private */,
      15,    1,   88,    2, 0x08 /* Private */,
      16,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, QMetaType::QString,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 12, 0x80000000 | 9,    7,   13,   10,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 12, 0x80000000 | 9,    7,   13,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,

       0        // eod
};

void DBWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DBWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->on_pushButton_3_clicked(); break;
        case 3: _t->on_pushButton_4_clicked(); break;
        case 4: { int _r = _t->GetRowEntry((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->HandleGetRes((*reinterpret_cast< Response(*)>(_a[1]))); break;
        case 6: _t->HandlePostRes((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2])),(*reinterpret_cast< Response(*)>(_a[3]))); break;
        case 7: _t->HandlePutRes((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2])),(*reinterpret_cast< Response(*)>(_a[3]))); break;
        case 8: _t->HandleDelRes((*reinterpret_cast< Response(*)>(_a[1]))); break;
        case 9: _t->on_pushButton_5_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DBWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_DBWindow.data,
    qt_meta_data_DBWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DBWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DBWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DBWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int DBWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
