// Muhammad Huzaifa Elahi
// 260726386

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// String constants
const char *runCmd = "run";
const char *printCmd = "print";
const char *setCmd = "set";
const char *quitCmd = "quit";
const char *helpCmd = "help";

// Function Declarations
extern int parse(char string[]);
extern int addNode(char *key, char *value);
extern int printValue(char *key);
int interpreter(char *words[]);
int unknown();
int script(FILE *filePtr);
int run(char *file);
int print(char*key);
int set(char *words[]);
int quit();
int help();

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
	char line[1000];

	fgets(line, 999, filePtr);
	while(!feof(filePtr)){
		errCode = parse(line);
		if(errCode != 0){
			fclose(filePtr);
			return errCode;
		}
		fgets(line, 999, filePtr);
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
	char string[1000];
	char key[1000];
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

	printf("Command (case sensative)           Description\n");
	printf("     help 			      	Displays all the commands\n");
	printf("     quit 				    Exits / terminates the shell with \"Bye!\"\n");
	printf("set VAR STRING 			    Assigns a value to shell memory\n");
	printf("   print VAR 				Displays the STRING assigned to VAR\n");
	printf("run SCRIPT.TXT 				Executes the file SCRIPT.TXT\n");

	return 0;
}
