#include<stdio.h>
#include<stdlib.h>
int top = -1,*stack,size;
void push(int x){
    if(top==size-1){
        printf("Stack Overflow!\n");
        return;
    }
    top++;
    stack[top]=x;
}
int pop(){
    if(top==-1){
        printf("Stack Underflow!\n");
        return -1;
    }
    top--;
    return stack[top+1];
}
void display(){
    if(top==-1){
        printf("Stack is Empty!\n");
        return;
    }
    printf("\n\n\n");
    for(int i=0;i<=top;i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
}
int main(){
    printf("Enter a Size of Stack:");
    scanf("%d",&size);
    stack = (int *)malloc(sizeof(int)*size);
    while(1){
        int c,x,removed;
        printf("1.push:\n");
        printf("2.pop:\n");
        printf("Choose the case:");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            printf("Enter a Element: ");
            scanf("%d",&x);
            push(x);
            display();
            break;
        case 2:
            removed = pop();
            if(removed != -1){
                printf("Removed Element = %d",removed);
                display();
            }
            break;
        default:
            free(stack);
            exit(0);
        }
    }
    return 0;
}