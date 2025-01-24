#include <stdio.h>
#include <math.h>

int main() {
  
    double X1, Y1, X2, Y2, D;

    scanf("%lf %lf\n%lf %lf", &X1, &Y1, &X2, &Y2);

    D = sqrt((X2 - X1)*(X2 - X1) + (Y2 - Y1)*(Y2 - Y1));

    printf("%.4lf\n", D);

    return 0;
}
