/***************************************************************************/
/* Copyright (C) 1998 (1998 - 2010) Renesas Electronics Corporation and    */
/* Renesas Solutions Corp. All Rights Reserved.                            */
/***************************************************************************/
/***********************************************************************/
/* SPEC;                                                               */
/*  NAME = new_edg.h :                                                 */
/*                                                                     */
/*  FUNC = Include file for C++ default operator new .                 */
/*                                                                     */
/*  CLAS = UNIT;                                                       */
/*                                                                     */
/* END;                                                                */
/***********************************************************************/

#ifndef __NEW_H
#define __NEW_H

#ifndef _STDDEF
#include <stddef.h>
#endif  /* ifndef _STDDEF */
#ifndef _EXCEPTION_H
#include <exception.h>
#endif /* _EXCEPTION_H */

#ifndef __EDG_STD_NAMESPACE
/* If not already defined, define a macro that expands to the namespace
   containing the standard library. */
#ifdef __EDG_RUNTIME_USES_NAMESPACES
#define __EDG_STD_NAMESPACE std
#else /* ifndef __EDG_RUNTIME_USES_NAMESPACES */
#define __EDG_STD_NAMESPACE /* nothing */
#endif /* ifdef __EDG_RUNTIME_USES_NAMESPACES */
#endif /* ifdef __EDG_STD_NAMESPACE */


#ifdef __EDG_RUNTIME_USES_NAMESPACES
namespace std {
#endif /* ifdef __EDG_RUNTIME_USES_NAMESPACES */

/* This lets users disable the EDG supplied exception classes. */
#ifndef __NO_EDG_EXCEPTION_CLASSES

  class bad_alloc : public exception {
  public:
    bad_alloc() throw();
    bad_alloc(const bad_alloc&) throw();
    bad_alloc& operator=(const bad_alloc&) throw();
    virtual ~bad_alloc() throw();
    virtual const char* what() const throw();
  };

#endif /* ifndef __NO_EDG_EXCEPTION_CLASSES */

  typedef void (*new_handler)();
  new_handler set_new_handler(new_handler);
  struct nothrow_t { };
  // Declaration of object nothrow to permit the use of the placement new
  // syntax: new (nothrow) T;
  const nothrow_t nothrow = {};

#ifdef __EDG_RUNTIME_USES_NAMESPACES
}  /* namespace std */

#ifdef __EDG_IMPLICIT_USING_STD
/* Implicitly include a using directive for the STD namespace when this
   preprocessing flag is TRUE. */
using namespace std;
#endif /* ifdef __EDG_IMPLICIT_USING_STD */

#endif /* ifdef __EDG_RUNTIME_USES_NAMESPACES */

/* Normal operator new. */
void *operator new(size_t) throw(__EDG_STD_NAMESPACE::bad_alloc);

/* Normal operator delete. */
void operator delete(void*) throw ();

/* Nothrow version of operator new. */
void *operator new(size_t, const __EDG_STD_NAMESPACE::nothrow_t&) throw();

/* Nothrow version of operator delete. */
void operator delete(void*, const __EDG_STD_NAMESPACE::nothrow_t&) throw();

/* Placement new. */
void *operator new(size_t, void*) throw();

/* Placement delete. */
#ifdef __PLACEMENT_DELETE
void operator delete(void*, void*) throw();
#endif /* ifdef __PLACEMENT_DELETE */

#ifdef __ARRAY_OPERATORS

/* Array new. */
void *operator new[](size_t) throw(__EDG_STD_NAMESPACE::bad_alloc);

/* Array delete. */
void operator delete[](void*) throw ();

/* Placement array new. */
void *operator new[](size_t, void*) throw();

/* Placement array delete. */
#ifdef __PLACEMENT_DELETE
void operator delete[](void*, void*) throw();
#endif /* ifdef __PLACEMENT_DELETE */

/* Nothrow version of array new. */
void *operator new[](size_t,
                     const __EDG_STD_NAMESPACE::nothrow_t&) throw();

/* Nothrow version of array delete. */
void operator delete[](void*,
                       const __EDG_STD_NAMESPACE::nothrow_t&) throw();
#endif /* __ARRAY_OPERATORS */

// EC++ use new_handler
extern __EDG_STD_NAMESPACE::new_handler _ec2p_new_handler;

#endif  /* ifndef __NEW_H */
