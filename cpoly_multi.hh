// Multiprecision iteration of void cpoly(T** A, int n) from cpoly_single.hh. For inclusion in
// cpoly.hh.

// SPDX-License-Identifier: MIT
// Copyright (c) [2024] [George William Patrick]

// 2024-14-10 (GWP)

#include<limits>

#include <gmp_adaptor.hh>

namespace cpolycc {

template<typename T, typename U> 
int cpoly(T** A, int n, int prec_step, int dbl_depth, int max_depth,
	  U *q, int &m, int &depth, int &prec) {

  using namespace gmp_adaptor;

  { // sparsity

    int i, ii, j, jj, ij;

    for (ij = n-1; ij >= 0; ij--) {
      for (i = 0; i < n && (A[i][ij] == 0); i++);
      for (j = 0; j < n && (A[ij][j] == 0); j++);
      if (i == n || j == n) {
	for (jj = ij + 1; jj < n; jj++)  // delete column ij
	  for (ii = 0; ii < n; ii++) 
	    { A[ii][jj-1] = A[ii][jj]; }
	for (ii = ij + 1; ii < n; ii++) A[ii-1] = A[ii];  // delete row ij
	n--;
      }
    }
  }

  depth = 0;
  if (n == 0) { m = 0; return 0; }
  if (n == 1) { m = 1; q[0] = -U(A[0][0]); return 0; }

  { // Balance.

    int i, j;
    bool b;
    T c2, r2, c, s, t;

    do {
      for (i = 0, b = false; i < n; i++) {
	for (j = 0, r2 = 0; j < n; j++) r2 += A[i][j] * A[i][j];
	for (j = 0, c2 = 0; j < n; j++) c2 += A[j][i] * A[j][i];
	if (std::isinf(s = c2 + r2)) { b = false; break; }
	c = 1;
	if (c2 == 0) continue;
	while ((t = 4 * c2) < r2) { c2 = t; r2 /= 4; c *= 2; }
	if (r2 == 0 ) continue;
	while ((t = 4 * r2) <= c2) { r2 = t; c2 /= 4; c /= 2; }
	if (c2 + r2 < .95 * s) {
	  for (j = 0; j < n; j++) A[i][j] /= c;
	  for (j = 0; j < n; j++) A[j][i] *= c; 
	  b = true;
	}
      }
    } while (b);
  }

  {
    int i, j;

    float64_t *AA_64,  **A_64  = 0;
    float128_t *AA_128, **A_128 = 0;
    mpfr_t *AA_mpfr1 = 0, **A_mpfr1 = 0;
    mpfr_t *AA_mpfr2 = 0, **A_mpfr2 = 0;

    mpfr_t ***p1 = &A_mpfr1, ***p2  = &A_mpfr2;


    mpfr_t Thgh; mpfr_init2(Thgh, 113); cpy(Thgh, (float128_t) std::numeric_limits<U>::max());
    mpfr_t Tlow; mpfr_init2(Tlow, 113); cpy(Tlow, (float128_t) std::numeric_limits<U>::lowest());
    int err = 0;

    auto equal = []<typename F, typename FF, typename FFF>(F &v, FF &x, FFF &y) {
      F vx;      cpy(vx,x);
      F &vy = v; cpy(vy,y);	      
      if (std::fpclassify(vx) != FP_SUBNORMAL && std::fpclassify(vy) != FP_SUBNORMAL)
	return std::nextafter(vx, vy) == vy;
      if (std::fpclassify(vx) == FP_SUBNORMAL && std::fpclassify(vy) == FP_SUBNORMAL) {
	if (std::abs(vx - vy) <= std::numeric_limits<F>::min()) { v = 0; return true; }
	return false;
      }
      else return false;
    };

   if constexpr (      std::is_same_v<U, float16_t>	
                    || std::is_same_v<U, bfloat16_t>
                    || std::is_same_v<U, float32_t>
		 )
    {
      if (depth == max_depth) { err = ECPOLYCC_LIMIT; goto done; }
      prec = 53;
      AA_64 = new float64_t[n * n];
      A_64  = new float64_t*[n];
      for (i = 1, A_64[0] = AA_64; i < n; i++) A_64[i] = A_64[i-1] + n;
      for (i = 0; i < n; i++) for (j = 0; j < n; j++) cpy(A_64[i][j], A[i][j]);
      cpoly(A_64, n); depth++;
    }

    if constexpr (     std::is_same_v<U, float16_t>	
                    || std::is_same_v<U, bfloat16_t>
                    || std::is_same_v<U, float32_t>
                    || std::is_same_v<U, float64_t>
		 )
    {
      if (depth == max_depth) { err = ECPOLYCC_LIMIT; goto done; }
      prec = 113;
      AA_128 = new float128_t[n * n];
      A_128  = new float128_t*[n];
      for (i = 1, A_128[0] = AA_128; i < n; i++) A_128[i] = A_128[i-1] + n;
      for (i = 0; i < n; i++) for (j = 0; j < n; j++) cpy(A_128[i][j], A[i][j]);
      cpoly(A_128, n); depth++;
      if (A_64) {
	for (i = 0; i < n; i++) if (!equal(q[i], A_64[n-1][i], A_128[n-1][i])) break;
	delete[] A_64; delete[] AA_64;
	if (i == n) {
	  for (i = 0; i < n; i++) {
	    if (is_gt(A_128[n-1][i], Thgh)) { err = ECPOLYCC_OVERFLOW; break; }
	    if (is_lt(A_128[n-1][i], Tlow)) { err = ECPOLYCC_OVERFLOW; break; }
	  }
	  if (i == n) goto done;
	}
      }
    }

    prec = 120;

    {
      if (depth == max_depth) { err = ECPOLYCC_LIMIT; goto done; }
      AA_mpfr1 = new mpfr_t[n * n];
      for (i = 0; i < n * n; i++) mpfr_init2(AA_mpfr1[i], prec);
      A_mpfr1  = new mpfr_t*[n]; 
      for (i = 1, A_mpfr1[0] = AA_mpfr1; i < n; i++) A_mpfr1[i] = A_mpfr1[i-1] + n;
      for (i = 0; i < n; i++) for (j = 0; j < n; j++) cpy(A_mpfr1[i][j], A[i][j]);
      cpoly(A_mpfr1, n); depth++;
      if (A_128) {
	for (i = 0; i < n; i++) if (!equal(q[i], A_128[n-1][i], A_mpfr1[n-1][i])) break;
	delete[] A_128; delete[] AA_128;
	if (i == n) {
	  for (i = 0; i < n; i++) {
	    if (is_gt(A_mpfr1[n-1][i], Thgh)) { err = ECPOLYCC_OVERFLOW; break; }
	    if (is_lt(A_mpfr1[n-1][i], Tlow)) { err = ECPOLYCC_OVERFLOW; break; }
	  }
	  if (i == n) goto done;
	}
      }
    }

    prec += prec_step;
    AA_mpfr2 = new mpfr_t[n * n];
    for (i = 0; i < n * n; i++) mpfr_init2(AA_mpfr2[i], prec);
    A_mpfr2  = new mpfr_t*[n];
    for (i = 1, A_mpfr2[0] = AA_mpfr2; i < n; i++) A_mpfr2[i] = A_mpfr2[i-1] + n;

    for(;;) {
      if (depth == max_depth) { err = ECPOLYCC_LIMIT; goto done; }
      for (i = 0; i < n; i++) for (j = 0; j < n; j++) cpy((*p2)[i][j], A[i][j]);
      cpoly(*p2, n); depth++;

      for (i = 0; i < n; i++) if (!equal(q[i], (*p1)[n-1][i], (*p2)[n-1][i])) break;
      if (i == n) break;
      std::swap(p1, p2);
      if (depth <  dbl_depth) prec += prec_step; else prec *= 2;
      for (i = 0; i < n; i++) for (j = 0; j < n; j++) mpfr_set_prec((*p2)[i][j], prec);
      for (i = 0; i < n; i++) {
	if (is_gt(A_mpfr2[n-1][i], Thgh)) { err = ECPOLYCC_OVERFLOW; break; }
	if (is_lt(A_mpfr2[n-1][i], Tlow)) { err = ECPOLYCC_OVERFLOW; break; }
      }
    }

  done:

    if (AA_mpfr2) for (i = 0; i < n * n; i++) mpfr_clear(AA_mpfr2[i]);
    if (AA_mpfr1) for (i = 0; i < n * n; i++) mpfr_clear(AA_mpfr1[i]);
    mpfr_clear(Thgh);
    mpfr_clear(Tlow);

    delete[] AA_mpfr2;
    delete[] A_mpfr2;
    delete[] AA_mpfr1;
    delete[] A_mpfr1;
    for (i = 0; i < n; i++) if (q[i] !=0) break;
    for (j = i; j < n; j++) q[j-i] = q[j];
    m = n - i;
    return err;
  }

}

template<typename T, typename U> 
int cpoly(T** A, int n, U *q, int &m, int &depth, int &prec) {
  return cpoly(A, n, 8, 4, std::numeric_limits<int>::max(), q, m, depth, prec);
}

} // namespace
