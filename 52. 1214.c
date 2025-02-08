#include <stdio.h>

int main() {
    int C, N, alunos[1000];
    double media, resposta;

    scanf("%d", &C);

    while (C--) {
        scanf("%d", &N);

        media = 0.0;
        for (int i = 0; i < N; ++i) {
            scanf("%d", &alunos[i]);
            media += alunos[i];
        }

        media /= N;
        resposta = 0;
        for (int i = 0; i < N; ++i)
            if (alunos[i] > media)
                resposta++;

        resposta = (resposta / N) * 100;
        printf("%.3lf%%\n", resposta);
    }

    return 0;
}
