#include <stdlib.h>
#include <stdio.h>
//kol-vo cifr v zapici ch-la
int task(long long int chislo)
    {
    int res = 0;
    printf("i worked\n");
    chislo = abs(chislo);
    while(chislo>0)
    {

        if (chislo%10 == 5) res++;
        chislo = chislo/10;

    }
    return res;
    }


int main()
    {
    long long int chislo = -1;
    printf("vvedi neotr chislo\n");
    scanf("%d", &chislo);
    int res1 = -1;
    res1 = task(chislo);

    printf("%d\n",res1);

    printf("xai omg xai\n");
    return 0;
    }

