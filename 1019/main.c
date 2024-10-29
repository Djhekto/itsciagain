#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    Stack St = initstack();
    int c;
    int res;

    while( (c = getchar() ) != '\n' ){
        if (c == '{' || c == '(' || c == '[' ){
            St = push(c,St);
            continue;
        }
        if (c == '}' || c == ')' || c == ']' ){
            res= pop(&St);

            if (res == '(' && c== ')'){

            continue;
            }
            if (res == '{' && c== '}'){
            
            continue;
            }
            if (res == '[' && c== ']'){
                
            continue;
            }
            //else cos continue;
            printf("incorrect skobki\n");
            return 0;
        }

    }// while end

    if (is_empty(St)) printf("correct skobki\n");

    return 0;
}