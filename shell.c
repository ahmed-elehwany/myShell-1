// Muhammad Huzaifa Elahi
// 260726386

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shell.h"
#include "interpreter.h"

// Constants
const int SHELL_LENGTH = 1000;
const int MAX_WORD_COUNT = 100;
const int MAX_WORD_LENGTH = 100;

int main(){
	char shellBuffer[SHELL_LENGTH];
	int errCode = 0;

	printf("Welcome to the Muhammad Huzaifa Elahi shell!\n");
	printf("Version 1.0 Created January 2020\n");

	while(1){
		printf("$ ");

		if(fgets(shellBuffer, SHELL_LENGTH, stdin) == NULL){
			printf("Unable to retrieve process input, please try again\n");
			return 0;;
		}

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
	if(string == NULL || strlen(string) == 0){
		printf("Please enter a valid command\n");
		return -1;
	}

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
