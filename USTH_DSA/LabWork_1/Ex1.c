/*
PSEUDO CODE:
func swap(n):
    digits = log10(n)  
    first = n / (10^digits)  
    last = n % 10  
    
    n = n % (10^digits) 
    n = n / 10  
    n = last * (10^digits) + n * 10 + first  
    
    return n

func main:
    n = 1234
    print(swap(n))
*/

#include <stdio.h>
#include <math.h>

int swap(int n) {
    int digits = (int)log10(n);  
    int first = n / (int)pow(10, digits);  
    int last = n % 10;  
    
    n = n % (int)pow(10, digits);  
    n = n / 10; 
    n = last * (int)pow(10, digits) + n * 10 + first;
    
    return n;
}

int main() {
    int n = 1234;
    printf("Swap: %d", swap(n));
}
