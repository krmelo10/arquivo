#include <stdio.h>

int main() {
    int a, b, carry, resposta;

    while (scanf("%d %d", &a, &b) && (a || b)) {
        carry = resposta = 0;

        while (a || b) {
            int soma = (a % 10) + (b % 10) + carry;
            carry = soma > 9 ? 1 : 0;
            resposta += carry;
            a /= 10;
            b /= 10;
        }

        if (resposta == 0)
            printf("No carry operation.\n");
        else
            printf("%d carry operation%s.\n", resposta, resposta > 1 ? "s" : "");
    }

    return 0;
}
