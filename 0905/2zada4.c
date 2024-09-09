#include <string.h>
#include <stdlib.h>
#include <stdio.h>
//kol-vo cifr v zapici ch-la + dinami4 kol-vo pamyati lol
char* task(char* stroka)
    {
    printf("\n%s",stroka);
    int temp = strlen(stroka);
    printf("\ndlina str %d\n", temp);

    //char res[temp];
//      str = (char*)malloc(sizeof(char));
    char* res = malloc(temp);
    temp = sizeof(res);
    printf("\ntmemory siely  %d\n", temp);

    unsigned int ii = 0;
    unsigned int iii = 0;
    while(stroka[ii]!='\0') {
        if (stroka[ii]!=' ') {
            res[iii] = stroka[ii];
            iii++;
        } ii++;


    }

    res[iii]= '\0';
    return res;
    }


int main()
    {
   // char stroka[1000];
    char *stroka;
    scanf("%m[^\n]", &stroka);


//    scanf("%s",&stroka);
    printf("%s",stroka);
//    stroka = task(stroka);

    strcpy(stroka,task(stroka));
    printf("%s",stroka);

    return 0;
    }