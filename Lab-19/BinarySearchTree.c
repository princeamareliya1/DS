#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *left;
    int info;
    struct node *right;
};

struct node* createNode(int value){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->left = NULL;
    new->info = value;
    new->right = NULL;
    return new;
}

struct node* insert(struct node *root,int value){

    if(root==NULL){
        return createNode(value);
    }
    if(value<root->info){
        root->left = insert(root->left,value);
    }
    else if(value>root->info){
        root->right = createNode(value);
    }
    return root;
}

void main(){
    struct node* root = NULL;
    insert(root,15);
    insert(root,5);
    insert(root,20);

    // int choice,value,flag=0;
    // while(1){
    //     printf("\n1.Insert a node\n2.Exit\nEnter a choice:");
    //     scanf("%d",&choice);
    //     switch(choice){
    //         case 1:
    //             printf("Enter a Value to be inserted: ");
    //             scanf("%d",&value);
    //             root = insert(root,value);
    //             break;
    //         case 2:
    //             flag=1;
    //             break;
    //     }
    //     if(flag==1){
    //         break;
    //     }
    // }
}