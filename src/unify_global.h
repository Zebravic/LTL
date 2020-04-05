#ifndef UNIFY_GLOBAL_H
#define UNIFY_GLOBAL_H

#if defined(_MSC_VER) || defined(WIN64) || defined(_WIN64) || defined(__WIN64__) || defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#  define Q_DECL_EXPORT __declspec(dllexport)
#  define Q_DECL_IMPORT __declspec(dllimport)
#else
#  define Q_DECL_EXPORT     __attribute__((visibility("default")))
#  define Q_DECL_IMPORT     __attribute__((visibility("default")))
#endif

#if defined(UNIFY_LIBRARY)
#  define UNIFY_EXPORT Q_DECL_EXPORT
#else
#  define UNIFY_EXPORT Q_DECL_IMPORT
#endif

#define BEGIN_UNIFY_NAMESPACE   namespace unify {
#define END_UNIFY_NAMESPACE     }

#define BEGIN_DETAIL_NAMESPACE  namespace unify::detail {
#define END_DETAIL_NAMESPACE    }

#endif // UNIFY_GLOBAL_H
