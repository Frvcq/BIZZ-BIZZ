/****************************************************************************
** Meta object code from reading C++ file 'clientdata.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../clientdata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientdata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ClientData_t {
    QByteArrayData data[15];
    char stringdata0[298];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClientData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClientData_t qt_meta_stringdata_ClientData = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ClientData"
QT_MOC_LITERAL(1, 11, 23), // "lesNomsDesChampsChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 25), // "lesPointsGraphiqueChanged"
QT_MOC_LITERAL(4, 62, 36), // "onQnetworkAccessManagerReplyF..."
QT_MOC_LITERAL(5, 99, 32), // "onQnetworkAccessManagerReadyRead"
QT_MOC_LITERAL(6, 132, 28), // "onQnetworkAccessManagerError"
QT_MOC_LITERAL(7, 161, 32), // "onQnetworkAccessManagerSslErrors"
QT_MOC_LITERAL(8, 194, 10), // "parserData"
QT_MOC_LITERAL(9, 205, 17), // "segmentationFault"
QT_MOC_LITERAL(10, 223, 16), // "lesNomsDesChamps"
QT_MOC_LITERAL(11, 240, 14), // "QList<QString>"
QT_MOC_LITERAL(12, 255, 18), // "lesPointsGraphique"
QT_MOC_LITERAL(13, 274, 14), // "QList<QPointF>"
QT_MOC_LITERAL(14, 289, 8) // "nbChamps"

    },
    "ClientData\0lesNomsDesChampsChanged\0\0"
    "lesPointsGraphiqueChanged\0"
    "onQnetworkAccessManagerReplyFinished\0"
    "onQnetworkAccessManagerReadyRead\0"
    "onQnetworkAccessManagerError\0"
    "onQnetworkAccessManagerSslErrors\0"
    "parserData\0segmentationFault\0"
    "lesNomsDesChamps\0QList<QString>\0"
    "lesPointsGraphique\0QList<QPointF>\0"
    "nbChamps"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientData[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       3,   62, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       8,    0,   60,    2, 0x02 /* Public */,
       9,    0,   61,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      10, 0x80000000 | 11, 0x00495009,
      12, 0x80000000 | 13, 0x00495009,
      14, QMetaType::Int, 0x00095001,

 // properties: notify_signal_id
       0,
       1,
       0,

       0        // eod
};

void ClientData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ClientData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->lesNomsDesChampsChanged(); break;
        case 1: _t->lesPointsGraphiqueChanged(); break;
        case 2: _t->onQnetworkAccessManagerReplyFinished(); break;
        case 3: _t->onQnetworkAccessManagerReadyRead(); break;
        case 4: _t->onQnetworkAccessManagerError(); break;
        case 5: _t->onQnetworkAccessManagerSslErrors(); break;
        case 6: _t->parserData(); break;
        case 7: _t->segmentationFault(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ClientData::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientData::lesNomsDesChampsChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ClientData::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientData::lesPointsGraphiqueChanged)) {
                *result = 1;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QPointF> >(); break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ClientData *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QList<QString>*>(_v) = _t->getLesNomsDesChamps(); break;
        case 1: *reinterpret_cast< QList<QPointF>*>(_v) = _t->getLesPointsGraphique(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->getNbChamps(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject ClientData::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ClientData.data,
    qt_meta_data_ClientData,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ClientData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ClientData.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ClientData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ClientData::lesNomsDesChampsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ClientData::lesPointsGraphiqueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
