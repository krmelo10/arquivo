#include <stdio.h>

int main(){
    
    int R;
    double V;
    const double PI = 3.14159;

    scanf("%d", &R);

    V = (4.0/3.0 * PI * R * R * R);

    printf("VOLUME = %.3lf\n", V);

    return 0;
}
