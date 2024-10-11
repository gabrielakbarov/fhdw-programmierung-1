#include <stdio.h>

int main(void) {
    int n;
    printf("Bitte gib eine Zahl zwischen 1 und 10 ein:");
    scanf(" %i", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            printf("+");
        }
        printf("o");
        for (int k = 1; k < i; k++) {
            printf("+");
        }
        printf("\n");
    }
    return 0;
}