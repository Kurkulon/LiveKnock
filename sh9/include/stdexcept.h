/***************************************************************************/
/* Copyright (C) 1998 (1998 - 2010) Renesas Electronics Corporation and    */
/* Renesas Solutions Corp. All Rights Reserved.                            */
/***************************************************************************/
/***********************************************************************/
/* SPEC;                                                               */
/*  NAME = stdexcept.h :                                               */
/*                                                                     */
/*  FUNC = Include file for exception handling (see 19.1.1)            */
/*                                                                     */
/*  CLAS = UNIT;                                                       */
/*                                                                     */
/* END;                                                                */
/***********************************************************************/

#ifndef _STDEXCEPT_H
#define _STDEXCEPT_H

/* This lets users disable the EDG supplied exception classes. */
#ifndef __NO_EDG_EXCEPTION_CLASSES

#ifdef __EDG_RUNTIME_USES_NAMESPACES
namespace std {
#endif /* ifdef __EDG_RUNTIME_USES_NAMESPACES */
  class exception {
  public:
    exception() throw();
    exception& operator=(const exception&) throw();
    virtual ~exception() throw();
    virtual const char* what() const throw();
  };
#ifdef __EDG_RUNTIME_USES_NAMESPACES
}  /* namespace std */

#ifdef __EDG_IMPLICIT_USING_STD
/* Implicitly include a using directive for the STD namespace when this
   preprocessing flag is TRUE. */
using namespace std;
#endif /* ifdef __EDG_IMPLICIT_USING_STD */

#endif /* ifdef __EDG_RUNTIME_USES_NAMESPACES */

#endif /* ifndef __NO_EDG_EXCEPTION_CLASSES */

#endif /* _STDEXCEPT_H */

