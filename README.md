# RNACI 

* **Version:** 0.5.0
* **License:** [![License](http://img.shields.io/badge/license-BSD%202--Clause-orange.svg?style=flat)](http://opensource.org/licenses/BSD-2-Clause)
* **Author:** Drew Schmidt


RNACI is a set of tools to aid in dealing with R's native C interface.


## Building and Installation

To build, you can run

```bash
make
```

This will create a header-only version of the library in `build/headeronly`, and a "regular" version in `build/regular`.  The header-only version works just like C++ header-only libraries; just `#include` the file `RNACI.h` and you're good to go.  The "regular" version produces an API header `RNACI.h` and a C file `RNACI.c` which must be compiled.  In either case, copy the output to your project source tree and proceed as necessary depending on which you want.  

During the build/make process, nothing is actually compiled.  Some shell scripts cobble everything together.



## Examples

Creating a dataframe:

```C
#include "RNACI.h"

SEXP example_df()
{
  R_INIT;
  SEXP a, b;
  SEXP R_df;
  
  newRvec(a, 2, "int");
  newRvec(b, 2, "double");
  
  INT(a) = 1;
  INT(a,1) = 2;
  
  DBL(b,0) = -10.10214;
  DBL(b,1) = 1.23456;
  
  R_df = make_dataframe(RNULL, RNULL, 2, a, b);
  
  R_END;
  return R_df;
}
```



## Comparison to Rcpp

Ignoring the many packages in the *ecosystem* of Rcpp (RcppArmadillo, RcppEigen, ...), if we just focus on "regular" Rcpp, there are many differences compared to RNACI.  I think it's fair to say that Rcpp makes it very simple to write *new* code callable by R, or wrapping C++ code.  In my opinion, it mostly gets in the way for wrapping C; this is really more a criticism of C++ itself rather than Rcpp.

Code re-use is something I take very seriously.  I *want* people to take my code and re-purpose it for something I never imagined.

If you are interfacing R to C or Fortran, bringing C++ into the mix can be a recipe for headaches and disaster.  Also, C++ takes much longer to compile than C, so if you aren't really using the features of C++, then this is a fruitless way to complicate development.  This package tries to fill the "wrapper gap" for C/Fortran programmers interfacing compiled code to R.



If you are not a relatively experienced C programmer, I do not recommend using RNACI.  If you know C and like C, then I think it offers a valuable alternative to bringing C++ into a project.

About the only thing Rcpp and RNACI have in common is that they are both header-only and both try to improve the...let's say "imperfect" C interface for R.



Currently, the package is very young.  At this time, most of the proper improvements are in the form of SEXP allocation (and automatic gc counting), and the creation/management of lists and dataframes (by making extensive use of VA_ARGS).



## Testimony

> Dude, RNACI is amazing.
--- my friend, humoring me
