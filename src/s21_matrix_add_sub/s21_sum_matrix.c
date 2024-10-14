//
// Created by Calamari Yeste on 2024-10-14.
//
#include "../s21_matrix.h"

#include <stdlib.h>

#include "../auxiliary_functions.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    if (A == NULL || B == NULL) return ERROR_OR_IN_C_M;
    if (A->matrix == NULL || B->matrix == NULL) return ERROR_OR_IN_C_M;
    if (A->rows != B->rows || A->cols != B->cols) return ERROR_OR_IN_C_M;
    if (A->rows <= 0 || A->columns <= 0 || B->rows <= 0 || B->columns <= 0) return ERROR_OR_IN_C_M;

    int ret_code = s21_create_matrix(A->rows, A->columns, result);

    for(int i = 0; i < A->rows && ret_code == OK; i++) {
        for(int j = 0; j < A->columns && ret_code == OK; j++) {
            double value_A;
            double value_B;
            int ret_code_A = s21_get(A, i, j, &value_A);
            int ret_code_B = s21_get(B, i, j, &value_B);
            if(ret_code_A == OK && ret_code_B == OK) {
                long double sum = value_A + value_B;
                if (-DBL_MIN <= sum && sum <= DBL_MAX) {
                    ret_code = s21_set(result, i, j, sum);
                }
                else {
                    ret_code = CALC_ERROR;
                }
            }
            else {
                ret_code = ERROR_OR_IN_C_M;
            }
        }
    }

    return ret_code;
}