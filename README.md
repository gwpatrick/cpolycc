# CPOLYCC - Multiprecision calculation of a characteristic polynomial.

The coefficients of a characteristic polynomial (cp) sometimes depend sensitively on its
matrix. A C++ function is provided for the cp of a matrix by La Budde's method, as explained in
[Rehman and Ipsen](https://arxiv.org/abs/1104.3769) [RI]. By _multiprecision_ I mean iteratively
calculate the cp at increasing precision according to a flexible _schedule_, stopping when
successive coefficients of the cp are all the same or adjacent in a _target floating point type_
(tfp).

There are two sources of cp error: the floating point representation of an exact matrix (if
applicable), and the roundoff error in the method.  The calculated cp is accurate to the
floating point representation, in the following sense: the coefficients are the same tfp, or
adjacent tfp's, or separated by one tfp. That is, were the cp of the floating point
representation to be known exactly, and were that cp to be rounded to the tfp type, then there
would be at most one tfp between the two.

## Functions

In namespace `cpolycc` there are three overloads of function `cpoly` as follows.

### (1) `template<typename T> void cpoly(T** A, int n)` 

In-place calculation of the cp of the `n` by `n` matrix `A`, returning the coefficients from
degree `0` to `n-1` in the last row of `A` (the coefficient of `x^n` is not stored).  The matrix
must be represented by a vector of successive row pointers into a contiguous block of
`<stdfloat>` types. The type `T` is from `<stdfloat>` or `mpfr_t` from GNU MPFR. The algorithm
is the usual upper triangular Hessenberg reduction followed by a recursion for the cp.

### (2) `int cpoly(T** A, int n, int prec_step, int dbl_depth, int max_depth, U *q, int &m, int &depth, int &prec)`

A described at the beginning, iteratively invoke function (1) at increasing precision until the
coefficients of the characteristic polynomial stabilize up to type `U` from `<stdfloat>`. The
return value is `0` for success, `cpolycc::ECPOLYCC_LIMIT` when `max_depth` is exceeded, and
`cpolycc::ECPOLYCC_OVERFLOW` when a characteristic polynomial coefficient is the maximum or
lowest value of type `U`.  On success `q` is a dimension `m` vector representing a degree `m`
monic polynomial, such that the characteristic polynomial is `x^k q(x)` ie `k=n-m`. _On return,
the row pointers `A[0],...,A[n-1]` may not be in the same order as as input._

The number of times the characteristic polynomial is calculated is called the _depth_. The
precision is increased according to the following _schedule_: in bits, starting strictly after
the precision of `U`, 53 (double), 113 (quad), and 120bits and thereafter add `prec_step`, until
the depth is greater than `dbl_depth`, after which the precision is successively doubled.

### (3) `template<typename T, typename U> int cpoly(T** A, int n, U *q, int &m, int &depth, int &prec)`
Same as function (2) with defaults `prec_step=8`, `dbl_depth=4`, `max_depth=INTMAX`.

The functions are in header `cpoly.hh`. To help with the (human) memory, the programs are coded
with a thin wrapper called `gmp_adaptor`, which systematizes the GMP and MPFR function
calls. The included simple makefile compiles the wrapper to the shared object file
`gmp_adapter.so`, and also it compiles a minimal example.

## Further information

Testing was done on on a large number of randomly generated matrices with power-of-2 scaled
integer entries (for which the exact cp is exactly known). The cp was usually recovered at depth
3 or 4, but if the matrix had a kernel, then high precision is sometimes required to compute
the cp zero coefficients. At a tfp of quad precision and for a $128\times128$ matrix, it is not
uncommon for the schedule to reach $50,000$ bits of precision, corresponding to depth of
thousands were the precision to linearly increase by the default $8$ bits. Precision doubling
prevents the long run times that would result.

Some illustrative results follow.

An initial validation may be obtained with a conjugation of a Forsythe matrix ie a
$200\times200$ Jordan block with a value $\nu=10^{-10}$ at the lower left. The multiprecision
`cpoly` followed the schedule 113,120,128,136 bits and the [absolute
errors](./fig1_captioned.pdf) essentially replicate Fig. 7.1 from
[[RI](https://arxiv.org/abs/1104.3769)].  The relative errors for a conjugated diagonal matrix
with diagonal evenly spaced from $1/4$ to $5/4$ in steps of 1/160
[illustrates](./fig2_captioned.pdf) increasing accuracy as the tfp precision is increased.

A [Chow matrix](https://www.mathworks.com/help/matlab/ref/gallery.html) is an $n\times n$ upper
triangular matrix $\delta\,\mathbf1+A$, where the rows are successive powers of $\alpha$
starting at $1$ on the diagonal.  With $n=64$, $\delta=1$ and $\alpha=2$, the cp is not resolved
in [[RI](https://arxiv.org/abs/1104.3769)] due to ill conditioning of the coefficients, but it
is [resolved](./fig3_captioned.pdf) by the multiprecision `cpoly` at `std::float64_t` with
schedule 113,120 bits and at `std::float128_t` with schedule 120,128,136 bits. Changing to
$\delta=0$, the first 32 coefficients of the cp are zero, and, at `std::float128_t`, `cpoly`
does an excursion to depth 12 and precision 36864 bits. In that, the (zero) constant coefficient
decays at power $1/4$ of the depth, while the other (zero) coefficients decay at power
$1/2$. Conjugation introduces error in the floating point representation, with result an
excursion to depth 8 and precision 576 bits, but the error relative to the exact Chow matrix was
large. The [same behaviour](./fig4_captioned.pdf) (cp resolution for the exact matrix, but not
of a conjugation) occurs with the 
[Frank matrix](https://nhigham.com/2022/01/25/what-is-the-frank-matrix).
