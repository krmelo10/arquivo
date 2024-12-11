#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 

//gera um vetor aleatório
void vrandom(int *elemento, int tam) {
    for (int i = 0; i < tam; i++) {
        elemento[i] = rand();
    }
}

//função separa para o quicksort
int separa(int p, int r, int v[]) {
    int pivo = v[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (v[j] <= pivo) {
            i++;
            //troca v[i] com v[j]
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    //troca v[i+1] com v[r]
    int temp = v[i + 1];
    v[i + 1] = v[r];
    v[r] = temp;
    return i + 1;
}

//implementação do quicksort
void quicksort(int p, int r, int v[]) {
    int j;
    if (p < r) {
        j = separa(p, r, v);
        quicksort(p, j - 1, v); //ordena a parte esquerda
        quicksort(j + 1, r, v); //ordena a parte direita
    }
}

int main() {
    int tam = 8;
    int *elemento = (int *)malloc(tam * sizeof(int));

    if (elemento == NULL) {
        printf("erro ao alocar memória\n");
        return 1;
    }

    vrandom(elemento, tam);

    clock_t start = clock(); //marca o início do tempo
    quicksort(0, tam - 1, elemento);
    clock_t end = clock(); //marca o final do tempo

    printf("tempo de execução: %f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(elemento);

    return 0;
}
