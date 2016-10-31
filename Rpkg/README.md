# RNACI 

* **Version:** 0.2.0
* **License:** [![License](http://img.shields.io/badge/license-BSD%202--Clause-orange.svg?style=flat)](http://opensource.org/licenses/BSD-2-Clause)
* **Author:** Drew Schmidt and Wei-Chen Chen


RNACI is a set of tools to aid in dealing with R's native C interface.

If you are interfacing R to C or Fortran, bringing C++ into the mix can
be a recipe for headaches and disaster.  Also, C++ takes much longer to
compile than C, so if you aren't really using the features of C++, then
this is a fruitless way to complicate development.  This package 
tries to fill the "wrapper gap" for C/Fortran programmers interfacing 
compiled code to R.

Currently, the package is very young.  At this time, most of the 
proper improvements are in the form of SEXP allocation (and
automatic gc counting), and the creation/management of lists and
dataframes (by making extensive use of VA_ARGS).



## Installation

Using the devtools package:

```r
devtools::install_github("wrathematics/RNACI")
```

The package vignette explains how to use RNACI and how to link
an R package with RNACI.  See `RNACI/src/zzz_tests.c` and 
`RNACI/src/zzz_examples.c` for example usage.  For example usage 
in real packages, see pbdBASE (especially), pbdDMAT, and memuse.
