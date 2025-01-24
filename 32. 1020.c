#include <stdio.h>

int main(){
    
    int S, H, M;

    scanf("%d", &S);

    H = segundos/3600;
    S %= 3600;
    M = segundos/60;
    S %= 60;

    printf("%d:%d:%d\n", H, M, S);

    return 0;
}
