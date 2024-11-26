// La Budde's method with gmp_adaptor coding. For inclusion in cpoly.hh.

// La Budde's method is first reduction of Hessenberg form (MAPLE):
//
//  x = [ 0, 0, ... , 0, A[j+1,j], ... , A[n,j]]^T
//  x[j+1] = x[j+1] + sign(x[j+1]) * |x|
//  P = I - 2/|x|^2 x x^T
//  A = P A P^T 
//  j = 1 ... n-2
//
// and then the recursion
//
//  p[0] = 1
//  p[1] = x - A[1,1]
//  p[i] = (x - A[i,i]) p[i-1]
//         - A[i,i-1] A[i-1,i-2] ... A[2,1]  A[1,i] p[0]
//         - A[i,i-1] A[i-1,i-2] ... A[3,2]  A[2,i] p[1]
//         ...
//         - A[i,i-1]  A[i-1,i] p[i-2]  
//  i = 2 .. n 

// SPDX-License-Identifier: MIT
// Copyright (c) [2024] [George William Patrick]

// 10-12-2024 (GWP)

#include <gmp_adaptor.hh>

#include <iostream>
#include <limits>

namespace cpolycc {

template<typename T> void cpoly(T** A, int n) {

  using namespace gmp_adaptor;

  T t1, t2, nx;
  int i, ii, j,jj;

  if constexpr(std::is_same_v<T,mpfr_t>) {
    mpfr_init2(t1, mpfr_get_prec(A[0][0]));
    mpfr_init2(t2, mpfr_get_prec(A[0][0]));
    mpfr_init2(nx, mpfr_get_prec(A[0][0]));
  }

  // Hessenberg reduction. x = A[j+1::n,j] and v=x except v[j+1,j] = sign(A[j+1,j])
  // |x|+A[j+1,j]), and one calculates that A[j+1,j] becomes -sign(A[j+1,j])|x| at the end of
  // processing column j, and also that |v|^2=2 sign(A[j+1,j])|x|v[j+1,j]. So A[j+1::n,j]
  // becomes v and A[j+1,j] is restored before moving on to the next column. v does not need to
  // be normalized if the matrix -2vv^T in P is divided by |v|^2, and the factors of 2
  // cancel. Note: nx below is actually sign(A[j+1,j]) |x| (not |x|) so v[j+1,j] = nx+A[j+1,j])
  // and |v|^2 = 2 nx v[j+1,j].

  for (j = 0; j < n - 2; j++) {

   for (i = j+1, cpy(nx, 0); i < n ; i++) { sqr(t2, A[i][j]); add(nx, nx, t2); }
    if (is_zero(nx)) continue;
    sqrt(nx, nx);
    if (is_neg(A[j+1][j])) neg(nx,nx);
    add(A[j+1][j], A[j+1][j], nx);

    for (jj = j+1; jj < n; jj++) { // premultiply by P
      for (ii = j+1, cpy(t1, 0); ii < n; ii++) fma(t1, A[ii][j], A[ii][jj]);
      mul(t2, nx, A[j+1][j]);
      div(t1, t1, t2);


      for (ii = j+1; ii < n; ii++) fms(A[ii][jj], t1, A[ii][j]);
    }

    for (ii = 0; ii < n; ii++) { // postmultiply by P^T
      for (jj = j + 1, cpy(t1, 0); jj < n; jj++) fma(t1, A[jj][j], A[ii][jj]);
      mul(t2, nx, A[j+1][j]);
      div(t1, t1, t2);
      for (jj = j + 1; jj < n; jj++) fms(A[ii][jj], t1, A[jj][j]);
    }

    cpy(A[j+1][j], nx); neg(A[j+1][j], A[j+1][j]); // restore A[j+1][j]

  }

// Characteristic polynomial. The recursion is re-organized to 
//
//  p[0] = 1
//  p[1] = x - A[1,1]
//  p[i] = - A[i,i-1]  A[i-1,i] p[i-2]
//         ...
//         - A[i,i-1] A[i-1,i-2] ... A[3,2]  A[2,i] p[1]
//         - A[i,i-1] A[i-1,i-2] ... A[2,1]  A[1,i] p[0]
//         + (x - A[i,i]) p[i-1]
//  i = 2 .. n
//
// p[0]=1 is substituted, and the p[i] can be stored with i values since thay are monic
// degree i, so they fit into the first i values of row i+1 without destroying the
// subdiagonal. There is one too few such rows and the subdiagonal is used throughout the
// recursion, so it is saved into the last row of A and p[n] (which ends up in that row) is
// processed in place.

  for (j = 0; j < n-2; j++) cpy(A[n-1][j], A[j+1][j]); // put subdiagonal in the last row.

  neg(A[0][0], A[0][0]);
  for (i = 1; i < n-1; i++) { // p[1] ... p[n-1]
    cpy(A[i][0], A[0][i]);
    for (j = 1; j < i; j++) {
      for (jj = 0; jj < j; jj++) mul(A[i][jj], A[i][jj], A[n-1][j-1]);
      for (jj = 0; jj < j; jj++) fma(A[i][jj], A[j][i], A[j-1][jj]);
      cpy(A[i][j], A[j][i]); // monic
    }
    for (jj = 0; jj < i; jj++) { mul(A[i][jj], A[i][jj], A[n-1][i-1]); neg(A[i][jj], A[i][jj]); }
    for (jj = 0; jj < i; jj++) fms(A[i][jj], A[i][i], A[i-1][jj]);
    neg(A[i][i], A[i][i]);  // monic
    for (jj = 0; jj < i; jj++) add(A[i][jj+1], A[i][jj+1], A[i-1][jj]);
  }

  if (n != 1) { // in place for p[n]
    i = n - 1;
    cpy(t1, A[i][0]);
    cpy(A[i][0], A[0][i]);

    for (j = 1; j < n-1; j++) {
      cpy(t2, A[n-1][j]);
      for (jj = 0; jj < j; jj++) mul(A[i][jj], A[i][jj], t1);
      for (jj = 0; jj < j; jj++) fma(A[n-1][jj], A[j][n-1], A[j-1][jj]);
      cpy(A[i][jj], A[j][i]);
      cpy(t1, t2);
    }
    for (jj = 0; jj < n-1; jj++) { mul(A[i][jj], A[i][jj], t1); neg(A[i][jj], A[i][jj]); }
    for (jj = 0; jj < n-1; jj++) fms(A[i][jj], A[i][i], A[i-1][jj]);
    neg(A[i][i], A[i][i]);
    for (jj = 0; jj < n-1; jj++) add(A[i][jj+1], A[i][jj+1], A[i-1][jj]);
  }

  if constexpr(std::is_same_v<T,mpfr_t>) { 
    mpfr_clear(t1);
    mpfr_clear(t2);
    mpfr_clear(nx);
    mpfr_free_cache();
  }
}
} // namespace cpolycc
