/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.15.1
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

static const unsigned char qt_resource_data[] = {
  // /home/bngu/Repos/individual_project_db_3010/updated_code_2/PPWProj/data.txt
  0x0,0x0,0x0,0x0,
  
    // /home/bngu/Repos/individual_project_db_3010/updated_code_2/PPWProj/storage.txt
  0x0,0x0,0x0,0x2,
  0x23,
  0x20,
  
};

static const unsigned char qt_resource_name[] = {
  // data.txt
  0x0,0x8,
  0x8,0xa4,0x56,0xb4,
  0x0,0x64,
  0x0,0x61,0x0,0x74,0x0,0x61,0x0,0x2e,0x0,0x74,0x0,0x78,0x0,0x74,
    // storage.txt
  0x0,0xb,
  0x7,0x25,0x36,0xf4,
  0x0,0x73,
  0x0,0x74,0x0,0x6f,0x0,0x72,0x0,0x61,0x0,0x67,0x0,0x65,0x0,0x2e,0x0,0x74,0x0,0x78,0x0,0x74,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/storage.txt
  0x0,0x0,0x0,0x16,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x4,
0x0,0x0,0x1,0x75,0xdd,0xf0,0x66,0x74,
  // :/data.txt
  0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x75,0xdd,0xf0,0x66,0x74,

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

int QT_RCC_MANGLE_NAMESPACE(qInitResources_qmake_qmake_immediate)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_qmake_qmake_immediate)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_qmake_qmake_immediate)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_qmake_qmake_immediate)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_qmake_qmake_immediate)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_qmake_qmake_immediate)(); }
   } dummy;
}
