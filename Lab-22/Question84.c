#include<stdio.h>
struct node{
    int info;
    struct node *link;
};
struct graph{
    int vertices;
    struct node **adjlist;
};
struct node* createNode(int info){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info =  info;
    newNode->link = NULL;
    return newNode;
}
struct graph* createGraph(int vertices){
    struct graph *grp = (struct graph*)malloc(sizeof(struct graph));Z
}