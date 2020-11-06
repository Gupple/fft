#ifndef MATRIX_H
#define MATRIX_H

#ifndef MAX_WIDTH
#define MAX_WIDTH 8192
#endif

#include <stdio.h>
#include <inttypes.h>
#include "complex.h"

// A matrix struct stored in row-major order.
typedef struct Matrix {
    size_t rows;
    size_t cols;
    Complex **elements;
} Matrix;

// Primitive matrix operations.
Matrix* scale(Matrix *v, Complex *z);
Matrix* add_matrix(Matrix *u, Matrix *v);
Matrix* subtract_matrix(Matrix *u, Matrix *v);

Complex* dot(Complex **u, Complex **v, size_t length, 
size_t stride_u, size_t stride_v);

Matrix* multiply_matrix(Matrix *u, Matrix *v);
Matrix* operate(Matrix *u, Matrix *v, 
Complex* (*func) (Complex*, Complex*));

void free_intermediate(Matrix *m, Complex **elements, 
uint32_t index);

Matrix* read_matrix(char *filename);
void free_matrix(Matrix *m);
Matrix* setup(Matrix *u, Matrix *v);
#endif

