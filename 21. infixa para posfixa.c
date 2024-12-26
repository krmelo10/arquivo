#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *intopos(char infixa[]) {
    int n = strlen(infixa);
    char *posfixa = malloc(n * sizeof(char)); //guarda a tradução final
    char *p = malloc(n * sizeof(char)); //pilha
    int x; //variável temporária
    int t = 0; //topo da pilha
    int i, j;

    p[t++] = '('; //empilha '(' para facilitar o controle
    strcat(infixa, ")"); //adiciona ')' ao final da expressão para completar o processamento

    for (j = 0, i = 0; infixa[i] != '\0'; i++) {
        switch (infixa[i]) {
            case '(':
                p[t++] = infixa[i]; //empilha '('
                break;
            case ')':
                while (1) {
                    x = p[--t]; //desempilha
                    if (x == '(')
                        break; //para quando encontra '('
                    posfixa[j++] = x; //adiciona operador à saída pós-fixa
                }
                break;
            case '+':
            case '-':
                while (1) {
                    x = p[t - 1]; //pega o operador no topo da pilha
                    if (x == '(')
                        break; //para ao encontrar '('
                    --t; //desempilha
                    posfixa[j++] = x; //adiciona operador à saída pós-fixa
                }
                p[t++] = infixa[i]; //empilha o operador atual
                break;
            case '*':
            case '/':
                while (1) {
                    x = p[t - 1]; //pega o operador no topo da pilha
                    if (x == '(' || x == '+' || x == '-')
                        break; //para ao encontrar '(' ou operadores de menor precedência
                    --t; //desempilha
                    posfixa[j++] = x; //adiciona operador à saída pós-fixa
                }
                p[t++] = infixa[i]; //empilha o operador atual
                break;
            default:
                posfixa[j++] = infixa[i]; //adiciona operandos diretamente na saída
        }
    }

    free(p);
    posfixa[j] = '\0'; //finaliza a string pós-fixa.
    return posfixa;
}

int main() {
    char infixa[100];

    printf("infixa: "); 
    fgets(infixa, sizeof(infixa), stdin);
    infixa[strcspn(infixa, "\n")] = '\0'; 

    char *posfixa = intopos(infixa);

    printf("pós-fixa: %s\n", posfixa); 

    free(posfixa); 

    return 0;
}
