#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct no {
  char nome[MAX];
  struct no *seg;
}no;

//função cria nós (caixinhas onde serão armazenados os nomes);

no* criano(char nome[]){
  no *novo = malloc(sizeof(no));
if(novo != NULL){
  strcpy(novo->nome, nome);
  novo->seg = NULL;
  }
return novo;
}

//função que adiciona o nó (recém criado) no final da lista
void adfinal(no **head, char nome[]){
  no *novo = criano(nome);
  if(*head == NULL){
  *head = novo;
  return;
  }
  no *temp = *head;
  while(temp->seg != NULL){
    temp = temp->seg;
  }
  temp->seg = novo;
}

//função para imprimir a lista (nó por nó)
void print(no* head){
  no *temp = head;
  while(temp != NULL){
    printf("%s ", temp->nome);
    temp = temp->seg;
  }
printf("\n");
}

//função para adicionar a nova lista antes do nome do amigo indicado.
void adantes(no **head, char indicado[], no *nova){
  no *temp = *head;
  no *prev = NULL;

  //caso especial: se o nome do amigo indicado estiver no primeiro nó. 
  if(temp != NULL && strcmp(temp->nome, indicado) == 0){
    no *ultimo = nova;
    while(ultimo->seg != NULL){
      ultimo = ultimo->seg;
    }
    ultimo->seg = *head;
    *head = nova;
    return;
  }
  
  //percorre a lista para encontrar o nó do amigo indicado;
  while (temp != NULL){
    prev = temp;
    temp = temp->seg;
  }

    //caso o nó seja encontrado;
    if (temp != NULL){
      no *ultimo = nova;
      while(ultimo->seg != NULL){
        ultimo = ultimo->seg;
      }
      prev->seg = nova;
      ultimo->seg = temp;
    }
}

    int main(){
      char atual[MAX * 10];
      char nova[MAX * 10];
      char indicado[MAX];
      no *head = NULL;
      no *novahead = NULL;

      //leitura da lista atual
      fgets(atual, sizeof(atual), stdin);
      atual[strlen(atual) - 1] = '\0';

      //adicionando os amigos na lista atual
      char *token = strtok(atual, " ");
      while (token != NULL){
        adfinal(&head, token);
        token = strtok(NULL, " ");
      }

      //leitura da nova lista;
      fgets(nova, sizeof(nova), stdin);
      nova[strlen(nova) - 1] = '\0';

      //adicionando os novos amigos na nova lista
      token = strtok(nova, " ");
      while(token != NULL){
        adfinal(&novahead, token);
        token = strtok(NULL, " ");
      }

      //leitura do amigo indicado
      fgets(indicado, sizeof(indicado), stdin);
      indicado[strlen(indicado) - 1] = '\0';

      //verificando onde inserir a lista baseado no amigo indicado
      if(strcmp(indicado, "nao") == 0){
        no *temp = head;
        while(temp->seg != NULL){
          temp = temp->seg;
        }
        temp->seg = novahead;
      }
      else{
        adantes(&head, indicado, novahead);
      }

      //imprimindo a lista
      print(head);

      return 0;
}
