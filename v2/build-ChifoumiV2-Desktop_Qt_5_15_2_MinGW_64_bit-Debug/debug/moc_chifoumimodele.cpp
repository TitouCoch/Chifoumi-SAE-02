/****************************************************************************
** Meta object code from reading C++ file 'chifoumimodele.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ChifoumiV2/chifoumimodele.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chifoumimodele.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChifoumiModele_t {
    QByteArrayData data[13];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChifoumiModele_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChifoumiModele_t qt_meta_stringdata_ChifoumiModele = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ChifoumiModele"
QT_MOC_LITERAL(1, 15, 13), // "setCoupJoueur"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 6), // "UnCoup"
QT_MOC_LITERAL(4, 37, 6), // "p_coup"
QT_MOC_LITERAL(5, 44, 14), // "setCoupMachine"
QT_MOC_LITERAL(6, 59, 14), // "setScoreJoueur"
QT_MOC_LITERAL(7, 74, 7), // "p_score"
QT_MOC_LITERAL(8, 82, 15), // "setScoreMachine"
QT_MOC_LITERAL(9, 98, 9), // "majScores"
QT_MOC_LITERAL(10, 108, 9), // "p_gagnant"
QT_MOC_LITERAL(11, 118, 10), // "initScores"
QT_MOC_LITERAL(12, 129, 9) // "initCoups"

    },
    "ChifoumiModele\0setCoupJoueur\0\0UnCoup\0"
    "p_coup\0setCoupMachine\0setScoreJoueur\0"
    "p_score\0setScoreMachine\0majScores\0"
    "p_gagnant\0initScores\0initCoups"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChifoumiModele[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x0a /* Public */,
       5,    1,   52,    2, 0x0a /* Public */,
       6,    1,   55,    2, 0x0a /* Public */,
       8,    1,   58,    2, 0x0a /* Public */,
       9,    1,   61,    2, 0x0a /* Public */,
      11,    0,   64,    2, 0x0a /* Public */,
      12,    0,   65,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::UInt,    7,
    QMetaType::Void, QMetaType::UInt,    7,
    QMetaType::Void, QMetaType::Char,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ChifoumiModele::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChifoumiModele *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setCoupJoueur((*reinterpret_cast< UnCoup(*)>(_a[1]))); break;
        case 1: _t->setCoupMachine((*reinterpret_cast< UnCoup(*)>(_a[1]))); break;
        case 2: _t->setScoreJoueur((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 3: _t->setScoreMachine((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 4: _t->majScores((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 5: _t->initScores(); break;
        case 6: _t->initCoups(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ChifoumiModele::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ChifoumiModele.data,
    qt_meta_data_ChifoumiModele,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ChifoumiModele::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChifoumiModele::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChifoumiModele.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ChifoumiModele::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
