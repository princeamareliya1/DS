#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *createnode(int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
k
struct node *copylist(struct node *head){
    struct node first2 = createnode(first2->data);
}

void main()
{
    
}