// Muhammad Huzaifa Elahi
// 260726386

#ifndef SHELL_MEMORY_H_
#define SHELL_MEMORY_H_

// Constants
extern const int MAX_STRING_LENGTH;

// Functional Declarations
int printValue(char *key);
int addNode(char *key, char *value);

// Keep track of variables in memory
struct SHELL_MEM {
    struct SHELL_MEM *next;
    char *currVariable;
    char *currValue;
}   *shellMemory, *temp;

#endif /* SHELL_MEMORY_H_ */