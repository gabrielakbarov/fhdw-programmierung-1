#include <stdio.h>
int static sum = 0;

int summieren(int i) {
    return sum += i;
}

int main(void) {
    printf("%i: %i\n", 3, summieren(3));
    printf("%i: %i\n", 4, summieren(4));
    printf("%i: %i\n", 5, summieren(5));
    printf("%i: %i\n", 6, summieren(6));

    return 0;
}