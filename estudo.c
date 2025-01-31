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

