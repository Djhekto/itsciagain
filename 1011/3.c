/*3. Написать программу, которая распечатывает те аргументы своей командной строки,
 которые оканчиваются символами ".c"

*/
#include <stdio.h>
#include <string.h>


int main(int argc, char** argv){

    if (argc<2){printf("error"); return 1; }

    char* p1;
    short flagfordot = 0;
    short flagforci  = 0;
    int storestrlen = 0;

    for (int i = 1; i<argc; i++){

        p1 = argv[i];

        flagfordot = 0;
        flagforci  = 0;
        storestrlen = strlen(argv[i]);

        if (storestrlen<3) {continue;}
//        printf("\n");

        while (*p1!='\0'){

            if (flagfordot){
                if (*p1 == 'c'){
                    flagforci = 1;
                    p1++;
//                    printf("  %c %d %d   ",*p1,flagfordot, flagforci);
                    continue;
                }
            }

            if (*p1 == '.'){
                flagfordot = 1;
            }
            else {                flagfordot = 0;            }

//            printf("  %c %d %d   ",*p1,flagfordot, flagforci);
            
            p1++;

        }//while

    if (flagforci && flagfordot) {printf("\n%s\n",argv[i]);}

    }//for

    return 0;
}

/*
//    char**p2;

    for (int i = 1; i<argc; i++){
        p1 = argv[i]; //p1++;
//        p2 = argv[i][0];
        printf("s %s\n",p1);
        printf("c %c\n",*p1);
//        printf("c2%c\n",p2);
        printf("s %s\n",argv[i]);
    }

//    return 0;


        for (int ii = 0; i<storestrlen ; i++){
                    
        }


        printf("s %s\n",p1);
        printf("c %c\n",*p1);
        printf("s %s\n",argv[i]);


int main(int argc, char **argv)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < argc; i ++)
    {
    j = 0;      
    while(argv[i][j] != '\0')
       printf("Argument %d letter %d : %c\n", i,j,argv[i][j++]);   
    }
    return 0;
}

    char buf[1000] = " ";

*/
