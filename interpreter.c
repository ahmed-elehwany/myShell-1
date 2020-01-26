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
int script(char *words[]);
int run();
int print(char*key);
int set(char *key, char *value);
int quit();
int help();

int interpreter(char *words[]){
	if(words[0][0] == '.' || words[0][1] == '/') 
		return script(words);
	if(strcmp(words[0], runCmd) == 0)
		return run();
	else if(strcmp(words[0], printCmd) == 0)
		return print(words[1]);
	else if (strcmp(words[0], setCmd) == 0)
		return set(words[1], words[2]);
	else if (strcmp(words[0], quitCmd) == 0)
		return quit();
	else if (strcmp(words[0], helpCmd) == 0)
		return help();
	else
		return unknown();

	return 0;
}

int script(char *words[]){
	printf("Script\n");

	int errCode = 0;
	char line[1000];

	FILE *p = fopen(words[0]+2, "rt");

	fgets(line, 999, p);
	while(!feof(p)){
		errCode = parse(line);
		if(errCode != 0){
			fclose(p);
			return errCode;
		}
		fgets(line, 999, p);
	}

	fclose(p);

	return errCode;
}

int unknown(){
	printf("Unknown command\n");
	return -1;
}

int run(){
	printf("Run\n");
	return 0;
}

int print(char*key){
	printValue(key);
	return 0;
}

int set(char*key, char*value){
	addNode(key, value);
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
