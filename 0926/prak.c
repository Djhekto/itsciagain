/*

1. Написать функцию, которая увеличивает в строке
 на 1 все цифры от '0' до '8'
  (если цифр нет, строка не изменяется. 

2. Написать функцию конкатенации строк 
my_strcat(s,t): вторая строка-аргумент
 добавляется в конец первой. Не использовать 
 операцию индексирования.

3. Написать функцию, переворачивающую 
содержимое строки reverse(s).

4. В заданном массиве вещественных 
чисел поменять местами максимальный 
и минимальный элемент (не использовать 
операцию индексирования)

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void task1(char*);
void task2(char*, char*);
void task3(char*);
void task4(int*, int);

int main(int argc, char const **argv)
{
    {
    task1("asjkdkjashd123798127asjkhjd");}
    {
    char str2 [100] = "asjkdkjashd123798127asjkhjd";
    task1(str2);}

    {
    char str2 [100] = "asjkdkjashd123798127asjkhjd";
    char str3 [100] = "appendme";
    task2(str2, str3);}

    {
    char str4 [100] = "asjkdkjashd123798127asjkhjd";
    task3(str4);}

    {
    int masnum [5] = {1,2,3,4,5};
    task4(masnum, 5);}

    {
    int masnum [7] = {5,2,3,4,5,6,1};
    task4(masnum, 7);}

    return 0;
}

void task1(char* str1){
/*1. Написать функцию, которая увеличивает в строке
 на 1 все цифры от '0' до '8'
  (если цифр нет, строка не изменяется.
*/
    printf("\ntask1 inp %s\n", str1);


    char* copy = strdup(str1);
    if(copy == NULL) {return;    }

    char *p = copy;
    while(*p) {
        if((*p >= '0' && *p <= '8')) {
            *p = (*p + 1);
        }
        p++;
    }//while end
    printf("task1 res %s\n", copy);

    free(copy);
    return;
}

void task2(char* str1, char* str2){
/*2. Написать функцию конкатенации строк 
my_strcat(s,t): вторая строка-аргумент
 добавляется в конец первой. Не использовать 
 операцию индексирования.
 */
    printf("\ntask2 inp %s %s\n", str1, str2);

    char* p = str1;
    char* p1= str2;
    while (*p) p++;
    while (*p1){
        *p++ = *p1++;
    }
    *p = '\0';
    printf("task2 res %s %s\n", str1, str2);

    return;
}

void task3(char* str1){
/*3. Написать функцию, переворачивающую 
содержимое строки reverse(s).
 */
    char* str2 = (char*) malloc( (strlen(str1)+1) *sizeof(char ));
    strcpy(str2,str1);

    printf("\ntask3 inp %s copy %s\n", str1, str2);

    char* p = str1;
    char* p1= str2;
    while (*p1++); p1--; p1--;
    while (*p)
    {
        *p = *p1;
        *p1--;
        *p++;
    }
    

    printf("task3 res %s copy %s\n", str1, str2);

    free(str2);
    return;
}

void task4(int* masnum, int maslen){
/*4. В заданном массиве вещественных 
чисел поменять местами максимальный 
и минимальный элемент (не использовать 
операцию индексирования)
*/

    printf("\ntask4 inp %d \n", maslen);
    for(int i=0; i<maslen; i++) {             printf("%d ", masnum[i]); ;}

    int* maxp = masnum;
    int* minp = masnum;
    printf(" %p %d %p %d \n", maxp, *maxp,minp,*minp );
    int number;

    for(int i=0; i<maslen; i++) { 
        number = *(masnum+i);

        if ( number > (*maxp)) { maxp = masnum+i;}
        if ( number < (*minp)) { minp = masnum+i;}
        
        
        ;}

    printf(" %p %d %p %d \n", maxp, *maxp,minp,*minp );
    for(int i=0; i<maslen; i++) {             printf("%d ", masnum[i]);;}

    number = *minp;
    *minp = *maxp;
    *maxp = number;

    printf("task4 out %p %d %p %d \n", maxp, *maxp,minp,*minp );
    for(int i=0; i<maslen; i++) {             printf("%d ", masnum[i]);;}
    printf("\n" );


}