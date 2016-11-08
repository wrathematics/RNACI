#ifndef __RNACI_API_H_
#define __RNACI_API_H_


#include <R.h>
#include <Rinternals.h>

#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <float.h>


// Internals, please excuse the mess
#define RNACI_VERSION 0.4.0

#define RNACI_MAX(m,n) m<n?n:m

#define RNACI_IGNORED -1

#define __RNACI_INT(x,y,...) INTEGER(x)[y]
#define __RNACI_DBL(x,y,...) REAL(x)[y]
#define __RNACI_STR(x,y,...) ((char*)CHAR(STRING_ELT(x,y)))

#define RNACI_PT(x) {PROTECT((x)); RNACIptct(1);}

#define OPTIONALARG1(a,b,c,...) (a),(b),(c)

extern unsigned int RNACI_ptct;


// defs
#define RNULL R_NilValue

// Access SEXP by value
#define INT(...) __RNACI_INT(__VA_ARGS__,0,RNACI_IGNORED)
#define DBL(...) __RNACI_DBL(__VA_ARGS__,0,RNACI_IGNORED)
#define STR(...) __RNACI_STR(__VA_ARGS__,0,RNACI_IGNORED)

// SEXP data pointer
#define MatINT(x,i,j) (INTEGER(x)[i+nrows(x)*j])
#define MatDBL(x,i,j) (REAL(x)[i+nrows(x)*j])

#define INTP(x) (INTEGER(x))
#define DBLP(x) (REAL(x))

// gc guards
#define R_INIT
#define R_END UNPROTECT(RNACIptct(0)); RNACIptct(-1);
#define hidefromGC(x) RNACI_PT(x)
#define unhideGC() R_END

// External pointers
#define newRptr(ptr,Rptr,fin) PROTECT(Rptr = R_MakeExternalPtr(ptr, R_NilValue, R_NilValue));R_RegisterCFinalizerEx(Rptr, fin, TRUE);RNACIptct(1);
#define getRptr(ptr) R_ExternalPtrAddr(ptr);

#define newRptrfreefun(FNAME,TYPE,FREEFUN) \
static inline void FNAME(SEXP ptr) \
{ \
  if (NULL == R_ExternalPtrAddr(ptr)) return; \
  TYPE *tmp = (TYPE *) R_ExternalPtrAddr(ptr); \
  FREEFUN(tmp); \
  R_ClearExternalPtr(ptr); \
} \
void __ignore_me_just_here_for_semicolons();

// allocators
#define newRlist(x,n) (x=__Rvecalloc(n, "vec", false))
// #define newRvec(x,n,type) RNACI_PT(x=__Rvecalloc(n, type,false))
#define newRvec(x,...) (x=__Rvecalloc(OPTIONALARG1(__VA_ARGS__,false,RNACI_IGNORED)))
// #define newRmat(x,m,n,type) RNACI_PT(x=__Rmatalloc(m,n,type,false))
#define newRmat(x,m,...) (x=__Rmatalloc(m,OPTIONALARG1(__VA_ARGS__,false,RNACI_IGNORED)))

#define setRclass(x,name) __Rsetclass(x, name);

// misc
#define Rputchar(c) Rprintf("%c", c)



// floats.c
RNACI_FUNTYPE int fis_zero(double x);
RNACI_FUNTYPE int fequals(double x, double y);

// misc.c
RNACI_FUNTYPE int is_Rnull(SEXP x);
RNACI_FUNTYPE int is_Rnan(SEXP x);
RNACI_FUNTYPE int is_Rna(SEXP x);
RNACI_FUNTYPE int is_double(SEXP x);
RNACI_FUNTYPE int is_integer(SEXP x);

// printinc.c
RNACI_FUNTYPE void PRINT(SEXP x);

// structures_dataframes.c
RNACI_FUNTYPE SEXP make_dataframe(SEXP R_rownames, SEXP R_colnames, int n, ...);

// structures_lists.c
RNACI_FUNTYPE SEXP make_list_names(int n, ...);
RNACI_FUNTYPE SEXP make_list(SEXP R_list_names, const int n, ...);

// structures_misc.c
RNACI_FUNTYPE void set_list_names(SEXP R_list, SEXP R_names);
RNACI_FUNTYPE void set_df_rownames(SEXP R_df, SEXP R_rownames);
RNACI_FUNTYPE void set_df_colnames(SEXP R_df, SEXP R_colnames);
RNACI_FUNTYPE void set_list_as_df(SEXP R_list);


#endif
