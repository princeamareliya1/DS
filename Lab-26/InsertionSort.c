#include <stdio.h>
void main()
{
        int arr[]={42, 7, 19, 3, 56, 12, 88, 25, 1, 34};
        int size=sizeof(arr)/sizeof(arr[0]);
        int key;

        for (int i=1;i<size;i++)
        {
                key=arr[i];
                int j=i-1;
                while (j>=0 && arr[j]>key)
                {
                        arr[j+1]=arr[j];
                        j--;
                }

                arr[j+1] = key;
        }
        for (int i=0;i<size;i++)
        {
                printf("%d ",arr[i]);
        }
}