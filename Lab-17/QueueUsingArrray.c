#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int Queue[MAX];
int first=0;
int top=0;

void Enqueue(int x){
    Queue[top++] = x;
}

void Dequeue(){
    first++;
    Display();
}

void Display(){
    for(int i=first;i<top;i++){
        printf("%d ",Queue[i]);
    }
}

void main(){
    int choice,x,flag=0;
    while(1){
        printf("\n\n\n1.Enqueue\n2.dequeue\n3.Display:\nSelect Choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter a Element which will insert: ");
            scanf("%d",&x);
            Enqueue(x);
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            Display();
            flag=1;
            break;
        }
        if(flag==1){
            break;
        }
    }
}