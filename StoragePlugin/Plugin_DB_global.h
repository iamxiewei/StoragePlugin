#ifndef PLUGIN_DB_GLOBAL_H
#define PLUGIN_DB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PLUGIN_DB_LIBRARY)
#  define PLUGIN_DB_EXPORT Q_DECL_EXPORT
#else
#  define PLUGIN_DB_EXPORT Q_DECL_IMPORT
#endif

#endif // PLUGIN_DB_GLOBAL_H
