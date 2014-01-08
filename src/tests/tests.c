// Copyright 2013, Schmidt

#include "../Rtools/Rtools.h"


// Lists
SEXP test_list(SEXP names)
{
  PTINIT;
  SEXP a, b;
  SEXP R_list, R_list_names;
  int hasnames = INTEGER(names)[0];

  PT(a = Rvecalloc(2, "int"));
  PT(b = Rvecalloc(1, "double"));

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
  
  
  UNPT;
  return R_list;
}



// Printing
SEXP test_print()
{
  PTINIT;
  SEXP a;

  PT(a = Rmatalloc(2, 2, "double"));

  DBL(a,0) = 1;
  DBL(a,1) = 2;
  DBL(a,2) = 3;
  DBL(a,3) = 4;

  PRINT(a);

  UNPT;
  return R_NilValue;
}



// Dataframes
SEXP test_df()
{
  PTINIT;
  SEXP a, b;
  SEXP R_list, R_list_names;
  
  PT(a = Rvecalloc(2, "int"));
  PT(b = Rvecalloc(2, "double"));
  
  INT(a,0) = 1;
  INT(a,1) = 2;
  
  DBL(b,0) = -10.10214;
  DBL(b,1) = 1.23456;
  
  R_list_names = make_list_names(2, "abc", "defg");
  R_list = make_dataframe_nonames(2, a, b);
  
  UNPT;
  return R_list;
}




