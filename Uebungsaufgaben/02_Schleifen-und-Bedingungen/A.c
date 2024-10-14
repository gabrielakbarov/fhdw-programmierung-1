#include <stdio.h>

int main(void) {
    long int n = 1;
    long double e = 1;
    int lim = 10;

    for (int i = 1; i <= lim; i++) {
        n *= i;
        e += (1.0L / n);
    }

    printf("e = %Lf", e);
    return 0;
}