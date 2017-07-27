RNACI_FUNTYPE SEXP _make_list_names(int n, ...)
{
  char *tmp;
  SEXP R_list_names;
  va_list listPointer;
  
  PROTECT(R_list_names = allocVector(STRSXP, n));
  
  va_start(listPointer, n);
  
  for (int i=0; i<n; i++)
  {
    tmp = va_arg(listPointer, char*);
  
    SET_STRING_ELT(R_list_names, i, mkChar(tmp));
  }
  
  va_end(listPointer);
  
  UNPROTECT(1);
  return R_list_names;
}

RNACI_FUNTYPE SEXP _make_list(SEXP R_list_names, const int n, ...)
{
  SEXP tmp, R_list;
  va_list listPointer;
  
  PROTECT(R_list = allocVector(VECSXP, n));
  
  va_start(listPointer, n);
  
  for (int i=0; i<n; i++)
  {
    tmp = va_arg(listPointer, SEXP);
  
    SET_VECTOR_ELT(R_list, i, tmp);
  }
  
  va_end(listPointer);
  
  if (R_list_names != RNULL)
    set_list_names(R_list, R_list_names);
  
  UNPROTECT(1);
  return R_list;
}
