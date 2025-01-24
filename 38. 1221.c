#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int crivo(int *c, int *primos, int n)
{
    int p = 0;
  
    for (int i = 0; i < n; ++i){
        c[i] = 1;
    }
    c[1] = 0;
    primos[p++] = 2;

    for (int i = 4; i < n; i += 2){
        c[i] = 0;
    }

    for (int i = 3; i < n; i += 2){
        if (c[i] == 1){
            primos[p++] = i;
            for (int j = i * 3; j < n; j += 2 * i){
                c[j] = 0;
            }
        }
    }
    return p;
}

int vprimo(int *primos, int p, int n)
{
    int lim = sqrt(n) + 1;

    for (int i = 0; i < p && primos[i] < lim; ++i){
        if (n % primos[i] == 0){
            if (n == primos[i])
                return 1;
            return 0;
        }
    }
    return 1;
}

int main()
{
    int N, X, numprimos, c[65536], primos[65536];

    numprimos = crivo(c, primos, 65536);

    scanf("%d", &N);

    for (int i = 0; i < N; ++i){
        scanf("%d", &X);
        printf("%s\n", vprimo(primos, numprimos, X) ? "primo" : "não primo");
    }

    return 0;
}
