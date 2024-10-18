#include <stdio.h>
int static sum = 0;

int summieren(int i) {
    return sum += i;
}

int main(void) {
    for(int i = 3; i <= 6; i++) {
        printf("%i: %i\n", i, summieren(i));
    }

    return 0;
}