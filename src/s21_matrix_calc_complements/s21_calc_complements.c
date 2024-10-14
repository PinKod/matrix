//
// Created by Calamari Yeste on 2024-10-14.
//
#include "../s21_matrix.h"

#include <stdlib.h>

#include "../auxiliary_functions.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
    if (A == NULL) return ERROR_OR_IN_C_M;
    if (A->matrix == NULL) return ERROR_OR_IN_C_M;
    if (A->rows <= 0 || A->columns <= 0) return ERROR_OR_IN_C_M;
    if(A->rows != A->columns) return CALC_ERROR;

    int ret_code = s21_create_matrix(A->rows, A->columns, result);

    for(int i = 0; ret_code == OK && i < A->rows; i++) {
        for(int j = 0; ret_code == OK && j < A->columns; j++) {
            double value_A;
            ret_code = s21_get(A, i, j, &value_A);
            if(ret_code == OK) {
                double value_minor;
                ret_code = s21_minor(A, i, j, &value_minor);
                if(ret_code == OK) {
                    ret_code = s21_set(result, i, j, value_minor);
                }
            }
        }
    }



    return ret_code;
}
