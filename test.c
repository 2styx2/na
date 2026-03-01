#define NA_IMPLEMENTATION
#include "na.h"
#include <stdio.h>

int main(void) {
    VecF vec = {0};
    vec_insert(&vec, 1);
    vec_insert(&vec, -2);
    vec_insert(&vec, 4);
    printf("Vector:\n");
    for (size_t i = 0; i < vec.rows; i++) {
        printf("       | %2f |\n", vec.data[i]);
    }
    VecF vec1 = {0};
    vec_insert(&vec1, 1);
    vec_insert(&vec1, -2);
    vec_insert(&vec1, 4);
    float res = vecf_dot(&vec, &vec1);
    printf("Res: %f\n", res);
    vec_free(vec);
    return 0;
}
