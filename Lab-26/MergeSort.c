#include<stdio.h>
void merge(int arr[],int low,int mid,int high){
    int i=low,j=mid+1,k=0;
    int temp[high-low+1];
    while(i<=mid&&j<=high)
    {
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=high){
        temp[k++]=arr[j++];
    }
    for(i=low,k=0;i<=high;i++,k++){
        arr[i]=temp[k];
    }
}
void mergeSort(int arr[],int low,int high){
    if(low<high)
    {
        int mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
void main()
{
    int arr[]={42,7,19,3,56,12,88,25};
    int size=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,size-1);
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}
