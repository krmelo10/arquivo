#include <stdio.h>
#include <string.h>

int main() {
    char a[50], b[13];
    int m;

    scanf("%d", &m);
    while (m--) {
        int j = 0;
        getchar();  // para consumir o '\n' após o número
        fgets(a, sizeof(a), stdin);
        
        for (int i = 0; a[i] != '\0' && j < 12; i++) {
            if (a[i] == ' ') continue;

            switch (a[i]) {
                case 'G': case 'Q': case 'a': case 'k': case 'u': b[j++] = '0'; break;
                case 'I': case 'S': case 'b': case 'l': case 'v': b[j++] = '1'; break;
                case 'E': case 'O': case 'Y': case 'c': case 'm': case 'w': b[j++] = '2'; break;
                case 'F': case 'P': case 'Z': case 'd': case 'n': case 'x': b[j++] = '3'; break;
                case 'J': case 'T': case 'e': case 'o': case 'y': b[j++] = '4'; break;
                case 'D': case 'N': case 'X': case 'f': case 'p': case 'z': b[j++] = '5'; break;
                case 'A': case 'K': case 'U': case 'g': case 'q': b[j++] = '6'; break;
                case 'C': case 'M': case 'W': case 'h': case 'r': b[j++] = '7'; break;
                case 'B': case 'L': case 'V': case 'i': case 's': b[j++] = '8'; break;
                case 'H': case 'R': case 'j': case 't': b[j++] = '9'; break;
            }
        }

        for (int i = 0; i < 12; i++) {
            printf("%c", b[i]);
            if (i == 11) printf("\n");
        }
    }

    return 0;
}
