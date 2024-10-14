//
// Created by Calamari Yeste on 2024-10-14.
//
#include "../s21_matrix.h"

#include <stdlib.h>

#include "../auxiliary_functions.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    if (A == NULL || B == NULL) return FAILURE;
    if (A->matrix == NULL || B->matrix == NULL) return FAILURE;
    if (A->rows != B->rows || A->cols != B->cols) return FAILURE;
    if (A->rows <= 0 || A->columns <= 0 || B->rows <= 0 || B->columns <= 0) return FAILURE;

    int ret_code = SUCCESS;
    for (int i = 0; i < A->rows && ret_code == SUCCESS; i++) {
        for (int j = 0; j < A->columns; j++) {
            double *value_A = NULL;
            double *value_B = NULL;
            int ret_code_A = s21_get(A, i, j, value_A);
            int ret_code_B = s21_get(B, i, j, value_B);
            if (ret_code_A != OK || ret_code_B != OK) {
                ret_code = FAILURE;
            }
            else if(*value_A == NULL || *value_B == NULL) {
                ret_code = FAILURE;
            }
            else if( *value_A != *value_B) {
                ret_code = FAILURE;
            }
        }
    }
    return ret_code;
}