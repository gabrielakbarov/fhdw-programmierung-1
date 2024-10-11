#include <stdio.h>

int main(void) {
    for(int i=0;i<26;i++){
      switch(i+97){
          case 'a':
          case 'e':
          case 'i':
          case 'o':
          case 'u':
              printf("%c",i+65);
              break;
          default:
              printf("%c",i+97);
      }
      printf("\n");
    }
    return 0;
}