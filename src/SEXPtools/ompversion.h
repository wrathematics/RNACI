/* This Source Code Form is subject to the terms of the BSD 2-Clause
 * License. If a copy of the this license was not distributed with this
 * file, you can obtain one from http://opensource.org/licenses/BSD-2-Clause. */

// Copyright 2014, Schmidt

#ifdef _OPENMP
#include <omp.h>
#if _OPENMP >= 201307
#define _OPENMP_SUPPORT_SIMD
#endif
#endif


