// Copyright 2013, Schmidt

#include "../Rtools/Rtools.h"


// Lists
SEXP test_list(SEXP names)
{
  int ptct = 0;
  SEXP a, b;
  SEXP R_list, R_list_names;
  int hasnames = INTEGER(names)[0];

  PT(a = Rvecalloc(2, "int"), ptct);
  PT(b = Rvecalloc(1, "double"), ptct);

  INT(a,0) = 1;
  INT(a,1) = 2;

  DBL(b,0) = -10.10214;

  if (hasnames == 0)
  {
    R_list = make_list_nonames(2, a, b);
  }
  else
  {
    R_list_names = make_list_names(2, "abc", "defg");
    R_list = make_list(R_list_names, a, b);
  }


  UNPT(ptct);
  return R_list;
}



// Printing
SEXP test_print()
{
  int ptct = 0;
  SEXP a;

  PT(a = Rmatalloc(2, 2, "double"), ptct);

  DBL(a,0) = 1;
  DBL(a,1) = 2;
  DBL(a,2) = 3;
  DBL(a,3) = 4;

  PRINT(a);

  UNPT(ptct);
  return R_NilValue;
}
