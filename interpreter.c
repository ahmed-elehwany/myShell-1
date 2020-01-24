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
int interpreter(char *words[]);
int unknown();
int run();
int print();
int set();
int quit();
int help();

int interpreter(char *words[]){
	//if(words[0][0] == '.' || words[0][1] == '/') 
	
	if(strcmp(words[0], runCmd) == 0)
		return run();
	else if(strcmp(words[0], printCmd) == 0)
		return print();
	else if (strcmp(words[0], setCmd) == 0)
		return set();
	else if (strcmp(words[0], quitCmd) == 0)
		return quit();
	else if (strcmp(words[0], helpCmd) == 0)
		return help();
	else
		return unknown();

	return 0;
}

int unknown(){
	printf("Unknown Command");
	return -1;
}

int run(){
	printf("Run");
	return 0;
}

int print(){
	printf("Print");
	return 0;
}

int set(){
	printf("Set");
	return 0;
}

int quit(){
	printf("Quit");
	return 0;
}

int help(){
	printf("Help");
	return 0;
}
