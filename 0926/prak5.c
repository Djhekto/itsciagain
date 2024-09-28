/*
5.  Написать программу, которая подсчитывает
 количество своих аргументов командной
  строки вида  "123".  Остальные,
  отличные от "123", аргументы
   распечатать на экран в обратном
    порядке*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const **argv)
{
    if (argc<2){printf("error"); return 1; }

    char buf[1000] = " ";
    int rescount = 0;

    //for (int i =1; i<argc; i++){
    for (int i =argc-1; i>0; i--){
        if (strcmp(argv[i], "123") == 0){
            rescount++;
            continue;
        }
        strcat(buf, argv[i]);
        strcat(buf, " ");
    }
    printf("%s %d\n",buf,rescount);

}
