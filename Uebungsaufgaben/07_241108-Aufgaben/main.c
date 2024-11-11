#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct adress {
  int isUsed;
  char street[100];
  int number;
  char city[100];
  int postalCode;
};

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

void setAddress(struct adress* arr, int pos, char* street, int number, char* city, int postalCode)
{
  arr[pos].isUsed = 1;
  strcpy(arr[pos].street, street);
  arr[pos].number = number;
  strcpy(arr[pos].city, city);
  arr[pos].postalCode = postalCode;
}

void printAddress(struct adress* arr, int pos)
{
  printf("Die Adresse an Position %i lautet: %s %i, %i %s\n", pos+1, arr[pos].street, arr[pos].number, arr[pos].postalCode, arr[pos].city);
}

void printAllAdds(struct adress* arr)
{
  for(int i = 0; i < 100; i++)
  {
    printAddress(arr, i);
  }
}

void printAddsAtPostalCode(struct adress* arr, int postalCode)
{
  for(int i = 0; i < 100; i++)
  {
    if(arr[i].postalCode == postalCode)
    {
      printAddress(arr, i);
    }
  }
}

void deleteAddsAtPostalCode(struct adress* arr, int postalCode)
{
  for(int i = 0; i < 100; i++)
  {
    if(arr[i].postalCode == postalCode)
    {
      arr[i].isUsed = 0;
      strcpy(arr[i].street, "");
      arr[i].number = 0;
      strcpy(arr[i].city, "");
      arr[i].postalCode = 0;
    }
  }
}

int countAdds(struct adress* arr)
{
  int count = 0;

  for(int i = 0; i < 100; i++)
  {
    if(arr[i].isUsed != 0)
    {
      count++;
    }
  }

  return count;
}

int checkIfUsed(struct adress* arr, int pos)
{
  return arr[pos].isUsed;
}

void printIfUsed(struct adress* arr, int pos)
{
  if(checkIfUsed(arr, pos) == 1)
  {
    printf("Adresse an der Stelle %i ist belegt.\n", pos+1);
  }else
  {
    printf("Adresse an der Stelle %i ist nicht belegt.\n", pos+1);
  }
}

void swap(struct adress* arr, int pos1, int pos2)
{
  struct adress temp;
  temp = arr[pos1];
  arr[pos1] = arr[pos2];
  arr[pos2] = temp;
}

void deleteAllAdds(struct adress* arr)
{
  for(int i = 0; i < 100; i++)
  {
    arr[i].isUsed = 0;
    strcpy(arr[i].street, "");
    arr[i].number = 0;
    strcpy(arr[i].city, "");
    arr[i].postalCode = 0;
  }
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

  printf("\n");
  struct adress add1 = {1,"Hauptstrasse", 23, "Paderborn", 33100};
  printf("1. Adresse: %s %i, %i %s\n", add1.street, add1.number, add1.postalCode, add1.city);

  struct adress adds[100] = {0};
  setAddress(&adds, 10, "Mistelweg", 12, "Paderborn", 33100);
  printf("11. Adresse: %s %i, %i %s\n", adds[10].street, adds[10].number, adds[10].postalCode, adds[10].city);

  setAddress(&adds, 11, "Mistelweg", 12, "Paderborn", 33101);
  setAddress(&adds, 12, "Mistelweg", 12, "Paderborn", 33100);
  printf("\n");
  printAddress(adds, 1);
  printAddress(adds, 10);
  printf("\n");
  //printAllAdds(adds);
  printf("Aktuell sind %i Adressen gespeichert.\n", countAdds(adds));
  printIfUsed(adds, 10);
  printAddsAtPostalCode(adds, 33100);
  deleteAddsAtPostalCode(adds, 33100);

  printf("\n");
  printf("Aktuell sind %i Adressen gespeichert.\n", countAdds(adds));
  printAddsAtPostalCode(adds, 33101);
  deleteAddsAtPostalCode(adds, 33101);
  printf("Aktuell sind %i Adressen gespeichert.\n", countAdds(adds));
  printIfUsed(adds, 10);

  printf("\n");

  setAddress(adds, 11, "Mistelweg", 12, "Paderborn", 33133);
  setAddress(adds, 12, "Weg", 12, "Münster", 33133);
  printAddsAtPostalCode(adds, 33133);
  swap(adds, 11, 12);
  printAddsAtPostalCode(adds, 33133);

  printf("\n");

  deleteAllAdds(adds);
  printf("Alle Adressen wurden gelöscht.");
  printAddsAtPostalCode(adds, 33100);
  printAddsAtPostalCode(adds, 33101);
  printAddsAtPostalCode(adds, 33133);

  printf("\n");
  printf("\n");

  return 0;
}