#include <stdio.h>

void copyString(char *von, char *nach)
{
    while(*von != '\0')
    {
        *nach = *von;
        nach++;
        von++;
    }
    *nach = '\0';

}

void swapString(char *a, char *b)
{
    char temp;
    while(*a != '\0' || *b != '\0')
    {
        temp = *a;
        *a = *b;
        *b = temp;
        a++;
        b++;
    }
}

void replaceCharInString(char *st, char a, char b)
{
    for(int i = 0; st[i] != '\0'; i++)
    {
        if(st[i] == a)
            st[i] = b;
    }
}

int strCountVocals(char *arr){
    int i = 0, vocals = 0;
    while(arr[i] != '\0'){
        switch(arr[i]){
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
        vocals++;
        }
        i++;
    }
    return vocals;
}

int strLen(char *arr){
    int i = 0;
    while(arr[i] != '\0'){
        i++;
    }
    return i;
}

void strRevert(char *arr){
    for(int i=strLen(arr); i > 0; i--){
        printf("%c", arr[i-1]);
    }
    printf("\n");
}

void strConcat(char *arr, char *str2, char *concat){
    int i = 0;
    int j = 0;
    while(arr[i] != '\0'){
        concat[i] = arr[i];
        i++;
    }
    while(str2[j] != '\0'){
        concat[i+j] = str2[j];
        j++;
    }
    concat[i+j] = '\0';
}

int main(void) {
    char von[50] = "Hallo";
    char nach[50] = "Welt";
    char concat[100];

    printf("\n");

    printf("Strings tauchen:\n");
    printf("Vorher: 1. '%s' 2. '%s'\n", von, nach);
    swapString(von, nach);
    printf("Nachher: 1. '%s' 2. '%s'\n", von, nach);

    printf("\n");

    printf("Vokale in einem String zählen:\n");
    printf("String 1: %i \nString 2: %i\n", strCountVocals(von), strCountVocals(nach));

    printf("\n");

    printf("String kopieren:\n");
    printf("Vorher: 1. '%s' 2. '%s'\n", von, nach);
    copyString(von, nach);
    printf("Nachher: 1. '%s' 2. '%s'\n", von, nach);

    printf("\n");

    printf("Character in einem String ersetzen:\n");
    printf("Vorher: 1. '%s' 2. '%s'\n", von, nach);
    replaceCharInString(von, 'a', 'A');
    replaceCharInString(von, 'e', 'E');
    replaceCharInString(von, 'l', 'L');
    replaceCharInString(von, 'W', 'w');
    printf("Nachher: 1. '%s' 2. '%s'\n", von, nach);

    printf("\n");

    printf("Laenge eines Strings ausgeben:\n");
    printf("Vorher: 1. '%s' 2. '%s'\n", von, nach);
    printf("String 1: %i\nString 2: %i \n", strLen(von), strLen(nach));
    printf("Nachher: 1. '%s' 2. '%s'\n", von, nach);

    printf("\n");

    printf("String umkehren:\n");
    printf("Vorher: 1. '%s' 2. '%s'\n", von, nach);
    strRevert(von);
    printf("Nachher: 1. '%s' 2. '%s'\n", von, nach);

    printf("\n");

    printf("Strings aneinanderhaengen:\n");
    printf("Vorher: 1. '%s' 2. '%s' 3. '%s'\n", von, nach, concat);
    strConcat(von, nach, concat);
    printf("Nachher: 1. '%s' 2. '%s' 3. '%s'\n", von, nach, concat);

    return 0;
}
