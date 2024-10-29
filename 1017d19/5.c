#include <stdio.h>
#include <stdlib.h>

void task5(int agrc, char** argv);


int main(int agrc, char** argv){
    task5(agrc, argv);
    return 0;
}


void task5(int agrc, char** argv){
/* 5. Программа. Определить, какая строка является самои длиннои в
    заданном фаиле. Если таких строк несколько, то в качестве
    результата выдать первую из них. Имя фаила задается в
    команднои строке.
*/
    FILE *fp;
    char c; //iter
    long max=0, cur=0; //ind stroki
    long count=0, countmax =0; //dlin strok

    if ( (fp = fopen(argv[1],"r+") ) == NULL) { printf("err\n") ;return;}

    while ( (c = fgetc(fp)) != EOF ) {
        if (c!= '\n') {count++;}
        else {
            if (count > countmax){
                countmax;
                max = cur;
            }
            count = 0;
            cur = ftell(fp);
        }

    }//while

    fseek(fp, max, 0);
    while((c = fgetc(fp)) != '\n'){
        printf("%c",c);
    }
    printf("\ntask 5 samaya dlinn str\n");


    fclose(fp);
    return;
}
