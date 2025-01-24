#include <stdio.h>

int main()
{
    int V, T;

    while (scanf("%d %d", &V, &T) != EOF)
    {
        printf("%d\n", V * 2 * T);
    }

    return 0;
}
