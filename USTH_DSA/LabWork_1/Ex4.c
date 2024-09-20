/*
TIME COMPLEXITY: O(sqrt(n)*logn)
PSEUDO CODE:
func isSphenic(n)
    cnt = 0
    for i = 2 to sqrt(n):
        if n % i = 0 then
            expo = 0
            while n % i = 0 do
                expo = expo + 1
                n = n / i
            end while
            if expo >= 2 then
                return 0
            cnt++

    if n > 1: 
        cnt = cnt + 1
    if cnt == 3:
        return 1
    else
        return 0

func main
    input n

    if isSphenic(n) then
        print(n is a sphenic number)
    else
        print(n is not a sphenic number)

*/

#include <stdio.h>
#include <math.h>

int isSphenic(int n){
    int cnt = 0;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            int expo = 0;
            while(n % i == 0){
                expo++;
                n /= i;
            }
            if(expo >= 2) return 0;
            cnt++;
        }
    }

    if(n > 1) cnt++;
    if(cnt == 3) return 1;
    else return 0;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    if(isSphenic(n)) {
        printf("%d is a sphenic number", n);
    }
    else{
        printf("%d is not a sphenic number", n);
    }
}
