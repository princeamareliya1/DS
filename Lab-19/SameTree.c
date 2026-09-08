#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* createNode(int data)
{
    struct Node *new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}
int areSame(struct Node *root1, struct Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return 1;

    if (root1 == NULL || root2 == NULL)
        return 0;

    return (root1->data == root2->data &&
            areSame(root1->left, root2->left) &&
            areSame(root1->right, root2->right));
}
int isMirror(struct Node *root1, struct Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return 1;

    if (root1 == NULL || root2 == NULL)
        return 0;

    return (root1->data == root2->data &&
            isMirror(root1->left, root2->right) &&
            isMirror(root1->right, root2->left));
}
int isSymmetric(struct Node *root)
{
    if (root == NULL)
        return 1;

    return isMirror(root->left, root->right);
}
void main()
{
    struct Node *tree1 = createNode(8);
    tree1->left = createNode(5);
    tree1->right = createNode(5);
    tree1->left->left = createNode(3);
    tree1->left->right = createNode(6);
    tree1->right->left = createNode(6);
    tree1->right->right = createNode(3);
    struct Node *tree2 = createNode(8);
    tree2->left = createNode(5);
    tree2->right = createNode(5);
    tree2->left->left = createNode(3);
    tree2->left->right = createNode(6);
    tree2->right->left = createNode(6);
    tree2->right->right = createNode(3);
    if (areSame(tree1, tree2)){
        printf("Given two trees are same\n");
    }
    else{
        printf("Given two trees are not same\n");
    }
    if (isSymmetric(tree1)){
        printf("Given tree is symmetric\n");
    }
    else{
        printf("Given tree is not symmetric\n");
    }
}