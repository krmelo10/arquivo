#include <stdio.h>

long long int f[21] = {1};

long long int fatorial(int n) {
    if (!f[n])
        f[n] = n * fatorial(n - 1);
    return f[n];
}

int main() {
    int m, n;
    while (scanf("%d %d", &m, &n) != EOF)
        printf("%lld\n", fatorial(m) + fatorial(n));
    return 0;
}
