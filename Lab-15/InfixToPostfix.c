#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char c) {
    if (top < MAX - 1) stack[++top] = c;
}
char pop() {
    if (top >= 0) return stack[top--];
    return '\0';
}
char peek() {
    if (top >= 0) return stack[top];
    return '\0';
}
int precedence(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}
void Postfix(char* infix) {
    char postfix[MAX];
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        char c = infix[i];
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && peek() != '(')
                postfix[j++] = pop();
            pop();
        } else {
            while (top != -1 && precedence(peek()) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
        i++;
    }
    while (top != -1)   postfix[j++] = pop();
    postfix[j] = '\0';
    printf("Output = %s", postfix);
}
void main() {
    char s[MAX];
    printf("Enter String: ");
    scanf("%s", s);
    Postfix(s);
}