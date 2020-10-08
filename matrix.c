#include <stdio.h>
#include <inttypes.h>
#include "matrix.h"
#include "complex.h"
#include <stdlib.h>

Matrix* scale(Matrix *v, Complex *z) {
    Matrix *scaled = setup(v, v);
    if (!scaled) {
        return NULL;
    }
    size_t total_elements = scaled->rows * scaled->cols;
    for (uint32_t i = 0; i < total_elements; ++i) {
        Complex *element = multiply(v->elements[i], z);
        if (!element) {
            free_intermediate(scaled, scaled->elements, i);
            return NULL;
        }
        scaled->elements[i] = element;
    }
    return scaled;
}

Matrix* add_matrix(Matrix *u, Matrix *v) {
    return operate(u, v, &add);
}

Matrix* subtract_matrix(Matrix *u, Matrix *v) {
    return operate(u, v, &subtract);
}

Complex* dot(Complex **u, Complex **v, size_t length, size_t stride_u, 
size_t stride_v) {
    Complex *dot_product = malloc(sizeof(Complex));
    if (!dot_product) {
        return NULL;
    }
    dot_product->re = 0; dot_product->im = 0;
    for (size_t i = 0; i < length; ++i) {
        Complex *entry_u = u[0];
        Complex *entry_v = v[0];
        Complex *product = multiply(entry_u, entry_v);
        if (!product) {
            free(dot_product);
            return NULL;
        }

        Complex *temp = dot_product;
        Complex *dot_product = add(dot_product, product);
        free(temp); free(product);
        if (!dot_product) {
            return NULL;
        }
        u += stride_u;
        v += stride_v;
    }
    return dot_product;
}

Matrix* multiply_matrix(Matrix *u, Matrix *v) {
    if (u->cols != v->rows) {
        return NULL;
    }
    Matrix *product = malloc(sizeof(Matrix));
    if (!product) {
        return NULL;
    }
    size_t rows = u->rows;
    size_t cols = v->cols;
    size_t length = u->cols;
    product->rows = rows; product->cols = cols;
    size_t total_elements = rows * cols;
    Complex **elements = malloc(total_elements * sizeof(Complex));
    if (!elements) {
        free(product);
        return NULL;
    }

    Complex **elements_u = u->elements;
    Complex **elements_v = v->elements;

    for (uint32_t i = 0; i < rows; ++i) {
        for (uint32_t j = 0; j < cols; ++j) {
            uint32_t index = (i * cols) + j;
            Complex *element = dot(elements_u, elements_v,
            length, 1, cols);
            if (!element) {
                free_intermediate(product, elements, index);
                return NULL;
            }
            elements[index] = element;
            elements_v += 1;
        }
        elements_u += length;
        elements_v = v->elements;
    }
    product->elements = elements;
    return product;
}

Matrix *operate(Matrix *u, Matrix *v, 
Complex* (*func) (Complex*, Complex*)) {
    Matrix *m = setup(u, v);
    if (!m) {
        return NULL;
    }
    size_t total_elements = m->rows * m->cols;
    for (uint32_t i = 0; i < total_elements; ++i) {
        Complex *element = (*func)(u->elements[i], v->elements[i]);
        if (!element) {
            free_intermediate(m, m->elements, i);
            return NULL;
        }
        m->elements[i] = element;
    }

    return m;
}

void free_intermediate(Matrix *m, Complex **elements, uint32_t index) {
    --index;
    while (index >= 0) {
        free(elements[index]);
        --index;
    }
    free(elements);
    free(m);
}

Matrix* setup(Matrix *u, Matrix *v) {
    if ((u->rows != v->rows) && (u->cols != v->cols)) {
        return NULL;
    }
    Matrix *m = malloc(sizeof(Matrix));
    if (!m) {
        return NULL;
    }
    size_t rows = u->rows; size_t cols = u->cols;
    m->rows = rows; m->cols = cols;
    size_t total_elements = rows * cols;
    Complex **elements = malloc(total_elements * sizeof(Complex*));
    
    if (!elements) {
        free(m);
        return NULL;
    }

    m->elements = elements;
    return m;
}

void free_matrix(Matrix *m) {
    size_t total_elements = m->rows * m->cols;
    for (size_t i = 0; i < total_elements; ++i) {
        free(m->elements[i]);
    }
    free(m->elements);
    free(m);
}

