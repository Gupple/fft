#include <stdio.h>
#include <inttypes.h>
#include "complex.h"
#include "matrix.h"

int main() {
    Complex y = {20, 5};
    Complex z = {30, 8};
    Complex *x = add(&y, &z);
    printf("%f + %fi\n", Re(x), Im(x));
}
