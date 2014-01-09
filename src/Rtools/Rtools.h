/* This Source Code Form is subject to the terms of the BSD 2-Clause
 * License. If a copy of the this license was not distributed with this
 * file, you can obtain one from http://opensource.org/licenses/BSD-2-Clause. */

// Copyright 2014, Schmidt


#ifndef __RTOOLS_H__
#define __RTOOLS_H__


#include <R.h>
#include <Rinternals.h>

#include <stdarg.h>
#include <string.h>


/* R stuff */

#define RNULL R_NilValue

// R data accessors
#define INT(x,i) (INTEGER(x)[i])
#define DBL(x,i) (REAL(x)[i])
#define STR(x,i) ((char*)CHAR(STRING_ELT(x,i)))

#define MatINT(x,i,j) (INTEGER(x)[i+nrows(x)*j])
#define MatDBL(x,i,j) (REAL(x)[i+nrows(x)*j])

#define INTP(x) (INTEGER(x))
#define DBLP(x) (REAL(x))

// GC stuff
#define R_INIT int __Rtools_SEXP_protect_counter=0
#define PT(x) PROTECT((x)); (__Rtools_SEXP_protect_counter)++
#define R_END (UNPROTECT(__Rtools_SEXP_protect_counter))

// Allocations
#define newRlist(x,n) PT(x=Rvecalloc(n, "vec"))
#define newRvec(x,n,type) PT(x=Rvecalloc(n, type))
#define newRmat(x,m,n,type) PT(x=Rmatalloc(m,n,type))

/* Misc stuff */

#define nonzero(x) (x?x:1)

#define true 1
#define false 0

#define is_null(x) (x==NULL)

#if __STDC_VERSION__ >= 199901L
#define dbstart printf("%s Started\n", __func__);int __Rtools_debug_printing_counter=0
#define dbstop printf("%s Ended\n", __func__)
#else
#define dbstart int __Rtools_debug_printing_counter=0
#endif

#define dbshow printf("%d\n", __Rtools_debug_printing_counter);__Rtools_debug_printing_counter++;


// alloc.c
SEXP Rvecalloc(int n, char *type);
SEXP Rmatalloc(int m, int n, char *type);

// misc.c
int is_Rnull(SEXP x);
int is_Rnan(SEXP x);
int is_Rna(SEXP x);
int is_double(SEXP x);
int is_integer(SEXP x);

// printing.c
void PRINT(SEXP x);

// structures_dataframes.c
SEXP make_dataframe_nonames(int n, ...);

// structures_lists.c
SEXP make_list_names(int n, ...);
SEXP make_list(SEXP R_list_names, ...);
SEXP make_list_nonames(int n, ...);

// structures_misc.c
void set_list_names(SEXP R_list, SEXP R_names);
void set_df_rownames(SEXP R_df, SEXP R_rownames);
void set_df_colnames(SEXP R_df, SEXP R_colnames);


#endif
