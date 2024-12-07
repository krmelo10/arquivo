//balanço de parênteses
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

int parenthesis(char s[]){
 int n = strlen(s);
 int *p = malloc(n * sizeof(char));
 int t = 0;

 for (int z = 0; z < n; z++){
  if(s[z] == '(')
   //se é um parênteses aberto, adiciona à pilha
   p[t++] = '(';
  //se é um parênteses fechado
  else if (s[z] == ')') {
   //verifico se a pilha está vazia,
   //se estiver vazia (ao mesmo tempo que encontrar um parênteses fechado): sentença má balanceada
   if (t == 0){
    free(p);
    return 0;
   }
   //se encontrar um fechado e não entrar no if é porque há um correspondente aberto na pilha;
   //esse correspondente aberto será retirado da pilha.
   --t;
  }
 }
 return t == 0;
}

int main(){

 char s[MAX];
 fgets(s, sizeof(s), stdin);
 s[strcspn(s, "\n")] = '\0';
 
 if (parenthesis(s)) {
  printf("the string is balanced.\n");
 } else
    printf("the string is not balanced.\n");
 
 return 0;
}
