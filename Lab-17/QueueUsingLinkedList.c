#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct node{
    int data;
    struct node *link;
};

void display(struct node *first){
    struct node *temp = first;
    while (temp!=NULL)
    {  
       printf("%d ",temp->data);
       temp = temp->link; 
    }
    
}



int main(){

    struct node *first = NULL;
    struct node *last = NULL;

    int choice,x,flag=0;
    struct node *temp;

    while(flag!=1){
        printf("\n\n1.Enqueue\n2.Dequeue\n3.display\nEnter a Choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                printf("Enter a Value: ");
                scanf("%d",&x);
                struct node *new = (struct node *)malloc(sizeof(struct node));
                new->data = x;
                new->link = NULL;
                if(first==NULL){
                    first = new;
                    last = new;
                }else{
                    last->link = new;
                    last = last->link;
                }
                break;
            case 2:
                temp = first;
                if(first==last){
                    first = NULL;
                    last = NULL;
                }else{
                    first = first->link;
                }
                free(temp);
                break;
            case 3:
                display(first);
                flag=1;
                break;
        }
    }

    return 0;
}