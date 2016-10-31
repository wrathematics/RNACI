#ifndef __RNACI_INTERNAL_H_
#define __RNACI_INTERNAL_H_

#include "build_type.h"

#include <Rinternals.h>

#define RNACI_VERSION 0.3.0

#define RNACI_MAX(m,n) m<n?n:m
#define RNULL R_NilValue


// R data accessors
#define RNACI_IGNORED -1

#define __RNACI_INT(x,y,...) INTEGER(x)[y]
#define INT(...) __RNACI_INT(__VA_ARGS__,0,RNACI_IGNORED)

#define __RNACI_DBL(x,y,...) REAL(x)[y]
#define DBL(...) __RNACI_DBL(__VA_ARGS__,0,RNACI_IGNORED)

#define __RNACI_STR(x,y,...) ((char*)CHAR(STRING_ELT(x,y)))
#define STR(...) __RNACI_STR(__VA_ARGS__,0,RNACI_IGNORED)


#define MatINT(x,i,j) (INTEGER(x)[i+nrows(x)*j])
#define MatDBL(x,i,j) (REAL(x)[i+nrows(x)*j])

#define INTP(x) (INTEGER(x))
#define DBLP(x) (REAL(x))



#define newRptr(ptr,Rptr,fin) PROTECT(Rptr = R_MakeExternalPtr(ptr, R_NilValue, R_NilValue));R_RegisterCFinalizerEx(Rptr, fin, TRUE)
#define getRptr(ptr) R_ExternalPtrAddr(ptr);

#define newRfreeptrfun(FNAME,TYPE,FREEFUN) \
static void FNAME(SEXP ptr) \
{ \
  if (NULL == R_ExternalPtrAddr(ptr)) return; \
  TYPE *tmp = (TYPE *) R_ExternalPtrAddr(ptr); \
  FREEFUN(tmp); \
  R_ClearExternalPtr(ptr); \
}




// GC stuff
#define R_INIT int __RNACI_SEXP_protect_counter=0
#define PT(x) PROTECT((x)); (__RNACI_SEXP_protect_counter)++
#define R_END (UNPROTECT(__RNACI_SEXP_protect_counter))


// Allocations
#define OPTIONALARG1(a,b,c,...) (a),(b),(c)

#define newRlist(x,n) PT(x=__Rvecalloc(n, "vec", false))
// #define newRvec(x,n,type) PT(x=__Rvecalloc(n, type,false))
#define newRvec(x,...) PT(x=__Rvecalloc(OPTIONALARG1(__VA_ARGS__,false,RNACI_IGNORED)))
// #define newRmat(x,m,n,type) PT(x=__Rmatalloc(m,n,type,false))
#define newRmat(x,m,...) PT(x=__Rmatalloc(m,OPTIONALARG1(__VA_ARGS__,false,RNACI_IGNORED)))


/* Misc stuff */
#define nonzero(x) (x?x:1)

#define is_null(x) (x==NULL)

#if __STDC_VERSION__ >= 199901L
#define dbstart printf("DEBUGGING in %s Started\n", __func__);int __RNACI_debug_printing_counter=0
#define dbstop printf("DEBUGGING in %s Ended\n", __func__)
#else
#define dbstart int __RNACI_debug_printing_counter=0
#endif

#define dbshow printf("%d\n", __RNACI_debug_printing_counter);__RNACI_debug_printing_counter++;



#endif
