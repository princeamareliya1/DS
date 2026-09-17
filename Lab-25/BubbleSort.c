#include<stdio.h>
int main(){
    int arr[] = {7, 42, 19, 3, 56, 12, 88, 25, 1, 34};
    int size = sizeof(arr)/sizeof(arr[0]);
    int temp;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}