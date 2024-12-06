#include <stdio.h>
#include <string.h>

#define MAX 1000

void inverte(char *palavra) {
    int t = 0;
    char pilha[MAX];

    while (palavra[t] != '\0')
        pilha[t++] = palavra[t];
    t--;

    while (t >= 0)
        printf("%c", pilha[t--]);
}

int main() {
    char frase[MAX];
    char palavra[MAX];
    int j = 0;

    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';

    int i = 0;
    int primeiro = 1;

    while (frase[i] != '\0') {
        if (frase[i] != ' ') {
            palavra[j++] = frase[i];
        } 
        else {
            palavra[j] = '\0';
            if (!primeiro) {
                printf(" ");
            }
            inverte(palavra);
            primeiro = 0;
            j = 0;
        }
        i++;
    }

    palavra[j] = '\0';
    if (!primeiro) {
        printf(" ");
    }
    inverter_palavra(palavra);

    return 0;
}
