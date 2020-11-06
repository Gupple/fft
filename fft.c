#include <complex.h>
#include <matrix.h>
#include <stdio.h>
#include <inttypes.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#define TOLERANCE 0.00000001

Matrix* FFT(Matrix *v) { 
    if (v->rows = 1) {
        return v;
    }
    uint32_t n = v->rows;
    double root_angle = (2 * M_PI) / n; 
    omega = create_complex(root_angle, sin(root_angle));

    odd_dim = n / 2;
    even_dim = n - odd_dim;
    Matrix *odds = malloc(sizeof(Matrix));
    Matrix *evens = malloc(sizeof(Matrix));

    odds->rows = odd_dim; odds->cols = 1;
    evens->rows = even_dim; evens->cols = 1;
    odds->elements = malloc(odd_dim * sizeof(Complex*));

    evens->elements = malloc(even_dim * sizeof(Complex*));

    uint32_t odds_index = 0;
    uint32_t evens_index = 0;
    for (uint32_t i = 0; i < n; ++i) {
        Complex *copy_entry = copy(v->elements[i]);
        if (i % 2) {
            odds->elements[odds_index++] = copy_entry;
        } else {
            evens->elements[evens_index++] = copy_entry;
        }
    }
    
    Matrix *FFT_odds = FFT(odds);
    Matrix *FFT_evens = FFT(evens);
    Matrix *value_rep = malloc(sizeof(Matrix));

    value_rep->rows = n; value_rep->cols = 1;
    value_rep->elements = calloc(n, sizeof(Complex*));
    Complex *zero = malloc(sizeof(Complex));
    zero->re = 0; zero->im = 0;
    
    for (uint32_t i = 0; i < even_dim; ++i) {
        Complex *unity_power = power(omega, i);
        Complex *power_odd_entry = zero; 
        if (i < odd_dim) {
            Complex *power_odd_entry = 
            multiply(unity_power, odds->elements[i]);
        }
        Complex *entry_i = add(evens->elements[i], power_odd_entry);
        Complex *entry_i_offset = 
        subtract(evens->elements[i], power_odd_entry);
        value_rep->elements[i] = entry_i;
        value_rep->elements[i + odd_dim] = entry_i_offset;
    }
    return value_rep;
}
