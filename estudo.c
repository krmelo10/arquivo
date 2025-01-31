#include <stdio.h>
#include <stdlib.h>

//as listas relacionadas ao hashtable
typedef struct no {
  int chave;
  struct no *seg;
} no;

//hashtable
typedef struct hashtable {
  int tam;
  no **tabela;
} hashtable;

hashtable *criatabela(int tam){
  hashtable *novatabela = malloc(sizeof(hashtable));
  novatabela->tam = tam;
  novatabela->tabela = malloc(tam * sizeof(no*));

  for(int i = 0; i < tam; i++)
    novatabela->tabela[i] = NULL;

  return novatabela;
}

hashtable
