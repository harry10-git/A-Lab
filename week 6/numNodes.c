#include<stdio.h>
#include<stdlib.h>

static int count =0;

typedef struct node
{
    int data;
    struct node * left;
    struct node * right;
}node;

node * newNode(int val)
{
    node * temp = (node*)malloc(sizeof(node));
    temp->data = val;

    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void printInorder(node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the data of node */
    printf("%d ", node->data);
 
    /* now recur on right child */
    printInorder(node->right);
}

void countNodes(node * root)
{
    if(root !=NULL)
    {
        countNodes(root->left);
        count ++;
        countNodes(root->right);
    }

}
 

int main()
{
    node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(9);
    root->right->right = newNode(8);
    root->left->left->left = newNode(6);
    root->left->left->right = newNode(7);

    countNodes(root);

    printf("Num of nodes : %d ", count);




    return 0;
}
