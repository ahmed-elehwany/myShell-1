// Muhammad Huzaifa Elahi
// 260726386

#ifndef INTERPRETER_H_
#define INTERPRETER_H_

// Constants
extern const int MAX_LINE_LENGTH;

extern const char runCmd[];
extern const char printCmd[];
extern const char setCmd[];
extern const char quitCmd[];
extern const char helpCmd[];

// Functional Signatures
int interpreter(char *words[]);
int unknown();
int script(FILE *filePtr);
int run(char *file);
int print(char*key);
int set(char *words[]);
int quit();
int help();

#endif /* INTERPRETER_H_ */