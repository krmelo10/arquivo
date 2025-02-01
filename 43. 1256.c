#include <stdio.h>
#include <stdlib.h>

//estrutura para os nós das listas encadeadas
typedef struct no {
    int chave;
    struct no* seg;
} no;

//estrutura para a tabela hash
typedef struct {
    int tam;
    no** tabela; //vetor de ponteiros para listas encadeadas
} tabelahash;

// função para criar uma tabela hash
tabelahash* criartabela(int tam) {
    tabelahash* novatabela = malloc(sizeof(tabelahash));
    novatabela->tam = tam;
    novatabela->tabela = malloc(tam * sizeof(no*));
    
    for (int i = 0; i < tam; i++)
        //inicializa todas as listas como vazias
        novatabela->tabela[i] = NULL;
    
    return novatabela;
}

//função de dispersão (hash function)
int funcaohash(int chave, int tam) {
    return chave % tam;
}

//função para inserir uma chave na tabela hash
void inserir(tabelahash* tabela, int chave) {
    int indice = funcaohash(chave, tabela->tam);
    
    //cria um novo nó
    no* novono = (no*)malloc(sizeof(no));
    novono->chave = chave;
    novono->seg = tabela->tabela[indice]; // insere no início da lista
    tabela->tabela[indice] = novono;
}

//função para imprimir a tabela hash
void imprimetabela(tabelahash* tabela) {
    for (int i = 0; i < tabela->tam; i++) {
        printf("%d:", i);
        no* atual = tabela->tabela[i];
        while (atual != NULL) {
            printf(" -> %d", atual->chave);
            atual = atual->seg;
        }
        printf(" \n");
    }
}

//função para liberar a memória da tabela hash
void freetabela(tabelahash* tabela) {
    for (int i = 0; i < tabela->tam; i++) {
        no* atual = tabela->tabela[i];
        while (atual != NULL) {
            no* temp = atual;
            atual = atual->seg;
            free(temp);
        }
    }
    free(tabela->tabela);
    free(tabela);
}

int main() {
    //N = casos de teste. M = tamanho da tabela. C = número de chaves.
    int N; //número de casos de teste
    scanf("%d", &N);
    
    for (int t = 0; t < N; t++) {
        if (t > 0) printf("\n"); //linha em branco entre os testes
        
        int M, C;
        scanf("%d %d", &M, &C);
        
        tabelahash* tabela = criartabela(M);
        
        for (int i = 0; i < C; i++) {
            int chave;
            scanf("%d", &chave);
            inserir(tabela, chave);
        }
        
        imprimetabela(tabela);
        freetabela(tabela);
    }
    
    return 0;
}
