#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    int level;
    struct node *left;
    struct node *right;
};
struct node* createNode(int value,int level){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = value;
    newNode->level = level;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct node* insert(struct node *root,int value,int level){
    if(root==NULL){
        return createNode(value,level);
    }
    if(root->info>value){
        root->left = insert(root->left,value,level+1);
    }else if(root->info<value){
        root->right = insert(root->right,value,level+1);
    }
    return root;
}
void main(){
    struct node *root = NULL;
    root = insert(root,50,1);
    root = insert(root,30,1);
    root = insert(root,70,1);
    root = insert(root,20,1);
    root = insert(root,40,1); 
}