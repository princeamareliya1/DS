#include <stdio.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void insertFront(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}
void insertEnd(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}
void deletePos(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head, *prev;
    int count = 1;
    if (pos == 1) {
        while (temp->next != head) {
            temp = temp->next;
        }
        if (head->next == head) {
            free(head);
            head = NULL;
        } else {
            temp->next = head->next;
            free(head);
            head = temp->next;
        }
    }
    temp = head;
    while (count < pos && temp->next != head) {
        prev = temp;
        temp = temp->next;
        count++;
    }
    if (count == pos) {
        prev->next = temp->next;
        free(temp);
    } else {
        printf("Position not found!\n");
    }
}
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
    }
    struct Node *temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
}
int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Position\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePos(pos);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}
