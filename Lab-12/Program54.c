#include <stdio.h>
struct node{
    int data;
    struct node* lptr;
    struct node* rptr;
};
struct node* first = NULL;
void insert(int value)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->lptr=NULL;
    newnode->rptr=first;
    if (first!=NULL) 
    {
        first->lptr=newnode;
    }
    first=newnode;
}
void delete(int position) 
{
    if(first == NULL) 
    {
        printf("List is empty.\n");
    }
    struct node* save = first;
    int i;
    for(i=1;save!=NULL&&i<position;i++) 
    {
        save=save->rptr;
    }
    if(save==NULL) 
    {
        printf("Position out of range.\n");
    }
    if(save->lptr!=NULL)
    {
        save->lptr->rptr=save->rptr;
    }
    else{
        first=save->rptr;
    }
    if(save->rptr!=NULL) 
    {
        save->rptr->lptr = save->lptr;
    }
    free(save);
    printf("Node deleted at [%d] position\n", position);
    
}
void display() 
{
    struct node* save = first;
    if(save==NULL){
        printf("List is empty.\n\n");
    }
    while (save!=NULL){
        printf("%d ", save->data);
        save=save->rptr;
    }
}
int main()
{
    int n,data,choice,position;
    printf("Enter a size: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("Enter a number [%d]: ",(i));
        scanf("%d",&data);
        insert(data);
    }
    while(1){
        printf("1. Delete from Position\n");
        printf("2. exit\n");
        printf("select : ");
        scanf("%d", &choice);
        switch(choice) 
        {
        case 1:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            delete(position);
            break;
        case 2:
            display();
            exit(0);
            break;
        }
    }
}