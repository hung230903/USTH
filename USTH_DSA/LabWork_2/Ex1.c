#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *digits;
    int size;
    int capacity;
} UnboundedInteger;

UnboundedInteger* createUnboundedInteger(int initialCapacity, int sign) {
    UnboundedInteger *n = (UnboundedInteger *)malloc(sizeof(UnboundedInteger));

    n->digits = (int *)malloc(sizeof(int) * initialCapacity);
    n->size = 1; 
    n->capacity = initialCapacity;
    n->digits[0] = sign; 

    return n;
}

void resize(UnboundedInteger *n) {
    n->capacity *= 2;
    n->digits = (int *)realloc(n->digits, sizeof(int) * n->capacity);
}

void addDigit(UnboundedInteger *n, int digit, int position) {
    if (n->size == n->capacity) {
        resize(n);
    }

    for (int i = n->size; i > position; i--) {
        n->digits[i] = n->digits[i - 1];
    }

    n->digits[position] = digit;
    n->size++;
}

void removeDigit(UnboundedInteger *n, int position) {
    for (int i = position; i < n->size - 1; i++) {
        n->digits[i] = n->digits[i + 1];
    }

    n->size--;
}

int sumDigits(UnboundedInteger *n) {
    int sum = 0;
    for (int i = 1; i < n->size; i++) {
        sum += n->digits[i];
    }
    return sum;
}

void displayNumber(UnboundedInteger *n) {
    for (int i = 1; i < n->size; i++) {
        printf("%d", n->digits[i]);
    }
    printf("\n");
}

int main() {
    UnboundedInteger *n = createUnboundedInteger(10, 1);

    addDigit(n, 1, 1);
    addDigit(n, 2, 2);
    addDigit(n, 3, 3);
    addDigit(n, 4, 4);
    
    printf("Number: ");
    displayNumber(n); 
    
    addDigit(n, 9, 2);
    printf("Number after adding digit at position 2: ");
    displayNumber(n); 
    
    removeDigit(n, 3);
    printf("Number after removing digit at position 3: ");
    displayNumber(n); 
    
    int sum = sumDigits(n);
    printf("Sum of digits: %d", sum); 
    
}
