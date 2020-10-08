#include <stdio.h>
#include <inttypes.h>
#include "complex.h"
#include "matrix.h"

int main() {
    Complex y = {20, 5};
    Complex z = {30, 8};
    
	Complex *x = add(&y, &z);
    printf("(%f + %fi) + (%f + %fi) = (%f + %fi)\n", 
	Re(&y), Im(&y), Re(&z), Im(&z), Re(x), Im(x));
	
	x = subtract(&y, &z);
    printf("(%f + %fi) - (%f + %fi) = (%f + %fi)\n", 
	Re(&y), Im(&y), Re(&z), Im(&z), Re(x), Im(x));

	x = multiply(&y, &z);
    printf("(%f + %fi) * (%f + %fi) = (%f + %fi)\n", 
	Re(&y), Im(&y), Re(&z), Im(&z), Re(x), Im(x));

	x = divide(&y, &z);
    printf("(%f + %fi) / (%f + %fi) = (%f + %fi)\n", 
	Re(&y), Im(&y), Re(&z), Im(&z), Re(x), Im(x));
    
    x = conjugate(&y);
    printf("conjugate of %f + %fi = %f + %fi\n", Re(&y), Im(&y), Re(x), Im(x));

}
