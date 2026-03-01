#ifndef NA_H_
#define NA_H_

#ifndef NADEF
#define NADEF static inline
#endif // NADEF

// Good convention for cross platform and other reasons xD
#ifndef NA_ASSERT
#include <assert.h>
#define NA_ASSERT assert
#endif /* NA_ASSERT */

#ifndef NA_REALLOC
#include <stdlib.h>
#define NA_REALLOC realloc
#endif /* NA_REALLOC */

#ifndef NA_FREE
#include <stdlib.h>
#define NA_FREE free
#endif /* NA_FREE */

#define EPSILON_FLOAT 1.19e-23
#define EPSILON_DOUBLE 2.22e-52

typedef struct {
    size_t capacity;
    size_t rows;
    int *data;
} VecI;

typedef struct {
    size_t capacity;
    size_t rows;
    float *data;
} VecF;

typedef struct {
    size_t capacity;
    size_t rows, cols;
    int *data;
} MatI;

typedef struct {
    size_t capacity;
    size_t rows, cols;
    float *data;
} MatF;

#ifndef NA_DA_INIT_CAP
#define NA_DA_INIT_CAP 256
#endif

#ifdef __cplusplus
#define NA_DECLTYPE_CAST(T) (decltype(T))
#else
#define NA_DECLTYPE_CAST(T)
#endif

#define na_vec_da_reserve(da, expected_capacity)                                                                      \
    do {                                                                                                           \
        if ((expected_capacity) > (da)->capacity) {                                                                \
            if ((da)->capacity == 0) {                                                                             \
                (da)->capacity = NA_DA_INIT_CAP;                                                                   \
            }                                                                                                      \
            while ((expected_capacity) > (da)->capacity) {                                                         \
                (da)->capacity *= 2;                                                                               \
            }                                                                                                      \
            (da)->data = NA_DECLTYPE_CAST((da)->data)NA_REALLOC((da)->data, (da)->capacity * sizeof(*(da)->data)); \
            assert((da)->data != NULL && "Buy more RAM lol");                                                      \
        }                                                                                                          \
    } while (0)

#define na_vec_da_insert(da, item)               \
    do {                                      \
        na_vec_da_reserve((da), (da)->rows + 1); \
        (da)->data[(da)->rows++] = (item);    \
    } while (0)

#define na_da_free(da) NA_FREE((da).data)

// Vector funcs
NADEF int veci_dot(VecI *a, VecI *b);
NADEF float vecf_dot(VecF *a, VecF *b);

// TODO: Maybe add Matrix Vector ex: A*b=B
//                    A = [[ 1, 1 ]  b = [ 1, 1]
//                        [ 1, 1 ]]

// Matrix funcs
NADEF MatI mati_dot(MatI *A, MatI *B);
NADEF MatF matf_dot(MatF *A, MatF *B);

NADEF MatI mati_gauss_elim(MatI *A);
NADEF MatF matf_gauss_elim(MatF *A);

#endif // NA_H_

#ifdef NA_IMPLEMENTATION

NADEF int veci_dot(VecI *a, VecI *b) {
    NA_ASSERT(a != NULL && b != NULL && "Vectors cannot be NULL");
    NA_ASSERT(a->rows == b->rows && "Dot product failed: Vector sizes do not match");
    int prod = 0;
    for (size_t i = 0; i < a->rows; i++) {
        prod += a->data[i] * b->data[i];
    }
    return prod;
}
NADEF float vecf_dot(VecF *a, VecF *b) {
    NA_ASSERT(a != NULL && b != NULL && "Vectors cannot be NULL");
    NA_ASSERT(a->rows == b->rows && "Dot product failed: Vector sizes do not match");
    float prod = 0;
    for (size_t i = 0; i < a->rows; i++) {
        prod += a->data[i] * b->data[i];
    }
    return prod;
}

#endif // NA_IMPLEMENTATION

#ifndef NA_STRIP_PREFIX_GUARD_
#define NA_STRIP_PREFIX_GUARD_
    #ifndef NA_UNSTRIP_PREFIX
    #define vec_insert na_vec_da_insert
    #define vec_free na_da_free
    #endif
#endif
