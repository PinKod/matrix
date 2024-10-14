//
// Created by Calamari Yeste on 2024-10-14.
//

#ifndef MATRIX_AUXILIARY_FUNCTIONS_H
#define MATRIX_AUXILIARY_FUNCTIONS_H

#include "s21_matrix.h"

int s21_get(matrix_t matrix, int row, int col, double *value);
int s21_set(matrix_t *matrix, int row, int col, double value);

int s21_set_val(matrix_t *matrix, double value);

int s21_resize(matrix_t *matrix, int rows, int cols);

#endif //MATRIX_AUXILIARY_FUNCTIONS_H
