static inline unsigned int RNACIptct(const int increment)
{
  if (increment > 0)
    RNACI_ptct++;
  else if (increment == -1)
    RNACI_ptct = 0;
  
  return RNACI_ptct;
}

static inline SEXP __Rvecalloc(int n, char *type, int init)
{
  SEXP RET;
  
  if (strncmp(type, "vec", 1) == 0)
    PROTECT(RET = allocVector(VECSXP, n));
  else if (strncmp(type, "int", 1) == 0)
  {
    PROTECT(RET = allocVector(INTSXP, n));
    
    if (init)
      memset(INTP(RET), 0, n*sizeof(int));
  }
  else if (strncmp(type, "double", 1) == 0)
  {
    PROTECT(RET = allocVector(REALSXP, n));
    
    if (init)
      memset(DBLP(RET), 0, n*sizeof(double));
  }
  else if (strncmp(type, "str", 1) == 0 || strncmp(type, "char*", 1) == 0)
    PROTECT(RET = allocVector(STRSXP, n));
  else
    error("unknown allocation type\n");
  
  RNACIptct(1);
  return RET;
}

static inline SEXP __Rmatalloc(int m, int n, char *type, int init)
{
  SEXP RET;
  
  if (strncmp(type, "vec", 1) == 0)
    PROTECT(RET = allocMatrix(VECSXP, m, n));
  else if (strncmp(type, "int", 1) == 0)
  {
    PROTECT(RET = allocMatrix(INTSXP, m, n));
    
    if (init)
      memset(INTP(RET), 0, m*n*sizeof(int));
  }
  else if (strncmp(type, "double", 1) == 0)
  {
    PROTECT(RET = allocMatrix(REALSXP, m, n));
    
    if (init)
      memset(DBLP(RET), 0, m*n*sizeof(double));
  }
  else if (strncmp(type, "str", 1) == 0 || strncmp(type, "char*", 1) == 0)
    PROTECT(RET = allocMatrix(STRSXP, m, n));
  else
    error("unknown allocation type\n");
  
  RNACIptct(1);
  return RET;
}

static inline SEXP __Rsetclass(SEXP x, char *name)
{
  SEXP class;
  newRvec(class, 1, "str");
  SET_STRING_ELT(class, 0, mkChar(name));
  classgets(x, class);
  return class;
}
