#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



Stack initstack(void){
    return NULL;
    //return *S;
}

Stack push(Stack* S, int E) {
    struct Node* p = malloc(sizeof(struct Node));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    p->elem = E;
    p->next = *S;
    *S = p;
    return *S;
}

int pop(Stack* S) {
    if (is_empty(S)) {
        printf("Stack is empty\n");
        return 0;
    }
    int k = (*S)->elem;
    struct Node* p = *S;
    *S = (*S)->next;
    free(p);
    return k;
}

int is_empty(Stack* S){
    return *S==NULL;
}
