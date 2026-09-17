#include<stdio.h>
void main(){
    int arr[] = {42, 7, 19, 3, 56, 12, 88, 25, 1, 34};
    int size = sizeof(arr)/sizeof(arr[0]);
    int min,temp,minIndex;
    for(int i=0;i<size-1;i++){
        min = arr[i];
        for(int j=i+1;j<size;j++){
            if(min>arr[j]){
                minIndex = j;
                min = arr[j];
            }
        }
        if(min!=arr[i]){
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}