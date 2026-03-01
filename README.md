# Numerical Analysis Library (na)

## Goals:
The main goal of this library is to have a simple single file that you can use for numerical analysis

## Roadmap:
Phase 1: Foundation (Machine Precision & Basic Structures)
Concepts:
- Floating-point arithmetic, machine epsilon, round-off error, and catastrophic cancellation.
Implementation:
- [ ] Structs for Vector and Matrix (dynamically allocated)
- [ ] Utility functions for safe floating-point comparisons
- [ ] Basic operations (dot product, cross product, norms, transpose, etc.)

Phase 2: Numerical Linear Algebra
Concepts: Solving Ax=b, matrix factorizations, eigenvalues.
Implementation:
- [ ] Gaussian Elimination with Partial Pivoting.
- [ ] LU Decomposition and Cholesky Factorization.
- [ ] Iterative solvers (Jacobi, Gauss-Seidel).
- [ ] Stretch goal: Singular Value Decomposition (SVD), which is heavily referenced in your textbook.

Phase n: TBD

### This library follows parts of the stb "philosophy"
- for more [stb](https://github.com/nothings/stb)
