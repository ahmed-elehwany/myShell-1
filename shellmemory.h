// Muhammad Huzaifa Elahi
// 260726386

#ifndef SHELL_MEMORY_H_
#define SHELL_MEMORY_H_

// Constants
extern const int MAX_SHELL_MEMORY;
extern const int MAX_STRING_LENGTH;

// Functional Declarations
int printValue(char *var);
int addNode(char *var, char *value);

// Keep track of variables in memory
struct MEM {
    char *var;
    char *value;
};

#endif /* SHELL_MEMORY_H_ */