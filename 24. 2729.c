#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
#define ITEM 1001

typedef struct no{
  char item[MAX];
  struct no *seg;
}no;

//aloca nó.
no *criano(char item[]){
  no *novo = malloc(sizeof(no));
  if(novo != NULL){
    strcpy(novo->item, item);
    novo->seg = NULL;
    return novo;
  }
  return novo;
}

//inserção.
void insere(no **head, char item[]){
  no *novo = criano(item);
  if(*head == NULL){
    *head = novo;
    return;
  }
  no *aux = *head;
  while(aux != NULL){
    if(strcmp(aux->item, item) == 0){
      return;
    }
    aux = aux->seg;
  }
  no *temp = *head;
  while(temp->seg != NULL){
    temp = temp->seg;
  }
  temp->seg = novo;
}

//(bubble sort) ordenação por ordem alfabética.
void ordena(no *head){
  if(head == NULL)
    return;
  no *n, *m;
  char temp[MAX];

  for(n = head; n != NULL; n = n->seg){
    for(m = n->seg; m != NULL; m = m->seg){
      if(strcmp(n->item, m->item) > 0){
        strcpy(temp, n->item);
        strcpy(n->item, m->item);
        strcpy(m->item, temp);
      }
    }
  }
}

//printa a lista
void imprime(no *head){
  no *temp = head;
  while(temp != NULL){
    printf("%s ", temp->item);
    temp = temp->seg;
  }
  printf("\n");
}

int main(){
  int N;
  scanf("%d", &N);
  getchar();

  for(int n = 0; n < N; n++){
    no *lista = NULL;

    //leitura dos itens da lista de compras
    char linha[ITEM];
    fgets(linha, ITEM, stdin);
    linha[strcspn(linha, "\n")] = '\0';

    //divide a linha em palavras e as insere na lista
    char *item = strtok(linha, " ");
    while(item != NULL){
      insere(&lista, item);
      item = strtok(NULL, " \n");
    }
    
    ordena(lista);
    imprime(lista);
  }
  
  return 0;
}
