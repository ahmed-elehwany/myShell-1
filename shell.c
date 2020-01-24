// Muhammad Huzaifa Elahi
// 260726386

#include <stdio.h>
#include <stdlib.h>

int parse(char string[]); // function declarations

int main(){
	char shellBuffer[1000];

	printf("Welcome to the Muhammad Huzaifa Elahi shell!\n");
	printf("Version 1.0 Created January 2020\n");
	printf("$ ");
	scanf("%s", shellBuffer);
	parse(shellBuffer);
	return 0;
}

int parse(char string[]){
	char temp[200];
	char *words[100];

	int inputIndex, tokenIndex;
	int wordIndex = 0;

	for(inputIndex = 0; string[inputIndex]==' ' && inputIndex < 1000; inputIndex++); // skip white spaces

	while(string[inputIndex] != '\0' && inputIndex < 1000){
		
		for(tokenIndex = 0; string[inputIndex] != '\0' && string[inputIndex] != ' ' && inputIndex < 1000; inputIndex++, tokenIndex++){

			temp[tokenIndex] = string[inputIndex]; // extract a word
		
		}

		temp[tokenIndex] = '\0';

		words[wordIndex] = strdup(temp);

		inputIndex++;
		wordIndex++;
	}
	printf("\nThis is the output:\n%s\n", words[0]);
	return interpreter(words);
}
