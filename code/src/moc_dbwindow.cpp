/****************************************************************************
** Meta object code from reading C++ file 'dbwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dbwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dbwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DBWindow_t {
    QByteArrayData data[21];
    char stringdata0[295];
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
QT_MOC_LITERAL(8, 120, 9), // "table_num"
QT_MOC_LITERAL(9, 130, 12), // "HandleGetRes"
QT_MOC_LITERAL(10, 143, 8), // "Response"
QT_MOC_LITERAL(11, 152, 3), // "res"
QT_MOC_LITERAL(12, 156, 13), // "HandlePostRes"
QT_MOC_LITERAL(13, 170, 11), // "std::string"
QT_MOC_LITERAL(14, 182, 5), // "value"
QT_MOC_LITERAL(15, 188, 12), // "HandlePutRes"
QT_MOC_LITERAL(16, 201, 12), // "HandleDelRes"
QT_MOC_LITERAL(17, 214, 16), // "HandleDelUserRes"
QT_MOC_LITERAL(18, 231, 15), // "HandleShowUTRes"
QT_MOC_LITERAL(19, 247, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(20, 271, 23) // "on_pushButton_6_clicked"

    },
    "DBWindow\0on_pushButton_clicked\0\0"
    "on_pushButton_2_clicked\0on_pushButton_3_clicked\0"
    "on_pushButton_4_clicked\0GetRowEntry\0"
    "key\0table_num\0HandleGetRes\0Response\0"
    "res\0HandlePostRes\0std::string\0value\0"
    "HandlePutRes\0HandleDelRes\0HandleDelUserRes\0"
    "HandleShowUTRes\0on_pushButton_5_clicked\0"
    "on_pushButton_6_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DBWindow[] = {

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
       6,    2,   83,    2, 0x08 /* Private */,
       9,    1,   88,    2, 0x08 /* Private */,
      12,    3,   91,    2, 0x08 /* Private */,
      15,    3,   98,    2, 0x08 /* Private */,
      16,    1,  105,    2, 0x08 /* Private */,
      17,    1,  108,    2, 0x08 /* Private */,
      18,    1,  111,    2, 0x08 /* Private */,
      19,    0,  114,    2, 0x08 /* Private */,
      20,    0,  115,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, QMetaType::QString, QMetaType::Int,    7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 13, 0x80000000 | 10,    7,   14,   11,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 13, 0x80000000 | 10,    7,   14,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DBWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DBWindow *_t = static_cast<DBWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->on_pushButton_3_clicked(); break;
        case 3: _t->on_pushButton_4_clicked(); break;
        case 4: { int _r = _t->GetRowEntry((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->HandleGetRes((*reinterpret_cast< Response(*)>(_a[1]))); break;
        case 6: _t->HandlePostRes((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2])),(*reinterpret_cast< Response(*)>(_a[3]))); break;
        case 7: _t->HandlePutRes((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2])),(*reinterpret_cast< Response(*)>(_a[3]))); break;
        case 8: _t->HandleDelRes((*reinterpret_cast< Response(*)>(_a[1]))); break;
        case 9: _t->HandleDelUserRes((*reinterpret_cast< Response(*)>(_a[1]))); break;
        case 10: _t->HandleShowUTRes((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_pushButton_5_clicked(); break;
        case 12: _t->on_pushButton_6_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject DBWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DBWindow.data,
      qt_meta_data_DBWindow,  qt_static_metacall, nullptr, nullptr}
};


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
