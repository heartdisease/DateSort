/****************************************************************************
** Meta object code from reading C++ file 'DateSortProcess.h'
**
** Created: Sat Aug 20 01:23:54 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/DateSortProcess.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DateSortProcess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DateSortProcess[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   17,   16,   16, 0x05,
      46,   17,   16,   16, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_DateSortProcess[] = {
    "DateSortProcess\0\0msg\0progressMessage(QString)\0"
    "errorMessage(QString)\0"
};

const QMetaObject DateSortProcess::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_DateSortProcess,
      qt_meta_data_DateSortProcess, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DateSortProcess::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DateSortProcess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DateSortProcess::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DateSortProcess))
        return static_cast<void*>(const_cast< DateSortProcess*>(this));
    return QThread::qt_metacast(_clname);
}

int DateSortProcess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: progressMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: errorMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void DateSortProcess::progressMessage(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DateSortProcess::errorMessage(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
