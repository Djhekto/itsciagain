/*7. Программа — «архиватор» фаилов.
Написать две функции: archive_s(s,t) и extract_s(s,t), параметр
s - исходныи фаил, t - фаил в которои требуется получить
результат. 
archive_s(s,t) 
Последовательность из n одинаковых символов первого фаила
переносится во второи как 2 баита:  баит, содержащии значение n
и баит, содержащии код символа. Например, последовательность
bbbbbb (занимает 6 баитов) должна быть заменена на 6b (2
баита), последовательность a заменяется на 1а. Повторяющиеся
последовательности из более, чем 255 баитов поделить на
несколько подпоследовательностеи. 
extract_s(s,t) — обратная операция
Сравнить размеры фаилов, привести пример, когда «архивация»
уменьшает размер фаила, и когда происходит увеличение размера.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void archive(char* filename1, char*  filename2 );


int main(){
    archive("matrix2.bin", "matrix2.bin" );
    return 0;
}

void archive(char* filename1, char* filename2 ){
    int istr1[1000];
    {
    FILE *fp;

    printf("reading from binary file %s\n", filename1);

    if ( (fp = fopen(filename1,"rb") ) == NULL) { 
        printf("Error opening file\n");
        return;
    }

    int count = 0;
    while (count < 1000 && fread(&istr1[count], sizeof(int), 1, fp) == 1) {
        printf("%d\n", istr1[count]);
        count++;
    }

    fclose(fp);
    }

    {
    FILE *fp;

    printf("reading into binary file %s\n", filename2);

    if ( (fp = fopen(filename2,"rb") ) == NULL) { 
        printf("Error opening file\n");
        return;
    }


    fclose(fp);
    }

}
/*
void archive(char*  filename1, char*  filename2 ){
    FILE *fp;
    char str1[1000];
    int istr1[1000];
    char* p1 = str1;
    int* ip1 = istr1;

    printf("reading from binary file %s\n", filename1);

    if ( (fp = fopen(filename1,"rb") ) == NULL) { printf("err\n") ;return;}

    while ( 1 ) {
        fread(p1, sizeof(int), 1, fp);
        printf("%d\n",*p1);
        if (*p1 == EOF) {break;}
        p1++;
    }
    for (int i = 0; i<1000; i++)
    printf("reading %d", istr1[i]);


//    while ( (*p1 = fgetc(fp)) != EOF ) {
/*
    while ( 1 ) {
        fread(p1, sizeof(int), 1, fp);
        printf("%c\n",*p1);
        if (*p1 == EOF) {break;}
        p1++;
    }
    *p1 = '\0';

    printf("reading %s\n", str1);



    printf("End of binary file matrix input from file\n");

    fclose(fp);

    return;
}
*/