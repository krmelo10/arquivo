#include <stdio.h>

int main() {
    
    double N;

    scanf("%lf", &N);

    if(0 <= N && N <= 25){
        printf("Intervalo [0,25]\n");
    }else if(25 < N && N <= 50){
        printf("Intervalo (25,50]\n");
    }else if(50 < N && N <= 75){
        printf("Intervalo (50,75]\n");
    }else if(75 < N && N <= 100){
        printf("Intervalo (75,100]\n");
    }else{
        printf("Fora de intervalo\n");
    }

    return 0;
}
