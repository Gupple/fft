#include <stdio.h>
#include "complex.h"

// A matrix struct.
typedef struct Matrix {
    size_t rows;
    size_t cols;
    Complex **elements;
} Matrix;

// Primitive matrix operations.
Matrix* scale(Matrix *v, Complex *z);
Matrix* add(Matrix *u, Matrix *v);
Matrix* subtract(Matrix *u, Matrix *v);
Matrix* dot(Matrix *u, Matrix *v, stride_u, stride_v);
Matrix* multiply(Matrix *u, Matrix *v);

