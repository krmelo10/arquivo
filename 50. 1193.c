#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int valor(char simbolo) {
    return isalpha(simbolo) ? simbolo - 'a' + 10 : simbolo - '0';
}

char simbolo(int valor) {
    return valor > 9 ? valor - 10 + 'a' : valor + '0';
}

int converteParaDecimal(char *numero, int base) {
    int resposta = 0;
    for (int i = strlen(numero) - 1, potencia = 1; i >= 0; --i, potencia *= base)
        resposta += valor(numero[i]) * potencia;
    return resposta;
}

char *converteDeDecimal(int decimal, int base) {
    if (decimal == 0) return "0";
    
    char *numero = (char *)malloc(33 * sizeof(char)); // Espaço para até 32 bits e o '\0'
    int posicao = 0;

    while (decimal > 0) {
        numero[posicao++] = simbolo(decimal % base);
        decimal /= base;
    }

    for (int i = 0; i < posicao / 2; ++i) {
        char temp = numero[i];
        numero[i] = numero[posicao - i - 1];
        numero[posicao - i - 1] = temp;
    }
    numero[posicao] = '\0';

    return numero;
}

int main(void) {
    int N;
    char numero[100], base[100];

    scanf("%d", &N);
    for (int k = 1; k <= N; ++k) {
        scanf("%s %s", numero, base);
        int dec = 0;
        char *hex, *bin;

        printf("Case %d:\n", k);

        if (strcmp(base, "bin") == 0) {
            dec = converteParaDecimal(numero, 2);
            hex = converteDeDecimal(dec, 16);
            printf("%d dec\n%s hex\n", dec, hex);
            free(hex);
        } else if (strcmp(base, "dec") == 0) {
            dec = converteParaDecimal(numero, 10);
            hex = converteDeDecimal(dec, 16);
            bin = converteDeDecimal(dec, 2);
            printf("%s hex\n%s bin\n", hex, bin);
            free(hex);
            free(bin);
        } else if (strcmp(base, "hex") == 0) {
            dec = converteParaDecimal(numero, 16);
            bin = converteDeDecimal(dec, 2);
            printf("%d dec\n%s bin\n", dec, bin);
            free(bin);
        }
        printf("\n");
    }
    return 0;
}
