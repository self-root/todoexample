#ifndef TODOCORE_GLOBAL_H
#define TODOCORE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TODOCORE_LIBRARY)
#  define TODOCORE_EXPORT Q_DECL_EXPORT
#else
#  define TODOCORE_EXPORT Q_DECL_IMPORT
#endif

#endif // TODOCORE_GLOBAL_H
