#include<stdio.h>
int BinarySearch(int arr[],int size,int target){
    int index=0,left=0,right=size-1;
    while(left<=right){
        index = left + (right-left)/2;
        if(arr[index]<target){
            left = index+1;
        }else if(arr[index]>target){
            right = index-1;
        }else{
            return index;
        }
    }
    return -1;
}
int main(){
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 52;

    int result = BinarySearch(arr, size, target);
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }
}