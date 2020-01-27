// Muhammad Huzaifa Elahi
// 260726386

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
const int SHELL_LENGTH = 1000;
const int MAX_WORD_COUNT = 100;
const int MAX_WORD_LENGTH = 100;

// Function Declarations
int parse(char string[]);
extern int interpreter(char *words[]);

int main(){
	char shellBuffer[SHELL_LENGTH];
	int errCode = 0;

	printf("Welcome to the Muhammad Huzaifa Elahi shell!\n");
	printf("Version 1.0 Created January 2020\n");

	while(1){
		printf("$ ");
		fgets(shellBuffer, SHELL_LENGTH, stdin);
		while(shellBuffer[strlen(shellBuffer)-1] == '\r' || shellBuffer[strlen(shellBuffer)-1] == '\n'){
			shellBuffer[strlen(shellBuffer)-1] = '\0';
		}
		errCode = parse(shellBuffer);
		switch(errCode){
			case 0:
				// No error, continue
				break;
			case 2: 
				// Terminate shell (quit)
				return 0;
			default: 
				// continue
				break;
		}
	}

	return 0;
}

int parse(char string[]){
	char temp[MAX_WORD_LENGTH];
	char **words = calloc(MAX_WORD_COUNT, sizeof(char*));

	int inputIndex, tokenIndex;
	int wordIndex = 0;

	for(inputIndex = 0; string[inputIndex]== ' ' && inputIndex < SHELL_LENGTH; inputIndex++); // Skip white spaces

	// Move forward while input has not terminated
	while(string[inputIndex] != '\0' && inputIndex < SHELL_LENGTH){
		
		// Copy token from input
		for(tokenIndex = 0; string[inputIndex] != '\0' && string[inputIndex] != ' ' && inputIndex < SHELL_LENGTH; inputIndex++, tokenIndex++){
			temp[tokenIndex] = string[inputIndex]; // Extract a word
		}

		// Add string terminator to token and add token to word array
		temp[tokenIndex] = '\0'; 
		words[wordIndex] = strdup(temp);

		inputIndex++;
		wordIndex++;
	}
	int errCode = interpreter(words);
	free(words);
	return errCode;
}
