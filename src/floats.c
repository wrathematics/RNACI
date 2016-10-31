RNACI_FUNTYPE int fis_zerof(float x)
{
  const float abs_epsf = 1.1f * FLT_EPSILON;
  if (fabsf(x) < abs_epsf*FLT_MIN)
    return true;
  else
    return false;
}



RNACI_FUNTYPE int fis_zero(double x)
{
  const double abs_eps = 1.1 * DBL_EPSILON;
  if (fabs(x) < abs_eps*DBL_MIN)
    return true;
  else
    return false;
}



RNACI_FUNTYPE int fequalsf(float x, float y)
{
  const float abs_epsf = 1.1f * FLT_EPSILON;
  const double diff = fabsf(x - y);
  
  if (x == y)
    return true;
  else if (x == 0.0f || y == 0.0f || diff < FLT_MIN)
    return diff < (abs_epsf*FLT_MIN);
  else
    return diff/(fabsf(x) + fabsf(y)) < abs_epsf;
}



RNACI_FUNTYPE int fequals(double x, double y)
{
  const double abs_eps = 1.1 * DBL_EPSILON;
  const double diff = fabs(x - y);
  
  if (x == y)
    return true;
  else if (x == 0.0 || y == 0.0 || diff < DBL_MIN)
    return diff < (abs_eps*DBL_MIN);
  else
    return diff/(fabs(x) + fabs(y)) < abs_eps;
}
