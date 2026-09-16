#include<stdio.h>
int main(){
    int n;
    printf("Enter a Size of Array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter a Value of arr[%d]: ",(i));
        scanf("%d",&arr[i]);
    }
    int search,flag=0;
    printf("Enter a Number for Searching: ");
    scanf("%d",&search);
    for(int i=0;i<n;i++){
        if(arr[i]==search){
            printf("\n%d is found at index %d",search,i);
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("\n%d isn't found in the array",search);
    }
}