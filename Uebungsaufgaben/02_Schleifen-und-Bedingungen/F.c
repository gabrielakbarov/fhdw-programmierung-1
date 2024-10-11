#include <stdio.h>

int main(void) {
    for(int i=0;i<127;i++){
        printf("%c",i);
        if(i%16==0){
          printf("\n");
        }
    }

    return 0;
}
