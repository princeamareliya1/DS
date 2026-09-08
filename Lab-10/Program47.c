#include <stdio.h>
struct node {
    int data;
    struct node *link;
};
struct node *createNode(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->link = NULL;
    return newnode;
}
void insert(struct node **first, int data) {
    struct node *newnode = createNode(data);
    if (*first == NULL) {
        *first = newnode;
        return;
    }
    struct node *temp = *first;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = newnode;
}
void sortlist(struct node **first, int n) {
    for (int i = 0; i < n - 1; i++) {
        struct node **save = first;
        for (int j = 0; j < n - i - 1; j++) {
            struct node *a = *save;
            struct node *b = a->link;
            if (b != NULL && a->data > b->data) {
                a->link = b->link;
                b->link = a;
                *save = b;
            }
            save = &((*save)->link);
        }
    }
}
void printlist(struct node *first) {
    struct node *save = first;
    while (save != NULL) {
        printf("%d ", save->data);
        save = save->link;
    }
}
void main(){
    struct node *first = NULL;
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter a number: ");
        scanf("%d", &val);
        insert(&first, val);
    }
    sortlist(&first, n);
    printf("Sort : ");
    printlist(first);
}