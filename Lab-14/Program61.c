#include<stdio.h>
#include<stdlib.h>
int top=-1,*stack,len;
void push(char x){
    top++;
    stack[top]=x;
}
void pop(char x){
    if(x == ')' || '}' || '>' || ']'){
        top--;
    }
}
void main(){
    char s[100],len=0;
    printf("Enter a String: ");
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++){
        len++;
    }
    stack = (int *)malloc(sizeof(int)*len);
    for(int i=0;i<len;i++){
        switch(s[i]){
            case '(' || '{' || '<' || '[': push(s[i]);
            break;
            case ')' || '}' || '>' || ']' : pop(s[i]);
            break;
            default:
            break;
        }
    }
}