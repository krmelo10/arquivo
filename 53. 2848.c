#include <stdio.h>
#include <stdlib.h>

int contNum(int vet[], int tamVet, int num);
void selection(int vet[], int tamVet);
void copiaVetor(int vetOrig[], int vetDest[], int limInf, int tamVetDest);
void leVetor(int vet[], int tamVet);

int main() {
    int tamVet, rodadas;
    int limInf, limSup, kMenor, guga, dabriel;
    int *vet, *intervalo;

    scanf("%d %d", &tamVet, &rodadas);
    vet = (int*) malloc(tamVet * sizeof(int));
    leVetor(vet, tamVet);
    
    while (rodadas--) {
        scanf("%d %d %d %d %d", &limInf, &limSup, &kMenor, &guga, &dabriel);

        int tamIntervalo = limSup - limInf + 1;
        intervalo = (int*) malloc(tamIntervalo * sizeof(int));
        copiaVetor(vet, intervalo, limInf - 1, tamIntervalo);

        selection(intervalo, tamIntervalo);
        int menor = intervalo[kMenor - 1];
        int contKEsimo = contNum(intervalo, tamIntervalo, menor);

        char result = (abs(contKEsimo - guga) < abs(contKEsimo - dabriel)) ? 'G' : 
                      (abs(contKEsimo - dabriel) < abs(contKEsimo - guga)) ? 'D' : 'E';

        printf("%d %d %c\n", menor, contKEsimo, result);
        free(intervalo);
    }

    free(vet);
    return 0;
}

int contNum(int vet[], int tamVet, int num) {
    int cont = 0;
    for (int i = 0; i < tamVet; i++) {
        if (vet[i] == num) cont++;
    }
    return cont;
}

void selection(int vet[], int tamVet) {
    for (int i = 0; i < tamVet - 1; i++) {
        int min = i;
        for (int j = i + 1; j < tamVet; j++) {
            if (vet[j] < vet[min]) min = j;
        }
        int aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
    }
}

void copiaVetor(int vetOrig[], int vetDest[], int limInf, int tamVetDest) {
    for (int i = 0; i < tamVetDest; i++) {
        vetDest[i] = vetOrig[limInf + i];
    }
}

void leVetor(int vet[], int tamVet) {
    for (int i = 0; i < tamVet; i++) {
        scanf("%d", &vet[i]);
    }
}
