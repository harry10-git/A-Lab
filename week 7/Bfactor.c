#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node * left;
    struct node * right;
}node;  

node * newNode(int val){
    node * temp = malloc(sizeof(node));
    temp-> data = val;
    temp -> right = temp->left = NULL;
    return temp;
}

int max(int a , int b){
    return (a>b)?a:b;
}

int height (node * root)
{
    if(root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}


void balanceFactor(node * root){
    int l = height(root->left);
    int r = height(root->right);

    printf("BF of %d is %d", root->data, (l-r));
}

void inorder(node * root)
{
    if(root !=NULL){
        inorder(root->left);
        // printf("%d ",root->data);
        balanceFactor(root);
        printf("\n");
        inorder(root->right);
    }
}





int main()
{
    node * root = newNode(5);
    root->left = newNode(4);
    root->right = newNode(1);
    root-> left->left = newNode(14);
    root-> right -> left = newNode(25);
    root-> right -> left->right = newNode(55);

        //     5
        //    / \
        //   4   1
        //  /    /  
        // 14   25
        //       \
        //        55

    inorder(root);
    printf("\n");

    // printf("\n height %d", height(root));

    return 0;
}