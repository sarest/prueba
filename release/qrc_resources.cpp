/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.6.0
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

static const unsigned char qt_resource_data[] = {
  // C:/Qt/Proyectos/interface_v3/imgs/grid.png
  0x0,0x0,0x0,0xb2,
  0x89,
  0x50,0x4e,0x47,0xd,0xa,0x1a,0xa,0x0,0x0,0x0,0xd,0x49,0x48,0x44,0x52,0x0,
  0x0,0x0,0xa,0x0,0x0,0x0,0xa,0x8,0x2,0x0,0x0,0x0,0x2,0x50,0x58,0xea,
  0x0,0x0,0x0,0x9,0x70,0x48,0x59,0x73,0x0,0x0,0xb,0x13,0x0,0x0,0xb,0x13,
  0x1,0x0,0x9a,0x9c,0x18,0x0,0x0,0x0,0x7,0x74,0x49,0x4d,0x45,0x7,0xdd,0x6,
  0x15,0xc,0x33,0x28,0x42,0x37,0xc3,0xf2,0x0,0x0,0x0,0x19,0x74,0x45,0x58,0x74,
  0x43,0x6f,0x6d,0x6d,0x65,0x6e,0x74,0x0,0x43,0x72,0x65,0x61,0x74,0x65,0x64,0x20,
  0x77,0x69,0x74,0x68,0x20,0x47,0x49,0x4d,0x50,0x57,0x81,0xe,0x17,0x0,0x0,0x0,
  0x2c,0x49,0x44,0x41,0x54,0x18,0xd3,0x63,0xfc,0xff,0xff,0x3f,0x3,0xe,0xd0,0xf0,
  0xe6,0xf,0x13,0x3,0x5e,0x80,0x4f,0x5a,0x92,0x85,0x91,0x2,0xdd,0xcf,0xff,0xfc,
  0xa7,0x40,0x37,0xc5,0xd2,0x2c,0xd,0x6f,0xfe,0xe0,0x91,0x6,0x0,0x6d,0xa8,0xa,
  0xe3,0x41,0x39,0x8e,0x68,0x0,0x0,0x0,0x0,0x49,0x45,0x4e,0x44,0xae,0x42,0x60,
  0x82,
  
};

static const unsigned char qt_resource_name[] = {
  // imgs
  0x0,0x4,
  0x0,0x7,0x3,0xe3,
  0x0,0x69,
  0x0,0x6d,0x0,0x67,0x0,0x73,
    // grid.png
  0x0,0x8,
  0x8,0xf7,0x5a,0x87,
  0x0,0x67,
  0x0,0x72,0x0,0x69,0x0,0x64,0x0,0x2e,0x0,0x70,0x0,0x6e,0x0,0x67,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
  // :/imgs
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x2,
  // :/imgs/grid.png
  0x0,0x0,0x0,0xe,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_resources)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_resources)()
{
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (0x01, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_resources)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_resources)()
{
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (0x01, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_resources)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_resources)(); }
   } dummy;
}
