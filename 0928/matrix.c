#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"


int tototo(int n)
    {   printf("%d\n",n);
        return n;}

int**matrix_alloc(int N, int M){
    int** A = malloc(N * sizeof(int*));

    if (A==NULL){
        fprintf(stderr,"exit matrix mem alloc\n");
        exit(EXIT_FAILURE);
    }

    for (int i=0; i<N; i++){
        if(  (A[i] = calloc(M, sizeof(int))) == NULL  ) { 
                fprintf(stderr,"exit matrix lines mem alloc\n");
                exit(EXIT_FAILURE);
            ;}
    }
    
    return A;
}

void free_matrix(int** A,int N){
    for (int i=0; i<N; i++){
        free(A[i]);
    }
    free(A);
}

void input_matrix(int** A, int n, int m){
    for (int i = 0 ; i<n; ++i){
        for( int j=0; j<m; ++j){
            scanf("%d", &A[i][j]);
        }
    }
}

void print_matrix(int **A, int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            //if (A[i] && A[i][j]) {
                printf("%d ", A[i][j]);
            //} else {
                //printf("? ");
            //}
        }
        printf("\n");
    }
}

void print_max_inlines(int **A, int m, int n){
    int immax;
    for (int i = 0; i < m; ++i) {
        immax = A[i][1];
        for (int j = 1; j < n; ++j) {
            if (A[i][j] > immax) {immax = A[i][j];}
        }
        printf("line %d max is %d\n",i,immax);
    }
}

void print_max_incollums(int **A, int m, int n){
    int immax;
    for (int j = 0; j < n; ++j) {
        immax = A[1][j];
        for (int i = 1; i < m; ++i) {
            if (A[i][j] > immax) {immax = A[i][j];}
        }
        printf("column %d max is %d\n",j,immax);
    }
}

void is_special(int **A, int m, int n){
    if (m!=n) {printf("n!=m\n");;return;}
    is_upper_triangle(A, m, n);
    is_lower_triangle(A, m, n);
}

void is_upper_triangle(int **A, int m, int n){
    if (m!=n) {printf("n!=m\n");;return;}
    int kompare = 0; //any left non zero -> false
    for (int i = 1; i < m; ++i) {
        if (kompare<i) {kompare = i;}
        for (int j = 0; j < kompare; j++) {
            if (A[i][j]!=0){printf("ne verhne treug\n"); return;}
        }
    }//for for end
    {printf("verhne treug\n"); return;}
}

void is_lower_triangle(int **A, int m, int n){
    if (m!=n) {printf("n!=m\n");;return;}
    int kompare = 0+1; //any right non zero -> false
    for (int i = 0; i < m-1; ++i) {
        if (kompare<i+1) {kompare = i+1;}
        for (int j = n-1; j > kompare; j--) {
            if (A[i][j]!=0){printf("ne nizne treug\n"); return;}
        }
    }//for for end
    {printf("nizne treug\n"); return;}
}

void sumd2(int **A, int m, int n, int* sum1, int* sum2 ){
    if (m!=n) {printf("n!=m\n");;return;}
    //int res =0;
    for (int ii = 0; ii<n; ii++){
        *sum1+=A[ii][ii];
    }
    for (int ii = 0; ii<n; ii++){
        *sum2+=A[ii][n-1-ii];
    }
}



