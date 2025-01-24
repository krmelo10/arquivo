#include <stdio.h>
#include <stdlib.h>

int maior(int a, int b) {
    return (a + b + abs(a - b))/2;
}

int main(){
    int a, b, c, R;

    scanf("%d %d %d", &a, &b, &c);
    
    R = maior(a, maior(b, c));

    printf("%d eh o maior\n", resposta);

    return 0;
}
