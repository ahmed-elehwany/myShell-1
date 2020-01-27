// Muhammad Huzaifa Elahi
// 260726386

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shellmemory.h"

// Constants
const int MAX_STRING_LENGTH = 1000;

int printValue(char* key){
    temp = shellMemory;

    while(temp != NULL){
        if(strcmp(temp->currVariable, key) == 0){
            // Found key in memory
            printf("Variable: %s\nValue: %s\n", key, temp->currValue);
            return 0;
        }
        temp = temp->next;
    }
    printf("Variable does not exist\n");
    return -1; // Did not find key
}

int addNode(char *key , char *value) {
    // Create and allocate new node
    struct SHELL_MEM *newNode = (struct SHELL_MEM*) malloc(sizeof(struct SHELL_MEM));
    newNode->currVariable = malloc(MAX_STRING_LENGTH*sizeof(char));
    newNode->currValue = malloc(MAX_STRING_LENGTH*sizeof(char));
    strcpy(newNode->currVariable, key);
    strcpy(newNode->currValue, value);

    // If Head Empty, insert there
    if(shellMemory==NULL) {
        shellMemory = newNode;
        return 0;
    }

    if(strcmp(shellMemory->currVariable, key) == 0){
            // Found key in memory, overwrite
            strcpy(shellMemory->currValue, value);
            free(newNode);
            return 0;    
    }
   
    // Insert at end of list
    temp = shellMemory;
    while(temp->next!=NULL){
        temp = temp->next;
        if(strcmp(temp->currVariable, key) == 0){
            // Found key in memory, overwrite
            strcpy(temp->currValue, value);
            free(newNode);
            return 0;    
        }
    }

    temp->next = newNode; 
    return 0;
}

