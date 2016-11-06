RNACI_FUNTYPE SEXP make_list_names(int n, ...)
{
  int i;
  char *tmp;
  SEXP R_list_names;
  va_list listPointer;
  
  newRvec(R_list_names, n, "str");
  
  va_start(listPointer, n);
  
  for (i=0; i<n; i++)
  {
    tmp = va_arg(listPointer, char *);
  
    SET_STRING_ELT(R_list_names, i, mkChar(tmp));
  }
  
  va_end(listPointer);
  
  return R_list_names;
}

RNACI_FUNTYPE SEXP make_list(SEXP R_list_names, const int n, ...)
{
  int i;
  SEXP tmp, R_list;
  va_list listPointer;
  
  newRlist(R_list, n);
  
  va_start(listPointer, n);
  
  for (i=0; i<n; i++)
  {
    tmp = va_arg(listPointer, SEXP);
  
    SET_VECTOR_ELT(R_list, i, tmp);
  }
  
  va_end(listPointer);
  
  if (R_list_names != RNULL)
    set_list_names(R_list, R_list_names);
  
  return R_list;
}
