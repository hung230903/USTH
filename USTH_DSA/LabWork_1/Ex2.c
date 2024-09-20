#include <stdio.h>

void findMax(int *max, int a) {
    if (a > *max) {
        *max = a;  
    }
}

int main() {
    int max = 10;
    int a = 25;    
    
    findMax(&max, a);  
    printf("Max = %d", max);
}











