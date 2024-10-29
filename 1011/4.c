/*4. Написать функцию сравнения строк без учета
 пробелов (строки ”a b c” и ” ab c” считаются равными). 
*/

#include <stdio.h>

void task4 (char* , char*);

int main(int argc, char** argv){
    {    
    char* s1 = "as sda  da ds";
    char* s2 = "assda   dads";
    task4(s1,s2);
    }
    {    
    char* s1 = "a sd l kasj";
    char* s2 = "assda   dads";
    task4(s1,s2);
    }
    return 0;
}

void task4 (char* s1 , char* s2){
    char* p1 = s1;
    char* p2 = s2;
    while(*p1!='\0'){
        if(*p1=='\0'){break;}
        if(*p2=='\0'){break;}

        while (*p1==' '){
            p1++;
            if(*p1=='\0'){break;}
        }
        while (*p2==' '){
            p2++;
            if(*p2=='\0'){break;}
        }

        if (*p1!=*p2) {break;}
        p1++; p2++;

        if (*p1=='\0' && *p2=='\0') {
            printf("equal\n");
            return;
        }

    }
    printf("not equal\n");
    return;
    }

/*
void task4 (char* s1 , char* s2){
    char* p1 = s1;
    char* p2 = s2;
    char store1='1';
    char store2='2';
    while(1){
        
    }
    return;
}
*/