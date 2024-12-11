#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//gera um vetor aleatório
void vrandom(int *elemento, int tam) {
    for (int i = 0; i < tam; i++) {
        elemento[i] = rand();
    }
}

//ordena
void insertion_sort(int *elemento, int tam) {
    for (int i = 1; i < tam; i++) {
        int temp = elemento[i];
        int j = i - 1;
        while (j >= 0 && elemento[j] > temp) {
            elemento[j + 1] = elemento[j];
            j--;
        }
        elemento[j + 1] = temp;
    }
}

int main() {
    int tam = 100000;
    int *elemento = (int *)malloc(tam * sizeof(int));

    vrandom(elemento, tam);

    clock_t start = clock();
    insertion_sort(elemento, tam);
    clock_t end = clock();
    printf("tempo de execução: %f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(elemento);

    return 0;
}
