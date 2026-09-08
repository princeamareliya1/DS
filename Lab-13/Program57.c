#include<stdio.h>
#include<stdlib.h>
void push(int *last,int stack[],int data){
    (*last)++;
    stack[*last] = data;
}
int pop(int *last,int stack[]){
    int removed = stack[*last];
    (*last)--;
    return removed;
}
void display(int stack[],int last){
    printf("Stack element:\n ");
    for(int i=0;i<=last;i++){
        printf("%d ",stack[i]);
    }
}
void peep(int stack[],int index){
    printf("Element at [%d] position is %d",index,stack[index]);
}
void change(int stack[],int index,int data){
    stack[index] = data;
    printf("Changed at [%d] position with value %d",index,data);
}
void main(){
    int stack[100];
    int last = -1;
    while(1){
        int choice,data,result,index;
        printf("\n\n\n\n\n\n1.push \n2.pop \n3.display \n4.peep \n5.change\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter a Element which is push: ");
                scanf("%d",&data);
                push(&last,stack,data);
                break;
            case 2:
                result = pop(&last,stack);
                printf("Deleted element: %d",result);
                break;
            case 3:
                display(stack,last);
                break;
            case 4:
                printf("Enter a Index of Element: ");
                scanf("%d",&index);
                peep(stack,index);
                break;
            case 5:
                printf("Enter a Index of element which is change: ");
                scanf("%d",&index);
                printf("Enter a Element which is insert: ");
                scanf("%d",&data);
                change(stack,index,data);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid input!");
        }
    }
}