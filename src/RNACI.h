/* This Source Code Form is subject to the terms of the BSD 2-Clause
 * License. If a copy of the this license was not distributed with this
 * file, you can obtain one from http://opensource.org/licenses/BSD-2-Clause. */

// Copyright 2014, Schmidt


#ifndef __RNACI_H__
#define __RNACI_H__


#include <R.h>
#include <Rinternals.h>

#include <stdarg.h>
#include <string.h>
#include <stdbool.h>


#define RNULL R_NilValue

// Voodoo Args
#define OPTIONALARG1(a,b,...) (a),(b)

// R data accessors
#define __RNACI_INT(x,y,...) INTEGER(x)[y]
#define INT(x,...) __RNACI_INT(x,##__VA_ARGS__,0)

#define __RNACI_DBL(x,y,...) REAL(x)[y]
#define DBL(x,...) __RNACI_DBL(x,##__VA_ARGS__,0)

#define __RNACI_STR(x,y,...) ((char*)CHAR(STRING_ELT(x,y)))
#define STR(x,...) __RNACI_STR(x,##__VA_ARGS__,0)


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
#define newRlist(x,n) PT(x=__Rvecalloc(n, "vec", false))
//#define newRvec(x,n,type) PT(x=__Rvecalloc(n, type))
#define newRvec(x,n,...) PT(x=__Rvecalloc(n,OPTIONALARG1(__VA_ARGS__,false)))
//#define newRmat(x,m,n,type) PT(x=__Rmatalloc(m,n,type))
#define newRmat(x,m,n,...) PT(x=__Rmatalloc(m,n,OPTIONALARG1(__VA_ARGS__,false)))


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


// alloc.c
SEXP __Rvecalloc(int n, char *type, int init);
SEXP __Rmatalloc(int m, int n, char *type, int init);

// floats.c
int fis_zerof(float x);
int fis_zero(double x);
int fequalsf(float x, float y);
int fequals(double x, double y);

// misc.c
int is_Rnull(SEXP x);
int is_Rnan(SEXP x);
int is_Rna(SEXP x);
int is_double(SEXP x);
int is_integer(SEXP x);

// printing.c
void PRINT(SEXP x);

// structures_dataframes.c
SEXP make_dataframe(SEXP R_rownames, SEXP R_colnames, int n, ...);

// structures_lists.c
SEXP make_list_names(int n, ...);
SEXP make_list(SEXP R_list_names, const int n, ...);

// structures_misc.c
void set_list_names(SEXP R_list, SEXP R_names);
void set_df_rownames(SEXP R_df, SEXP R_rownames);
void set_df_colnames(SEXP R_df, SEXP R_colnames);
void set_list_as_df(SEXP R_list);


#endif
