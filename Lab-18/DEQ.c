#include <stdio.h>
#define MAX 100
int DEQ[MAX];
int first = -1;
int last = -1;
int size;
int flag=0;
void insertFirst(int x){
    if(first == 0){
        printf("Queue Overflow!");
        flag=1;
        return;
    }
    if(first == -1){
        first=0;
        last=0;
        DEQ[first] = x;
        return;
    }
    DEQ[--first] = x;
}
void insertLast(int x){
    if (last == size - 1){
        printf("Queue Overflow!");
        flag=1;
        return;
    }
    if (first==-1){
        first=0;
        last=0;
    }
    DEQ[++last] = x;
}
void deleteFirst(){
    if (first == -1){
        printf("Queue underflow!");
        flag=1;
        return;
    }
    first++;
}
void deleteLast(){
    if (last == -1){
        printf("Queue underflow!");
        flag=1;
        return;
    }
    if (first == last){
        first = last = -1;
    }else{
        last--;
    }
}
void display(){
    for (int i = first; i <= last; i++){
        printf("%d->", DEQ[i]);
    }
}
void main(){
    int choice,x;
    printf("Enter size:");
    scanf("%d",&size);
    while (1){
        printf("\n\n\n\n1.Insert Front\n2.Insert Rear\n3.Delete first\n4.Delete last\n5.display\nEnter a choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d",&x);
                insertFirst(x);
                display();
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d",&x);
                insertLast(x);
                display();
                break;
            case 3:
                deleteFirst();
                display();
                break;
            case 4:
                deleteLast();
                display();
                break;
            case 5:
                display();
                flag=1;
        }
        if(flag==1){
        break;
    }
    }
}