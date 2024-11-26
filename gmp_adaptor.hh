// Simple function adaptor to gmp.

//  SPDX-License-Identifier: MIT
//  Copyright (c) [2024] [George William Patrick]

// 2024-10-08 GWP

#pragma once

#include <iostream>

#include <charconv>              
#include <climits>
#include <cmath>
#include <cstdint>
#include <stdfloat>
#include <string>
#include <iomanip>

#define  MPFR_WANT_FLOAT128
#include <gmp.h>
#include <mpfr.h>
#undef   MPFR_WANT_FLOAT128

static_assert( std::numeric_limits<std::float16_t>  :: is_iec559  );
static_assert( std::numeric_limits<std::bfloat16_t> :: is_iec559  );
static_assert( std::numeric_limits<std::float32_t>  :: is_iec559  );
static_assert( std::numeric_limits<std::float64_t>  :: is_iec559  );
static_assert( std::numeric_limits<std::float128_t> :: is_iec559  );

// For binding to mpfr functions, which only use the usual c++ float, double, quad.

static_assert( std::numeric_limits<float>         :: digits == 24 );
static_assert( std::numeric_limits<double>        :: digits == 53 );
static_assert( std::numeric_limits<long double>   :: digits == 64 );
static_assert( std::numeric_limits<unsigned>      :: digits == 32 );
static_assert( std::numeric_limits<unsigned long> :: digits == 64 );
static_assert( std::numeric_limits<int>           :: digits == 31 );
static_assert( std::numeric_limits<long int>      :: digits == 63 );

namespace gmp_adaptor {

using std::int16_t;
using std::int32_t;
using std::int64_t;
using std::uint16_t;
using std::uint32_t;
using std::uint64_t;

typedef __int128_t int128_t;
typedef __uint128_t uint128_t;

using std::float16_t;
using std::bfloat16_t;
using std::float32_t;
using std::float64_t;
using std::float128_t;

bool is_inf(mpfr_t x);
bool is_nan(mpfr_t x);
bool is_neg(mpfr_t x);
bool is_neg(mpz_t x);
bool is_nneg(mpfr_t x);
bool is_nneg(mpz_t x);
bool is_npos(mpfr_t x);
bool is_npos(mpz_t x);
bool is_nzero(mpfr_t x);
bool is_nzero(mpz_t x);
bool is_pos(mpfr_t x);
bool is_pos(mpz_t x);
bool is_zero(mpfr_t x);
bool is_zero(mpz_t x);

bool is_eq(mpfr_t x, float128_t y);
bool is_eq(mpfr_t x, float16_t y);
bool is_eq(mpfr_t x, float32_t y);
bool is_eq(mpfr_t x, float64_t y);
bool is_eq(mpfr_t x, bfloat16_t y);
bool is_eq(mpfr_t x, int128_t y);
bool is_eq(mpfr_t x, int16_t y);
bool is_eq(mpfr_t x, int32_t y);
bool is_eq(mpfr_t x, int64_t y);
bool is_eq(mpfr_t x, mpfr_t y);
bool is_eq(mpfr_t x, mpz_t y);
bool is_eq(mpfr_t x, uint128_t y);
bool is_eq(mpfr_t x, uint16_t y);
bool is_eq(mpfr_t x, uint32_t y);
bool is_eq(mpfr_t x, uint64_t y);
bool is_eq(mpz_t x, int128_t y);
bool is_eq(mpz_t x, int16_t y);
bool is_eq(mpz_t x, int32_t y);
bool is_eq(mpz_t x, int64_t y);
bool is_eq(mpz_t x, mpz_t y);
bool is_eq(mpz_t x, uint128_t y);
bool is_eq(mpz_t x, uint16_t y);
bool is_eq(mpz_t x, uint32_t y);
bool is_eq(mpz_t x, uint64_t y);

bool is_lt(mpfr_t x, float128_t y);
bool is_lt(mpfr_t x, float16_t y);
bool is_lt(mpfr_t x, float32_t y);
bool is_lt(mpfr_t x, float64_t y);
bool is_lt(mpfr_t x, bfloat16_t y);
bool is_lt(mpfr_t x, int128_t y);
bool is_lt(mpfr_t x, int16_t y);
bool is_lt(mpfr_t x, int32_t y);
bool is_lt(mpfr_t x, int64_t y);
bool is_lt(mpfr_t x, mpfr_t y);
bool is_lt(mpfr_t x, mpz_t y);
bool is_lt(mpfr_t x, uint128_t y);
bool is_lt(mpfr_t x, uint16_t y);
bool is_lt(mpfr_t x, uint32_t y);
bool is_lt(mpfr_t x, uint64_t y);
bool is_lt(mpz_t x, int128_t y);
bool is_lt(mpz_t x, int16_t y);
bool is_lt(mpz_t x, int32_t y);
bool is_lt(mpz_t x, int64_t y);
bool is_lt(mpz_t x, mpz_t y);
bool is_lt(mpz_t x, uint128_t y);
bool is_lt(mpz_t x, uint16_t y);
bool is_lt(mpz_t x, uint32_t y);
bool is_lt(mpz_t x, uint64_t y);

bool is_le(mpfr_t x, float128_t y);
bool is_le(mpfr_t x, float16_t y);
bool is_le(mpfr_t x, float32_t y);
bool is_le(mpfr_t x, float64_t y);
bool is_le(mpfr_t x, bfloat16_t y);
bool is_le(mpfr_t x, int128_t y);
bool is_le(mpfr_t x, int16_t y);
bool is_le(mpfr_t x, int32_t y);
bool is_le(mpfr_t x, int64_t y);
bool is_le(mpfr_t x, mpfr_t y);
bool is_le(mpfr_t x, mpz_t y);
bool is_le(mpfr_t x, uint128_t y);
bool is_le(mpfr_t x, uint16_t y);
bool is_le(mpfr_t x, uint32_t y);
bool is_le(mpfr_t x, uint64_t y);
bool is_le(mpz_t x, int128_t y);
bool is_le(mpz_t x, int16_t y);
bool is_le(mpz_t x, int32_t y);
bool is_le(mpz_t x, int64_t y);
bool is_le(mpz_t x, mpz_t y);
bool is_le(mpz_t x, uint128_t y);
bool is_le(mpz_t x, uint16_t y);
bool is_le(mpz_t x, uint32_t y);
bool is_le(mpz_t x, uint64_t y);

bool is_gt(mpfr_t x, float128_t y);
bool is_gt(mpfr_t x, float16_t y);
bool is_gt(mpfr_t x, float32_t y);
bool is_gt(mpfr_t x, float64_t y);
bool is_gt(mpfr_t x, bfloat16_t y);
bool is_gt(mpfr_t x, int128_t y);
bool is_gt(mpfr_t x, int16_t y);
bool is_gt(mpfr_t x, int32_t y);
bool is_gt(mpfr_t x, int64_t y);
bool is_gt(mpfr_t x, mpfr_t y);
bool is_gt(mpfr_t x, mpz_t y);
bool is_gt(mpfr_t x, uint128_t y);
bool is_gt(mpfr_t x, uint16_t y);
bool is_gt(mpfr_t x, uint32_t y);
bool is_gt(mpfr_t x, uint64_t y);
bool is_gt(mpz_t x, int128_t y);
bool is_gt(mpz_t x, int16_t y);
bool is_gt(mpz_t x, int32_t y);
bool is_gt(mpz_t x, int64_t y);
bool is_gt(mpz_t x, mpz_t y);
bool is_gt(mpz_t x, uint128_t y);
bool is_gt(mpz_t x, uint16_t y);
bool is_gt(mpz_t x, uint32_t y);
bool is_gt(mpz_t x, uint64_t y);

bool is_ge(mpfr_t x, float128_t y);
bool is_ge(mpfr_t x, float16_t y);
bool is_ge(mpfr_t x, float32_t y);
bool is_ge(mpfr_t x, float64_t y);
bool is_ge(mpfr_t x, bfloat16_t y);
bool is_ge(mpfr_t x, int128_t y);
bool is_ge(mpfr_t x, int16_t y);
bool is_ge(mpfr_t x, int32_t y);
bool is_ge(mpfr_t x, int64_t y);
bool is_ge(mpfr_t x, mpfr_t y);
bool is_ge(mpfr_t x, mpz_t y);
bool is_ge(mpfr_t x, uint128_t y);
bool is_ge(mpfr_t x, uint16_t y);
bool is_ge(mpfr_t x, uint32_t y);
bool is_ge(mpfr_t x, uint64_t y);
bool is_ge(mpz_t x, int128_t y);
bool is_ge(mpz_t x, int16_t y);
bool is_ge(mpz_t x, int32_t y);
bool is_ge(mpz_t x, int64_t y);
bool is_ge(mpz_t x, mpz_t y);
bool is_ge(mpz_t x, uint128_t y);
bool is_ge(mpz_t x, uint16_t y);
bool is_ge(mpz_t x, uint32_t y);
bool is_ge(mpz_t x, uint64_t y);

void acos(mpfr_t &r, mpfr_t x);
void acosh(mpfr_t &r, mpfr_t x);
void add(mpfr_t r, mpfr_t x, const float128_t y);
void add(mpfr_t r, mpfr_t x, const float16_t y);
void add(mpfr_t r, mpfr_t x, const float32_t y);
void add(mpfr_t r, mpfr_t x, const float64_t y);
void add(mpfr_t r, mpfr_t x, const bfloat16_t y);
void add(mpfr_t r, mpfr_t x, const int128_t y);
void add(mpfr_t r, mpfr_t x, const int16_t y);
void add(mpfr_t r, mpfr_t x, const int32_t y);
void add(mpfr_t r, mpfr_t x, const int64_t y);
void add(mpfr_t r, mpfr_t x, const uint128_t y);
void add(mpfr_t r, mpfr_t x, const uint16_t y);
void add(mpfr_t r, mpfr_t x, const uint32_t y);
void add(mpfr_t r, mpfr_t x, const uint64_t y);
void add(mpfr_t r, mpfr_t x, mpfr_t y);
void add(mpfr_t r, mpfr_t x, mpz_t y);
void add(mpz_t r, mpz_t x, const int128_t y);
void add(mpz_t r, mpz_t x, const int16_t y);
void add(mpz_t r, mpz_t x, const int32_t y);
void add(mpz_t r, mpz_t x, const int64_t y);
void add(mpz_t r, mpz_t x, const uint128_t y);
void add(mpz_t r, mpz_t x, const uint16_t y);
void add(mpz_t r, mpz_t x, const uint32_t y);
void add(mpz_t r, mpz_t x, const uint64_t y);
void add(mpz_t r, mpz_t x, mpz_t y);
void asin(mpfr_t &r, mpfr_t x);
void asinh(mpfr_t &r, mpfr_t x);
void atan(mpfr_t &r, mpfr_t x);
void atan2(mpfr_t &r, mpfr_t y, mpfr_t x);
void atanh(mpfr_t &r, mpfr_t x);
void ceil(mpfr_t r, mpfr_t x);
void cos(mpfr_t &r, mpfr_t x);
void cosh(mpfr_t &r, mpfr_t x);

void cpy(float128_t &x, const std::string y);
void cpy(float128_t &x, mpfr_t y);
void cpy(float128_t &x, mpz_t y);
void cpy(float16_t &x, const std::string y);
void cpy(float16_t &x, mpfr_t y);
void cpy(float16_t &x, mpz_t y);
void cpy(float32_t &x, const std::string y);
void cpy(float32_t &x, mpfr_t y);
void cpy(float32_t &x, mpz_t y);
void cpy(float64_t &x, const std::string y);
void cpy(float64_t &x, mpfr_t y);
void cpy(float64_t &x, mpz_t y);
void cpy(bfloat16_t &x, const std::string y);
void cpy(bfloat16_t &x, mpfr_t y);
void cpy(bfloat16_t &x, mpz_t y);
void cpy(int128_t &x, const std::string y);
void cpy(int128_t &x, mpz_t y);
void cpy(int16_t &x, const std::string y);
void cpy(int16_t &x, mpz_t y);
void cpy(int32_t &x, const std::string y);
void cpy(int32_t &x, mpz_t y);
void cpy(int64_t &x, const std::string y);
void cpy(int64_t &x, mpz_t y);
void cpy(mpfr_t x, const std::string y);
void cpy(mpfr_t x, mpfr_t y);
void cpy(mpfr_t x, mpz_t y);
void cpy(mpfr_t x, const float128_t y);
void cpy(mpfr_t x, const float16_t y);
void cpy(mpfr_t x, const float32_t y);
void cpy(mpfr_t x, const float64_t y);
void cpy(mpfr_t x, const bfloat16_t y);
void cpy(mpfr_t x, const int128_t y);
void cpy(mpfr_t x, const int16_t y);
void cpy(mpfr_t x, const int32_t y);
void cpy(mpfr_t x, const int64_t y);
void cpy(mpfr_t x, const uint128_t y);
void cpy(mpfr_t x, const uint16_t y);
void cpy(mpfr_t x, const uint32_t y);
void cpy(mpfr_t x, const uint64_t y);
void cpy(mpz_t x, const std::string y);
void cpy(mpz_t x, const int128_t y);
void cpy(mpz_t x, const int16_t y);
void cpy(mpz_t x, const int32_t y);
void cpy(mpz_t x, const int64_t y);
void cpy(mpz_t x, const uint128_t y);
void cpy(mpz_t x, const uint16_t y);
void cpy(mpz_t x, const uint32_t y);
void cpy(mpz_t x, const uint64_t y);
void cpy(mpz_t x, mpz_t y);
void cpy(std::string &x, const float128_t y);
void cpy(std::string &x, const float16_t y);
void cpy(std::string &x, const float32_t y);
void cpy(std::string &x, const float64_t y);
void cpy(std::string &x, const bfloat16_t y);
void cpy(std::string &x, const int128_t y);
void cpy(std::string &x, const int16_t y);
void cpy(std::string &x, const int32_t y);
void cpy(std::string &x, const int64_t y);
void cpy(std::string &x, const uint128_t y);
void cpy(std::string &x, const uint16_t y);
void cpy(std::string &x, const uint32_t y);
void cpy(std::string &x, const uint64_t y);
void cpy(std::string &x, mpfr_t y);
void cpy(std::string &x, mpz_t y);
void cpy(uint128_t &x, const std::string y);
void cpy(uint128_t &x, mpz_t y);
void cpy(uint16_t &x, const std::string y);
void cpy(uint16_t &x, mpz_t y);
void cpy(uint32_t &x, const std::string y);
void cpy(uint32_t &x, mpz_t y);
void cpy(uint64_t &x, const std::string y);
void cpy(uint64_t &x, mpz_t y);

void div(mpfr_t r, const float128_t x, mpfr_t y);
void div(mpfr_t r, const float16_t x, mpfr_t y);
void div(mpfr_t r, const float32_t x, mpfr_t y);
void div(mpfr_t r, const float64_t x, mpfr_t y);
void div(mpfr_t r, const bfloat16_t x, mpfr_t y);
void div(mpfr_t r, const int128_t x, mpfr_t y);
void div(mpfr_t r, const int16_t x, mpfr_t y);
void div(mpfr_t r, const int32_t x, mpfr_t y);
void div(mpfr_t r, const int64_t x, mpfr_t y);
void div(mpfr_t r, const uint128_t x, mpfr_t y);
void div(mpfr_t r, const uint16_t x, mpfr_t y);
void div(mpfr_t r, const uint32_t x, mpfr_t y);
void div(mpfr_t r, const uint64_t x, mpfr_t y);
void div(mpfr_t r, mpfr_t x, const float128_t y);
void div(mpfr_t r, mpfr_t x, const float16_t y);
void div(mpfr_t r, mpfr_t x, const float32_t y);
void div(mpfr_t r, mpfr_t x, const float64_t y);
void div(mpfr_t r, mpfr_t x, const bfloat16_t y);
void div(mpfr_t r, mpfr_t x, const int128_t y);
void div(mpfr_t r, mpfr_t x, const int16_t y);
void div(mpfr_t r, mpfr_t x, const int32_t y);
void div(mpfr_t r, mpfr_t x, const int64_t y);
void div(mpfr_t r, mpfr_t x, const uint128_t y);
void div(mpfr_t r, mpfr_t x, const uint16_t y);
void div(mpfr_t r, mpfr_t x, const uint32_t y);
void div(mpfr_t r, mpfr_t x, const uint64_t y);
void div(mpfr_t r, mpfr_t x, mpfr_t y);
void div(mpfr_t r, mpfr_t x, mpz_t y);
void div(mpfr_t r, mpz_t x, mpfr_t y);
void div(mpz_t r , mpz_t x, const int128_t y);
void div(mpz_t r , mpz_t x, const int64_t y);
void div(mpz_t r, const int128_t x, mpz_t y);
void div(mpz_t r, const int16_t x, mpz_t y);
void div(mpz_t r, const int32_t x, mpz_t y);
void div(mpz_t r, const int64_t x, mpz_t y);
void div(mpz_t r, const uint128_t x, mpz_t y);
void div(mpz_t r, const uint16_t x, mpz_t y);
void div(mpz_t r, const uint32_t x, mpz_t y);
void div(mpz_t r, const uint64_t x, mpz_t y);
void div(mpz_t r, mpz_t x, const int16_t y);
void div(mpz_t r, mpz_t x, const int32_t y);
void div(mpz_t r, mpz_t x, const uint128_t y);
void div(mpz_t r, mpz_t x, const uint16_t y);
void div(mpz_t r, mpz_t x, const uint32_t y);
void div(mpz_t r, mpz_t x, const uint64_t y);
void div(mpz_t r, mpz_t x, mpz_t y);
void dve(mpz_t r, const int128_t x, mpz_t y);
void dve(mpz_t r, const int16_t x, mpz_t y);
void dve(mpz_t r, const int32_t x, mpz_t y);
void dve(mpz_t r, const int64_t x, mpz_t y);
void dve(mpz_t r, const uint128_t x, mpz_t y);
void dve(mpz_t r, const uint16_t x, mpz_t y);
void dve(mpz_t r, const uint32_t x, mpz_t y);
void dve(mpz_t r, const uint64_t x, mpz_t y);
void dve(mpz_t r, mpz_t x, const int128_t y);
void dve(mpz_t r, mpz_t x, const int16_t y);
void dve(mpz_t r, mpz_t x, const int32_t y);
void dve(mpz_t r, mpz_t x, const int64_t y);
void dve(mpz_t r, mpz_t x, const uint128_t y);
void dve(mpz_t r, mpz_t x, const uint16_t y);
void dve(mpz_t r, mpz_t x, const uint32_t y);
void dve(mpz_t r, mpz_t x, const uint64_t y);
void dve(mpz_t r, mpz_t x, mpz_t y);
void exp(mpfr_t &r, mpfr_t x);
void exp2(mpfr_t &r, mpfr_t x);
void expm1(mpfr_t &r, mpfr_t x);
void floor(mpfr_t r, mpfr_t x);
void fma(float128_t &x, float128_t y, float128_t z );
void fma(float16_t &x, float16_t y, float16_t z );
void fma(float32_t &x, float32_t y, float32_t z );
void fma(float64_t &x, float64_t y, float64_t z );
void fma(bfloat16_t &x, bfloat16_t y, bfloat16_t z );
void fma(mpfr_t x, mpfr_t y, mpfr_t z );
void fma(mpz_t x, mpz_t y, mpz_t z );
void fms(float128_t &x, float128_t y, float128_t z );
void fms(float16_t &x, float16_t y, float16_t z );
void fms(float32_t &x, float32_t y, float32_t z );
void fms(float64_t &x, float64_t y, float64_t z );
void fms(bfloat16_t &x, bfloat16_t y, bfloat16_t z );
void fms(mpfr_t x, mpfr_t y, mpfr_t z );
void fms(mpz_t x, mpz_t y, mpz_t z );

void ldexp(mpfr_t r, mpfr_t x, int y);
void log(mpfr_t &r, mpfr_t x);
void log10(mpfr_t &r, mpfr_t x);
void log1p(mpfr_t &r, mpfr_t x);
void log2(mpfr_t &r, mpfr_t x);
void mul(mpfr_t r, mpfr_t x, const float128_t y);
void mul(mpfr_t r, mpfr_t x, const float16_t y);
void mul(mpfr_t r, mpfr_t x, const float32_t y);
void mul(mpfr_t r, mpfr_t x, const float64_t y);
void mul(mpfr_t r, mpfr_t x, const bfloat16_t y);
void mul(mpfr_t r, mpfr_t x, const int128_t y);
void mul(mpfr_t r, mpfr_t x, const int16_t y);
void mul(mpfr_t r, mpfr_t x, const int32_t y);
void mul(mpfr_t r, mpfr_t x, const int64_t y);
void mul(mpfr_t r, mpfr_t x, const uint128_t y);
void mul(mpfr_t r, mpfr_t x, const uint16_t y);
void mul(mpfr_t r, mpfr_t x, const uint32_t y);
void mul(mpfr_t r, mpfr_t x, const uint64_t y);
void mul(mpfr_t r, mpfr_t x, mpfr_t y);
void mul(mpfr_t r, mpfr_t x, mpz_t y);
void mul(mpz_t r, mpz_t x , const int16_t y);
void mul(mpz_t r, mpz_t x, const int128_t y);
void mul(mpz_t r, mpz_t x, const int32_t y);
void mul(mpz_t r, mpz_t x, const int64_t y);
void mul(mpz_t r, mpz_t x, const uint128_t y);
void mul(mpz_t r, mpz_t x, const uint16_t y);
void mul(mpz_t r, mpz_t x, const uint32_t y);
void mul(mpz_t r, mpz_t x, const uint64_t y);
void mul(mpz_t r, mpz_t x, mpz_t y);
void neg(mpfr_t x, mpfr_t y);

void pown(mpfr_t r, mpfr_t x, const int128_t y);
void pown(mpfr_t r, mpfr_t x, const int16_t y);
void pown(mpfr_t r, mpfr_t x, const int32_t y);
void pown(mpfr_t r, mpfr_t x, const int64_t y);
void pown(mpfr_t r, mpfr_t x, const uint128_t y);
void pown(mpfr_t r, mpfr_t x, const uint16_t y);
void pown(mpfr_t r, mpfr_t x, const uint32_t y);
void pown(mpfr_t r, mpfr_t x, const uint64_t y);
void pown(mpfr_t r, mpfr_t x, mpz_t y);
void pown(mpz_t r, mpz_t x, const uint16_t y);
void pown(mpz_t r, mpz_t x, const uint32_t y);
void pown(mpz_t r, mpz_t x, const uint64_t y);

void powr(mpfr_t r, float128_t x, mpfr_t y);
void powr(mpfr_t r, float16_t x, mpfr_t y);
void powr(mpfr_t r, float32_t x, mpfr_t y);
void powr(mpfr_t r, float64_t x, mpfr_t y);
void powr(mpfr_t r, bfloat16_t x, mpfr_t y);
void powr(mpfr_t r, mpfr_t x, const float128_t y);
void powr(mpfr_t r, mpfr_t x, const float16_t y);
void powr(mpfr_t r, mpfr_t x, const float32_t y);
void powr(mpfr_t r, mpfr_t x, const float64_t y);
void powr(mpfr_t r, mpfr_t x, const bfloat16_t y);
void powr(mpfr_t r, mpfr_t x, mpfr_t y);
void round(mpfr_t r, mpfr_t x);
void sin(mpfr_t &r, mpfr_t x);
void sinh(mpfr_t &r, mpfr_t x);
void sqr(mpfr_t x, mpfr_t y);
void sqrt(mpfr_t x, mpfr_t y);
void sub(mpfr_t r, const float128_t x, mpfr_t y);
void sub(mpfr_t r, const float16_t x, mpfr_t y);
void sub(mpfr_t r, const float32_t x, mpfr_t y);
void sub(mpfr_t r, const float64_t x, mpfr_t y);
void sub(mpfr_t r, const bfloat16_t x, mpfr_t y);
void sub(mpfr_t r, const int128_t x, mpfr_t y);
void sub(mpfr_t r, const int16_t x, mpfr_t y);
void sub(mpfr_t r, const int32_t x, mpfr_t y);
void sub(mpfr_t r, const int64_t x, mpfr_t y);
void sub(mpfr_t r, const uint128_t x, mpfr_t y);
void sub(mpfr_t r, const uint16_t x, mpfr_t y);
void sub(mpfr_t r, const uint32_t x, mpfr_t y);
void sub(mpfr_t r, const uint64_t x, mpfr_t y);
void sub(mpfr_t r, mpfr_t x, const float128_t y);
void sub(mpfr_t r, mpfr_t x, const float16_t y);
void sub(mpfr_t r, mpfr_t x, const float32_t y);
void sub(mpfr_t r, mpfr_t x, const float64_t y);
void sub(mpfr_t r, mpfr_t x, const bfloat16_t y);
void sub(mpfr_t r, mpfr_t x, const int128_t y);
void sub(mpfr_t r, mpfr_t x, const int16_t y);
void sub(mpfr_t r, mpfr_t x, const int32_t y);
void sub(mpfr_t r, mpfr_t x, const int64_t y);
void sub(mpfr_t r, mpfr_t x, const uint128_t y);
void sub(mpfr_t r, mpfr_t x, const uint16_t y);
void sub(mpfr_t r, mpfr_t x, const uint32_t y);
void sub(mpfr_t r, mpfr_t x, const uint64_t y);
void sub(mpfr_t r, mpfr_t x, mpfr_t y);
void sub(mpfr_t r, mpfr_t x, mpz_t y);
void sub(mpfr_t r, mpz_t x, mpfr_t y);
void sub(mpz_t r, const int128_t x, mpz_t y);
void sub(mpz_t r, const int16_t x, mpz_t y);
void sub(mpz_t r, const int32_t x, mpz_t y);
void sub(mpz_t r, const int64_t x, mpz_t y);
void sub(mpz_t r, const uint128_t x, mpz_t y);
void sub(mpz_t r, const uint16_t x, mpz_t y);
void sub(mpz_t r, const uint32_t x, mpz_t y);
void sub(mpz_t r, const uint64_t x, mpz_t y);
void sub(mpz_t r, mpz_t x, const int128_t y);
void sub(mpz_t r, mpz_t x, const int16_t y);
void sub(mpz_t r, mpz_t x, const int32_t y);
void sub(mpz_t r, mpz_t x, const int64_t y);
void sub(mpz_t r, mpz_t x, const uint128_t y);
void sub(mpz_t r, mpz_t x, const uint16_t y);
void sub(mpz_t r, mpz_t x, const uint32_t y);
void sub(mpz_t r, mpz_t x, const uint64_t y);
void sub(mpz_t r, mpz_t x, mpz_t y);
void tan(mpfr_t &r, mpfr_t x);
void tanh(mpfr_t &r, mpfr_t x);
void trunc(mpfr_t r, mpfr_t x);

#define def1 template< typename T1 > \
requires std::is_arithmetic_v<T1>

#define def2 template< typename T1, typename T2 > \
requires std::is_arithmetic_v<T1> && std::is_arithmetic_v<T2>

#define def3 template< typename T1, typename T2, typename T3 > \
requires std::is_arithmetic_v<T1> && std::is_arithmetic_v<T2> && std::is_arithmetic_v<T3>

def1 bool is_nan   (T1 x             ) { return std::isnan(x); }
def1 bool is_inf   (T1 x             ) { return std::isinf(x); }
def1 bool is_zero  (T1 x             ) { return x == 0; }
def1 bool is_nzero (T1 x             ) { return x != 0; }
def1 bool is_neg   (T1 x             ) { return x < 0;  }
def1 bool is_nneg  (T1 x             ) { return x >= 0; }
def1 bool is_pos   (T1 x             ) { return x < 0;  }
def1 bool is_npos  (T1 x             ) { return x < 0;  }
def2 bool is_eq    (T1 x, T2 y       ) { return x = y;  }
def2 bool is_ne    (T1 x, T2 y       ) { return x != y; }
def2 bool is_lt    (T1 x, T2 y       ) { return x < y;  }
def2 bool is_le    (T1 x, T2 y       ) { return x <= y; }
def2 bool is_gt    (T1 x, T2 y       ) { return x > y;  }
def2 bool is_ge    (T1 x, T2 y       ) { return x >= y; }

def2 void cpy   ( T1 &x, T2 y        ) { x = T1(y); }
def3 void add   ( T1 &r, T2 x, T3 y  ) { r = x + y; }
def3 void mul   ( T1 &r, T2 x, T3 y  ) { r = x * y; }
def3 void sub   ( T1 &r, T2 x, T3 y  ) { r = x - y; }
def3 void div   ( T1 &r, T2 x, T3 y  ) { r = x / y; }
def3 void dve   ( T1 &r, T2 x, T3 y  ) { r = x / y; }
def1 void neg   ( T1 &x, T1 y        ) { x = -y; }
def1 void sqr   ( T1 &x, T1 y        ) { x = y * y; }
def1 void sqrt  ( T1 &x, T1 y        ) { x = std::sqrt(y); }
def1 void ldexp ( T1 &r, T1 x, int y ) { r = std::ldexp(x, y); }
def1 void ceil  ( T1 &r, T1 x        ) { r = std::ceil(x); }
def1 void floor ( T1 &r, T1 x        ) { r = std::floor(x); }
def1 void round ( T1 &r, T1 x        ) { r = std::round(x); }
def1 void trunc ( T1 &r, T1 x        ) { r = std::trunc(x); }
def2 void powr  ( T1 &r, T1 x, T2 y  ) { r = std::pow(x, y); }
def2 void pown  ( T1 &r, T1 x, T2 y  ) { r = std::pow(x, y); }
def1 void fma   ( T1 &x, T1 y, T1 z  ) { x += y * z; }
def1 void fms   ( T1 &x, T1 y, T1 z  ) { x -= y * z; }

def1 void exp   ( T1 &r, T1 x        ) { r = std::exp(x); }
def1 void expm1 ( T1 &r, T1 x        ) { r = std::expm1(x); }
def1 void exp2  ( T1 &r, T1 x        ) { r = std::exp2(x); }
def1 void log   ( T1 &r, T1 x        ) { r = std::log(x); }
def1 void log2  ( T1 &r, T1 x        ) { r = std::log2(x); }
def1 void log10 ( T1 &r, T1 x        ) { r = std::log10(x); }
def1 void log1p ( T1 &r, T1 x        ) { r = std::log1p(x); }
def1 void sin   ( T1 &r, T1 x        ) { r = std::sin(x); }
def1 void cos   ( T1 &r, T1 x        ) { r = std::cos(x); }
def1 void tan   ( T1 &r, T1 x        ) { r = std::tan(x); }
def1 void asin  ( T1 &r, T1 x        ) { r = std::asin(x); }
def1 void acos  ( T1 &r, T1 x        ) { r = std::acos(x); }
def1 void atan  ( T1 &r, T1 x        ) { r = std::atan(x); }
def1 void atan2 ( T1 &r, T1 x, T1 y  ) { r = std::atan2(x, y); }
def1 void sinh  ( T1 &r, T1 x        ) { r = std::sinh(x); }
def1 void cosh  ( T1 &r, T1 x        ) { r = std::cosh(x); }
def1 void tanh  ( T1 &r, T1 x        ) { r = std::tanh(x); }
def1 void asinh ( T1 &r, T1 x        ) { r = std::asinh(x); }
def1 void acosh ( T1 &r, T1 x        ) { r = std::acosh(x); }
def1 void atanh ( T1 &r, T1 x        ) { r = std::atanh(x); }

#undef def3
#undef def2
#undef def1

template<typename T1, typename T2> bool is_ne(T1 x, T2 y) { return !is_eq(x,y); }

template<typename T> bool is_eq(T x, mpfr_t y) { return is_eq(y,x); }
template<typename T> bool is_lt(T x, mpfr_t y) { return is_ge(y,x); }
template<typename T> bool is_le(T x, mpfr_t y) { return is_gt(y,x); }
template<typename T> bool is_gt(T x, mpfr_t y) { return is_le(y,x); }
template<typename T> bool is_ge(T x, mpfr_t y) { return is_lt(y,x); }
template<typename T> void add(mpfr_t r, T x, mpfr_t y) { add(r, y, x); }
template<typename T> void mul(mpfr_t r, T x, mpfr_t y) { mul(r, y, x); }

template<typename T> bool is_eq(T x, mpz_t y) { return is_eq(y,x); }
template<typename T> bool is_lt(T x, mpz_t y) { return is_ge(y,x); }
template<typename T> bool is_le(T x, mpz_t y) { return is_gt(y,x); }
template<typename T> bool is_gt(T x, mpz_t y) { return is_le(y,x); }
template<typename T> bool is_ge(T x, mpz_t y) { return is_lt(y,x); }
template<typename T> void add(mpz_t r, T x, mpz_t y) { add(r, y, x); }
template<typename T> void mul(mpz_t r, T x, mpz_t y) { mul(r, y, x); }

}
