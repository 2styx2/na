#include "na.h"
#include <stdio.h>

#define NA_IMPLEMENTATION

int main(void) {
    VecI vec = {0};
    vec_insert(&vec, 1);
    vec_insert(&vec, -2);
    vec_insert(&vec, 4);
    printf("Vector:\n");
    for (size_t i = 0; i < vec.rows; i++) {
        printf("       | %2d |\n", vec.data[i]);
    }
    vec_free(vec);
    return 0;
}
