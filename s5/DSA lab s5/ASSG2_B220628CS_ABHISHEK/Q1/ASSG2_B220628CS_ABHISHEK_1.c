//problem
/*
1. Given a sequence of operations to perform on an AVL tree T with n keys, where n ∈ [1, 106].
Implement a menu driven program with the following functions:
(a) AV L insert(T, n)- Insert the given key n into the AVL tree T . Perform necessary rotations
to balance the AVL tree and AVL tree properties are maintained after the insertion.
(b) AV L f ind(T, n)- Search for the given key n in the AVL tree T.
(c) AV L postorder(T )- Perform postorder traversal and print the keys in the AVL tree T.
(d) AV L rotations(T )- Calculate and print the total number of left and right rotations required
so far to balance the AVL tree T from the beginning.
(e) AV L delete(T, n)- Print all the ancestors of n in T (order starting from the node itself up to
the root) and delete the given key n. Ancestor of a node n: We call any node y on the unique
simple path from the root of the tree to n, an ancestor of n. Please note that n is also an
ancestor of itself. For the delete operation, if required, replace a node/key with its inorder
successor.
(f) AV L balanceF actor(T, n)- Find the balance factor of the given node n in T.
Input format:
• Each line contains a character from {‘i’, ‘f ’, ‘p’, ‘s’, ‘d’, ‘b’, ‘e’ } followed by zero or one
integer n, where n ∈ [1, 106].
• Character ‘i’ is followed by a positive integer n separated by a space. Perform AV L insert(T, n)
operation. Assume that unique values are inserted.
• Character ‘f ’ followed by a positive integer n separated by a space. Perform AV L f ind(T, n)
operation.
• Character ‘p’ is to perform postorder traversal of T , AV L postorder(T ).
• Character ‘s’ Perform AV L rotations(T ) operation.
• Character ‘d’ followed by a positive integer n separated by a space. Perform AV L delete(T, n)
operation.
• Character ‘b’ followed by an integer n separated by a space. Perform AV L balanceF actor(T, n)
operation.
• Character ‘e’ is to terminate the sequence of operations.
Output Format
• The output (if any) of each command should be printed on a separate line. However, no
output is printed for ‘i’and ‘e’.
• For option ‘f ’, If the given key is found, print the path from the root to the node containing
the keys separated by a space; otherwise, print -1.
• For option ‘p’, print the keys in the nodes of T obtained from the postorder traversal. Sequence
of integers are separated by a space.
• For option ‘s’, print two integers representing total number of left rotations followed by the
total number of right rotations separated by a space.
• For option ‘d’, print all the ancestors of the deleted node n in T . The output is printed as a
space-separated sequence in a single line. Print -1 if the key n is not present.
• For option ‘b’, print balance factor of the given node n in T . Print -1 if the key n is not
present.
2
Sample test case 1
Input:
i 10
i 20
i 30
s
i 40
p
i 50
i 5
b 20
i 1
s
f 10
f 56
d 40
e
Output:
1 0
10 40 30 20
0
2 1
20 5 10
-1
40 20
*/

//solution
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
    int height;
};
struct node *create(int data)
{
    struct node *root=(struct node *)malloc(sizeof(struct node));
    root->left=NULL;
    root->right=NULL;
    root->data=data;
    root->parent=NULL;
    root->height=1;
    return root;
}
int max(int a,int b)
{
    return (a>b?a:b);
}
int height(struct node *root)
{
    if(root==NULL)return 0;
    return root->height;
}
struct node *leftrotate(struct node *y)
{
    struct node *x=y->right;
    struct node *t=x->left;

    x->left=y;
    y->right=t;
    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;
    return x;

}
struct node *rightrotate(struct node *y)
{
    struct node *x=y->left;
    struct node *t=x->right;
    x->right=y;
    y->left=t;

    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;
    return x;

}
int getbalance(struct node *root)
{
    if(root==NULL)return 0;
    return height(root->left)-height(root->right);

}
struct node *insert(struct node *root,int data)
{
    if(root==NULL)return create(data);
    if(data>root->data)
    {

        root->right=insert(root->right,data);
        struct node *temp=root->right;
        temp->parent=root;
    }
    else if(root->data>data)
    {
        root->left=insert(root->left,data);
        struct node *temp=root->left;
        temp->parent=root;
    }
    else return root;
    
    root->height=max(height(root->left),height(root->right))+1;
    int balance=getbalance(root);
    if(balance>1 && data<root->left->data)
    {
        return rightrotate(root);
    }
    if(balance>1 && data>root->left->data)
    {
        root->left=leftrotate(root->left);
        return rightrotate(root);

    }
    if(balance<-1 && data>root->right->data)
    {
        return leftrotate(root);
    }
    if(balance<-1 && data<root->right->data)
    {
        root->right=rightrotate(root->right);
        return rightrotate(root);
    }
    return root;
}
void printanscestors_reverse(struct node *root){
    if(root==NULL)return  ;
    struct node *temp=root->parent;
    printf("%d ",root->data);
    int *arr=(int *)malloc(sizeof(int)*1000);
    int k=0;
    while(temp!=NULL)
    {
        // printf("%d ",temp->data);
        arr[k++]=temp->data;
        temp=temp->parent;
    }
    for(int i=k;i>=0;i--)
    {
        printf("%d ",arr[i]);
    }
}
struct node * search(struct node *root,int data)
{
    if(root==NULL)return NULL;
    if(data>root->data)
    {
        return search(root->right,data);
    }
    return search(root->left,data);

}
void postorder(struct node *root)
{
    if(root==NULL)return ;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
struct node *minimum(struct node *root)
{
    if(root==NULL)return NULL;
    while(root &&root->left)
    {
        root=root->left;
    }
    return root;
}
struct node *inorder_succ(struct node *root)
{
    if(root==NULL)return NULL;
    if(root->right)
    {
        return minimum(root->right);
    }
    struct node *y=root->parent;
    while(y && root==y->right)
    {
        root=y;
        y=y->parent;
    }
    return y;

    
}

void printanscestors(struct node *root){
    if(root==NULL)return  ;
    struct node *temp=root->parent;
    printf("%d ",root->data);
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->parent;
    }
}
struct node *delete(struct node *root,int data)
{
    if(root==NULL)
    {
        return root;
    }
    if(root->data>data)
    {
        root->left=delete(root->left,data);
    }
    if(root->data<data)
    {
        root->right=delete(root->right,data);
    }
    else
    {
        if(root->left==NULL)
        {
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        if(root->right==NULL)
        {
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        struct node *n=search(root,data);
        struct node *temp=inorder_succ(n);
        root->data=temp->data;
        root->right=delete(root->right,temp->data);

    }
    return root;

}
int main()
{
    struct node *root=NULL;
    char choice;
    int data;
    while(scanf("%c",&choice)!=EOF)
    {
        switch(choice)
        {
            case 'i':scanf("%d",&data);
                     root=insert(root,data);
                     break;

            case 'p':postorder(root);
                     printf("\n");
                     break;
            case 'f':scanf("%d",&data);
                     struct node *temp1=search(root,data);
                     printanscestors(temp1);
                     break;
            case 'd':scanf("%d",&data);
            struct node *temp2=search(root,data);
            printanscestors(temp2);
            root=delete(root,data);
            break;
            case 'b':
            scanf("%d",&data);
            struct node *temp3=search(root,data);
            printf("%d ",getbalance(temp3));
            break;
            case 'e':return 0;

        }
    }
}