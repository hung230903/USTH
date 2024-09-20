#include<stdio.h>
#include<math.h>

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

    if(n > 1){
        cnt++;
    }
    if(cnt == 3){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int n;
    scanf("%d", &n);

    if(isSphenic(n)){
        printf("%d true", n);
    }
    else{
        printf("%d false", n);
    }
}