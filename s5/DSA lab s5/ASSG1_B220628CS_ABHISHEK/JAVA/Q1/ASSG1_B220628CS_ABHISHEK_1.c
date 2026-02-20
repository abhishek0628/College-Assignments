//problem
/*
1. Given an inorder and a preorder traversals of a binary tree, construct the unique binary tree T
corresponding to these traversals. The binary tree contains non-negative integers.
The program should include the following functions:
(a) main(): Repeatedly reads an input character from the menu list through the terminal and
executes menu driven operations accordingly.
(b) P ostOrder(T ): Prints the post order traversal of the binary tree T.
(c) ZIG ZAG(T ): Prints the Zig zag traversal (Definition is given below) of the binary tree T.
(d) LevelM ax(T ): Prints the nodes with maximum value at each level of the binary tree T.
(e) Diameter(T ): Prints the diameter (Definition is given below) of the binary tree T.
(f) RightLeaf Sum(T ): Prints the sum of the values of right leaf nodes(Definition is given below).
Definitions:
• Depth of a node: The length (number of edges) of the unique simple path from the root to
the node.
• Level of a tree: Level i (i varies from 0 to max depth) of a binary tree contains all nodes at
depth i (level 0 contains only root node).
• Zig zag Traversal: Level-order traversal of the binary tree where nodes are printed in a
zig-zag pattern in a single line. Specifically, at even levels (where level numbering starts from
0), nodes are printed from right to left and at odd levels, nodes are printed from left to right.
• Diameter of a tree: The diameter/width of a tree is defined as the number of nodes on the
longest simple path between any two leaf nodes.
• Right Leaf Node: A leaf node that is present as a right child to its parent node.
Input Format:
• The first line contains an integer n ∈[1, 106] indicating the number of nodes in the tree.
• The second line contains a space-separated sequence of n integers representing the IN ORDER
traversal of the tree T with key values ∈[1, 106].
• The third line contains a space-separated sequence of n integers representing the P REORDER
traversal of the tree T with key values ∈[1, 106].
• Each subsequent line contains a character from the set {‘p’, ‘z’, ‘m’, ‘d’, ‘s’, ‘e’}.
– Character ‘p’ calls P ostorder(T ) - to print the postorder traversal of the tree.
– Character ‘z’ calls ZIG ZAG(T ) - to print the Zig zag traversal of the tree.
– Character ‘m’ calls LevelM ax(T ) - to print the nodes with maximum value at each level.
– Character ‘d’ calls Diameter(T ) - to print the diameter of the binary tree.
– Character ‘s’ calls RightLeaf Sum(T ) - to print the sum of the values of all right leaf
nodes.
– Input ‘e’ terminates the execution of the program.
Output Format:
• The output of each command should be printed on a separate line.
• For option ‘p’, print the postorder traversal of T . Each node’s value is separated by a space.
• For option ‘z’, print the Zig zag traversal of T . Each node’s value is separated by a space.
• For option ‘m’, print the nodes with the maximum value at each level. Each node’s value is
separated by a space.
• For option ‘d’, print the diameter of T.
• For option ‘s’, print the sum of the values of all right leaf nodes.
Test Case 1
Input:
5
4 2 1 3 5
1 2 4 3 5
p
z
m
d
s
e
Output:
4 2 5 3 1
1 2 3 5 4
1 3 5
5
5
Test Case 2
Input:
7
4 2 5 1 6 3 7
1 2 4 5 3 6 7
p
z
m
d
s
e
Output:
4 5 2 6 7 3 1
1 2 3 7 6 5 4
1 3 7
5
12
*/

//solution
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create(int data)
{
    struct node *root=(struct node *)malloc(sizeof(struct node));
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    return root;
}
struct queue
{
    int rear;
    int front;
    int arr[100];

};
struct queue *createq()
{
    struct queue *q=(struct queue *)malloc(sizeof(struct queue));
    q->rear=0;
    q->front=0;
    return q;
}
int isEmpty(struct queue *q)
{
    return q->rear==q->front;
}
void push(struct queue *q,struct node *root )
{
    q->arr[q->rear++]=root;
    
}
struct node *pop(struct queue *q)
{
    if(q==NULL)return NULL;
    return q->arr[q->front++];
}
struct node *build(int l,int h,int *inorder,int *preorder,int *preindex,int size)
{
    
        int key=preorder[*preindex];
        (*preindex)++;
        struct node *root=create(key);
        if(l==h)return root;
        int i;
        for(i=0;i<size;i++)
        {
            if(inorder[i]==key)break;
        }
        root->left=build(l,i-1,inorder,preorder,preindex,size);
        root->right=build(i+1,h,inorder,preorder,preindex,size);
        return root;
    
    
    
}
void PostOrder(struct node *root)
{
    if(root==NULL)return;
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ",root->data);
}
void ZIG_ZAG(struct node *root)
{
    if(root==NULL)
    {
        printf("-1\n");
        return;
    }
    struct queue *q=createq();
    push(q,root);
    
    
    int islefttoright=1;
    while(isEmpty(q)==NULL)
    {
        int n=q->rear-q->front;
        int arr[100];
        for(int i=0;i<n;i++)
        {
            // int arr[100];
            struct node *temp=pop(q);
            arr[i]=temp->data;
            if(temp->left)
            {
                push(q,temp->left);
            }
            if(temp->right)
            {
                push(q,temp->right);
            }

        }
        if(islefttoright)
        for(int i=n-1;i>=0;i--)
        {
            printf("%d ",arr[i]);
        }
        else
        for(int i=0;i<n;i++)
        {
            printf("%d ",arr[i]);
        }
        islefttoright=0;
    }
}
int max(int arr[],int n)
{
    int m=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>m)

        {
            m=arr[i];
        }

    }
    return m;
}
void levelMax(struct node *root)
{
    if(root==NULL)
    {
        printf("-1\n");
        return;
    }
    struct queue *q=createq();
    push(q,root);
    
    
    while(isempty(q)==NULL)
    {
        int arr[100];
        int n=q->rear-q->front;
        for(int i=0;i<n;i++)
        {
            struct node *temp=pop(q);
            arr[i]=temp->data;
            if(temp->left)
            {
                push(q,temp->left);
            }
            if(temp->right)
            {
                push(q,temp->right);
            }

        }
        for(int i=0;i<n;i++)
        {
            printf("%d ",max(arr,n));
        }
    }
}
int height(struct node *root)
{
    if(root==NULL)return -1;
    int leftheight=height(root->left);
    int rightheight=height(root->right);
    return max(leftheight,rightheight)+1;


}
int dia(struct node *root,int *diameter)
{
    if(root==NULL)return;
    int left=dia(root->left,diameter);
    int right=dia(root->right,diameter);
    int current=left+right+2;
    if(current>*diameter)
    {
        *diameter=current;
    }
    return 1+max(left,right);
}
int diameter(struct node *root)
{
    int d=0;
    dia(root,&d);
    return d;
}
int rightleafsum(struct node *root)
{
    int sum=0;
    if(root && root->right->left==NULL && root->right->right==NULL)
    {
        sum=sum+root->right->data;
    }
    sum=sum+rightleafsum(root->left);
    sum=sum+rightleafsum(root->right);
    return sum;
}
int main()
{
    int n;
    scanf("%d",&n);
    int *inorder=(int *)malloc(sizeof(int)*n);
    int *preorder=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&inorder[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&preorder[i]);
    }
    int preindex=0;
    struct node *root=build(0,n-1,inorder,preorder,&preindex,n);
    char choice;
    while(scanf(" %c",&choice)!=EOF)
    {
        switch(choice)
        {
            case 'p':PostOrder(root);
                     printf("\n");
                     break;
            case 'z':ZIG_ZAG(root);
                     printf("\n");
                     break;
            case 'm':levelmax(root);
                     printf("\n");
                     break;
            case 'd':printf("%d\n",diameter(root));
                     break;
            case 's':printf("%d\n",rightleafsum(root));
                     break;
            case 'e':return 0;
        }
    }
    return 0;
}