#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void transposematrix(int **A, int m, int n){
    if (m!=n) {printf("n!=m\n");;return;}
    int swapwithme;
    for (int i = 0; i<m-1; i++){
        for (int ii=i+1; ii<n; ii++){
            swapwithme = A[i][ii];
            A[i][ii] = A[ii][i];
            A[ii][i] = swapwithme;
        }
    }

}

void extremumdots(int **A, int m, int n){
/*2*.Написать функцию, которая печатает на экран значения всех седловых точек 
матрицы (напечатать индексы и значения элементов, являющихся седловыми точками).
 Элемент является седловой точкой, если он 
- максимальный в своей строке и (одновременно) минимальный в своем столбце
либо
-минимальный в своей строке и (одновременно) максимальный в своем столбце
 */
    int storeminmaxvalue;
    int storeminmaxindexi;
    int storeminmaxindexii;
    short flagforextremum = 0;

    for (int i = 0; i<m; i++){
        printf("ishem max min %d stroka\n",i);
        storeminmaxvalue = A[i][0];
        storeminmaxindexi = i;
        storeminmaxindexii = 0;
        for (int ii = 1; ii<n; ii++){  //looking for max
            if (A[i][ii]> storeminmaxvalue){ 
                storeminmaxindexi = i;
                storeminmaxindexii = ii;
                storeminmaxvalue = A[i][ii];
                }
        }

        flagforextremum=1;
        for (int j = 0; j<m; j++){//stolbez fixed
            if (j == storeminmaxindexi){continue;} //no self comapare
            if ( storeminmaxvalue > A[j][storeminmaxindexii]){ //min in stolb
            flagforextremum=0; //ne extremum
            if ( storeminmaxvalue == A[j][storeminmaxindexii]) {printf("est1 ravenstvo min ??? sedlo\n");}
            }
        }

        if (flagforextremum){
            printf("found extremum max min\n");
            printf("value %d on index %d %d\n", storeminmaxvalue, storeminmaxindexi, storeminmaxindexii);
        }

        printf("ishem min max %d stroka\n",i);

        storeminmaxvalue = A[i][0];
        storeminmaxindexi = i;
        storeminmaxindexii = 0;

        for (int ii = 1; ii<n; ii++){  //looking for min
            if (A[i][ii]< storeminmaxvalue){ 
                storeminmaxindexi = i;
                storeminmaxindexii = ii;
                storeminmaxvalue = A[i][ii];
                }
        }

        flagforextremum=1;
        for (int j = 0; j<m; j++){//stolbez fixed
            if (j == storeminmaxindexi){continue;} //no self comapare
            if ( storeminmaxvalue < A[j][storeminmaxindexii]){ //max in stolb
            flagforextremum=0; //ne extremum
            if ( storeminmaxvalue == A[j][storeminmaxindexii]) {printf("est1 ravenstvo max ??? sedlo\n");}
            }
        }

        if (flagforextremum){
            printf("found extremum min max\n");
            printf("value %d on index %d %d\n", storeminmaxvalue, storeminmaxindexi, storeminmaxindexii);
        }

    }

/*
0 1 2 3 
1 2 3 4
1 2 3 4
1 2 3 4

0 1 1 1
1 2 2 2
2 3 3 3
3 4 4 4
ishem max min 0 stroka
found extremum max min
value 1 on index 0 1
ishem min max 0 stroka
ishem max min 1 stroka
ishem min max 1 stroka
ishem max min 2 stroka
ishem min max 2 stroka
ishem max min 3 stroka
ishem min max 3 stroka
found extremum min max
value 3 on index 3 0 */
    return;
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

void inputmatrixfromfile(int **A, int m, int n, char* filename ){
    /*-- ввод значении матрицы из текстового фаила,*/

    FILE *fp;
    char c;
    size_t len;
    char convertmetoint[100] = "-1111111111111111111111";

    if ( (fp = fopen(filename,"r+") ) == NULL) { printf("err\n") ;return;}

    if ( (c = fgetc(fp)) == EOF){
        printf("00file to short for matrix\n");
        printf("00crash \n");
    }

    for (int i = 0 ; i<n; ++i){
        for( int j=0; j<m; ++j){
            //scanf("%d", &A[i][j]);
            convertmetoint[0]= '\0';
            while(c!=' '&&c!='\n'){
                if (c>='0' && c<='9'){
                    len = strlen(convertmetoint);
                    convertmetoint[len] = c;
                    convertmetoint[len + 1] = '\0';
                    //strcat(convertmetoint, c);
                    printf("(%c,%d,%d)%s",c,i,j,convertmetoint);
                    }
                else {
                    printf("ne chislo %c v faile zapicivaem v matrix\n",c);
                    printf("value skiped\n");
                }
                if ( (c = fgetc(fp)) == EOF){
                    printf("file to short for matrix\n");
                    printf("crash \n");
                }
            }//while end
            A[i][j] = atoi(convertmetoint);

            if (c==' '){
                printf(" ");
                if ( (c = fgetc(fp)) == EOF){
                    printf("33file to short for matrix\n");
                    printf("33crash \n");
                }
            }

            if (c=='\n' && j==m-1){
                printf("\n");
                if ( (c = fgetc(fp)) == EOF){
                    printf("22file to short for matrix\n");
                    printf("22crash \n");
                }
            }


        }
    }//for for end

    printf("end of file matrix input\n\n");
    fclose(fp);
}


void outputmatrixtofile(int **A, int m, int n, char* filename ){
    //-- распечатку матрицы в фаил,

    FILE *fp;
    char str1[100];

    if ( (fp = fopen(filename,"w+") ) == NULL) { printf("err\n") ;return;}

    printf("input to file %s\n",filename);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
                printf("%d", A[i][j]);
                printf(" ");
                itoa(A[i][j], str1, 10);
                //str1 = ;
                fputs (str1, fp);
                fputs (" ", fp);
                
            }
        printf("\n");
        fputs ("\n", fp);

        }//for for

    printf("end of file matrix output to file\n");
    fclose(fp);

    return;
}

void binoutputmatrixtofile(int **A, int m, int n, char* filename) {
    FILE *fp;
    
    if ( (fp = fopen(filename,"wb") ) == NULL) { printf("err\n") ;return;}

    printf("Writing to binary file %s\n", filename);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", A[i][j]);
            fwrite(&A[i][j], sizeof(int), 1, fp);
        }
        printf("\n");
    }

    printf("End of binary file matrix output to file\n");
    fclose(fp);
}

void bininputmatrixfromfile(int **A, int m, int n, char* filename) {
    FILE *fp;

    printf("reading from binary file %s\n", filename);

    if ( (fp = fopen(filename,"wb") ) == NULL) { printf("err\n") ;return;}

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fread(&(A[i][j]), sizeof(int), 1, fp);
        }
    }
    printf("End of binary file matrix input from file\n");

    fclose(fp);
}

/*
void binoutputmatrixtofile(int **A, int m, int n, char* filename ){
    //-- -- сохранение матрицы в бинарный фаил,

    FILE *fp;
    //char str1[4];
    //"test.bin"
    if ( (fp = fopen(filename,"wb") ) == NULL) { printf("err\n") ;return;}

    printf("input to binary file %s\n",filename);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {

            printf("%d", A[i][j]);
            printf(" ");
            //fread(&A[i][j], sizeof(int), 1, fp);
            fwrite(&A[i][j], sizeof(int), 1, fp);
        }
    printf("\n");
    fread("\n",sizeof(char),1,fp);
    }

    printf("end of binary file matrix output to file\n");
    fclose(fp);

    return;
}
*/

/*
void bininputmatrixfromfile(int **A, int m, int n, char* filename ){
    //-- -- загрузку матрицы из бинарного фаила

    return;
}
*/