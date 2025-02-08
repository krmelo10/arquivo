#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define INF LLONG_MAX

long long minimo(long long a, long long b) {
    return a < b ? a : b;
}

void floyd_warshall(long long **grafo, int n) {
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (grafo[i][k] != INF && grafo[k][j] != INF)
                    grafo[i][j] = minimo(grafo[i][j], grafo[i][k] + grafo[k][j]);
}

long long **alocar_grafo(int n) {
    long long **grafo = malloc((n + 1) * sizeof(long long *));
    for (int i = 1; i <= n; ++i) {
        grafo[i] = malloc((n + 1) * sizeof(long long));
        for (int j = 1; j <= n; ++j)
            grafo[i][j] = INF;
    }
    return grafo;
}

void liberar_grafo(long long **grafo, int n) {
    for (int i = 1; i <= n; ++i)
        free(grafo[i]);
    free(grafo);
}

int main(void) {
    int n, e;

    while (scanf("%d %d", &n, &e) == 2 && (n || e)) {
        long long **grafo = alocar_grafo(n);

        for (int i = 0; i < e; ++i) {
            int x, y, h;
            scanf("%d %d %d", &x, &y, &h);
            grafo[x][y] = h;
        }

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (grafo[i][j] != INF && grafo[j][i] != INF)
                    grafo[i][j] = grafo[j][i] = 0;

        floyd_warshall(grafo, n);

        int k;
        scanf("%d", &k);
        for (int i = 0; i < k; ++i) {
            int origem, destino;
            scanf("%d %d", &origem, &destino);
            if (grafo[origem][destino] == INF)
                printf("Nao e possivel entregar a carta\n");
            else
                printf("%lld\n", grafo[origem][destino]);
        }
        printf("\n");

        liberar_grafo(grafo, n);
    }

    return 0;
}
