// Muhammad Huzaifa Elahi
// 260726386

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int printValue(char *key);
int addNode(char *key, char *value);

// Keep track of Memory with Head and Tail
struct SHELL_MEM {
    struct SHELL_MEM *next;
    char *currKey;
    char *currValue;
}   *shellMemory = NULL, *tail = NULL;

int printValue(char* key){
    struct SHELL_MEM *start;
    start = shellMemory;

    while(start != NULL){
        if(strcmp(start->currKey, key) == 0){
            // Found key in memory
            printf("Key: %s\nValue: %s\n", key, start->currValue);
            return 0;
        }
        start = start->next;
    }
    return -1;
}

int addNode(char *key , char *value) {
    struct SHELL_MEM *newNode = (struct SHELL_MEM*) malloc(sizeof(struct SHELL_MEM));
    newNode->currKey = key;
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

