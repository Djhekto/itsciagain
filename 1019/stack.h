#pragma once
//#include "stack.c"

typedef struct Node {
    int elem;
    struct Node* next;
} Node;

typedef struct Node* Stack;


Stack initstack(void);
Stack push(Stack* S, int E);
int pop(Stack* S);
int is_empty(Stack* S);



