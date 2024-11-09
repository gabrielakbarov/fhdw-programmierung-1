#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addTwoNumbers(int *a, int *b, int *c, int arrayLaenge) {
  for(int i = 0; i < arrayLaenge; i++){
    *c = *a + *b;
    a++;
    b++;
    c++;
  }
}

int countVocals(char* a)
{
  int count = 0;
  while(*a)
  {
    switch(*a)
    {
      case 'A':
      case 'a':
      case 'E':
      case 'e':
      case 'I':
      case 'i':
      case 'O':
      case 'o':
      case 'U':
      case 'u':
        count++;
        break;
    }
    a++;
  }
  return count;
}

void printIntArray(char arr, int *a, int arrayLaenge) {
  printf("%c: ", arr);
  for(int i = 0; i < arrayLaenge; i++){
    printf("%d ", *a);
    a++;
  }
  printf("\n");
}

int strLength(char* arr)
{
  int length = 0;
  while(*arr != '\0')
  {
    length++;
    arr++;
  }
  return length;
}

void replaceCharacter(char *s, char a, char b)
{
  while (*s) {
    if (*s == a)
      {
        *s = b;
      }
    s++;
  }
}

void changeCapitalization(char* s)
{
  while(*s)
  {
    if(*s >= 97 && *s <= 122)
    {
      *s -= 32;
    }
    else if(*s >= 65 && *s <= 90)
    {
      *s += 32;
    }
    s++;
  }
}

char* concat(char* a, char* b)
{
  char *p, *r;
  p = (char*) malloc(strLength(a) + strLength(b) + 1);
  r = p;
  while(*a)
  {
    *p = *a;
    p++;
    a++;
  }
  while(*b)
  {
    *p = *b;
    p++;
    b++;
  }
  *p = '\0';
  return r;
}

int substring(char* string, char* substring) {
  int count = 0;
  char* subP;
  char* strP;

  while (*string) {
    strP = string;
    subP = substring;
    while (*strP == *subP) {
      strP++;
      subP++;
      if (!*subP) {
        count++;
      }
    }
    string++;
  }
  return count;
}

char* compareStrings(char* a, char* b)
{
  char *p, *r;
  p = (char*) malloc(strLength(a) + 1);
  r = p;

  while(*a && *b)
  {
    if(*a != *b)
    {
      *p = *b;
      p++;
    }
    a++;
    b++;
  }
  return r;
}

char* stringRemoveChars(char* string, char* spanset)
{
  char *p;
  p = string;
  while(*spanset)
  {
    replaceCharacter(p, *spanset, ' ');
    spanset++;
  }
  return string;
}

int main(){
  int a[] = {1,2,3,4,5};
  int b[] = {6,7,8,9,10};
  int c[5];
  char d[] = "abcdeFGH";
  char e[] = "ABCDEFGH";
  char f[] = "HalloXwiexgehtxesxdir?X";
  char g[] = "Xx";
  char h[] = "ABCABCABC";
  char i[] = "ABC";

  addTwoNumbers(a,b,c,5);
  printf("Die entsprechenden Werte aus A und B werden addiert und in C gespeichert:\n");
  printIntArray('A', a,5);
  printIntArray('B',b,5);
  printIntArray('C',c,5);

  printf("\n");

  printf("'%s'\n", d);
  printf("Laenge des Arrays D: %i\n",strLength(d));
  printf("Vokale im Array D: %i\n",countVocals(d));
  printf("Wir tauschen einige Buchstaben und ändern die Groß- und Kleinschreibung: ");
  replaceCharacter(d, 'a', 'b');
  replaceCharacter(d, 'c', 'a');
  changeCapitalization(d);
  printf("'%s'\n", d);
  printf("Zwei Strings werden als ein neuer String zusammengesetzt: %s\n", concat(d, "abc"));
  printf("D: '%s'; E: '%s'; Unterschiede: '%s'\n", d, e, compareStrings(d, e));
  printf("%s\n", stringRemoveChars(f, g));
  printf("'ABC' kommt %i Mal in 'ABCABCABC' vor.", substring(h, i));
  printf("\n");

  return 0;
}