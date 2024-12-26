#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int num;
    struct no *seg;
}no;

//(push) empilha um valor na pilha
void push(no **topo, int num) {
    no *novo = malloc(sizeof(no));
    novo->num = num;
    novo->seg = *topo;
    *topo = novo;
}

//(pop) desempilha um valor da pilha
int pop(no **topo) {
    if (*topo == NULL) 
        //pilha vazia
        return -1;
    no *temp = *topo;
    int num = temp->num;
    *topo = temp->seg;
    free(temp);
    return num;
}

//inverte a pilha (simula fila com pilhas)
void inverte_pilha(no **topo) {
    no *invertida = NULL;
    while (*topo != NULL) {
        push(&invertida, pop(topo));
    }
    *topo = invertida;
}

//processa o problema
void processa_cartas(int n) {
    no *pilha = NULL;

    //preenche a pilha com os números de 1 a n
    for (int i = n; i >= 1; i--) {
        push(&pilha, i);
    }

    //inverte a pilha para simular uma fila
    inverte_pilha(&pilha);

    //armazena as cartas descartadas
    int descartadas[n];
    int indice_descartadas = 0;

    //processamento das cartas
    while (pilha != NULL && pilha->seg != NULL) {
        //descarta a carta do topo
        descartadas[indice_descartadas++] = pop(&pilha);

        //move a próxima carta para o final
        int carta = pop(&pilha);
        inverte_pilha(&pilha);
        push(&pilha, carta);
        inverte_pilha(&pilha);
    }

    //saída: cartas descartadas
    printf("cartas descartadas: ");
    for (int i = 0; i < indice_descartadas; i++) {
        printf("%d", descartadas[i]);
        if (i < indice_descartadas - 1) {
            printf(", ");
        }
    }
    printf("\n");

    //saída: carta restante
    printf("carta restante: %d\n", pop(&pilha));
}

int main() {
    int n;

    while (1) {
        scanf("%d", &n);
        if (n == 0) 
            break;
        processa_cartas(n);
    }

    return 0;
}
