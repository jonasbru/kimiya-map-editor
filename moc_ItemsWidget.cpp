/****************************************************************************
** Meta object code from reading C++ file 'ItemsWidget.h'
**
** Created: Sat Nov 28 17:37:03 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ItemsWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ItemsWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ItemsWidget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      22,   13,   12,   12, 0x08,
      47,   13,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ItemsWidget[] = {
    "ItemsWidget\0\0newIndex\0itemThemeHasChanged(int)\0"
    "itemHasChanged(int)\0"
};

const QMetaObject ItemsWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ItemsWidget,
      qt_meta_data_ItemsWidget, 0 }
};

const QMetaObject *ItemsWidget::metaObject() const
{
    return &staticMetaObject;
}

void *ItemsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ItemsWidget))
        return static_cast<void*>(const_cast< ItemsWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ItemsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: itemThemeHasChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: itemHasChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
