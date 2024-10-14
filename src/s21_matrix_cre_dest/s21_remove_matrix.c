//
// Created by Calamari Yeste on 2024-10-14.
//
#include "../s21_matrix.h"

#include <stdlib.h>

void s21_remove_matrix(matrix_t *A) {
    if(A == NULL) return;
    if(A->matrix == NULL) return;
    if(A->rows <= 0 || A->columns <= 0) return;

    for(int i = 0; i < A->rows; i++) {
        if(A->matrix[i] != NULL) free(A->matrix[i]);
    }
    if(A->matrix != NULL) free(A->matrix);
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
}