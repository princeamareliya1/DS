#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int stack[MAX];
int top=-1;

void push(int value){
    stack[++top] = value;
}

int pop(){
    return stack[top--];
}

void operation(char c){
    int op;
    int b = pop();
    int a = pop();
    switch (c)
    {
    case '+':
        op = a + b;
        break;
    case '-':
        op = a - b;
        break;
    case '*':
        op = a * b;
        break; 
    case '/':
        op = a / b;
        break;
    }
    push(op);
}

void main(){
    char prefix[MAX];
    int num,j=0;
    printf("Enter a postfix Expression: ");
    scanf("%s",prefix);
    while(prefix[j] != '\0'){ 
        switch(prefix[j]){
            case '+':
            case '-':
            case '*':
            case '/':
                operation(prefix[j++]);
                break;
            default:
                num = prefix[j++] - '0';
                push(num);
        }
        j++;
    }
    printf("Result = ",stack[top]);
}
