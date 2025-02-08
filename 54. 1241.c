#include <stdio.h>
#include <string.h>

#define TAM 1000

int main() {
    int n;
    char a[TAM], b[TAM];

    scanf("%d", &n);

    while (n--) {
        scanf(" %s %s", a, b);

        if (strlen(b) > strlen(a)) {
            printf("nao encaixa\n");
        } else if (strcmp(a + strlen(a) - strlen(b), b) == 0) {
            printf("encaixa\n");
        } else {
            printf("nao encaixa\n");
        }
    }

    return 0;
}
