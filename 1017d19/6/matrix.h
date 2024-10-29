#ifndef MATRIX_H

#define MATRIX_H



int tototo(int n);

int**matrix_alloc(int N, int M);

void free_matrix(int **A, int N);

void input_matrix(int** A, int n, int m);

void print_matrix(int ** A, int  m, int n);

void print_max_inlines(int **A, int m, int n);

void print_max_incollums(int **A, int m, int n);

void is_special(int **A, int m, int n);

void is_upper_triangle(int **A, int m, int n);

void is_lower_triangle(int **A, int m, int n);

void sumd2(int **A, int m, int n, int* sum1, int* sum2 );

void transposematrix(int **A, int m, int n);

void extremumdots(int **A, int m, int n);

void inputmatrixfromfile(int **A, int m, int n, char* filename );

void outputmatrixtofile(int **A, int m, int n, char* filename );

void binoutputmatrixtofile(int **A, int m, int n, char* filename );

void bininputmatrixfromfile(int **A, int m, int n, char* filename);




#endif



//#ifdef 0

//skl;aksld

//;saldl;ak

//#endif



