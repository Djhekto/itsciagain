#include <stdio.h>
#include "matrix.h"

int main(){
    tototo(12);
    int **A;
    int a1 = 4, a2 =4;
    A = matrix_alloc(a1,a2);
    input_matrix(A,a1,a2);
    print_matrix(A,a1,a2);
    print_max_inlines(A,a1,a2);
    print_max_incollums(A,a1,a2);
    is_special(A,a1,a2);
    int sum1=0; int sum2=0;
    int* p1 = &sum1; int* p2 = &sum2;
    sumd2(A,a1,a2, p1, p2 );
    printf("main line sum %d\n sidemain line sum %d\n ",sum1,sum2);
    free_matrix(A,a1);
    
    return 0;}
