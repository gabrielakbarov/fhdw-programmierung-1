#include <stdio.h>

int function(int i) {
    if(i == 0) {
        return 1;
    }
    i *= function(i-1);
    return i;
}

int main(void) {
    for(int i = 1; i <= 6; i++) {
        printf("%d\n", function(i));
    }
    return 0;
}