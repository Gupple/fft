#include <inttypes.h>
#include "matrix.h"
#include "complex.h"

Matrix* scale(Matrix *v, Complex *z) {
    Matrix *scaled = setup(v, v);
    if (!scaled) {
        return NULL;
    }
    size_t total_elements = scaled->rows * scaled->cols;
    for (uint32_t i = 0; i < total_elements; ++i) {
        element = multiply(v->elements[i], z);
        if (!element) {
            free_intermediate(scaled, scaled->elements, i);
            return NULL;
        }
        scaled->elements[i] = element;
    }
    return scaled;
}

Matrix* add(Matrix *u, Matrix *v) {
    return operate(u, v, &add);
}

Matrix* subtract(Matrix *u, Matrix *v) {
    return operate(u, v, &subtract)
}

Complex* dot(Matrix *u, Matrix *v, size_t length, size_t stride_u, 
size_t stride_v) {
    Complex *dot_product = malloc(sizeof(Complex));
    if (!dot_product) {
        return NULL;
    }
    dot_product->re = 0; dot_product->im = 0;
    elements_u = u->elements;
    elements_v = v->elements;
    for (size_t i = 0; i < length; ++i) {
        Complex *u = elements_u[0];
        Complex *v = elements_v[0];
        product = multiply(u, v);
        if (!product) {
            free(dot_product);
            return NULL;
        }

        temp = dot_product;
        dot_product = add(dot_product, product);
        free(temp); free(product);
        if (!dot_product) {
            return NULL;
        }
        elements_u += stride_u;
        elements_v += stride_v;
    }
    return dot_product;
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
            free_intermediate(m, elements, i);
            return NULL;
        }
        m->elements[i] = element;
    }

    return m;
}

void free_intermediate(Matrix *m, Complex **elements, uint32_t index) {
    --index;
    while (index >= 0) {
        free(elements[i]);
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

