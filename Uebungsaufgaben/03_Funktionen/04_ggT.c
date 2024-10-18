#include <stdio.h>

int recursive(int a, int b) {
    if(a%b == 0) {
        return b;
    }else {
        return recursive(b, a%b);
    }
}

int iterative(int a, int b) {
    while(a%b != 0) {
        int c = b;
        b = a%b;
        a = c;
    }
    return b;
}

int main(void) {
    printf("%i\n", recursive(5, 10));
    printf("%i\n", recursive(7, 456));
    printf("%i\n", recursive(56, 56));

    printf("\n");

    printf("%i\n", iterative(5, 10));
    printf("%i\n", iterative(7, 456));
    printf("%i\n", iterative(56, 56));
    return 0;
}