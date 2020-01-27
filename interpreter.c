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
	printf("Script\n");

	int errCode = 0;
	char line[MAX_LINE_LENGTH];

	fgets(line, MAX_LINE_LENGTH, filePtr);
	while(!feof(filePtr)){
		while(line[strlen(line)-1] == '\r' || line[strlen(line)-1] == '\n'){
			line[strlen(line)-1] = '\0';
		}
		errCode = parse(line);
		fgets(line, MAX_LINE_LENGTH, filePtr);
	}

	fclose(filePtr);

	return errCode;
}

int unknown(){
	printf("Unknown command\n");
	return -1;
}

int run(char *file){
	FILE *filePtr = fopen(file, "r");
	if(filePtr == NULL){
		printf("Script not found\n");
		return -1;
	}
	return script(filePtr);
}

int print(char*key){
	printValue(key);
	return 0;
}

int set(char*words[]){
	int i = 3;
	char string[MAX_LINE_LENGTH];
	char key[MAX_LINE_LENGTH];
	if(words[1] != NULL){
		strcpy(key, words[1]);
	} else{
		printf("Invalid Variable\n");
		return -1;
	}

	if(words[2] != NULL){
		strcpy(string, words[2]);
	} else{
		printf("Invalid String\n");
		return -1;
	}
	while (words[i] != NULL){
		strcat(string, " ");
		strcat(string, words[i]);
		i++;
	}
	addNode(words[1], string);
	printf("Variable: %s\nValue: %s\n", words[1], string);
	return 0;
}

int quit(){
	printf("Bye!\n");
	return 2;
}

int help(){

	printf("Command (case sensitive)           Description\n");
	printf("     help 			      	Displays all the commands\n");
	printf("     quit 				    Exits / terminates the shell with \"Bye!\"\n");
	printf("set VAR STRING 			    Assigns a value to shell memory\n");
	printf("   print VAR 				Displays the STRING assigned to VAR\n");
	printf("run SCRIPT.TXT 				Executes the file SCRIPT.TXT\n");

	return 0;
}
