#include <stdio.h>
#include <string.h>

#define MAX 50

int main(void) {
    int grafo[MAX][MAX];
    int T;

    scanf("%d", &T);

    while (T--) {
        int X, n, m;
        scanf("%d %d %d", &X, &n, &m);

        memset(grafo, 0, sizeof(grafo));

        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            grafo[u][v] = grafo[v][u] = 1;
        }

        int resposta = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                resposta += grafo[i][j];
            }
        }

        printf("%d\n", resposta * 2);
    }

    return 0;
}
