#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int sign;       
    int digits[1000];  
    int size;     
} UnboundedInteger;

void initializeInteger(UnboundedInteger *n, int sign) {
    n->sign = sign;
    n->size = 0;
}

void addDigit(UnboundedInteger *n, int digit, int pos) {
    for (int i = n->size; i > pos; i--) {
        n->digits[i] = n->digits[i - 1];
    }
    n->digits[pos] = digit;
    n->size++;
}

void removeDigit(UnboundedInteger *n, int pos) {
    for (int i = pos; i < n->size - 1; i++) {
        n->digits[i] = n->digits[i + 1];
    }
    n->size--;
}

int sumDigits(UnboundedInteger *n) {
    int sum = 0;
    for (int i = 0; i < n->size; i++) {
        sum += n->digits[i];
    }
    return sum;
}

void displayNumber(UnboundedInteger *n) {
    for (int i = 0; i < n->size; i++) {
        printf("%d", n->digits[i]);
    }
    printf("\n");
}

int main() {
    UnboundedInteger n;
    initializeInteger(&n, 1); 

    addDigit(&n, 1, 0); 
    addDigit(&n, 2, 1);
    addDigit(&n, 3, 2); 
    addDigit(&n, 4, 3); 
    addDigit(&n, 5, 4); 

    printf("Number after adding digits: ");
    displayNumber(&n);

    removeDigit(&n, 0);
    removeDigit(&n, 4);
    removeDigit(&n, 1);
    printf("Number after removing a digit: ");
    displayNumber(&n);

    int sum = sumDigits(&n);
    printf("Sum of digits: %d", sum);
}















