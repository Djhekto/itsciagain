/*1. Написать функцию, которая для заданной квадратной матрицы 
печатает ее транспонированную матрицу

2*.Написать функцию, которая печатает на экран значения всех седловых точек 
матрицы (напечатать индексы и значения элементов, являющихся седловыми точками).
 Элемент является седловой точкой, если он 
- максимальный в своей строке и (одновременно) минимальный в своем столбце
либо
-минимальный в своей строке и (одновременно) максимальный в своем столбце
*/

#include <stdio.h>
#include "matrix.h"

int main(){
    tototo(12);
    int **A;
    int a1 = 4, a2 =4;
    A = matrix_alloc(a1,a2);
    input_matrix(A,a1,a2);
    print_matrix(A,a1,a2);
    transposematrix(A, a1, a2);
    printf("transpose:\n");
    print_matrix(A,a1,a2);
    extremumdots(A,a1,a2);


    free_matrix(A,a1);
    
    return 0;}



/*    print_max_inlines(A,a1,a2);
    print_max_incollums(A,a1,a2);
    is_special(A,a1,a2);
    int sum1=0; int sum2=0;
    int* p1 = &sum1; int* p2 = &sum2;
    sumd2(A,a1,a2, p1, p2 );
    printf("main line sum %d\n sidemain line sum %d\n ",sum1,sum2);
*/
