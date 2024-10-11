#include <stdio.h>

int main(void) {

    int n, i = 0, binaryArray[32], rest;

    printf("Gib eine Zahl ein:");
    scanf("%i", &n);

    while (n > 0) {
        rest = n % 2;
        binaryArray[i] = rest;
        n /= 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%i", binaryArray[j]);
    }

    printf("\n");
    return 0;
}