#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex.h"

// Constructs a new complex number.
Complex* create_complex(double re, double im) {
    Complex* z = malloc(sizeof(Complex));
    if (!z) {
        return NULL;
    }
    z->re = re;
    z->im = im;
    return z;
}

// If z = a + bi, Re(z) = a.
double Re(Complex *z) {
    return z->re;
}

// If z = a + bi, Im(z) = b.
double Im(Complex *z) {
    return z->im;
}

// Given z = a + bi, returns a new pointer to a - bi.
Complex* conjugate(Complex *z) {
    Complex *conj = malloc(sizeof(Complex));
    if (!conj) {
        return NULL;
    }
    conj->re = z->re;
    conj->im = -(z->im);
    return conj;
}

// Returns a new pointer to y + z.
Complex* add(Complex *y, Complex *z) {
    Complex *new_sum = malloc(sizeof(Complex));
    if (!new_sum) {
        return NULL;
    }
    new_sum->re = y->re + z->re;
    new_sum->im = y->im + z->im;
    return new_sum;
}

// Returns a new pointer to y - z.
Complex* subtract(Complex *y, Complex *z) {
    Complex *difference = malloc(sizeof(Complex));
    if (!difference) {
        return NULL;
    }
    difference->re = y->re - z->re;
    difference->im = y->im - z->im;
    return difference;
}

// Returns a new pointer to yz.
Complex* multiply(Complex *y, Complex *z) {
    Complex *product = malloc(sizeof(Complex));
    if (!product) {
        return NULL;
    }
    double prod_sum = (y->re + y->im) * (z->re + z->im);
    double prod_re = y->re * z->re;
    double prod_im = y->im * z->im;
    
    product->re = prod_re - prod_im;
    product->im = prod_sum - (prod_re + prod_im);
    return product;
}

// Returns a new pointer to y / z. 
Complex* divide(Complex *y, Complex *z) {
    Complex *product = malloc(sizeof(Complex));
    if (!product) {
        return NULL;
    }

    double prod_sum = (y->re + y->im) * (z->re - z->im);
    double prod_re = y->re * z->re;
    double prod_im = y->im * -z->im;
    
    product->re = prod_re - prod_im;
    product->im = prod_sum - (prod_re + prod_im);

    double quotient = pow(z->re, 2.0) + pow(z->im, 2.0);
    product->re = product->re / quotient;
    product->im = product->im / quotient;
    return product;
}

