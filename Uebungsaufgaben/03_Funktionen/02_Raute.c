#include <stdio.h>

void output(int n) {
    int m = 0;

    for (int i = 1; i <= n*2-1; i++) {
        if (i <= n) {
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
}

int main(void) {
    int n;
    printf("Bitte gib eine Zahl zwischen 1 und 10 ein:");
    scanf(" %i", &n);

    output(n);
    output(n+3);
    output(n+5);

    return 0;
}