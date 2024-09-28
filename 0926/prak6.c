/*
6. Написать программу, которая
 получает которая получает в командной
 строке число N и печатает N символов '*'
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const **argv)
{
    if (argc<2){printf("error"); return 1; }
    int n;
    if (sscanf(argv[1],"%d",&n)) {return 1;}
    for(int i=0; i<n; i++) {printf("*");}
    return 0;
};