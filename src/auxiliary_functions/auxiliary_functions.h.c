//
// Created by Calamari Yeste on 2024-10-14.
//
#include "../auxiliary_functions.h"

#include <stdlib.h>

int s21_get(matrix_t matrix, int row, int col, double *value) {
    if(row < 0 || col < 0) return  ERROR_OR_IN_C_M;
    if(value == NULL) return ERROR_OR_IN_C_M;
    if(row > matrix.rows - 1 || col > matrix.columns - 1) return ERROR_OR_IN_C_M;

    *value = matrix.matrix[row][col];
    return OK;
}

int s21_set(matrix_t *matrix, int row, int col, double value) {
    if(matrix == NULL) return ERROR_OR_IN_C_M;
    if(matrix->matrix == NULL) return ERROR_OR_IN_C_M;
    if(row < 0 || col < 0) return  ERROR_OR_IN_C_M;
    if(row > matrix.rows - 1 || col > matrix.columns - 1) return ERROR_OR_IN_C_M;

    matrix->matrix[row][col] = value;
    return OK;
}

int s21_set_val(matrix_t *matrix, double value) {
    if(matrix == NULL) return ERROR_OR_IN_C_M;
    if(matrix->matrix == NULL) return ERROR_OR_IN_C_M;

    int ret_code = OK;
    for(int i = 0; i < matrix->rows && ret_code == OK; i++) {
        for(int j = 0; j < matrix->columns; j++) {
            ret_code = s21_set(matrix, i, j, value);
            break;
        }
    }
    return ret_code;
}

int s21_realloc_rows(matrix_t *matrix, int rows) {
    int ret_code = OK
    double **tmp_matrix = realloc(matrix->matrix, rows * sizeof (double *));
    if(tmp_matrix != NULL) {
        matrix->matrix = tmp_matrix;
    }
    else {
        ret_code = ERROR_OR_IN_C_M;
    }

    if(matrix->rows < rows) {
        for(int i = matrix->rows; i < rows && ret_code == OK; i++) {
            for(int j = 0; j < matrix->columns; j++) {
                ret_code = s21_set(matrix, i, j, 0);
                break;
            }
        }
    }
    return ret_code;
}

//absolute rows and columns: starts from 1
int s21_resize(matrix_t *matrix, int rows, int cols) {
    if(matrix == NULL) return ERROR_OR_IN_C_M;
    if(matrix->matrix == NULL) return ERROR_OR_IN_C_M;
    if(rows <= 0 || cols <= 0) return  ERROR_OR_IN_C_M;
    if(matrix->rows == rows && matrix->columns == cols) return s21_set_val(matrix, 0);

    int ret_code = OK;

    if(rows != matrix->rows) {
        if (rows < matrix->rows) {
            for (int i = rows - 1; i < matrix->rows; i++) free(matrix->matrix[i]);
        }
        ret_code = s21_realloc_rows(matrix, rows);
    }

    if(cols != matrix->columns) {
        for(int i = 0; i < matrix->rows && ret_code == OK; i++) {
            double *temp_col = realloc(matrix->matrix[i], cols * sizeof (double));
            if(temp_col != NULL) {
                if(cols > matrix->columns) {
                    for(int j = matrix->columns; j < cols; j++) {
                        ret_code = s21_set(matrix, i, j, 0);
                    }
                }
            }
            else {
                ret_code = ERROR_OR_IN_C_M;
            }
        }
    }
    return ret_code;
}