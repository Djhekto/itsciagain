#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void task1(unsigned int);
char* task2(char*);
void task3();

int main()
    {
    task1(201);
    task1(3232300000);
    task1(18);
    task1(81);
    //
    char *c;
    //printf("во входном потоке находится последовательность символов, заканчивающаяся переводом строки (‘\n’) или концом файла\n");
    printf("\ntask2 input\n");
    scanf("%m[^\n]", &c);
    strcpy(c,task2(c) );
    printf("res task2\n %s\n", c);

    //
    task3();
    return 0;
    }

void task1(unsigned int x)
    {
    //Определить, является ли натуральное число n степенью числа 3
    double y = (double) x;
    while (y>=3)
        {
        if ((y/3)==1.0) {printf("yes\n"); return;}
        y = y/3; 
        //printf("%lf\n",y);
        }
    printf("no\n");
    }

char* task2(char* inputstr)
    {
/*    Пусть во входном потоке находится последовательность символов, 
заканчивающаяся переводом строки (‘\n’) или концом файла. 
Вывести в выходной поток последовательность символов,
 измененную согласно условию:
 каждую группу рядом стоящих символов ‘+’ 
 заменить одним таким символом (a+++c+++b+ ==>a+c+b+).
 ++++++++++-> + */
    printf("test in task2\n %s\n", inputstr);

    int temp = strlen(inputstr)+1;
    char* c1 = malloc(temp);

    //strcpy(c1, inputstr);//, strlen(inputstr+1));
    //printf("copy of string is %s \n", c1);

    short boolpreviousplus = 0;
    int ii = 0;
    for(int i = 0; i<temp-1; i++){
        /*
        if (inputstr[i]=='+') //{   ( boolpreviousplus==0)? continue : boolpreviousplus=1;  }
        {
            if (boolpreviousplus == 1) continue;
            if (boolpreviousplus == 0) boolpreviousplus=1;
        }
        else{
            c1[ii] = inputstr[i]; ii++;
            boolpreviousplus = 0;
        }
        */
       if (boolpreviousplus==1 && inputstr[i]=='+') {continue;}
       if (inputstr[i]=='+')// && boolpreviousplus == 0)
       {
        c1[ii] = inputstr[i]; ii++;
        boolpreviousplus=1;
        continue;
       }
       else
       {
         c1[ii] = inputstr[i]; ii++;
        boolpreviousplus=0;
        continue;
       }
    }

    c1[ii]='\0';
    strcpy(inputstr,c1);
    free(c1);

    return inputstr;
    }

void task3()
{
/*
С клавиатуры вводится последовательность натуральных чисел (не менее двух), 
признак конца последовательности - число 0 (сам 0 в последовательность не входит). 
Все числа в последовательности - различные. Напечатать в стандартный 
вывод два наибольших элемента последовательности.
*/
    char c;
    char cc [5000];
    unsigned i=0;
    while (1)
    {
        c= getchar();
        if (c==' ') break;
        cc[i] = c;
        i++;

    }
    printf(cc);






}