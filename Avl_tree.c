#include<stdio.h>
#include<stdlib.h>

typedef struct st
{
    struct st *left, *right;
    int data, bfactor;
}Node;

Node* create_node(int value)
{
    Node* tmp = (Node*)malloc(sizeof(Node));

    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->bfactor = 0;

    return tmp;
}

int depth(Node* root)
{
    int lh, rh;
    if(root == NULL)
        return 0;
    lh = depth(root->left);
    rh = depth(root->right);

    return (lh>rh)? lh+1 : rh+1;
}

void updatefactor(Node* root)
{
    if(root != NULL)
        return;
    root->bfactor = depth(root->left) - depth(root->right);
}

void leftrotate(Node** root)
{
    if((*root) == NULL || (*root)->right == NULL)
        return;
    
    Node* temp = (*root)->right->left;
    (*root)->right->left = (*root);
    (*root) = (*root)->right;
    (*root)->left->right = temp;

    updatefactor(*root);
    updatefactor((*root)->left);
}

void rightrotate(Node** root)
{
    if((*root) == NULL || (*root)->left == NULL)
        return;
    
    Node* temp = (*root)->left->right;
    (*root)->left->right = (*root);
    (*root) = (*root)->left;
    (*root)->right->left = temp;

    updatefactor(*root);
    updatefactor((*root)->right);
}

void balancenode(Node** root)
{
    if(*root == NULL)
        return;
    if(*root)
    {
        updatefactor(*root);
        if((*root)->bfactor > 1)
        {
            if((*root)->left->bfactor < 0)
                leftrotate(&(*root)->left);
            rightrotate(root);
        }
        else if((*root)->bfactor < -1)
        {
            if((*root)->bfactor > 0)
                rightrotate(&(*root)->right);
            leftrotate(root);
        }
        else
            return;
    }
}

void insert(Node** root, int value)
{
    if(*root == NULL)
        *root = create_node(value);
    else
    {
        if(value < (*root)->data)
            insert(&(*root)->left, value);
        else
            insert(&(*root)->right, value);
    } 
}