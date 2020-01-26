// Muhammad Huzaifa Elahi
// 260726386

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int printValue(char *key);
int addNode(char *key, char *value);

// Keep track of Memory with Head and Tail
struct SHELL_MEM {
    struct SHELL_MEM *next;
    char *currVariable;
    char *currValue;
}   *shellMemory = NULL, *tail = NULL;

int printValue(char* key){
    struct SHELL_MEM *start;
    start = shellMemory;

    while(start != NULL){
        if(strcmp(start->currVariable, key) == 0){
            // Found key in memory
            printf("Variable: %s\nValue: %s\n", key, start->currValue);
            return 0;
        }
        start = start->next;
    }
    printf("Variable does not exist\n");
    return -1; // Did not find key
}

int addNode(char *key , char *value) {
    // Create and allocate new node
    struct SHELL_MEM *newNode = (struct SHELL_MEM*) malloc(sizeof(struct SHELL_MEM));
    newNode->currVariable = key;
    newNode->currValue = value;

    // If Head Empty, insert there
    if(shellMemory==NULL) {
        shellMemory = newNode;
        return 0;
    }

    // Insert at end of list
    tail = shellMemory;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    tail->next = newNode; 
    return 0;
}

