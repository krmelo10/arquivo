#include <stdio.h>

int main() {
    
    int X;
    double Y, C;

    scanf("%d\n%lf", &X, &Y);
    
    C = X/Y;

    printf("%.3lf km/l\n", C);

    return 0;
}
