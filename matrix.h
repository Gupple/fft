#ifndef MATRIX_H
#define MATRIX_H

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
Matrix* add(Matrix *u, Matrix *v);
Matrix* subtract(Matrix *u, Matrix *v);

Complex* dot(Matrix *u, Matrix *v, uint32_t length, 
uint32_t stride_u, uint32_t stride_v);

Matrix* multiply(Matrix *u, Matrix *v);
Matrix* operate(Matrix *u, Matrix *v, 
Complex* (*func) (Complex*, Complex*));

void free_intermediate(Matrix *m, Complex **elements, 
uint32_t index);

void free_matrix(Matrix *m);
Matrix* setup(Matrix *u, Matrix *v);
#endif

