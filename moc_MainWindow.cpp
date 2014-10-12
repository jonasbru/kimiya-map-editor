/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created: Sat Nov 28 17:36:50 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MainWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      23,   11,   11,   11, 0x08,
      40,   11,   11,   11, 0x08,
      47,   11,   11,   11, 0x08,
      56,   11,   11,   11, 0x08,
      66,   11,   11,   11, 0x08,
      78,   11,   11,   11, 0x08,
      85,   11,   11,   11, 0x08,
      92,   11,   11,   11, 0x08,
      99,   11,   11,   11, 0x08,
     107,   11,   11,   11, 0x08,
     113,   11,   11,   11, 0x08,
     124,   11,   11,   11, 0x08,
     136,   11,   11,   11, 0x08,
     150,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0openFile()\0openFileDialog()\0"
    "save()\0saveAs()\0newFile()\0closeFile()\0"
    "undo()\0redo()\0copy()\0paste()\0cut()\0"
    "deselect()\0selectAll()\0showOptions()\0"
    "showAbout()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

const QMetaObject *MainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: openFile(); break;
        case 1: openFileDialog(); break;
        case 2: save(); break;
        case 3: saveAs(); break;
        case 4: newFile(); break;
        case 5: closeFile(); break;
        case 6: undo(); break;
        case 7: redo(); break;
        case 8: copy(); break;
        case 9: paste(); break;
        case 10: cut(); break;
        case 11: deselect(); break;
        case 12: selectAll(); break;
        case 13: showOptions(); break;
        case 14: showAbout(); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
