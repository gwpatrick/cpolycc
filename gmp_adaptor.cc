//Simple function adaptor to gmp.

// SPDX-License-Identifier: MIT
// Copyright (c) [2024] [George William Patrick]

// 2024-10-08 GWP

#include <iostream>
#include <gmp_adaptor.hh>

namespace gmp_adaptor {

#define R MPFR_RNDZ

bool is_nan   ( mpfr_t x ) { return mpfr_nan_p(x); }
bool is_inf   ( mpfr_t x ) { return mpfr_inf_p(x); }
bool is_zero  ( mpfr_t x ) { return mpfr_sgn(x) == 0; }
bool is_nzero ( mpfr_t x ) { return mpfr_sgn(x) != 0; }
bool is_neg   ( mpfr_t x ) { return mpfr_sgn(x) < 0; }
bool is_nneg  ( mpfr_t x ) { return mpfr_sgn(x) >= 0; }
bool is_pos   ( mpfr_t x ) { return mpfr_sgn(x) > 0; }
bool is_npos  ( mpfr_t x ) { return mpfr_sgn(x) <= 0; }
bool is_zero  ( mpz_t  x ) { return mpz_sgn(x) == 0; }
bool is_nzero ( mpz_t  x ) { return mpz_sgn(x) != 0; }
bool is_neg   ( mpz_t  x ) { return mpz_sgn(x) < 0; }
bool is_nneg  ( mpz_t  x ) { return mpz_sgn(x) >= 0; }
bool is_pos   ( mpz_t  x ) { return mpz_sgn(x) > 0; }
bool is_npos  ( mpz_t  x ) { return mpz_sgn(x) <= 0; }

bool is_eq  ( mpfr_t x, mpfr_t y  ) { return mpfr_equal_p(x, y); }
bool is_eq  ( mpfr_t x, float128_t y  ) ;
bool is_eq  ( mpfr_t x, float64_t y   ) ;
bool is_eq  ( mpfr_t x, float32_t y   ) ;
bool is_eq  ( mpfr_t x, float16_t y   ) { return is_eq(x, (float32_t) y); }
bool is_eq  ( mpfr_t x, bfloat16_t y  ) { return is_eq(x, (float32_t) y); }
bool is_eq  ( mpfr_t x, mpz_t y   ) { return mpfr_cmp_z(x, y) == 0;  }
bool is_eq  ( mpfr_t x, uint128_t y ) ;
bool is_eq  ( mpfr_t x, uint64_t y  ) { return mpfr_cmp_ui(x, y) == 0; }
bool is_eq  ( mpfr_t x, uint32_t y  ) { return mpfr_cmp_ui(x, y) == 0; }
bool is_eq  ( mpfr_t x, uint16_t y  ) { return mpfr_cmp_ui(x, y) == 0; }
bool is_eq  ( mpfr_t x, int128_t y  ) ;
bool is_eq  ( mpfr_t x, int64_t y   ) { return mpfr_cmp_si(x, y) == 0; }
bool is_eq  ( mpfr_t x, int32_t y   ) { return mpfr_cmp_si(x, y) == 0; }
bool is_eq  ( mpfr_t x, int16_t y   ) { return mpfr_cmp_si(x, y) == 0; }
bool is_eq  ( mpz_t x,  mpz_t y   ) { return mpz_cmp(x, y) == 0; }
bool is_eq  ( mpz_t x,  uint128_t y ) ;
bool is_eq  ( mpz_t x,  uint64_t y  ) { return mpz_cmp_ui(x, y) == 0; }
bool is_eq  ( mpz_t x,  uint32_t y  ) { return mpz_cmp_ui(x, y) == 0; }
bool is_eq  ( mpz_t x,  uint16_t y  ) { return mpz_cmp_ui(x, y) == 0; }
bool is_eq  ( mpz_t x,  int128_t y  ) ;
bool is_eq  ( mpz_t x,  int64_t y   ) { return mpz_cmp_si(x, y) == 0; }
bool is_eq  ( mpz_t x,  int32_t y   ) { return mpz_cmp_si(x, y) == 0; }
bool is_eq  ( mpz_t x,  int16_t y   ) { return mpz_cmp_si(x, y) == 0; }

bool is_lt  ( mpfr_t x, mpfr_t y  ) { return mpfr_less_p(x, y); }
bool is_lt  ( mpfr_t x, float128_t y  ) ;
bool is_lt  ( mpfr_t x, float64_t y   ) ;
bool is_lt  ( mpfr_t x, float32_t y   ) ;
bool is_lt  ( mpfr_t x, float16_t y   ) { return is_lt(x, (float32_t) y); }
bool is_lt  ( mpfr_t x, bfloat16_t y  ) { return is_lt(x, (float32_t) y); }
bool is_lt  ( mpfr_t x, mpz_t y   ) { return mpfr_cmp_z(x, y) < 0;  }
bool is_lt  ( mpfr_t x, uint128_t y ) ;
bool is_lt  ( mpfr_t x, uint64_t y  ) { return mpfr_cmp_ui(x, y) < 0; }
bool is_lt  ( mpfr_t x, uint32_t y  ) { return mpfr_cmp_ui(x, y) < 0; }
bool is_lt  ( mpfr_t x, uint16_t y  ) { return mpfr_cmp_ui(x, y) < 0; }
bool is_lt  ( mpfr_t x, int128_t y  ) ;
bool is_lt  ( mpfr_t x, int64_t y   ) { return mpfr_cmp_si(x, y) < 0; }
bool is_lt  ( mpfr_t x, int32_t y   ) { return mpfr_cmp_si(x, y) < 0; }
bool is_lt  ( mpfr_t x, int16_t y   ) { return mpfr_cmp_si(x, y) < 0; }
bool is_lt  ( mpz_t x,  mpz_t y   ) { return mpz_cmp(x, y) < 0; }
bool is_lt  ( mpz_t x,  uint128_t y ) ;
bool is_lt  ( mpz_t x,  uint64_t y  ) { return mpz_cmp_ui(x, y) < 0; }
bool is_lt  ( mpz_t x,  uint32_t y  ) { return mpz_cmp_ui(x, y) < 0; }
bool is_lt  ( mpz_t x,  uint16_t y  ) { return mpz_cmp_ui(x, y) < 0; }
bool is_lt  ( mpz_t x,  int128_t y  ) ;
bool is_lt  ( mpz_t x,  int64_t y   ) { return mpz_cmp_si(x, y) < 0; }
bool is_lt  ( mpz_t x,  int32_t y   ) { return mpz_cmp_si(x, y) < 0; }
bool is_lt  ( mpz_t x,  int16_t y   ) { return mpz_cmp_si(x, y) < 0; }

bool is_le  ( mpfr_t x, mpfr_t y  ) { return mpfr_lessequal_p(x, y); }
bool is_le  ( mpfr_t x, float128_t y  ) ;
bool is_le  ( mpfr_t x, float64_t y   ) ;
bool is_le  ( mpfr_t x, float32_t y   ) ;
bool is_le  ( mpfr_t x, float16_t y   ) { return is_le(x, (float32_t) y); }
bool is_le  ( mpfr_t x, bfloat16_t y  ) { return is_le(x, (float32_t) y); }
bool is_le  ( mpfr_t x, mpz_t y   ) { return mpfr_cmp_z(x, y) <= 0;  }
bool is_le  ( mpfr_t x, uint128_t y ) ;
bool is_le  ( mpfr_t x, uint64_t y  ) { return mpfr_cmp_ui(x, y) <= 0; }
bool is_le  ( mpfr_t x, uint32_t y  ) { return mpfr_cmp_ui(x, y) <= 0; }
bool is_le  ( mpfr_t x, uint16_t y  ) { return mpfr_cmp_ui(x, y) <= 0; }
bool is_le  ( mpfr_t x, int128_t y  ) ;
bool is_le  ( mpfr_t x, int64_t y   ) { return mpfr_cmp_si(x, y) <= 0; }
bool is_le  ( mpfr_t x, int32_t y   ) { return mpfr_cmp_si(x, y) <= 0; }
bool is_le  ( mpfr_t x, int16_t y   ) { return mpfr_cmp_si(x, y) <= 0; }
bool is_le  ( mpz_t x,  mpz_t y   ) { return mpz_cmp(x, y) <= 0; }
bool is_le  ( mpz_t x,  uint128_t y ) ;
bool is_le  ( mpz_t x,  uint64_t y  ) { return mpz_cmp_ui(x, y) <= 0; }
bool is_le  ( mpz_t x,  uint32_t y  ) { return mpz_cmp_ui(x, y) <= 0; }
bool is_le  ( mpz_t x,  uint16_t y  ) { return mpz_cmp_ui(x, y) <= 0; }
bool is_le  ( mpz_t x,  int128_t y  ) ;
bool is_le  ( mpz_t x,  int64_t y   ) { return mpz_cmp_si(x, y) <= 0; }
bool is_le  ( mpz_t x,  int32_t y   ) { return mpz_cmp_si(x, y) <= 0; }
bool is_le  ( mpz_t x,  int16_t y   ) { return mpz_cmp_si(x, y) <= 0; }

bool is_gt  ( mpfr_t x, mpfr_t y  ) { return mpfr_greater_p(x, y); }
bool is_gt  ( mpfr_t x, float128_t y  ) ;
bool is_gt  ( mpfr_t x, float64_t y   ) ;
bool is_gt  ( mpfr_t x, float32_t y   ) ;
bool is_gt  ( mpfr_t x, float16_t y   ) { return is_gt(x, (float32_t) y); }
bool is_gt  ( mpfr_t x, bfloat16_t y  ) { return is_gt(x, (float32_t) y); }
bool is_gt  ( mpfr_t x, mpz_t y   ) { return mpfr_cmp_z(x, y) > 0;  }
bool is_gt  ( mpfr_t x, uint128_t y ) ;
bool is_gt  ( mpfr_t x, uint64_t y  ) { return mpfr_cmp_ui(x, y) > 0; }
bool is_gt  ( mpfr_t x, uint32_t y  ) { return mpfr_cmp_ui(x, y) > 0; }
bool is_gt  ( mpfr_t x, uint16_t y  ) { return mpfr_cmp_ui(x, y) > 0; }
bool is_gt  ( mpfr_t x, int128_t y  ) ;
bool is_gt  ( mpfr_t x, int64_t y   ) { return mpfr_cmp_si(x, y) > 0; }
bool is_gt  ( mpfr_t x, int32_t y   ) { return mpfr_cmp_si(x, y) > 0; }
bool is_gt  ( mpfr_t x, int16_t y   ) { return mpfr_cmp_si(x, y) > 0; }
bool is_gt  ( mpz_t x,  mpz_t y   ) { return mpz_cmp(x, y) > 0; }
bool is_gt  ( mpz_t x,  uint128_t y ) ;
bool is_gt  ( mpz_t x,  uint64_t y  ) { return mpz_cmp_ui(x, y) > 0; }
bool is_gt  ( mpz_t x,  uint32_t y  ) { return mpz_cmp_ui(x, y) > 0; }
bool is_gt  ( mpz_t x,  uint16_t y  ) { return mpz_cmp_ui(x, y) > 0; }
bool is_gt  ( mpz_t x,  int128_t y  ) ;
bool is_gt  ( mpz_t x,  int64_t y   ) { return mpz_cmp_si(x, y) > 0; }
bool is_gt  ( mpz_t x,  int32_t y   ) { return mpz_cmp_si(x, y) > 0; }
bool is_gt  ( mpz_t x,  int16_t y   ) { return mpz_cmp_si(x, y) > 0; }

bool is_ge  ( mpfr_t x, mpfr_t y  ) { return mpfr_greaterequal_p(x, y); }
bool is_ge  ( mpfr_t x, float128_t y  ) ;
bool is_ge  ( mpfr_t x, float64_t y   ) ;
bool is_ge  ( mpfr_t x, float32_t y   ) ;
bool is_ge  ( mpfr_t x, float16_t y   ) { return is_ge(x, (float32_t) y); }
bool is_ge  ( mpfr_t x, bfloat16_t y  ) { return is_ge(x, (float32_t) y); }
bool is_ge  ( mpfr_t x, mpz_t y   ) { return mpfr_cmp_z(x, y) >= 0;  }
bool is_ge  ( mpfr_t x, uint128_t y ) ;
bool is_ge  ( mpfr_t x, uint64_t y  ) { return mpfr_cmp_ui(x, y) >= 0; }
bool is_ge  ( mpfr_t x, uint32_t y  ) { return mpfr_cmp_ui(x, y) >= 0; }
bool is_ge  ( mpfr_t x, uint16_t y  ) { return mpfr_cmp_ui(x, y) >= 0; }
bool is_ge  ( mpfr_t x, int128_t y  ) ;
bool is_ge  ( mpfr_t x, int64_t y   ) { return mpfr_cmp_si(x, y) >= 0; }
bool is_ge  ( mpfr_t x, int32_t y   ) { return mpfr_cmp_si(x, y) >= 0; }
bool is_ge  ( mpfr_t x, int16_t y   ) { return mpfr_cmp_si(x, y) >= 0; }
bool is_ge  ( mpz_t x,  mpz_t y   ) { return mpz_cmp(x, y) >= 0; }
bool is_ge  ( mpz_t x,  uint128_t y ) ;
bool is_ge  ( mpz_t x,  uint64_t y  ) { return mpz_cmp_ui(x, y) >= 0; }
bool is_ge  ( mpz_t x,  uint32_t y  ) { return mpz_cmp_ui(x, y) >= 0; }
bool is_ge  ( mpz_t x,  uint16_t y  ) { return mpz_cmp_ui(x, y) >= 0; }
bool is_ge  ( mpz_t x,  int128_t y  ) ;
bool is_ge  ( mpz_t x,  int64_t y   ) { return mpz_cmp_si(x, y) >= 0; }
bool is_ge  ( mpz_t x,  int32_t y   ) { return mpz_cmp_si(x, y) >= 0; }
bool is_ge  ( mpz_t x,  int16_t y   ) { return mpz_cmp_si(x, y) >= 0; }

void cpy ( mpfr_t      x,  mpfr_t            y ) { mpfr_set(x, y, R); }
void cpy ( mpfr_t      x,  mpz_t             y ) { mpfr_set_z(x, y, R); }
void cpy ( mpfr_t      x, const float128_t       y ) { mpfr_set_float128(x, y, R); }
void cpy ( mpfr_t      x, const float64_t        y ) { mpfr_set_d(x, y, R); }
void cpy ( mpfr_t      x, const float32_t        y ) { mpfr_set_flt(x, y, R); }
void cpy ( mpfr_t      x, const float16_t        y ) { mpfr_set_flt(x, y, R); }
void cpy ( mpfr_t      x, const bfloat16_t       y ) { mpfr_set_flt(x, y, R); }
void cpy ( mpfr_t      x, const uint128_t      y ) ;
void cpy ( mpfr_t      x, const uint64_t       y ) { mpfr_set_ui(x, y, R); }
void cpy ( mpfr_t      x, const uint32_t       y ) { mpfr_set_ui(x, y, R); }
void cpy ( mpfr_t      x, const uint16_t       y ) { mpfr_set_ui(x, y, R); }
void cpy ( mpfr_t      x, const int128_t       y ) ;
void cpy ( mpfr_t      x, const int64_t        y ) { mpfr_set_si(x, y, R); }
void cpy ( mpfr_t      x, const int32_t        y ) { mpfr_set_si(x, y, R); }
void cpy ( mpfr_t      x, const int16_t        y ) { mpfr_set_si(x, y, R); }
void cpy ( float128_t      &x, mpfr_t            y ) { x = mpfr_get_float128(y, R); }
void cpy ( float64_t       &x, mpfr_t            y ) { x = mpfr_get_d(y, R); }
void cpy ( float32_t       &x, mpfr_t            y ) { x = (float32_t) mpfr_get_flt(y, R); }
void cpy ( float16_t       &x, mpfr_t            y ) { x = (float16_t) mpfr_get_flt(y, R); }
void cpy ( bfloat16_t      &x, mpfr_t            y ) { x = (bfloat16_t) mpfr_get_flt(y, R); }
void cpy ( mpz_t       x, mpz_t              y ) { mpz_set(x, y); }
void cpy ( mpz_t       x, const uint128_t      y ) ;
void cpy ( mpz_t       x, const uint64_t       y ) { mpz_set_ui(x, y); }
void cpy ( mpz_t       x, const uint32_t       y ) { mpz_set_ui(x, y); }
void cpy ( mpz_t       x, const uint16_t       y ) { mpz_set_ui(x, y); }
void cpy ( mpz_t       x, const int128_t       y ) ;
void cpy ( mpz_t       x, const int64_t        y ) { mpz_set_si(x, y); }
void cpy ( mpz_t       x, const int32_t        y ) { mpz_set_si(x, y); }
void cpy ( mpz_t       x, const int16_t        y ) { mpz_set_si(x, y); }

void cpy ( float128_t      &x, mpz_t             y ) ;
void cpy ( float64_t       &x, mpz_t             y ) ;
void cpy ( float32_t       &x, mpz_t             y ) ;
void cpy ( float16_t       &x, mpz_t             y ) ;
void cpy ( bfloat16_t      &x, mpz_t             y ) ;
void cpy ( uint128_t     &x, mpz_t             y ) ;
void cpy ( uint64_t      &x, mpz_t             y ) { x = mpz_get_ui(y); }
void cpy ( uint32_t      &x, mpz_t             y ) { x = mpz_get_ui(y); }
void cpy ( uint16_t      &x, mpz_t             y ) { x = mpz_get_ui(y); }
void cpy ( int128_t      &x, mpz_t             y ) ;
void cpy ( int64_t       &x, mpz_t             y ) { x = mpz_get_si(y); }
void cpy ( int32_t       &x, mpz_t             y ) { x = mpz_get_si(y); }
void cpy ( int16_t       &x, mpz_t             y ) { x = mpz_get_si(y); }
void cpy ( std::string &x, mpfr_t            y ) ;
void cpy ( std::string &x, mpz_t             y ) ;
void cpy ( std::string &x, const float128_t      y ) ;
void cpy ( std::string &x, const float64_t       y ) ;
void cpy ( std::string &x, const float32_t       y ) ;
void cpy ( std::string &x, const float16_t       y ) ;
void cpy ( std::string &x, const bfloat16_t      y ) ;
void cpy ( std::string &x, const uint128_t     y ) ;
void cpy ( std::string &x, const uint64_t      y ) ;
void cpy ( std::string &x, const uint32_t      y ) ;
void cpy ( std::string &x, const uint16_t      y ) ;
void cpy ( std::string &x, const int128_t      y ) ;
void cpy ( std::string &x, const int64_t       y ) ;
void cpy ( std::string &x, const int32_t       y ) ;
void cpy ( std::string &x, const int16_t       y ) ;
void cpy ( mpfr_t       x, const std::string y ) ;
void cpy ( mpz_t        x, const std::string y ) { mpz_set_str(x, y.c_str(), 16); }
void cpy ( float128_t      &x, const std::string y ) ;
void cpy ( float64_t       &x, const std::string y ) ;
void cpy ( float32_t       &x, const std::string y ) ;
void cpy ( float16_t       &x, const std::string y ) ;
void cpy ( bfloat16_t      &x, const std::string y ) ;
void cpy ( uint128_t     &x, const std::string y ) ;
void cpy ( uint64_t      &x, const std::string y ) ;
void cpy ( uint32_t      &x, const std::string y ) ;
void cpy ( uint16_t      &x, const std::string y ) ;
void cpy ( int128_t      &x, const std::string y ) ;
void cpy ( int64_t       &x, const std::string y ) ;
void cpy ( int32_t       &x, const std::string y ) ;
void cpy ( int16_t       &x, const std::string y ) ;

void add ( mpfr_t r, mpfr_t x, mpfr_t        y ) { mpfr_add(r, x, y, R); }
void add ( mpfr_t r, mpfr_t x, mpz_t         y ) { mpfr_add_z(r, x, y, R); }
void add ( mpfr_t r, mpfr_t x, const float128_t  y ) ;
void add ( mpfr_t r, mpfr_t x, const float64_t   y ) { mpfr_add_d(r, x, y, R); }
void add ( mpfr_t r, mpfr_t x, const float32_t   y ) { mpfr_add_d(r, x, y, R); }
void add ( mpfr_t r, mpfr_t x, const float16_t   y ) { mpfr_add_d(r, x, y, R); }
void add ( mpfr_t r, mpfr_t x, const bfloat16_t  y ) { mpfr_add_d(r, x, y, R); }
void add ( mpfr_t r, mpfr_t x, const uint128_t y ) ;
void add ( mpfr_t r, mpfr_t x, const uint64_t  y ) { mpfr_add_ui(r, x, y, R); }
void add ( mpfr_t r, mpfr_t x, const uint32_t  y ) { mpfr_add_ui(r, x, y, R); }
void add ( mpfr_t r, mpfr_t x, const uint16_t  y ) { mpfr_add_ui(r, x, y, R); }
void add ( mpfr_t r, mpfr_t x, const int128_t  y ) ;
void add ( mpfr_t r, mpfr_t x, const int64_t   y ) { mpfr_add_si(r, x, y, R); }
void add ( mpfr_t r, mpfr_t x, const int32_t   y ) { mpfr_add_si(r, x, y, R); }
void add ( mpfr_t r, mpfr_t x, const int16_t   y ) { mpfr_add_si(r, x, y, R); }
void add ( mpz_t  r, mpz_t  x, mpz_t         y ) { mpz_add(r, x, y); }
void add ( mpz_t  r, mpz_t  x, const uint128_t y ) ;
void add ( mpz_t  r, mpz_t  x, const uint64_t  y ) { mpz_add_ui(r, x, y); }
void add ( mpz_t  r, mpz_t  x, const uint32_t  y ) { mpz_add_ui(r, x, y); }
void add ( mpz_t  r, mpz_t  x, const uint16_t  y ) { mpz_add_ui(r, x, y); }
void add ( mpz_t  r, mpz_t  x, const int128_t  y ) ;
void add ( mpz_t  r, mpz_t  x, const int64_t   y ) ;
void add ( mpz_t  r, mpz_t  x, const int32_t   y ) { add(r, x, (int64_t) y); }
void add ( mpz_t  r, mpz_t  x, const int16_t   y ) { add(r, x, (int64_t) y); }

void mul ( mpfr_t r, mpfr_t x, mpfr_t        y ) { mpfr_mul(r, x, y, R); }
void mul ( mpfr_t r, mpfr_t x, mpz_t         y ) { mpfr_mul_z(r, x, y, R); }
void mul ( mpfr_t r, mpfr_t x, const float128_t  y ) ;
void mul ( mpfr_t r, mpfr_t x, const float64_t   y ) { mpfr_mul_d(r, x, y, R); }
void mul ( mpfr_t r, mpfr_t x, const float32_t   y ) { mpfr_mul_d(r, x, y, R); }
void mul ( mpfr_t r, mpfr_t x, const float16_t   y ) { mpfr_mul_d(r, x, y, R); }
void mul ( mpfr_t r, mpfr_t x, const bfloat16_t  y ) { mpfr_mul_d(r, x, y, R); }
void mul ( mpfr_t r, mpfr_t x, const uint128_t y ) ;
void mul ( mpfr_t r, mpfr_t x, const uint64_t  y ) { mpfr_mul_ui(r, x, y, R); }
void mul ( mpfr_t r, mpfr_t x, const uint32_t  y ) { mpfr_mul_ui(r, x, y, R); }
void mul ( mpfr_t r, mpfr_t x, const uint16_t  y ) { mpfr_mul_ui(r, x, y, R); }
void mul ( mpfr_t r, mpfr_t x, const int128_t  y ) ;
void mul ( mpfr_t r, mpfr_t x, const int64_t   y ) { mpfr_mul_si(r, x, y, R); }
void mul ( mpfr_t r, mpfr_t x, const int32_t   y ) { mpfr_mul_si(r, x, y, R); }
void mul ( mpfr_t r, mpfr_t x, const int16_t   y ) { mpfr_mul_si(r, x, y, R); }
void mul ( mpz_t r,  mpz_t  x, mpz_t         y ) { mpz_mul(r, x, y); }
void mul ( mpz_t r,  mpz_t  x, const uint128_t y ) ;
void mul ( mpz_t r,  mpz_t  x, const uint64_t  y ) { mpz_mul_ui(r, x, y); }
void mul ( mpz_t r,  mpz_t  x, const uint32_t  y ) { mpz_mul_ui(r, x, y); }
void mul ( mpz_t r,  mpz_t  x, const uint16_t  y ) { mpz_mul_ui(r, x, y); }
void mul ( mpz_t r,  mpz_t  x, const int128_t  y ) ;
void mul ( mpz_t r,  mpz_t  x, const int64_t   y ) { mpz_mul_si(r, x, y); }
void mul ( mpz_t r,  mpz_t  x, const int32_t   y ) { mpz_mul_si(r, x, y); }
void mul ( mpz_t r,  mpz_t x , const int16_t   y ) { mpz_mul_si(r, x, y); }

void sub ( mpfr_t r, mpfr_t        x, mpfr_t        y ) { mpfr_sub   (r, x, y, R);   }
void sub ( mpfr_t r, mpfr_t        x, mpz_t         y ) { mpfr_sub_z (r, x, y, R );  }
void sub ( mpfr_t r, mpfr_t        x, const float128_t  y ) ;
void sub ( mpfr_t r, mpfr_t        x, const float64_t   y ) { mpfr_sub_d (r, x, y, R );  }
void sub ( mpfr_t r, mpfr_t        x, const float32_t   y ) { mpfr_sub_d (r, x, y, R );  }
void sub ( mpfr_t r, mpfr_t        x, const bfloat16_t  y ) { mpfr_sub_d (r, x, y, R );  }
void sub ( mpfr_t r, mpfr_t        x, const float16_t   y ) { mpfr_sub_d (r, x, y, R );  }
void sub ( mpfr_t r, mpfr_t        x, const uint128_t y ) ;
void sub ( mpfr_t r, mpfr_t        x, const uint64_t  y ) { mpfr_sub_ui( r, x, y, R ); }
void sub ( mpfr_t r, mpfr_t        x, const uint32_t  y ) { mpfr_sub_ui (r, x, y, R ); }
void sub ( mpfr_t r, mpfr_t        x, const uint16_t  y ) { mpfr_sub_ui (r, x, y, R ); }
void sub ( mpfr_t r, mpfr_t        x, const int128_t  y ) ;
void sub ( mpfr_t r, mpfr_t        x, const int64_t   y ) { mpfr_sub_si (r, x, y, R ); }
void sub ( mpfr_t r, mpfr_t        x, const int32_t   y ) { mpfr_sub_si (r, x, y, R ); }
void sub ( mpfr_t r, mpfr_t        x, const int16_t   y ) { mpfr_sub_si (r, x, y, R ); }
void sub ( mpfr_t r, mpz_t         x, mpfr_t        y ) { mpfr_z_sub(r, x, y, R ); }
void sub ( mpfr_t r, const float128_t  x, mpfr_t        y ) ;
void sub ( mpfr_t r, const float64_t   x, mpfr_t        y ) { mpfr_d_sub(r, x, y, R ); }
void sub ( mpfr_t r, const float32_t   x, mpfr_t        y ) { mpfr_d_sub(r, x, y, R ); }
void sub ( mpfr_t r, const bfloat16_t  x, mpfr_t        y ) { mpfr_d_sub(r, x, y, R ); }
void sub ( mpfr_t r, const float16_t   x, mpfr_t        y ) { mpfr_d_sub(r, x, y, R ); }
void sub ( mpfr_t r, const uint128_t x, mpfr_t        y ) ;
void sub ( mpfr_t r, const uint64_t  x, mpfr_t        y ) { mpfr_ui_sub(r, x, y, R ); }
void sub ( mpfr_t r, const uint32_t  x, mpfr_t        y ) { mpfr_ui_sub(r, x, y, R ); }
void sub ( mpfr_t r, const uint16_t  x, mpfr_t        y ) { mpfr_ui_sub(r, x, y, R ); }
void sub ( mpfr_t r, const int128_t  x, mpfr_t        y ) ;
void sub ( mpfr_t r, const int64_t   x, mpfr_t        y ) { mpfr_si_sub(r, x, y, R ); }
void sub ( mpfr_t r, const int32_t   x, mpfr_t        y ) { mpfr_si_sub(r, x, y, R ); }
void sub ( mpfr_t r, const int16_t   x, mpfr_t        y ) { mpfr_si_sub(r, x, y, R ); }
void sub ( mpz_t r, mpz_t          x,       mpz_t   y ) { mpz_sub(r, x, y); }
void sub ( mpz_t r, mpz_t          x, const uint128_t y ) ;
void sub ( mpz_t r, mpz_t          x, const uint64_t  y ) { mpz_sub_ui(r, x, y); }
void sub ( mpz_t r, mpz_t          x, const uint32_t  y ) { mpz_sub_ui(r, x, y); }
void sub ( mpz_t r, mpz_t          x, const uint16_t  y ) { mpz_sub_ui(r, x, y); }
void sub ( mpz_t r, mpz_t          x, const int128_t  y ) ;
void sub ( mpz_t r, mpz_t          x, const int64_t   y ) ;
void sub ( mpz_t r, mpz_t          x, const int32_t   y ) { sub(r, x, (int64_t) y); }
void sub ( mpz_t r, mpz_t          x, const int16_t   y ) { sub(r, x, (int64_t) y); }
void sub ( mpz_t r, const uint128_t  x, mpz_t         y ) { sub(r, y, x); mpz_neg(r, r); }
void sub ( mpz_t r, const uint64_t   x, mpz_t         y ) { mpz_ui_sub(r, x, y); }
void sub ( mpz_t r, const uint32_t   x, mpz_t         y ) { mpz_ui_sub(r, x, y); }
void sub ( mpz_t r, const uint16_t   x, mpz_t         y ) { mpz_ui_sub(r, x, y); }
void sub ( mpz_t r, const int128_t   x, mpz_t         y ) { sub(r, y, x); mpz_neg(r, r); }
void sub ( mpz_t r, const int64_t    x, mpz_t         y ) { sub(r, y, x); mpz_neg(r, r); }
void sub ( mpz_t r, const int32_t    x, mpz_t         y ) { sub(r, y, x); mpz_neg(r, r); }
void sub ( mpz_t r, const int16_t    x, mpz_t         y ) { sub(r, y, x); mpz_neg(r, r); }

void div ( mpfr_t r, mpfr_t        x, mpfr_t         y ) { mpfr_div(r, x, y, R );  }
void div ( mpfr_t r, mpfr_t        x, mpz_t          y ) { mpfr_div_z(r, x, y, R );  }
void div ( mpfr_t r, mpfr_t        x, const float128_t   y ) ;
void div ( mpfr_t r, mpfr_t        x, const float64_t    y ) { mpfr_div_d(r, x, y, R );  }
void div ( mpfr_t r, mpfr_t        x, const float32_t    y ) { mpfr_div_d(r, x, y, R );  }
void div ( mpfr_t r, mpfr_t        x, const float16_t    y ) { mpfr_div_d(r, x, y, R );  }
void div ( mpfr_t r, mpfr_t        x, const bfloat16_t   y ) { mpfr_div_d(r, x, y, R );  }
void div ( mpfr_t r, mpfr_t        x, const uint128_t  y ) ;
void div ( mpfr_t r, mpfr_t        x, const uint64_t   y ) { mpfr_div_ui(r, x, y, R ); }
void div ( mpfr_t r, mpfr_t        x, const uint32_t   y ) { mpfr_div_ui(r, x, y, R ); }
void div ( mpfr_t r, mpfr_t        x, const uint16_t   y ) { mpfr_div_ui(r, x, y, R ); }
void div ( mpfr_t r, mpfr_t        x, const int128_t   y ) ;
void div ( mpfr_t r, mpfr_t        x, const int64_t    y ) { mpfr_div_si(r, x, y, R ); }
void div ( mpfr_t r, mpfr_t        x, const int32_t    y ) { mpfr_div_si(r, x, y, R ); }
void div ( mpfr_t r, mpfr_t        x, const int16_t    y ) { mpfr_div_si(r, x, y, R ); }
void div ( mpfr_t r, mpz_t         x, mpfr_t         y ) ;
void div ( mpfr_t r, const float128_t  x, mpfr_t         y ) ;
void div ( mpfr_t r, const float64_t   x, mpfr_t         y ) { mpfr_d_div(r, x, y, R ); }
void div ( mpfr_t r, const float32_t   x, mpfr_t         y ) { mpfr_d_div(r, x, y, R ); }
void div ( mpfr_t r, const float16_t   x, mpfr_t         y ) { mpfr_d_div(r, x, y, R ); }
void div ( mpfr_t r, const bfloat16_t  x, mpfr_t         y ) { mpfr_d_div(r, x, y, R ); }
void div ( mpfr_t r, const uint128_t x, mpfr_t         y ) ;
void div ( mpfr_t r, const uint64_t  x, mpfr_t         y ) { mpfr_ui_div(r, x, y, R ); }
void div ( mpfr_t r, const uint32_t  x, mpfr_t         y ) { mpfr_ui_div(r, x, y, R ); }
void div ( mpfr_t r, const uint16_t  x, mpfr_t         y ) { mpfr_ui_div(r, x, y, R ); }
void div ( mpfr_t r, const int128_t  x, mpfr_t         y ) ;
void div ( mpfr_t r, const int64_t   x, mpfr_t         y ) { mpfr_si_div(r, x, y, R ); }
void div ( mpfr_t r, const int32_t   x, mpfr_t         y ) { mpfr_si_div(r, x, y, R ); }
void div ( mpfr_t r, const int16_t   x, mpfr_t         y ) { mpfr_si_div(r, x, y, R ); }
void div ( mpz_t r,  mpz_t         x, mpz_t          y ) { mpz_tdiv_q(r, x, y); }
void div ( mpz_t r,  mpz_t          x, const uint128_t y ) { cpy(r, y); mpz_tdiv_q(r, x, r); }
void div ( mpz_t r,  mpz_t          x, const uint64_t  y ) { mpz_tdiv_q_ui(r, x, y); }
void div ( mpz_t r,  mpz_t          x, const uint32_t  y ) { mpz_tdiv_q_ui(r, x, y); }
void div ( mpz_t r,  mpz_t          x, const uint16_t  y ) { mpz_tdiv_q_ui(r, x, y); }
void div ( mpz_t r , mpz_t          x, const int128_t  y ) { cpy(r, y); mpz_tdiv_q(r, x, r); }
void div ( mpz_t r , mpz_t          x, const int64_t   y ) ;
void div ( mpz_t r,  mpz_t          x, const int32_t   y ) { div(r, x, (int64_t) y); }
void div ( mpz_t r,  mpz_t          x, const int16_t   y ) { div(r, x, (int64_t) y); }
void div ( mpz_t r,  const uint128_t  x, mpz_t         y ) { cpy(r, x); mpz_tdiv_q(r, r, y); }
void div ( mpz_t r,  const uint64_t   x, mpz_t         y ) { cpy(r, x); mpz_tdiv_q(r, r, y); }
void div ( mpz_t r,  const uint32_t   x, mpz_t         y ) { cpy(r, x); mpz_tdiv_q(r, r, y); }
void div ( mpz_t r,  const uint16_t   x, mpz_t         y ) { cpy(r, x); mpz_tdiv_q(r, r, y); }
void div ( mpz_t r,  const int128_t   x, mpz_t         y ) { cpy(r, x); mpz_tdiv_q(r, r, y); }
void div ( mpz_t r,  const int64_t    x, mpz_t         y ) { cpy(r, x); mpz_tdiv_q(r, r, y); }
void div ( mpz_t r,  const int32_t    x, mpz_t         y ) { cpy(r, x); mpz_tdiv_q(r, r, y); }
void div ( mpz_t r,  const int16_t    x, mpz_t         y ) { cpy(r, x); mpz_tdiv_q(r, r, y); }

void dve ( mpz_t r, mpz_t x,         mpz_t          y ) { mpz_divexact(r, x, y); }
void dve ( mpz_t r, mpz_t x,         const uint128_t  y ) { cpy(r, y); mpz_divexact(r, x, r); }
void dve ( mpz_t r, mpz_t x,         const uint64_t   y ) { mpz_divexact_ui(r, x, y); }
void dve ( mpz_t r, mpz_t x,         const uint32_t   y ) { mpz_divexact_ui(r, x, y); }
void dve ( mpz_t r, mpz_t x,         const uint16_t   y ) { mpz_divexact_ui(r, x, y); }
void dve ( mpz_t r, mpz_t x,         const int128_t   y ) { cpy(r, y); mpz_divexact(r, x, r); }
void dve ( mpz_t r, mpz_t x,         const int64_t    y ) ;
void dve ( mpz_t r, mpz_t x,         const int32_t    y ) { dve(r, x, (int64_t) y); }
void dve ( mpz_t r, mpz_t x,         const int16_t    y ) { dve(r, x, (int64_t) y); }
void dve ( mpz_t r, const uint128_t x, mpz_t          y ) { cpy(r, x); mpz_divexact(r, r, y); }
void dve ( mpz_t r, const uint64_t  x, mpz_t          y ) { cpy(r, x); mpz_divexact(r, r, y); }
void dve ( mpz_t r, const uint32_t  x, mpz_t          y ) { cpy(r, x); mpz_divexact(r, r, y); }
void dve ( mpz_t r, const uint16_t  x, mpz_t          y ) { cpy(r, x); mpz_divexact(r, r, y); }
void dve ( mpz_t r, const int128_t  x, mpz_t          y ) { cpy(r, x); mpz_divexact(r, r, y); }
void dve ( mpz_t r, const int64_t   x, mpz_t          y ) { cpy(r, x); mpz_divexact(r, r, y); }
void dve ( mpz_t r, const int32_t   x, mpz_t          y ) { cpy(r, x); mpz_divexact(r, r, y); }
void dve ( mpz_t r, const int16_t   x, mpz_t          y ) { cpy(r, x); mpz_divexact(r, r, y); }

void neg  ( mpfr_t x, mpfr_t y ) { mpfr_neg(x, y, R); }
void sqr  ( mpfr_t x, mpfr_t y ) { mpfr_sqr(x, y, R); }
void sqrt ( mpfr_t x, mpfr_t y ) { mpfr_sqrt(x, y, R); }

void ldexp ( mpfr_t r, mpfr_t x, int y ) { mpfr_mul_2si(r, x, y, R); }
void ceil  ( mpfr_t r, mpfr_t x        ) { mpfr_ceil(r, x); }
void floor ( mpfr_t r, mpfr_t x        ) { mpfr_floor(r, x); }
void round ( mpfr_t r, mpfr_t x        ) { mpfr_round(r, x); }
void trunc ( mpfr_t r, mpfr_t x        ) { mpfr_trunc(r, x); }

void powr ( mpfr_t r, mpfr_t x, mpfr_t        y ) { mpfr_powr(r, x, y, R); }
void powr ( mpfr_t r, mpfr_t x, const float128_t  y ) ;
void powr ( mpfr_t r, mpfr_t x, const float64_t   y ) ;
void powr ( mpfr_t r, mpfr_t x, const float32_t   y ) { powr(r, x, (float64_t) y); }
void powr ( mpfr_t r, mpfr_t x, const float16_t   y ) { powr(r, x, (float64_t) y); }
void powr ( mpfr_t r, mpfr_t x, const bfloat16_t  y ) { powr(r, x, (float64_t) y); }
void powr ( mpfr_t r, float128_t x, mpfr_t        y ) ;
void powr ( mpfr_t r, float64_t x,  mpfr_t        y ) ;
void powr ( mpfr_t r, float32_t x,  mpfr_t        y ) { powr(r, (float64_t) x, y); }
void powr ( mpfr_t r, float16_t x,  mpfr_t        y ) { powr(r, (float64_t) x, y); }
void powr ( mpfr_t r, bfloat16_t x, mpfr_t        y ) { powr(r, (float64_t) x, y); }

void pown ( mpfr_t r, mpfr_t x, mpz_t         y ) { mpfr_pow_z(r, x, y, R); }
void pown ( mpfr_t r, mpfr_t x, const uint128_t y ) ;
void pown ( mpfr_t r, mpfr_t x, const uint64_t  y ) { mpfr_pow_ui(r, x, y, R); }
void pown ( mpfr_t r, mpfr_t x, const uint32_t  y ) { mpfr_pow_ui(r, x, y, R); }
void pown ( mpfr_t r, mpfr_t x, const uint16_t  y ) { mpfr_pow_ui(r, x, y, R); }
void pown ( mpfr_t r, mpfr_t x, const int128_t  y ) ;
void pown ( mpfr_t r, mpfr_t x, const int64_t   y ) { mpfr_pow_si(r, x, y, R); }
void pown ( mpfr_t r, mpfr_t x, const int32_t   y ) { mpfr_pow_si(r, x, y, R); }
void pown ( mpfr_t r, mpfr_t x, const int16_t   y ) { mpfr_pow_si(r, x, y, R); }
void pown( mpz_t r,   mpz_t x,  const  uint64_t y ) { mpz_pow_ui(r, x, y); }
void pown( mpz_t r,   mpz_t x,  const  uint32_t y ) { mpz_pow_ui(r, x, y); }
void pown( mpz_t r,   mpz_t x,  const  uint16_t y ) { mpz_pow_ui(r, x, y); }

void fma  ( mpfr_t x,  mpfr_t y, mpfr_t z  ) { mpfr_fma(x, y, z, x, R); }
void fma  ( mpz_t  x,  mpz_t  y, mpz_t  z  ) { mpz_addmul(x, y, z); }
void fma  ( float128_t &x, float128_t y, float128_t z  ) { x = std::fma(y, z, x); }
void fma  ( float64_t  &x, float64_t y, float64_t    z ) { x = std::fma(y, z, x); }
void fma  ( float32_t  &x, float32_t y, float32_t    z ) { x = std::fma(y, z, x); }
void fma  ( float16_t  &x, float16_t y, float16_t    z ) { x = std::fma(y, z, x); }
void fma  ( bfloat16_t &x, bfloat16_t y, bfloat16_t z  ) { x = std::fma(y, z, x); }

void fms  ( mpfr_t x, mpfr_t y, mpfr_t z   ) ;
void fms  ( mpz_t  x, mpz_t  y, mpz_t  z   ) { mpz_submul(x, y, z); }
void fms  ( float128_t &x, float128_t y, float128_t z  ) { x = std::fma(-y, z, x); }
void fms  ( float64_t  &x, float64_t y, float64_t    z ) { x = std::fma(-y, z, x); }
void fms  ( float32_t  &x, float32_t y, float32_t    z ) { x = std::fma(-y, z, x); }
void fms  ( float16_t  &x, float16_t y, float16_t    z ) { x = std::fma(-y, z, x); }
void fms  ( bfloat16_t &x, bfloat16_t y, bfloat16_t z  ) { x = std::fma(-y, z, x); }

void exp   ( mpfr_t &r, mpfr_t x           ) { mpfr_exp(r, x, R); }
void expm1 ( mpfr_t &r, mpfr_t x           ) { mpfr_expm1(r, x, R); }
void exp2  ( mpfr_t &r, mpfr_t x           ) { mpfr_exp2(r, x, R); }
void log   ( mpfr_t &r, mpfr_t x           ) { mpfr_log(r, x, R); }
void log2  ( mpfr_t &r, mpfr_t x           ) { mpfr_log2(r, x, R); }
void log10 ( mpfr_t &r, mpfr_t x           ) { mpfr_log10(r, x, R); }
void log1p ( mpfr_t &r, mpfr_t x           ) { mpfr_log1p(r, x, R); }
void sin   ( mpfr_t &r, mpfr_t x           ) { mpfr_sin(r, x, R); }
void cos   ( mpfr_t &r, mpfr_t x           ) { mpfr_cos(r, x, R); }
void tan   ( mpfr_t &r, mpfr_t x           ) { mpfr_tan(r, x, R); }
void asin  ( mpfr_t &r, mpfr_t x           ) { mpfr_asin(r, x, R); }
void acos  ( mpfr_t &r, mpfr_t x           ) { mpfr_acos(r, x, R); }
void atan  ( mpfr_t &r, mpfr_t x           ) { mpfr_atan(r, x, R); }
void atan2 ( mpfr_t &r, mpfr_t y, mpfr_t x ) { mpfr_atan2(r, y, x, R); }
void sinh  ( mpfr_t &r, mpfr_t x           ) { mpfr_sinh(r, x, R); }
void cosh  ( mpfr_t &r, mpfr_t x           ) { mpfr_cosh(r, x, R); }
void tanh  ( mpfr_t &r, mpfr_t x           ) { mpfr_tanh(r, x, R); }
void asinh ( mpfr_t &r, mpfr_t x           ) { mpfr_asinh(r, x, R); }
void acosh ( mpfr_t &r, mpfr_t x           ) { mpfr_acosh(r, x, R); }
void atanh ( mpfr_t &r, mpfr_t x           ) { mpfr_atanh(r, x, R); }

#undef R

bool is_eq(mpfr_t x, float128_t y) {
  MPFR_DECL_INIT(yy, 113);
  mpfr_set_float128(yy, y, MPFR_RNDN);
  return mpfr_equal_p(x, yy);
}

bool is_eq(mpfr_t x, float64_t y) {
  MPFR_DECL_INIT(yy, 53);
  mpfr_set_d(yy, y, MPFR_RNDN);
  return mpfr_equal_p(x, yy);
}

bool is_eq(mpfr_t x, float32_t y) {
  MPFR_DECL_INIT(yy, 24);
  mpfr_set_flt(yy, y, MPFR_RNDN);
  return mpfr_equal_p(x, yy);
}

bool is_eq(mpfr_t x, uint128_t y) {
  bool r;
  mpz_t yy;
  mpz_init(yy);
  cpy(yy,y);
  r = (mpfr_cmp_z(x, yy) == 0);
  mpz_clear(yy);
  return r;
}

bool is_eq(mpfr_t x, int128_t y) {
  bool r;
  mpz_t yy;
  mpz_init(yy);
  cpy(yy,y);
  r = (mpfr_cmp_z(x, yy) == 0);
  mpz_clear(yy);
  return r;
}

bool is_eq  (mpz_t x, uint128_t y) {
  bool r;
  mpz_t yy; mpz_init(yy);
  cpy(yy,y);
  r = (mpz_cmp(x, yy) == 0);
  mpz_clear(yy);
  return r;
}

bool is_eq  (mpz_t x, int128_t y) {
  bool r;
  mpz_t yy; mpz_init(yy);
  cpy(yy,y);
  r = (mpz_cmp(x, yy) == 0);
  mpz_clear(yy);
  return r;
}

bool is_lt(mpfr_t x, float128_t y) {
  MPFR_DECL_INIT(yy, 113);
  mpfr_set_float128(yy, y, MPFR_RNDN);
  return mpfr_less_p(x, yy);
}

bool is_lt(mpfr_t x, float64_t y) {
  MPFR_DECL_INIT(yy, 53);
  mpfr_set_d(yy, y, MPFR_RNDN);
  return mpfr_less_p(x, yy);
}

bool is_lt(mpfr_t x, float32_t y) {
  MPFR_DECL_INIT(yy, 24);
  mpfr_set_flt(yy, y, MPFR_RNDN);
  return mpfr_less_p(x, yy);
}

bool is_lt(mpfr_t x, uint128_t y) {
  bool r;
  mpz_t yy;
  mpz_init(yy);
  cpy(yy,y);
  r = (mpfr_cmp_z(x, yy) < 0);
  mpz_clear(yy);
  return r;
}

bool is_lt(mpfr_t x, int128_t y) {
  bool r;
  mpz_t yy;
  mpz_init(yy);
  cpy(yy,y);
  r = (mpfr_cmp_z(x, yy) < 0);
  mpz_clear(yy);
  return r;
}

bool is_lt(mpz_t x, uint128_t y) {
  bool r;
  mpz_t yy; mpz_init(yy);
  cpy(yy,y);
  r = (mpz_cmp(x, yy) < 0);
  mpz_clear(yy);
  return r;
}

bool is_lt(mpz_t x, int128_t y) {
  bool r;
  mpz_t yy; mpz_init(yy);
  cpy(yy,y);
  r = (mpz_cmp(x, yy) < 0);
  mpz_clear(yy);
  return r;
}

bool is_le(mpfr_t x, float128_t y) {
  MPFR_DECL_INIT(yy, 113);
  mpfr_set_float128(yy, y, MPFR_RNDN);
  return mpfr_lessequal_p(x, yy);
}

bool is_le(mpfr_t x, float64_t y) {
  MPFR_DECL_INIT(yy, 53);
  mpfr_set_d(yy, y, MPFR_RNDN);
  return mpfr_lessequal_p(x, yy);
}

bool is_le(mpfr_t x, float32_t y) {
  MPFR_DECL_INIT(yy, 24);
  mpfr_set_flt(yy, y, MPFR_RNDN);
  return mpfr_lessequal_p(x, yy);
}

bool is_le(mpfr_t x, uint128_t y) {
  bool r;
  mpz_t yy;
  mpz_init(yy);
  cpy(yy,y);
  r = (mpfr_cmp_z(x, yy) <= 0);
  mpz_clear(yy);
  return r;
}

bool is_le(mpfr_t x, int128_t y) {
  bool r;
  mpz_t yy;
  mpz_init(yy);
  cpy(yy,y);
  r = (mpfr_cmp_z(x, yy) <= 0);
  mpz_clear(yy);
  return r;
}

bool is_le(mpz_t x, uint128_t y) {
  bool r;
  mpz_t yy; mpz_init(yy);
  cpy(yy,y);
  r = (mpz_cmp(x, yy) <= 0);
  mpz_clear(yy);
  return r;
}

bool is_le(mpz_t x, int128_t y) {
  bool r;
  mpz_t yy; mpz_init(yy);
  cpy(yy,y);
  r = (mpz_cmp(x, yy) <= 0);
  mpz_clear(yy);
  return r;
}

bool is_gt(mpfr_t x, float128_t y) {
  MPFR_DECL_INIT(yy, 113);
  mpfr_set_float128(yy, y, MPFR_RNDN);
  return mpfr_greater_p(x, yy);
}

bool is_gt(mpfr_t x, float64_t y) {
  MPFR_DECL_INIT(yy, 53);
  mpfr_set_d(yy, y, MPFR_RNDN);
  return mpfr_greater_p(x, yy);
}

bool is_gt(mpfr_t x, float32_t y) {
  MPFR_DECL_INIT(yy, 24);
  mpfr_set_flt(yy, y, MPFR_RNDN);
  return mpfr_greater_p(x, yy);
}

bool is_gt(mpfr_t x, uint128_t y) {
  bool r;
  mpz_t yy;
  mpz_init(yy);
  cpy(yy,y);
  r = (mpfr_cmp_z(x, yy) > 0);
  mpz_clear(yy);
  return r;
}

bool is_gt(mpfr_t x, int128_t y) {
  bool r;
  mpz_t yy;
  mpz_init(yy);
  cpy(yy,y);
  r = (mpfr_cmp_z(x, yy) > 0);
  mpz_clear(yy);
  return r;
}

bool is_gt(mpz_t x, uint128_t y) {
  bool r;
  mpz_t yy; mpz_init(yy);
  cpy(yy,y);
  r = (mpz_cmp(x, yy) > 0);
  mpz_clear(yy);
  return r;
}

bool is_gt(mpz_t x, int128_t y) {
  bool r;
  mpz_t yy; mpz_init(yy);
  cpy(yy,y);
  r = (mpz_cmp(x, yy) > 0);
  mpz_clear(yy);
  return r;
}

bool is_ge(mpfr_t x, float128_t y) {
  MPFR_DECL_INIT(yy, 113);
  mpfr_set_float128(yy, y, MPFR_RNDN);
  return mpfr_greaterequal_p(x, yy);
}

bool is_ge(mpfr_t x, float64_t y) {
  MPFR_DECL_INIT(yy, 53);
  mpfr_set_d(yy, y, MPFR_RNDN);
  return mpfr_greaterequal_p(x, yy);
}

bool is_ge(mpfr_t x, float32_t y) {
  MPFR_DECL_INIT(yy, 24);
  mpfr_set_flt(yy, y, MPFR_RNDN);
  return mpfr_greaterequal_p(x, yy);
}

bool is_ge(mpfr_t x, uint128_t y) {
  bool r;
  mpz_t yy;
  mpz_init(yy);
  cpy(yy,y);
  r = (mpfr_cmp_z(x, yy) >= 0);
  mpz_clear(yy);
  return r;
}

bool is_ge(mpfr_t x, int128_t y) {
  bool r;
  mpz_t yy;
  mpz_init(yy);
  cpy(yy,y);
  r = (mpfr_cmp_z(x, yy) >= 0);
  mpz_clear(yy);
  return r;
}

bool is_ge(mpz_t x, uint128_t y) {
  bool r;
  mpz_t yy; mpz_init(yy);
  cpy(yy,y);
  r = (mpz_cmp(x, yy) >= 0);
  mpz_clear(yy);
  return r;
}

bool is_ge(mpz_t x, int128_t y) {
  bool r;
  mpz_t yy; mpz_init(yy);
  cpy(yy,y);
  r = (mpz_cmp(x, yy) >= 0);
  mpz_clear(yy);
  return r;
}

void cpy(mpfr_t x, const uint128_t y)
{
  mpfr_set_ui(x, uint64_t(y >> 64), MPFR_RNDN);
  mpfr_mul_2exp(x, x, 64, MPFR_RNDN);
  mpfr_add_ui(x, x, (uint64_t) y, MPFR_RNDN);
}

void cpy(mpfr_t x, const int128_t y)
{
  if (y >= 0) cpy(x, (uint128_t) y);
  else {
    cpy(x, (uint128_t) (-y));
    mpfr_neg(x, x, MPFR_RNDN);
  }
}

void cpy(mpz_t x, const uint128_t y)
{
  mpz_t yh, yl;
  mpz_init(yl); mpz_set_ui(yl, (uint64_t) y);
  mpz_init(yh); mpz_set_ui(yh, (uint64_t) (y >> 64)); mpz_mul_2exp(yh, yh, 64);
  mpz_add(x, yh, yl);
  mpz_clear(yh);
  mpz_clear(yl);
}

void cpy(mpz_t x, const int128_t y)
{ 
  if (y > 0) cpy(x, (uint128_t) y);
  else {
    cpy(x, (uint128_t) -y);
    mpz_neg(x, x);
  }
}

void cpy(float128_t &x, mpz_t y)
{
  MPFR_DECL_INIT(yy, 113);
  mpfr_set_z(yy, y, MPFR_RNDN);
  x = mpfr_get_float128(yy, MPFR_RNDN);
}

void cpy(float64_t &x, mpz_t y)
{
  MPFR_DECL_INIT(yy, 53);
  mpfr_set_z(yy, y, MPFR_RNDN);
  x = mpfr_get_d(yy, MPFR_RNDN);
}

void cpy(float32_t &x, mpz_t y)
{
  MPFR_DECL_INIT(yy, 24);
  mpfr_set_z(yy, y, MPFR_RNDN);
  x = mpfr_get_flt(yy, MPFR_RNDN);
}

void cpy(float16_t &x, mpz_t y)
{
  MPFR_DECL_INIT(yy, 24);
  mpfr_set_z(yy, y, MPFR_RNDN);
  x = (float16_t) mpfr_get_flt(yy, MPFR_RNDN);
}

void cpy(bfloat16_t &x, mpz_t y)
{
  MPFR_DECL_INIT(yy, 24);
  mpfr_set_z(yy, y, MPFR_RNDN);
  x = (bfloat16_t) mpfr_get_flt(yy, MPFR_RNDN);
}

void cpy(uint128_t &x, mpz_t y)
{
  uint64_t xl;
  mpz_t yy; mpz_init(yy);
  xl = mpz_get_ui(y);
  mpz_tdiv_q_2exp(yy, y, 64);
  x = ((uint128_t) mpz_get_ui(yy) << 64) + xl;
  mpz_clear(yy);
}

void cpy(int128_t &x, mpz_t y)
{
  uint64_t xl;
  mpz_t yy; mpz_init(yy);
  if (mpz_sgn(y) >= 0) {
    xl = mpz_get_ui(y);
    mpz_tdiv_q_2exp(yy, y, 64);
    x = ((int128_t) mpz_get_ui(yy) << 64) + xl;
  } else {
    mpz_neg(yy, y);
    xl = mpz_get_ui(yy);
    mpz_tdiv_q_2exp(yy, yy, 64);
    x = -((int128_t) mpz_get_ui(yy) << 64) - xl;
  }
  mpz_clear(yy);
}

void cpy(std::string &x, mpfr_t y)
{
  if      (mpfr_nan_p(y))  x = "nan";
  else if (mpfr_zero_p(y)) x = mpfr_signbit(y) ? "-0" : "0";
  else if (mpfr_inf_p(y))  x = mpfr_signbit(y) ? "-inf" : "inf";
  else    {
    mpfr_exp_t e;
    char *s = mpfr_get_str(0, &e, 16, 0, y, MPFR_RNDN);
    char *pc = s; while (*pc) { *pc = toupper(*(pc)); pc++; }
    x = s;
    mpfr_free_str(s);
    x.erase(x.find_last_not_of('0')+1, std::string::npos);
    if (mpfr_sgn(y) == -1) x.insert(1, 1, '.'); else x.insert(0, 1, '.');
    if (e >= 0) x += 'P'  + std::to_string( 4*e);
    if (e < 0) x += "P-" + std::to_string(-4*e);
  }
}

void cpy(std::string &x, mpz_t y) {
  char s[mpz_sizeinbase(y, 16) + 2];
  char *pc = s;
  mpz_get_str(s, 16, y);
  while (*pc) { *pc = toupper(*(pc)); pc++; }
  x = s;
}

void cpy(std::string &x, const float128_t y)
{
  MPFR_DECL_INIT(yy, 113);
  mpfr_set_float128(yy, y, MPFR_RNDN);
  cpy(x, yy);
}

void cpy(std::string &x, const float64_t y)
{
  MPFR_DECL_INIT(yy, 53);
  mpfr_set_d(yy, y, MPFR_RNDN);
  cpy(x, yy);
}

void cpy(std::string &x, const float32_t y)
{
  MPFR_DECL_INIT(yy, 24);
  mpfr_set_flt(yy, y, MPFR_RNDN);
  cpy(x, yy);
}

void cpy(std::string &x, const float16_t y)
{
  MPFR_DECL_INIT(yy, 24);
  mpfr_set_flt(yy, y, MPFR_RNDN);
  cpy(x, yy);
}

void cpy(std::string &x, const bfloat16_t y)
{
  MPFR_DECL_INIT(yy, 24);
  mpfr_set_flt(yy, y, MPFR_RNDN);
  cpy(x, yy);
}

void cpy(std::string &x, const uint128_t y)
{
  mpz_t yh, yl;
  mpz_init_set_ui(yl, (uint64_t) y);
  mpz_init_set_ui(yh, (uint64_t) (y >> 64));
  mpz_mul_2exp(yh, yh, 64);
  mpz_add(yh, yh, yl);
  cpy(x, yh);
  mpz_clear(yh);
  mpz_clear(yl);
}

void cpy(std::string &x, const uint64_t y)
{
  char s[17]{0};
  std::to_chars(s, s + 16, y, 16);
  char *pc = s; while (*pc) { *pc = toupper(*(pc)); pc++; }
  x = s;
}

void cpy(std::string &x, const uint32_t y)
{
  char s[9]{0};
  std::to_chars(s, s + 8, y, 16);
  char *pc = s; while (*pc) { *pc = toupper(*(pc)); pc++; }
  x = s;
}

void cpy(std::string &x, const uint16_t y)
{
  char s[5]{0};
  std::to_chars(s, s + 4, y, 16);
  char *pc = s; while (*pc) { *pc = toupper(*(pc)); pc++; }
  x = s;
}

void cpy(std::string &x, const int128_t y)
{ 
  if (y >= 0) cpy(x, (uint128_t) y);
  else {
    cpy(x, (uint128_t) (-y));
    x = '-' + x; 
  }
}

void cpy(std::string &x, const int64_t y) 
{
  char s[18]{0};
  std::to_chars(s, s + 17, y, 16);
  char *pc = s; while (*pc) { *pc = toupper(*(pc)); pc++; }
  x = s;
}

void cpy(std::string &x, const int32_t y) 
{
  char s[10]{0};
  std::to_chars(s, s + 9, y, 16);
  char *pc = s; while (*pc) { *pc = toupper(*(pc)); pc++; }
  x = s;
}

void cpy(std::string &x, const int16_t y) 
{
  char s[6]{0};
  std::to_chars(s, s + 5, y, 16);
  char *pc = s; while (*pc) { *pc = toupper(*(pc)); pc++; }
  x = s;
}

void cpy(mpfr_t x, const std::string y) {
  char **ep = 0;
  if      ( y == "nan"  ) mpfr_set_nan(x)    ;
  else if ( y == "inf"  ) mpfr_set_inf(x, 1) ;
  else if ( y == "-inf" ) mpfr_set_inf(x, -1);
  else {
    mpfr_strtofr (x, y.c_str(), ep, 16, MPFR_RNDN);
    if (mpfr_zero_p(x) && y[0] == '-') mpfr_setsign(x, x, 1, MPFR_RNDN);
  }
}

void cpy(float128_t &x, const std::string y)
{
  MPFR_DECL_INIT(xx, 113);
  cpy(xx, y);
  x = mpfr_get_float128(xx, MPFR_RNDN);
}

void cpy(float64_t &x, const std::string y)
{
  MPFR_DECL_INIT(xx, 53);
  cpy(xx, y);
  x = mpfr_get_d(xx, MPFR_RNDN);
}

void cpy(float32_t &x, const std::string y)
{ 
  MPFR_DECL_INIT(xx, 24);
  cpy(xx, y);
  x = (float32_t) mpfr_get_flt(xx, MPFR_RNDN); 
}

void cpy(float16_t &x, const std::string y)
{
  MPFR_DECL_INIT(xx, 24);
  cpy(xx, y);
  x = (float16_t) mpfr_get_flt(xx, MPFR_RNDN); 
}

void cpy(bfloat16_t &x, const std::string y)
{
  MPFR_DECL_INIT(xx, 24);
  cpy(xx, y);
  x = (bfloat16_t) mpfr_get_flt(xx, MPFR_RNDN); 
}

void cpy(uint128_t &x, const std::string y)
{
  mpz_t yy; mpz_init(yy);
  mpz_set_str(yy, y.c_str(), 16);
  cpy(x, yy);
  mpz_clear(yy);
}

void cpy(uint64_t &x, const std::string y)
{
 mpz_t yy; mpz_init(yy); 
 mpz_set_str(yy, y.c_str(), 16);
 x = (uint64_t) mpz_get_ui(yy); 
 mpz_clear(yy);
}

void cpy(uint32_t &x, const std::string y)
{
 mpz_t yy; mpz_init(yy); 
 mpz_set_str(yy, y.c_str(), 16);
 x = (uint32_t) mpz_get_ui(yy); 
 mpz_clear(yy);
}

void cpy(uint16_t &x, const std::string y)
{
 mpz_t yy; mpz_init(yy); 
 mpz_set_str(yy, y.c_str(), 16);
 x = (uint16_t) mpz_get_ui(yy); 
 mpz_clear(yy);
}

void cpy(int128_t &x, const std::string y)
{
  mpz_t yy; mpz_init(yy);
  cpy(yy, y);
  cpy(x, yy);
  mpz_clear(yy);
}

void cpy(int64_t &x, const std::string y)
{
  mpz_t yy; mpz_init(yy);
  mpz_set_str(yy, y.c_str(), 16);
  x = (int64_t) mpz_get_si(yy);
  mpz_clear(yy);
}

void cpy(int32_t &x, const std::string y)
{
  mpz_t yy; mpz_init(yy);
  mpz_set_str(yy, y.c_str(), 16);
  x = (int32_t) mpz_get_si(yy);
  mpz_clear(yy);
}

void cpy(int16_t &x, const std::string y)
{
  mpz_t yy; mpz_init(yy);
  mpz_set_str(yy, y.c_str(), 16);
  x = (int16_t) mpz_get_si(yy);
  mpz_clear(yy);
}

void add(mpfr_t r, mpfr_t x, float128_t y)
{
  MPFR_DECL_INIT(yy, 113);
  mpfr_set_float128(yy, y, MPFR_RNDN);
  mpfr_add(r, x, yy, MPFR_RNDN); 
}

void add(mpfr_t r, mpfr_t x, const uint128_t y)
{
  mpz_t yy;
  mpz_init(yy);
  cpy(yy, y);
  mpfr_add_z(r, x, yy, MPFR_RNDN);
  mpz_clear(yy); 
}

void add(mpfr_t r, mpfr_t x, const int128_t y)
{
  mpz_t yy; mpz_init(yy);
  cpy(yy, y);
  mpfr_add_z(r, x, yy, MPFR_RNDN);
  mpz_clear(yy);
}

void add(mpz_t r, mpz_t x, const uint128_t y)
{
  mpz_t yy; mpz_init(yy);
  cpy(yy, y);
  mpz_add(r, x, yy);
  mpz_clear(yy);
 }

void add(mpz_t r, mpz_t x, const int128_t y)
{
  mpz_t yy; mpz_init(yy);
  cpy(yy, y);
  mpz_add(r, x, yy);
  mpz_clear(yy);
}

void add(mpz_t r, mpz_t x, const int64_t y)
{
  if (y >= 0) mpz_add_ui(r, x, (uint64_t) y);
  else mpz_sub_ui(r, x, (uint64_t) -y);
}

void mul(mpfr_t r, mpfr_t x, float128_t y)
{
  MPFR_DECL_INIT(yy, 113);
  mpfr_set_float128(yy, y, MPFR_RNDN);
  mpfr_mul(r, x, yy, MPFR_RNDN);
}

void mul(mpfr_t r, mpfr_t x, const uint128_t y)
{
  mpz_t yy; mpz_init(yy);
  cpy(yy, y); 
  mpfr_mul_z(r, x, yy, MPFR_RNDN);
  mpz_clear(yy);
}

void mul(mpfr_t r, mpfr_t x, const int128_t y)
{
  mpz_t yy; mpz_init(yy);
  cpy(yy, y);
  mpfr_mul_z(r, x, yy, MPFR_RNDN);
  mpz_clear(yy); }

void mul(mpz_t r, mpz_t x, const uint128_t y)
{
  mpz_t yy; mpz_init(yy);
  cpy(yy, y); 
  mpz_mul(r, x, yy);
  mpz_clear(yy);
}

void mul(mpz_t r, mpz_t x, const int128_t y)
{
  mpz_t yy; mpz_init(yy);
  cpy(yy, y);
  mpz_mul(r, x, yy);
  mpz_clear(yy);
}

void sub(mpfr_t r, mpfr_t x, const float128_t y)
{
  MPFR_DECL_INIT(yy, 113);
  mpfr_set_float128(yy, y, MPFR_RNDN);
  mpfr_sub(r, x, yy, MPFR_RNDN);
}

void sub(mpfr_t r, mpfr_t x, const uint128_t y)
{
  mpz_t yy; mpz_init(yy);
  cpy(yy, y);
  mpfr_sub_z(r, x, yy, MPFR_RNDN);
  mpz_clear(yy);
}

void sub(mpfr_t r, mpfr_t x, const int128_t y)
{
  mpz_t yy; mpz_init(yy);
  cpy(yy, y);
  mpfr_sub_z(r, x, yy, MPFR_RNDN);
  mpz_clear(yy);
}

void sub(mpfr_t r, float128_t x, mpfr_t y) {
  MPFR_DECL_INIT(xx, 113);
  mpfr_set_float128(xx, x, MPFR_RNDN);
  mpfr_sub(r, xx, y, MPFR_RNDN);
}

void sub(mpfr_t r, uint128_t x, mpfr_t y)
{
  mpz_t xx; mpz_init(xx);
  cpy(xx, x);
  mpfr_z_sub(r, xx, y, MPFR_RNDN);
  mpz_clear(xx);
}

void sub(mpfr_t r, int128_t x, mpfr_t y)
{
  mpz_t xx; mpz_init(xx);
  cpy(xx, x);
  mpfr_z_sub(r, xx, y, MPFR_RNDN);
  mpz_clear(xx);
}

void sub(mpz_t r, mpz_t x, const uint128_t y)
{
  mpz_t yy; 
  cpy(yy, y); 
  mpz_sub(r, x, yy);
  mpz_clear(yy);
}

void sub(mpz_t r, mpz_t x, const int128_t y )
{
  mpz_t yy; mpz_init(yy);
  cpy(yy, y);
  if (y >= 0) mpz_sub(r, x, yy);
  else {
    mpz_neg(yy, yy);
    mpz_add(r, x, yy);
  }
  mpz_clear(yy);
}

void sub (mpz_t r, mpz_t x, const int64_t y)
{ 
  if (y >= 0) mpz_sub_ui(r, x, y);
  else mpz_add_ui(r, x, -y);
}

void div(mpfr_t r, mpfr_t x, const float128_t y)
{
  MPFR_DECL_INIT(yy, 113);
  mpfr_set_float128(yy, y, MPFR_RNDN);
  mpfr_div(r, x, yy, MPFR_RNDN); 
}

void div(mpfr_t r, mpfr_t x, const uint128_t y)
{
  mpz_t yy; mpz_init(yy);
  cpy(yy, y);
  mpfr_div_z(r, x, yy, MPFR_RNDN);
  mpz_clear(yy);
}

void div(mpfr_t r, mpfr_t x, const int128_t y)
{
  mpz_t yy; mpz_init(yy);
  cpy(yy, y);
  mpfr_div_z(r, x, yy, MPFR_RNDN);
  mpz_clear(yy);
}

void div(mpfr_t r, mpz_t x, mpfr_t y)
{
  mpfr_prec_t rp = mpfr_get_prec(r), yp = mpfr_get_prec(y);
  if (rp >= yp) {
    mpfr_set_z(r, x, MPFR_RNDN);
    mpfr_div(r, r, y, MPFR_RNDN);
  } else {
    MPFR_DECL_INIT(t, yp);
    mpfr_set_z(t, x, MPFR_RNDN);
    mpfr_div(r, t, y, MPFR_RNDN);
  }
}

void div(mpfr_t r, const float128_t x, mpfr_t y)
{
  MPFR_DECL_INIT(xx, 113);
  mpfr_set_float128(xx, x, MPFR_RNDN);
  mpfr_div(r, xx, y, MPFR_RNDN);
}

void div(mpfr_t r, const uint128_t x, mpfr_t y)
{
  mpz_t xx; mpz_init(xx);
  cpy(xx, x);
  div(r, xx, y);
  mpz_clear(xx);
}

void div(mpfr_t r, const int128_t x, mpfr_t y)
{
  mpz_t xx; mpz_init(xx);
  cpy(xx, x);
  div(r, xx, y);
  mpz_clear(xx);
}

void div(mpz_t r, mpz_t x, int64_t y)
{
  if (y >= 0) mpz_tdiv_q_ui(r, x, y);
  else        mpz_tdiv_q_ui(r, x, -y);
}

void dve(mpz_t r, mpz_t x, const int64_t y)
{
  if (y >= 0) mpz_divexact_ui(r, x, y);
  else {
    mpz_divexact_ui(r, x, -y);
    mpz_neg(r,r);
  }
}

void powr(mpfr_t r, mpfr_t x, const float128_t y)
{
  MPFR_DECL_INIT(yy, 113);
  mpfr_set_float128(yy, y, MPFR_RNDN);
  mpfr_pow(r, x, yy, MPFR_RNDN);
}

void powr(mpfr_t r, mpfr_t x, const float64_t y)
{
  MPFR_DECL_INIT(yy,  53);
  mpfr_set_d(yy, y, MPFR_RNDN);
  mpfr_pow(r, x, yy, MPFR_RNDN);
}

void powr(mpfr_t r, float128_t x, mpfr_t y)
{
  MPFR_DECL_INIT(xx, 113);
  mpfr_set_float128(xx, x, MPFR_RNDN);
  mpfr_pow(r, xx, y, MPFR_RNDN);
}

void powr(mpfr_t r, float64_t x,  mpfr_t y)
{
  MPFR_DECL_INIT(xx, 53);
  mpfr_set_d(xx, x, MPFR_RNDN);
  mpfr_pow(r, xx, y, MPFR_RNDN);
}

void pown(mpfr_t r, mpfr_t x, const uint128_t y)
{
  mpz_t yy; mpz_init(yy);
  cpy(yy, y);
  mpfr_pow_z(r, x, yy, MPFR_RNDN);
  mpz_clear(yy);
}

void pown(mpfr_t r, mpfr_t x, const int128_t y)
{
  mpz_t yy; mpz_init(yy);
  cpy(yy, y);
  mpfr_pow_z(r, x, yy, MPFR_RNDN);
  mpz_clear(yy);
}

void fms(mpfr_t x, mpfr_t y, mpfr_t z)
{
  neg(x, x);
  mpfr_fma(x, y, z, x, MPFR_RNDN);
  neg(x, x);
}

} // namespace gmp_adaptor
