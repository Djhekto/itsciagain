#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void task1();
void task2();
void task3(int);

int main()
    {
    //task1();
    task2();
    //task3(10);
    return 0;
    }

void task1()
    {
// Со стандартного ввода читается 
//последовательность символов (до конца файла или до перевода строки '\n') 
//.  Подсчитать в ней количество троек символов the.
    unsigned int res = 0;
    short state = 0;
    char *c;
    scanf("%m[^\n]", &c);

    for ( int i = 0; i<strlen(c);i++ ){
        if (c[i]=='\0') break;
        if (c[i]=='t'){state = 1; continue;}
        if (state == 1 && c[i]=='h'){state = 2; continue;}
        if (state == 2 && c[i]=='e'){state = 0; res++; continue;}
        state = 0;
    }
    printf("task1 %d the in %s \n", res, c);
    return;
    }

void task2()
    {
// Со стандартного ввода читается последовательность символов
//(до конца файла или до перевода строки '\n').  Проверить, является
//ли она сбалансированной по круглым скобкам.
    short res = -1; // 1 balan ; 0 ne balans
    int state = 0; // -1 (  ;  +1 )
    char *c;
    scanf("%m[^\n]", &c);
    int temp = strlen(c)+1;
    char* c1 = malloc(temp);
    //strcpy(c1,c);
    memcpy(c1, c, strlen(c));
    printf("copy of string is %s \n", c1);

    for (int i= 0; i<strlen(c); i++)
    {
        if (state > 0 ) {printf(") zakrita do otkritia ( !!!");break;}
        if (c1[i]=='(') {
            state--;
            continue;
        }
        if (c1[i]==')') {
            state++;
            continue;
        }

    }
    printf("\nstate is %d\n",state);
    if (!state) {//==0
        printf("balans soxranen\n");
    }

    free(c1);free(c);
    return;
    }

void task3(int n)
    {
//Распечатать первые n чисел Фибоначчи ( f0 = 1; f1 = 1;
        //каждое следующее число равно сумме двух предыдущих).
        //Решить задачу с помощью рекурсивной функции и с
        //помощью нерекурсивной функции. Сравнить эффективность решений.
    {
    int a = 1, b = 1;
    printf("\n1\n1 ");
    for(int i=2, c;i<n;i++){
        c = a+b;;;;;;;;;;;;;
        a=b;;;;
        b=c;;;;
        printf("\n%d ", c);
    }
    printf("\n task3 %d\n", b);
    }
    return;
    }
