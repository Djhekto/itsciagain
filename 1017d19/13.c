/*
1. Программа. Определить, сколько раз в данном фаиле f
встречается символ ‘A’. Имя фаила берется из команднои строки

2. По заданному фаилу построить его копию, имена фаилов
задаются в команднои строке. (Рассмотреть посимвольное
копирование и копирование блоками)

3. Написать логическую функцию, которая проверяет, имеют ли два
фаила равное содержимое.

5. Программа. Определить, какая строка является самои длиннои в
заданном фаиле. Если таких строк несколько, то в качестве
результата выдать первую из них. Имя фаила задается в
команднои строке.

6. Программа из нескольких модулеи: обработка матриц.
-- ввод значении матрицы из текстового фаила,
-- распечатку матрицы в фаил,
-- сохранение матрицы в бинарный фаил,
-- загрузку матрицы из бинарного фаила 

*/

#include <stdio.h>
#include <stdlib.h>

void task3(int agrc, char** argv);


int main(int agrc, char** argv){
    {//1
    FILE *fp;
    char c;
    int counter = 0;

    if ( (fp = fopen(argv[1],"r+") ) == NULL){ printf("err\n") ;return 1;}

    while ( (c = fgetc(fp)) != EOF ) {
        if (c == 'A') { counter++;}
        //printf("%c\n",c);
    }

    printf("TASK1 RES %d\n\n",counter);

    fclose(fp);
    }

    task3(agrc, argv);
    return 0;
}

void task3(int agrc, char** argv){
    {//3
    FILE *fp;
    char *buf1 = malloc(1000 * sizeof(char));
    char* p1 = buf1;

    if ( (fp = fopen(argv[1],"r+") ) == NULL){ printf("err\n") ;return 1;}

    while ( (*p1 = fgetc(fp)) != EOF ) {
        p1++;
        //printf("%c\n",c);
    }
    *p1 = '\0';

    printf("%s\n", buf1);
    fclose(fp);


    if ( (fp = fopen(argv[2],"r+") ) == NULL){ printf("err\n") ;return 1;}

    char* p2 = buf1; p1 = buf1;
    printf("%s\n", buf1);

    while ( (*p2 = fgetc(fp)) != EOF && *p1!='\0') {
        printf("%c%c ", *p1, *p2);
        if (*p1!=*p2) {
                free(buf1);
                printf("ne ravni \n");
                return;
                }
    }
    //*p1 = '\0';

    printf("ravni \n");

    free(buf1);
    }
    return;
}
