//problem
/*
2. Given the PARENTHESIS REPRESENTATION of the binary Tree T with n nodes (where n ∈
[1,104] ). Write a menu driven program to implement the operations outlined below:
(a) Levelordertraversal(T): This function prints the level order traversal of the binary tree. Level
order traversal of a tree is breadth-first traversal for the tree.
(b) MaximumSumBst(T): This function computes the maximum sum of all keys of any sub-tree
which is also a Binary Search Tree (BST).
(c) RightView(T): This function prints the Right view of a Binary Tree which is a set of nodes
visible when the tree is viewed from the right side.
Level order Traversal : 1 4 3 2 4 2 5 4 6
Maximum Sum of BST: 20
Right view : 1 3 5 6
Input Format:
• First line of the input contains a space separated Parenthesis Representation of the tree T
with key values ∈ [1, 106].
• Next Each line contains a character ‘l’, ’m’ and ‘r’.
• Character ‘l’ is to print the level order traversal of Tree
• Character ‘m’ is to print the maximum sum of BST in a binary tree.
• Character ‘r’ is to print the right view of the binary tree.
Output Format:
• The output (if any) of each command should be printed on a separate line.
Sample Input 1:
1(4(2)(4))(3(2)(5(4)(6))
l
r
m
Sample Output 1:
1 4 3 2 4 2 5 4 6
1 3 5 6
20
Sample Input 2:
4(2(1)(3))(6(5)(7))
l
m
r
Sample Output 2:
4 2 6 1 3 5 7
28
4 6 7
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
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node *build(char str[],int *i)
{
    int n=strlen(str);
    if(n==0||*i>n)return NULL;
    int val=0;
    while(str[*i]<='('&& str[*i]>=')'&& *i<n)
    {
        int num=str[*i]-'0';
        val=val*10+num;

    }
    struct node *root=NULL;
    if(val>0)
    {
       root=create(val);
    }
    if(str[*i]=='('&& *i<n)
    {
        (*i)++;
        root->left=build(str,i);
    }
    if(str[*i]==')'&& *i<n)
    {
        return root;
    }
    if(str[*i]=='('&& *i<n)
    {
        (*i)++;
        root->right=build(str,i);
    }
    if(str[*i]==')'&& *i<n)
    {
        
        return root;
    }
    return root;
    

}
void display(struct node *root)
{
    if(root==NULL)return ;
    display(root->left);
    display(root->right);
    printf("%d ",root->data);
}
int main()
{
    struct node *root=NULL;
    
}