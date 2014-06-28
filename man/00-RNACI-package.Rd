\name{RNACI-package}
\alias{RNACI-package}
\alias{RNACI}

\docType{package}
\title{RNACI: Utilities for R's Native C Interface}
\description{
  This package contains a set of hopefully useful functions and 
  macros that live on top of R's native C interface. It can be used 
  somewhat in the same way as Rcpp, though it is much less comprehensive 
  in scope than Rcpp. 
}
\details{
  This package is meant to help with the task of 
  wrapping pure C (not C++) and Fortran code for use with R using the 
  native interface.  Currently, the package is very young.  At this time, 
  most of its utility is found in the SEXP printer, simplified SEXP 
  allocation (with automatic gc counting), and the creation and 
  management of lists and dataframes.  For instance, by making use of 
  C99's va_args, we can create arbitrary lists of named objects in just 2 
  simple function calls.  For a full specification, see the package 
  vignette.
  
  The ngram package is distributed under the permissive 2-clause BSD 
  license.  If you find the code here useful, please let us know
  and/or cite the package, whatever is appropriate.
}
\author{
  Drew Schmidt \email{wrathematics AT gmail.com}, Wei-Chen Chen
}
\keyword{Package}
