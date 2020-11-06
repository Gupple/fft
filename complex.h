#ifndef COMPLEX_H
#define COMPLEX_H

// The complex number struct.
typedef struct Complex {
    double re;
    double im;
} Complex;

// Primitive operations on complex numbers.
Complex* create_complex(double re, double im);
Complex* conjugate(Complex *z);
Complex* add(Complex *y, Complex *z);
Complex* subtract(Complex *y, Complex *z);
Complex* multiply(Complex *y, Complex *z);
Complex* divide(Complex *y, Complex *z);
double Re(Complex *z);
double Im(Complex *z);
#endif

