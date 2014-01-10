/* This Source Code Form is subject to the terms of the BSD 2-Clause
 * License. If a copy of the this license was not distributed with this
 * file, you can obtain one from http://opensource.org/licenses/BSD-2-Clause. */

// Copyright 2014, Schmidt

#include "SEXPtools.h"


void set_list_names(SEXP R_list, SEXP R_names)
{
  setAttrib(R_list, R_NamesSymbol, R_names);
}



void set_df_rownames(SEXP R_df, SEXP R_rownames)
{
  setAttrib(R_df, R_RowNamesSymbol, R_rownames);
}



void set_df_colnames(SEXP R_df, SEXP R_colnames)
{
  set_list_names(R_df, R_colnames);
}



void set_list_as_df(SEXP R_list)
{
  setAttrib(R_list, R_ClassSymbol, mkString("data.frame"));
}

