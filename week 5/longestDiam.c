#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node * left;
    struct node * right;
}node;

node * newNode(int ele)
{
    node * temp = (node*)malloc(sizeof(node));

    temp->data= ele;
    temp->left= NULL;
    temp->right= NULL;

    return temp;
}


int max(int a , int b)
{
    return (a>b)?a:b;
}



int height(node * root)
{
    if(root == NULL)
        return 0;
    
    return 1 + max(height(root->left), height(root->right));
}


int diameter(node * root)
{
    if(root == NULL)
        return 0;

    int lheight = height(root->left);
    int rheight = height(root->right);
    
    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);

    return max(lheight+rheight+1, max(ldiameter,rdiameter));

    
}



int main()
{

    node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int res= diameter(root);

    printf("The diameter is %d ", res);
    return 0;
}