/****************************************************************************
** Meta object code from reading C++ file 'threads.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/threads.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'threads.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Threads_t {
    QByteArrayData data[13];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Threads_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Threads_t qt_meta_stringdata_Threads = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Threads"
QT_MOC_LITERAL(1, 8, 11), // "txStartDraw"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 10), // "startPoint"
QT_MOC_LITERAL(4, 32, 10), // "txDrawLine"
QT_MOC_LITERAL(5, 43, 8), // "endPoint"
QT_MOC_LITERAL(6, 52, 13), // "txClearScreen"
QT_MOC_LITERAL(7, 66, 11), // "txPenColour"
QT_MOC_LITERAL(8, 78, 2), // "pc"
QT_MOC_LITERAL(9, 81, 11), // "rxStartDraw"
QT_MOC_LITERAL(10, 93, 10), // "rxDrawLine"
QT_MOC_LITERAL(11, 104, 13), // "rxClearScreen"
QT_MOC_LITERAL(12, 118, 11) // "rxPenColour"

    },
    "Threads\0txStartDraw\0\0startPoint\0"
    "txDrawLine\0endPoint\0txClearScreen\0"
    "txPenColour\0pc\0rxStartDraw\0rxDrawLine\0"
    "rxClearScreen\0rxPenColour"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Threads[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       6,    0,   60,    2, 0x06 /* Public */,
       7,    1,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   64,    2, 0x0a /* Public */,
      10,    1,   67,    2, 0x0a /* Public */,
      11,    0,   70,    2, 0x0a /* Public */,
      12,    1,   71,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void, QMetaType::QPoint,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QColor,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void, QMetaType::QPoint,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QColor,    8,

       0        // eod
};

void Threads::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Threads *_t = static_cast<Threads *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->txStartDraw((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 1: _t->txDrawLine((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 2: _t->txClearScreen(); break;
        case 3: _t->txPenColour((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 4: _t->rxStartDraw((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 5: _t->rxDrawLine((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 6: _t->rxClearScreen(); break;
        case 7: _t->rxPenColour((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Threads::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Threads::txStartDraw)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Threads::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Threads::txDrawLine)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Threads::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Threads::txClearScreen)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Threads::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Threads::txPenColour)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Threads::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Threads.data,
      qt_meta_data_Threads,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Threads::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Threads::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Threads.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int Threads::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Threads::txStartDraw(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Threads::txDrawLine(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Threads::txClearScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Threads::txPenColour(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
