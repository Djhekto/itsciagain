/*
 Программа из нескольких модулеи: обработка матриц.
-- ввод значении матрицы из текстового фаила,
-- распечатку матрицы в фаил,
-- сохранение матрицы в бинарный фаил,
-- загрузку матрицы из бинарного фаила
*/

#include <stdio.h>
#include "matrix.h"

int main(){
    //tototo(12);
    int **A;
    int a1 = 4, a2 =4;
    A = matrix_alloc(a1,a2);
    //input_matrix(A,a1,a2);
    char* str1 = "matrix1.txt";
    inputmatrixfromfile(A,a1,a2, str1 );

    print_matrix(A,a1,a2);

    char* str2 = "matrix2.txt";
    outputmatrixtofile(A,a1,a2, str2 );

    char* str3 = "matrix2.bin";
    binoutputmatrixtofile(A,a1,a2, str3 );
    //bininputmatrixfromfile(A,a1,a2, str3 );

    print_matrix(A,a1,a2);

    free_matrix(A,a1);
    
    return 0;}
