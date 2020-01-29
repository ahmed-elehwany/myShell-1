// Muhammad Huzaifa Elahi
// 260726386

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interpreter.h"
#include "shellmemory.h"
#include "shell.h"

// Constants
const int MAX_LINE_LENGTH = 1000;

const char runCmd[] = "run";
const char printCmd[] = "print";
const char setCmd[] = "set";
const char quitCmd[] = "quit";
const char helpCmd[] = "help";

int interpreter(char *words[]){
	if(strcmp(words[0], runCmd) == 0)
		return run(words[1]);
	else if(strcmp(words[0], printCmd) == 0)
		return print(words[1]);
	else if (strcmp(words[0], setCmd) == 0)
		return set(words);
	else if (strcmp(words[0], quitCmd) == 0)
		return quit();
	else if (strcmp(words[0], helpCmd) == 0)
		return help();
	else
		return unknown();

	return 0;
}

int script(FILE *filePtr){
	int errCode = 0;
	char *line = calloc(MAX_LINE_LENGTH, sizeof(char));

	while(!feof(filePtr)){
		if(fgets(line, MAX_LINE_LENGTH, filePtr) == NULL){
			printf("Unable to retrieve file input, please try again\n");
			return 0;;
		}
		while(line[strlen(line)-1] == '\r' || line[strlen(line)-1] == '\n'){
			line[strlen(line)-1] = '\0';
		}

		errCode = parse(line);
		//TODO: CLOSE ONLY SCRIPT ON QUIT, NOT TERMINAL
		if(errCode != 0){
			fclose(filePtr);
			return errCode;
		}
	}

	free(line);
	fclose(filePtr);

	return errCode;
}

int unknown(){
	printf("Unknown command\n");
	return -1;
}

int run(char *file){
	if(file == NULL){
		printf("Please enter a script\n");
		return -1;
	}

	FILE *filePtr = fopen(file, "r");
	if(filePtr == NULL){
		printf("Script not found\n");
		return -1;
	}

	return script(filePtr);
}

int print(char *var){
	if(var == NULL){
		printf("Please enter a variable\n");
		return -1;
	}

	char* value = getValue(var);
	if(value == NULL){
		printf("Variable does not exist\n");
		return -1;
	}

	printf("%s\n", value);
	return 0;
}

int set(char*words[]){
	int i = 3;
	int errCode = 0;

	// Check var
	if(words[1] == NULL){
		printf("Please enter a variable\n");
		return -1;
	}

	// Check string
	if(words[2] == NULL){
		printf("Please enter a string\n");
		return -1;
	}

	errCode = addNode(words[1], words[2]);
	if(errCode){
		printf("Shell memory full\n");
	}

	return errCode;
}

int quit(){
	printf("Bye!\n");
	return 2;
}

int help(){

	printf("Command (case sensitive)         		  Description\n");
	printf("     help 			      	Displays all the commands\n");
	printf("     quit 			        Exits / terminates the shell with \"Bye!\"\n");
	printf("set VAR STRING 			    	Assigns a value to shell memory\n");
	printf("   print VAR 				Displays the STRING assigned to VAR\n");
	printf("run SCRIPT.TXT 				Executes the file SCRIPT.TXT\n");

	return 0;
}
