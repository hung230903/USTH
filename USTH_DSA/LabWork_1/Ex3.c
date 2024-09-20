#include <stdio.h>

typedef struct {
    float real;
    float imag;
} Complex;

Complex add(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

Complex multiply(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real * c2.real - c1.imag * c2.imag;
    result.imag = c1.real * c2.imag + c1.imag * c2.real;
    
    return result;
}

int main() {
    Complex c1 = {1.2, 3.4};  
    Complex c2 = {5.6, 7.8}; 
    
    Complex sum = add(c1, c2);  
    Complex product = multiply(c1, c2);  
    
    printf("Sum: %.2f + %.2fi\n", sum.real, sum.imag);
    printf("Product: %.2f + %.2fi", product.real, product.imag);
}















