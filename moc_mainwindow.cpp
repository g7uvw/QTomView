/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[372];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "createMdiChild"
QT_MOC_LITERAL(2, 26, 11), // "QTomV_View*"
QT_MOC_LITERAL(3, 38, 0), // ""
QT_MOC_LITERAL(4, 39, 30), // "on_actionInformation_triggered"
QT_MOC_LITERAL(5, 70, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(6, 94, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(7, 118, 29), // "on_actionDown_Slice_triggered"
QT_MOC_LITERAL(8, 148, 26), // "on_actionUpSlice_triggered"
QT_MOC_LITERAL(9, 175, 27), // "on_actionXY_Slice_triggered"
QT_MOC_LITERAL(10, 203, 27), // "on_actionYZ_Slice_triggered"
QT_MOC_LITERAL(11, 231, 27), // "on_actionXZ_Slice_triggered"
QT_MOC_LITERAL(12, 259, 21), // "on_action25_triggered"
QT_MOC_LITERAL(13, 281, 21), // "on_action50_triggered"
QT_MOC_LITERAL(14, 303, 22), // "on_action100_triggered"
QT_MOC_LITERAL(15, 326, 22), // "on_action200_triggered"
QT_MOC_LITERAL(16, 349, 22) // "on_action300_triggered"

    },
    "MainWindow\0createMdiChild\0QTomV_View*\0"
    "\0on_actionInformation_triggered\0"
    "on_actionOpen_triggered\0on_actionExit_triggered\0"
    "on_actionDown_Slice_triggered\0"
    "on_actionUpSlice_triggered\0"
    "on_actionXY_Slice_triggered\0"
    "on_actionYZ_Slice_triggered\0"
    "on_actionXZ_Slice_triggered\0"
    "on_action25_triggered\0on_action50_triggered\0"
    "on_action100_triggered\0on_action200_triggered\0"
    "on_action300_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    3, 0x08 /* Private */,
       4,    0,   85,    3, 0x08 /* Private */,
       5,    0,   86,    3, 0x08 /* Private */,
       6,    0,   87,    3, 0x08 /* Private */,
       7,    0,   88,    3, 0x08 /* Private */,
       8,    0,   89,    3, 0x08 /* Private */,
       9,    0,   90,    3, 0x08 /* Private */,
      10,    0,   91,    3, 0x08 /* Private */,
      11,    0,   92,    3, 0x08 /* Private */,
      12,    0,   93,    3, 0x08 /* Private */,
      13,    0,   94,    3, 0x08 /* Private */,
      14,    0,   95,    3, 0x08 /* Private */,
      15,    0,   96,    3, 0x08 /* Private */,
      16,    0,   97,    3, 0x08 /* Private */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QTomV_View* _r = _t->createMdiChild();
            if (_a[0]) *reinterpret_cast< QTomV_View**>(_a[0]) = std::move(_r); }  break;
        case 1: _t->on_actionInformation_triggered(); break;
        case 2: _t->on_actionOpen_triggered(); break;
        case 3: _t->on_actionExit_triggered(); break;
        case 4: _t->on_actionDown_Slice_triggered(); break;
        case 5: _t->on_actionUpSlice_triggered(); break;
        case 6: _t->on_actionXY_Slice_triggered(); break;
        case 7: _t->on_actionYZ_Slice_triggered(); break;
        case 8: _t->on_actionXZ_Slice_triggered(); break;
        case 9: _t->on_action25_triggered(); break;
        case 10: _t->on_action50_triggered(); break;
        case 11: _t->on_action100_triggered(); break;
        case 12: _t->on_action200_triggered(); break;
        case 13: _t->on_action300_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE