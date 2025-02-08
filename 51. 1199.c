#include <stdio.h>
#include <string.h>

int main() {
    int numero;
    char entrada[100];

    while (scanf("%s", entrada) && strcmp(entrada, "-1") != 0) {
        if (entrada[1] == 'x') {
            sscanf(entrada, "%x", &numero);
            printf("%d\n", numero);
        } else {
            sscanf(entrada, "%d", &numero);
            printf("0x%X\n", numero);
        }
    }

    return 0;
}
