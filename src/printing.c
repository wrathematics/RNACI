RNACI_FUNTYPE void PRINT(SEXP x)
{
  R_INIT;
  SEXP basePackage;
  
  PT( basePackage = eval( lang2( install("getNamespace"), ScalarString(mkChar("base")) ), R_GlobalEnv ) );
  
  eval( lang2( install("print"), x), basePackage);
  
  R_END;
}
