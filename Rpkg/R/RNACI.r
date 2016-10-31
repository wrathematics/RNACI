#' RNACI
#' 
#' This package contains a set of hopefully useful functions and 
#' macros that live on top of R's native C interface. It can be used 
#' somewhat in the same way as Rcpp, though it is much less comprehensive 
#' in scope than Rcpp.
#' 
#' This package is meant to help with the task of 
#' wrapping pure C (not C++) and Fortran code for use with R using the 
#' native interface.  Currently, the package is very young.  At this time, 
#' most of its utility is found in the SEXP printer, simplified SEXP 
#' allocation (with automatic gc counting), and the creation and 
#' management of lists and dataframes.  For instance, by making use of 
#' C99's va_args, we can create arbitrary lists of named objects in just 2 
#' simple function calls.  For a full specification, see the package 
#' vignette.
#'
#' This package is licensed under the permissive 2-clause BSD license.
#'
#' @useDynLib RNACI
#'
#' @name RNACI
#' @docType package
#' @title RNACI
#' @author Drew Schmidt \email{wrathematics@@gmail.com} and Wei-Chen Chen
#' @keywords package
NULL
