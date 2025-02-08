#include <stdio.h>
#include <string.h>

#define MAX 1000000

int minimos[MAX];

int main() {
    char operacao[5];
    int N, V, p = -1;

    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%s", operacao);

        if (strcmp(operacao, "PUSH") == 0) {
            scanf("%d", &V);
            minimos[++p] = (p == 0) ? V : (V < minimos[p - 1] ? V : minimos[p - 1]);
        } else if (strcmp(operacao, "POP") == 0) {
            if (p == -1) {
                printf("EMPTY\n");
            } else {
                --p;
            }
        } else if (strcmp(operacao, "MIN") == 0) {
            if (p == -1) {
                printf("EMPTY\n");
            } else {
                printf("%d\n", minimos[p]);
            }
        }
    }

    return 0;
}
