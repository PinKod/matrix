//
// Created by Calamari Yeste on 2024-10-14.
//
#include "../s21_matrix.h"

#include <stdlib.h>

#include "../auxiliary_functions.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
    if (A == NULL) return ERROR_OR_IN_C_M;
    if (A->matrix == NULL) return ERROR_OR_IN_C_M;

    int ret_code = s21_create_matrix(A->rows, A->columns, result);

    for(int i = 0; i < A->rows && ret_code == OK; i++) {
        for(int j = 0; j < A->columns && ret_code == OK; j++) {
            double value_A;
            int ret_code_A = s21_get(A, i, j, &value_A);
            if(ret_code_A == OK) {
                long double multiplication = value_A * number;
                if (-DBL_MIN <= multiplication && multiplication <= DBL_MAX) {
                    ret_code = s21_set(result, i, j, multiplication);
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

