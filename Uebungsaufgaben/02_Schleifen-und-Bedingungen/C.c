#include <stdio.h>

int main(void) {
    int n;
    printf("Bitte gib eine Zahl zwischen 1 und 10 ein:");
    scanf(" %i", &n);

    int m = 0;
    bool b = false;

    for (int i = 1; i <= n*2-1; i++) {
        if (m == n) {
            b = true;
        }
        if (!b) {
            m++;
        } else {
            m--;
        }

        for (int j = 1; j <= n - m; j++) {
            printf(" ");
        }

        for (int k = 1; k <= m * 2 - 1; k++) {
            printf("+");
        }

        for (int j = 1; j <= n - m; j++) {
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}