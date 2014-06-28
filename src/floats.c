#include "SEXPtools.h"
#include <math.h>
#include <float.h>


// Absolute epsilons
const float abs_epsf = 1.1f * FLT_EPSILON;
const double abs_eps = 1.1 * DBL_EPSILON;



int fis_zerof(float x)
{
  if (fabsf(x) < abs_epsf*FLT_MIN)
    return true;
  else
    return false;
}

int fis_zero(double x)
{
  if (fabs(x) < abs_eps*DBL_MIN)
    return true;
  else
    return false;
}


int fequalsf(float x, float y)
{
  const double diff = fabsf(x - y);
  
  if (x == y)
    return true;
  else if (x == 0.0f || y == 0.0f || diff < FLT_MIN)
    return diff < (abs_epsf*FLT_MIN);
  else
    return diff/(fabsf(x) + fabsf(y)) < abs_epsf;
}

int fequals(double x, double y)
{
  const double diff = fabs(x - y);
  
  if (x == y)
    return true;
  else if (x == 0.0 || y == 0.0 || diff < DBL_MIN)
    return diff < (abs_eps*DBL_MIN);
  else
    return diff/(fabs(x) + fabs(y)) < abs_eps;
}


