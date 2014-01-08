#ifndef __RTOOLS_H__
#define __RTOOLS_H__


#include <R.h>
#include <Rinternals.h>

#include <stdarg.h>
#include <string.h>


/* R stuff */

// Dummy return
#define RNULL R_NilValue

// R data accessors
#define INT(x,i) (INTEGER(x)[i])
#define DBL(x,i) (REAL(x)[i])
#define STR(x,i) ((char*)CHAR(STRING_ELT(x,i)))

#define INTP(x) (INTEGER(x))
#define DBLP(x) (REAL(x))

// GC stuff
#define PTINIT int __Rtools_SEXP_protect_counter=0
#define PT(x) PROTECT((x)); (__Rtools_SEXP_protect_counter)++
#define UNPT (UNPROTECT(__Rtools_SEXP_protect_counter))


/* Misc stuff */

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
