//
// Created by Calamari Yeste on 2024-10-14.
//
#include "../s21_matrix.h"

#include <stdlib.h>

#include "../auxiliary_functions.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    if( rows <= 0 || columns <= 0) return ERROR_OR_IN_C_M;
    //optimization can done here if matrix exist,we need to clear result matrix and resize it
    if(result != NULL && result->matrix != NULL) {
        return s21_resize(result, rows, columns);
    }

    //assume that here result matrix is NULL
    int ret_code = OK;

    matrix_t *matrix_str = NULL;
    if(result == NULL) matrix_str = malloc(sizeof (matrix_t));
    if(matrix_str == NULL && result != NULL) {
        ret_code = ERROR_OR_IN_C_M;
    }

    double **matrix = malloc(rows * sizeof (double *));
    if(matrix == NULL) {
        ret_code = ERROR_OR_IN_C_M;
    }

    for(int i = 0; i < rows && ret_code == OK; i++) {
        matrix[i] = malloc(columns * sizof(double));
        if(matrix[i] == NULL) {
            ret_code = ERROR_OR_IN_C_M;
        }
    }

    if(ret_code == OK) {
        if(result == NULL) {
            result = matrix_str;
        }
        result->matrix = matrix;
        result->rows = rows;
        result->columns = columns;
    }
    return ret_code;
}