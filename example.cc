// Example for multiprecision cpoly ie cpoly(T**, int, U*, int&, int&, int&), which uses the
// default precision schedule.  The matrix is similar to an 8x8 Forsythe (sparse, superdiagonal
// 1, bottom leftmost entry .125); the correct characteristic polynomial is x^8-.125.

// SPDX-License-Identifier: MIT
// Copyright (c) [2024] [George William Patrick]

// 2024-10-26 GWP

#include <iomanip>
#include <iostream>
#include <stdfloat>

#include <cpoly.hh>

using namespace gmp_adaptor;

int main() {

  const int n = 8;

  std::cout << "\nMatrix:\n";
  std::float64_t AA[64]={-0X1.8611336b965d2p-3,0X1.d2608ea99f54p-2,-0X1.1c2a189c1f2dfp-1,0X1.25b7e61d0809cp-2,-0X1.c5d4926aa56fp-3,0X1.6c1d06c9e3858p-2,-0X1.a16b0c0b27657p-4,-0X1.72489ff83e9c2p-2,0X1.89c3110c896dcp-1,0X1.0041ddc717ce3p-3,0X1.79ab21df94b0dp-5,-0X1.0901af1f29c9dp-9,-0X1.3d6a50f2dd5fbp-2,0X1.5fc90f16a437bp-2,0X1.0433044617e8dp-3,0X1.47c11551a1617p-2,-0X1.1ffbc8c688637p-6,-0X1.87416074a7dcp-3,0X1.292e014af2276p-3,0X1.18befed1f622fp-6,-0X1.6591904ef8a4cp-2,-0X1.992d254b2dbeap-2,0X1.c0720a240a52ep-2,-0X1.9cf9ec0d433bbp-2,0X1.a56f3f42ed648p-3,0X1.b0765f781055cp-2,-0X1.caa5920d98fabp-6,-0X1.b1289c775e0e6p-3,0X1.91c510004aa78p-2,-0X1.c1f16de56ff67p-2,-0X1.b4daf160ad297p-2,0X1.87c6c856a0d47p-6,0X1.0ae0178646b44p-4,0X1.074ee4499dd49p-2,0X1.0c7b210acbb1ep-15,-0X1.80c08e22ecaa8p-1,-0X1.83aa936c7549p-2,-0X1.25c9c245d94e6p-5,-0X1.3e1d0048f5a68p-5,-0X1.4016143c92fcfp-2,-0X1.3ad23d329807fp-2,-0X1.7254bfc2c7359p-2,-0X1.6239e1cad256dp-2,-0X1.23183b8c8ced6p-2,-0X1.86ab4c4289028p-2,-0X1.07358f000f81cp-5,-0X1.3f06238ed9a1fp-2,0X1.f3fee9ad166f1p-2,0X1.432f9e595ce2bp-4,-0X1.dc629ac09debap-5,-0X1.30d7e8fe0f9dp-1,-0X1.369e413c9c42cp-2,0X1.aeb35981324p-2,-0X1.9ffaa5c3ce70ap-6,0X1.309564a94842ap-1,0X1.c82d771a9a008p-4,0X1.7fd1c18b43a15p-2,-0X1.253abaaa5f9ap-3,-0X1.b3cbc92aa3fe6p-2,0X1.5adb746a0523ap-2,-0X1.dbbbb1b620883p-3,-0X1.1b4c834554b97p-1,-0X1.4daf4054563d3p-3,-0X1.ada45ced20887p-5};

  int nn, depth, prec;
  std::float64_t q[n], **A;

  A = new std::float64_t*[n]; A[0] = AA; for (int i = 1; i < n; i++) A[i]= A[i-1] + n;

  std::cout << std::setprecision(4);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) std::cout << std::setw(10) << A[i][j];
    std::cout << '\n';
  }

  int e = cpolycc::cpoly(A, n, q, nn, depth, prec);
  if (e) { std::cout << "cpoly return error " << e << '\n'; return 1; }

  std::cout << "\nCharacteristic polyniomial:\n";
  for (int i = 0; i < nn; i++) std::cout << q[i] << ' ';

  std::cout << "\n\n";
  std::cout << "Computed " << depth
            << " times with increasing precision finally at " << prec << " bits.\n\n";
  return 0;
}
