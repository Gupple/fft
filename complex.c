#include <stdio.h>
#include "complex.h"

// Given z = a + bi, returns a new pointer to a - bi.
Complex* conjugate(Complex *z) {
    Complex *conj = malloc(sizeof(Complex));
    conj->re = z->re;
    conj->im = -(z->im);
    return conj;
}

// Returns a new pointer to y + z.
Complex* add(Complex *y, Complex *z) {
    Complex *new_sum = malloc(sizeof(Complex));
    new_sum->re = y->re + z->re;
    new_sum->im = y->im + z->im;
    return new_sum;
}

// Returns a new pointer to y - z.
Complex* subtract(Complex *y, Complex *z) {
    Complex *difference = malloc(sizeof(Complex));
    difference->re = y->re - z->re;
    difference->im = y->im - z->im;
    return difference;
}

// Returns a new pointer to yz.
Complex* multiply(Complex *y, Complex *z) {
    Complex *product = malloc(sizeof(Complex));
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
    double prod_sum = (y->re + y->im) * (z->re - z->im);
    double prod_re = y->re * z->re;
    double prod_im = y->im * -z->im;
    
    product->re = prod_re - prod_im;
    product->im = prod_sum - (prod_re + prod_im);

    double quotient = pow((y->re), 2.0) + pow((y->im), 2.0);
    product->re = product->re / quotient;
    product->im = product->im / quotient;
    return product;
}

