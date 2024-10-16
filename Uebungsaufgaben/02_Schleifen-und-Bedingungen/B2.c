#include <stdio.h>
void output(int n) {
    for (int i = 0; i < n; i++) {
        int limit = i <= n / 2 ? i : n - i - 1;

        for (int j = 0; j < limit; j++) {
            printf("+");
        }

        printf(i <= n / 2 ? "A" : "B");

        for (int j = 0; j < n - 2 * limit - 2; j++) {
            printf("+");
        }

        if (i != n / 2) {
            printf(i <= n / 2 ? "B" : "A");
        }

        for (int j = 0; j < limit; j++) {
            printf("+");
        }

        printf("\n");
    }
}

int main(void) {
    int n;
    printf("Bitte gib eine Zahl ein:");
    scanf(" %i", &n);

    output(n);

    return 0;
}