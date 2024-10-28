#include <stdio.h>

void strPrint(char arr[]) {
		printf("%s\n", arr);
}

int strLen(char arr[]){
	int i = 0; 
	while(arr[i] != '\0'){
		i++;
	}
	return i;
}

void strRevert(char arr[]){
	for(int i=strLen(arr); i >= 0; i--){
		printf("%c", arr[i]);
	}
	printf("\n");
}

int strCountVocals(char arr[]){
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

void strSwapChars(char arr[]){
	
}

void strConcat(char arr[], char str2[], char concat[]){
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
	printf("%s\n", concat);
}

int main(void) {
   char arr[5] = {'H', 'a','l','l','o'};
   char str2[4] = {'W', 'e', 'l', 't'};
   char concat[15];
   
   strPrint(arr);
   printf("Das Array hat %i Zeichen\n", strLen(arr));
   strRevert(arr);
   printf("%i Vokale\n", strCountVocals(arr));
   
   strConcat(arr, str2, concat);
   
   return 0;

}