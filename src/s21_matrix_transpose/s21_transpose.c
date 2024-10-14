//
// Created by Calamari Yeste on 2024-10-14.
//
#include "../s21_matrix.h"

#include <stdlib.h>

#include "../auxiliary_functions.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
    if (A == NULL || B == NULL) return ERROR_OR_IN_C_M;
    if (A->matrix == NULL) return ERROR_OR_IN_C_M;
    if (A->rows <= 0 || A->columns <= 0) return ERROR_OR_IN_C_M;

    int ret_code = s21_create_matrix(A->columns, A->rows, result);

    for(int i = 0; ret_code == OK && i < A->columns; i++) {
        for(int j = 0; ret_code == OK && j < A->rows; j++) {
            double value_A;
            int ret_code_A = s21_get(A, j, i, &value_A);
            if(ret_code_A == OK) {
                ret_code = s21_set(A, i, j, value_A);
            }
        }
    }

    return ret_code;
}
