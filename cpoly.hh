// Header for cpolycc function.

// SPDX-License-Identifier: MIT
// Copyright (c) [2024] [George William Patrick]

// 10-14-2024 (GWP)]

#pragma once

#define ECPOLYCC_LIMIT    1
#define ECPOLYCC_OVERFLOW 2

namespace cpolycc {
  template<typename T, typename U> int cpoly(T**, int, U*, int&, int&, int&);
  template<typename T, typename U> int cpoly(T**, int, int, int, int, U, int&, int&, int&);
  template<typename T> void cpoly(T**, int);
}

#include "cpoly_single.hh" 
#include "cpoly_multi.hh"
