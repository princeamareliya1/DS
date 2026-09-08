#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

void reversedList()
{
    struct node *save = first, *pred = NULL, *next = NULL;
    while(save != NULL){
        next = save->link;
        save -> link = pred;
        pred = save;
        save = next;
    }
    first = pred;
}

void main()
{

}