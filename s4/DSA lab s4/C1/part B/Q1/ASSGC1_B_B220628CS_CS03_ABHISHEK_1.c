//problem
/*
1. Given an inorder and a preorder traversal of a binary tree, construct the unique binary tree T
corresponding to the traversals given.
The binary tree contains non-negative integers as data to be sorted.
The program should support the following functions:
(a) main(): Repeatedly reads an input character from the menu list through the terminal and
executes menu driven operations accordingly.The Menu list is [‘p’,’z’,’m’,’d’,’s’].
(b) PostOrder(T): Prints the post order traversal of the binary tree T
(c) ZIG ZAG(T): Prints the ZIGZAG traversal (Definition is given below) of the binary tree T
(d) Level Max(T): Prints maximum element at each level of the binary tree T.
(e) Diameter(T): Prints the diameter of the binary tree T
(f) Left Leaf Sum(T): Prints the sum of the values of left leaf nodes.
Definitions:
Depth of a node: Length(no of edges) of the unique simple path from the root to the node
Level of a tree: All the nodes at the same depth form a level of the tree. Root is at level 0 and the
nodes at depth 1 are at level 1, nodes at depth 2 are at level 2.
ZIG-ZAG Traversal of a Binary Tree: It is a level order traversal in which if the level no is even,
nodes will be printed from left to right and if the level no is odd, nodes will be printed from right
to left. Please note that level no starts from 0.
DIAMETER of tree :The diameter/width of a tree is defined as the number of nodes on the longest
simple path between two end nodes.
Left Leaf Node: A leaf node which is present as a left child to its parent node.
Input Format:
• The first line is an integer n ∈ [1, 106] indicating the number of nodes in the tree.
• Second line of the input contains a space separated integer sequence of “n” numbers repres-
enting INORDER traversal of the tree T with key values ∈ [1, 106]
• Third line of the input contains a space separated integer sequence of “n” numbers representing
PREORDER traversal of the tree T with key values ∈ [1, 106]
• Next Each line contains a character [‘p’,’z’,’m’,’d’,’s’].
– Character ‘p’ call - Postorder(T) - is to print the post order traversal of a tree.
– Character ‘z’ call - ZIG ZAG(T) - is to print the zig-zag traversal of the tree.
– Character ‘m’call - Level Max(T) - is to print max elements at each level.
– Character ‘d’ call - Diameter(T) - is to print the diameter of a binary tree.
– Character ‘s’ call - Left Leaf Sum(T) - is to print the sum of all left leaf nodes.
Output Format:
• Lines contains appropriate output sequence of integer or an integer output
Sample Input 1:
7
4 2 5 1 6 3 7
1 2 4 5 3 6 7
p
z
m
d
s
Sample Output 1:
4 5 2 6 7 3 1
1 3 2 4 5 6 7
1 3 7
5
10
Sample Input 2:
4
4 2 5 1
1 2 4 5
z
p
s
d
Sample Output 2:
1 2 3 4
4 5 2 1
4
3
*/
//solution
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct q
{
    int front;
    int rear;
    struct node *arr[100];
};
struct q *createe()
{
    struct q *q=(struct q*)malloc(sizeof(struct q));
    q->front =0;
    q->rear=0;
    return q;
}
struct q* push(struct q* q,struct node *root)
{
    q->arr[q->rear++]=root;
    return q;

}
struct node *pop(struct q *q)
{
    return q->arr[q->front++];
}
int isempty(struct q *q)
{
    return q->front==q->rear;
}
void zigzag(struct node *root)
{
    struct q * q=createe();
    q=push(q,root);
    q=push(q,NULL);
    int level=0;
    while(!isempty(q))
    {
        struct node *temp=pop(q);
        if(temp==NULL)
        {
            level++;
            printf("\n");
            if(!isempty(q))
            {
                q=push(q,NULL);
            }
        }
        else
        {
            printf("%d ",temp->data);
            if(level%2==0)
            {
            if(temp->left)q=push(q,temp->left);
            if(temp->right)q=push(q,temp->right);

            }
            else if(level%2==1)
            {
            if(temp->right)q=push(q,temp->right);
            if(temp->left)q=push(q,temp->left);
            }
        }
    }
}
int sum(struct node *root)
{
    if(root==NULL)return 0;
    return sum(root->left)+sum(root->right)+root->data;

}
int leafsum(struct node *root)
{
    int count=0;
    if(root!=NULL && root->left!=NULL && root->left->left==NULL && root->left->right==NULL)
    {
        count=count+root->left->data;
    }
    count=count+leafsum(root->left);
    count=count+leafsum(root->right);
    return count;
}
// int leftleafsum(struct node *root)
// {
//     if(root==NULL)return 0;
//     if(root->left==NULL && root->right==NULL)return root->data;
//     return leftleafsum(root->left)+leftleafsum(root->right);
// }
struct node *search(struct node *root,int data)
{
    if(root==NULL||root->data==data)return root;
    struct node *f=search(root->left,data);
    if(f!=NULL)return f;
    return search(root->right,data);
}
void ancestor(struct node *root,int data)
{
    if(root==NULL)return ;
    if(root->data==data)
    {
        printf("%d ",root->data);
        return;
    }
    if(ancestor(root->left,data)||ancestor(root->right,data))
    {
        printf("%d ",root->data);
    }
    
}
int bst(struct node *root,int min,int max)
{
    if(root==NULL)return 1;
    if(root->data<min ||root->data>max)return 0;
    return bst(root->left,min,root->data)&&bst(root->right,root->data,max);

}

int isbst(struct node *root)
{
    return bst(root,INT_MIN,INT_MAX);
}
int maxsumbst(struct node *root,int *max)
{
    
    if(root==NULL)return 0;
    if(isbst(root)&&sum(root)>(*max))
    {
        *max=sum(root);
    }
    return maxsumbst(root->left)&&maxsumbst(root->right);
}

struct node *create(int data)
{
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node *build(int *inorder,int *preorder,int *preindex,int l,int r)
{
    if(l>r)return NULL;
    int key=preorder[*preindex];
    (*preindex)++;
    struct node *root=create(key);
    if(l==r)return root;
    int i;
    
    // (*preindex)++;
    for( i=l;i<=r;i++)
    {
        if(inorder[i]==key)
        {
           
            break;
        }
    }
    // (*preindex)++;
    root->left=build(inorder,preorder,preindex,l,i-1);
    root->right=build(inorder,preorder,preindex,i+1,r);
    return root;

}
void postorder(struct node *root)
{
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
int main()
{
    int n;
    scanf("%d",&n);
    struct node *root=NULL;
    int *inorder=(int *)malloc(sizeof(int)*n);
    int *preorder=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&inorder[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&preorder[i]);
    }
    int preindex=0;
    root=build(inorder,preorder,&preindex,0,n-1);
    
    char ch;
    while(scanf(" %c",&ch)!=EOF)
    {
        switch(ch)
        {
            case 'p':postorder(root);
            break;

            case 'z':zigzag(root);
            break;
            case 'm':printf("%d\n",maxsumbst(root));
            break;
            case 'l':
            printf("%d\n",leafsum(root));
            break;

        }
    }
    return 0;
}