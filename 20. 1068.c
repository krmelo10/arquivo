//balanço de parênteses II

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

int parentesesII(char s[]){
  int n = strlen(s);
  int *p = malloc(n * sizeof(char));
  int t = 0;

  for(int z = 0; z < n; z++){
    switch(s[z]){
      case '(':
       p[t++] = '(';
       break;
      case ')':
        //se houver abertos na pilha, t será > 0
        if (t > 0)
         //havendo abertos na pilha, decremente t (retire um aberto da pilha) a cada fechado que encontrar.
         --t;
        else
         //se ainda houver fechados na string, mas t não é maior que zero, não há como ter correspondentes. então, unbalanced.
         return 0;
        break;
     }
    }
  free(p);
  return t == 0;
}

int main(){

 char s[MAX];
 fgets(s, sizeof(s), stdin);
 s[strcspn(s, "\n")] = '\0';
 
 if (parentesesII(s)) {
  printf("balanced.\n");
 } else
    printf("unbalanced.\n");
 
 return 0;
}
