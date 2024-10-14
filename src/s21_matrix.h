//
// Created by Calamari Yeste on 2024-10-14.
//

#ifndef MATRIX_S21_MATRIX_H
#define MATRIX_S21_MATRIX_H

#include <stdlib.h>

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

enum {
    OK = 0,
    ERROR_OR_IN_C_M 1,
    CALC_ERROR 2,
};

#define SUCCESS 1
#define FAILURE 0
int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif //MATRIX_S21_MATRIX_H
