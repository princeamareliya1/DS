#include <stdio.h>
#define SIZE 20

void main()
{
    int a[SIZE],n=0,i,x,p;

    for(i=0;i<SIZE;i++)
        a[i]=-1;

    while(n<15)
    {
        printf("Enter value: ");
        scanf("%d",&x);

        p=(x%18)+2;

        while(a[p]!=-1)
        {
            if(a[p]==x)
                break;
            p=(p+1)%SIZE;
        }

        if(a[p]==-1)
        {
            a[p]=x;
            n++;
        }
    }

    printf("\nHash Set:\n");
    for(i=0;i<SIZE;i++)
        printf("%d : %d\n",i,a[i]);
}