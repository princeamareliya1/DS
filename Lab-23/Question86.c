#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a[20],n=0,i,x,p;

    for(i=0;i<20;i++)
        a[i]=-1;

    srand(time(0));

    while(n<15)
    {
        x=100000+rand()%900000;
        p=(x%18)+2;

        while(a[p]!=-1)
            p=(p+1)%20;

        a[p]=x;
        n++;
    }

    for(i=0;i<20;i++)
        printf("%d : %d\n",i,a[i]);

    return 0;
}
