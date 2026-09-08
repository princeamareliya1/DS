#include <stdio.h>
#include <stdlib.h>
struct node {
    struct node *left;
    int info;
    struct node *right;
};
struct node* newNode(int value) {
    struct node* new = (struct node *)malloc(sizeof(struct node));
    new->left = NULL;
    new->info = value;
    new->right = NULL;
    return new;
}
int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}
struct node* constructTree(int pre[], int post[],int *preIndex, int start, int end, int n) {
    if (*preIndex >= n || start > end)
        return NULL;

    struct node* root = newNode(pre[*preIndex]);
    (*preIndex)++;

    if (start == end || *preIndex >= n){
        return root;
    }

    int pos = search(post, start, end, pre[*preIndex]);
    if (pos != -1) {
        root->left = constructTree(pre, post, preIndex,start, pos, n);
        root->right = constructTree(pre, post, preIndex,pos + 1, end - 1, n);
    }

    return root;
}
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}
void main() {
    int n, preIndex = 0;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int pre[n], post[n];

    printf("Enter Preorder traversal: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pre[i]);

    printf("Enter Postorder traversal: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);

    struct node* root = constructTree(pre, post, &preIndex, 0, n - 1, n);

    printf("Inorder traversal of constructed tree: ");
    inorder(root);
}