// Muhammad Huzaifa Elahi
// 260726386

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Declarations
int parse(char string[]);
extern int interpreter(char *words[]);

int main(){
	char shellBuffer[1000];

	printf("Welcome to the Muhammad Huzaifa Elahi shell!\n");
	printf("Version 1.0 Created January 2020\n");
	printf("$ ");
	fgets(shellBuffer, 1000, stdin);
	shellBuffer[strlen(shellBuffer)-1] = '\0';
	
	return parse(shellBuffer);
}

int parse(char string[]){
	char temp[200];
	char **words = calloc(100, sizeof(char*));

	int inputIndex, tokenIndex;
	int wordIndex = 0;

	for(inputIndex = 0; string[inputIndex]==' ' && inputIndex < 1000; inputIndex++); // Skip white spaces

	// Move forward while input has not terminated
	while(string[inputIndex] != '\0' && inputIndex < 1000){
		
		// Copy token from input
		for(tokenIndex = 0; string[inputIndex] != '\0' && string[inputIndex] != ' ' && inputIndex < 1000; inputIndex++, tokenIndex++){
			temp[tokenIndex] = string[inputIndex]; // Extract a word
		}

		// Add string terminator to token and add token to word array
		temp[tokenIndex] = '\0'; 
		words[wordIndex] = strdup(temp);

		inputIndex++;
		wordIndex++;
	}

	return interpreter(words);
}
