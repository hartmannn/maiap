/****************************************************************************
** Meta object code from reading C++ file 'window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[24];
    char stringdata0[400];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "openRecentFile"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "filename"
QT_MOC_LITERAL(4, 36, 9), // "dropEvent"
QT_MOC_LITERAL(5, 46, 11), // "QDropEvent*"
QT_MOC_LITERAL(6, 58, 5), // "event"
QT_MOC_LITERAL(7, 64, 10), // "closeEvent"
QT_MOC_LITERAL(8, 75, 12), // "QCloseEvent*"
QT_MOC_LITERAL(9, 88, 14), // "dragEnterEvent"
QT_MOC_LITERAL(10, 103, 16), // "QDragEnterEvent*"
QT_MOC_LITERAL(11, 120, 18), // "openRecentFile_aux"
QT_MOC_LITERAL(12, 139, 23), // "updateRecentFileActions"
QT_MOC_LITERAL(13, 163, 16), // "addToRecentFiles"
QT_MOC_LITERAL(14, 180, 8), // "fileName"
QT_MOC_LITERAL(15, 189, 23), // "on_actionLoad_triggered"
QT_MOC_LITERAL(16, 213, 4), // "open"
QT_MOC_LITERAL(17, 218, 4), // "file"
QT_MOC_LITERAL(18, 223, 22), // "on_actionBox_triggered"
QT_MOC_LITERAL(19, 246, 25), // "on_actionCircle_triggered"
QT_MOC_LITERAL(20, 272, 24), // "on_actionClear_triggered"
QT_MOC_LITERAL(21, 297, 25), // "on_actionRefine_triggered"
QT_MOC_LITERAL(22, 323, 38), // "on_actionDelaunay_conforming_..."
QT_MOC_LITERAL(23, 362, 37) // "on_actionGabriel_conforming_t..."

    },
    "MainWindow\0openRecentFile\0\0filename\0"
    "dropEvent\0QDropEvent*\0event\0closeEvent\0"
    "QCloseEvent*\0dragEnterEvent\0"
    "QDragEnterEvent*\0openRecentFile_aux\0"
    "updateRecentFileActions\0addToRecentFiles\0"
    "fileName\0on_actionLoad_triggered\0open\0"
    "file\0on_actionBox_triggered\0"
    "on_actionCircle_triggered\0"
    "on_actionClear_triggered\0"
    "on_actionRefine_triggered\0"
    "on_actionDelaunay_conforming_triggered\0"
    "on_actionGabriel_conforming_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   92,    2, 0x09 /* Protected */,
       7,    1,   95,    2, 0x09 /* Protected */,
       9,    1,   98,    2, 0x09 /* Protected */,
      11,    0,  101,    2, 0x09 /* Protected */,
      12,    0,  102,    2, 0x09 /* Protected */,
      13,    1,  103,    2, 0x09 /* Protected */,
      15,    0,  106,    2, 0x09 /* Protected */,
      16,    1,  107,    2, 0x09 /* Protected */,
      18,    0,  110,    2, 0x0a /* Public */,
      19,    0,  111,    2, 0x0a /* Public */,
      20,    0,  112,    2, 0x0a /* Public */,
      21,    0,  113,    2, 0x0a /* Public */,
      22,    0,  114,    2, 0x0a /* Public */,
      23,    0,  115,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    6,
    QMetaType::Void, 0x80000000 | 10,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
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
        case 0: _t->openRecentFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->dropEvent((*reinterpret_cast< QDropEvent*(*)>(_a[1]))); break;
        case 2: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 3: _t->dragEnterEvent((*reinterpret_cast< QDragEnterEvent*(*)>(_a[1]))); break;
        case 4: _t->openRecentFile_aux(); break;
        case 5: _t->updateRecentFileActions(); break;
        case 6: _t->addToRecentFiles((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->on_actionLoad_triggered(); break;
        case 8: _t->open((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_actionBox_triggered(); break;
        case 10: _t->on_actionCircle_triggered(); break;
        case 11: _t->on_actionClear_triggered(); break;
        case 12: _t->on_actionRefine_triggered(); break;
        case 13: _t->on_actionDelaunay_conforming_triggered(); break;
        case 14: _t->on_actionGabriel_conforming_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::openRecentFile)) {
                *result = 0;
                return;
            }
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
        return static_cast<void*>(const_cast< MainWindow*>(this));
    if (!strcmp(_clname, "Ui_MainWindow"))
        return static_cast< Ui_MainWindow*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::openRecentFile(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
