// Muhammad Huzaifa Elahi
// 260726386

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shellmemory.h"

// Constants
const int MAX_SHELL_MEMORY = 1000;
const int MAX_STRING_LENGTH = 1000;

struct MEM shellMemory[1000];

char* getValue(char* var){
    for(int i = 0; i < MAX_SHELL_MEMORY; i++){
        if ((shellMemory[i].var != NULL) && (strcmp(shellMemory[i].var, var) == 0)){
            return shellMemory[i].value;
        }
    }
    return NULL; // Did not find key
}

int addNode(char *var , char *value) {

    for(int i = 0; i < MAX_SHELL_MEMORY; i++){
        // Insert in first empty struct in array
        if(shellMemory[i].var == NULL){
            // Create and allocate new node
            struct MEM newNode;
            newNode.var = malloc(MAX_STRING_LENGTH*sizeof(char));
            newNode.value = malloc(MAX_STRING_LENGTH*sizeof(char));
            strcpy(newNode.var, var);
            strcpy(newNode.value, value);
            shellMemory[i] = newNode;
            return 0;
        // Overwrite
        } else if (strcmp(shellMemory[i].var, var) == 0){
            strcpy(shellMemory[i].value, value);
            return 0;
        }
    }

    return -1; // Full
}

