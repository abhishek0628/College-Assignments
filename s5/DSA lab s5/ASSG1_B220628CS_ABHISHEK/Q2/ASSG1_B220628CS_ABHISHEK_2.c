//problem
/*
2. We are using a Binary Search Tree (BST) to store car details for a car showroom,
where each car is represented by its model number, model name, and price. The
BST is created based on the model number, which is unique for each car.
The BST data structure should support various dynamic-set operations and should
be implemented with the following specifications:
• BST Structure
Each node in the BST contains a model number (positive integer), model name
(string), and price (positive integer). In addition to these key attributes, each
node contains pointers to its left child, right child, and parent. If a child or the
parent is missing, the appropriate pointer should be set to NIL. The root node
is the only node in the tree whose parent is NIL.
• BST Property
Let x be a node in a BST. If y is a node in the left subtree of x, then y.key <
x.key. If y is a node in the right subtree of x, then y.key ≥x.key.
• Operations
(a) M ain(): Creates an empty BST and repeatedly reads a character from the
console to perform the following operations until ’e’ (exit) is entered:
– ‘a’ : Add a new car detail.
– ‘d’ : Delete an existing car detail.
– ‘s’ : Search for a car by model number.
– ‘i’ : Perform an inorder traversal of the BST and print car details.
– ‘p’ : Perform a preorder traversal of the BST and print car details.
– ‘t’ : Perform a postorder traversal of the BST and print car details.
– ‘m’ : Modify the price of an existing car.
(b) Create N ode(model number, model name, price): Creates a new node with
the given car details and returns a pointer to the new node. All pointer at-
tributes of the new node should be set to N IL.
(c) Add(T, x): Inserts the node x into the BST T . Here x is a pointer to the
new node returned by the Create N ode() function.
(d) Delete(T, x): Deletes the node x from the BST T . Here x is a pointer to the
node to be deleted returned by the Search() function to locate the node x.
(e) Search(T, model number): Searches for a node with the given model num-
ber in T and returns a pointer to the node if it exists; otherwise, it returns
N IL.
(f) Inorder(T ): Performs recursive inorder traversal of the BST T and prints
the car details in the nodes of T in inorder.
(g) P reorder(T ): Performs recursive preorder traversal of the BST T and prints
the car details in the nodes of T in preorder.
(h) P ostorder(T ): Performs recursive postorder traversal of the BST T and
prints the car details in the nodes of T in postorder.
(i) M odif y(T, model number, new price): Modifies the price of a car with the
given model number to the new price.
Input Format
• Each line contains a character from {‘a’, ‘d’, ‘s’, ‘i’, ‘p’, ‘t’, ‘m’, ‘e’}followed by
the arguments required for the corresponding operation.
– Character ‘a’ is followed by a positive integer n, a string s, and a positive
integer p separated by a space. Perform Add(T, x) operation.
– Character ‘d’ is followed by a positive integer n separated by a space. Per-
form Delete(T, x) operation
– Character ‘s’ is followed by a positive integer n separated by a space. Perform
Search(T, model number) operation.
– Character ‘i’ is to perform inorder traversal of T.
– Character ‘p’ is to perform preorder traversal of T.
– Character ‘t’ is to perform postorder traversal of T.
– Character ‘m’ is followed by two positive integers separated by a space.
Perform M odif y(T, model number, new price) operation.
– Character ‘e’ is to ‘exit’ from the program.
Output Format
• The output (if any) of each command should be printed on a separate line.
• For option ‘d’, print the deleted car’s details in the order: model number, model
name, price separated by a space. If a node with the entered model number is
not present in T , then print -1.
• For option ‘s’, If a node with entered model number is present in T , then print all
the details of that car in the order: model number, model name, price separated
by a space. If a node with the entered model number is not present in T , then
print -1.
• For options ‘i’, ‘p’, ‘t’, print the data in the nodes of T obtained from the
corresponding traversal. Each car’s details are written on a separate line in the
order: model number, model name, price separated by a space.
• For option ‘m’, print the modified car’s details in the order: model number,
model name, and updated price separated by a space. If a node with the entered
model number is not present in T , then print -1.
Test Case
Input:
a 1 Toyota 20000
a 2 Honda 18000
a 3 Ford 25000
s 2
i
p
t
m 2 19000
s 2
d 3
s 3
i
e
Output:
2 Honda 18000
1 Toyota 20000
2 Honda 18000
3 Ford 25000
2 Honda 18000
1 Toyota 20000
3 Ford 25000
1 Toyota 20000
3 Ford 25000
2 Honda 18000
2 Honda 19000
2 Honda 19000
3 Ford 25000
-1
1 Toyota 20000
2 Honda 19000
*/

//solution
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
struct node
{
    struct node *left;
    struct node *right;
    struct node *parent;
    int model_number;
    char model_name[100];
    int price;
};
struct node *create_model(int model_number,char model_name[],int price)
{
    struct node *root=(struct node *)malloc(sizeof(struct node));
    root->left=NULL;
    root->right=NULL;
    root->parent=NULL;
    root->model_number=model_number;
    // root->model_name=model_name;
    strcpy(root->model_name,model_name);
    root->price=price;
    return root;
}
void search(struct node *root,int model_number)
{
    if(root==NULL)
    {
        printf("-1\n");
        return ;
    }
    if(root->model_number>model_number)
    {
        search(root->left,model_number);
    }
    else if(root->model_number<model_number)
    {
        search(root->right,model_number); 
    }
    printf("%d %s %d",root->model_number,root->model_name,root->price);
}
struct node *Add(struct node *root,int model_number,char model_name[],int price)
{
    if(root==NULL)
    {
        return create_model(model_number,model_name,price);
    }
    if(root->model_number>model_number){
        root->left=Add(root->left,model_number,model_name,price);
    }
    else if(root->model_number<model_number){
        root->right=Add(root->right,model_number,model_name,price);
    }
    else return root;

}
struct node *minimum(struct node *root)
{
    while(root->left)
    {
        root=root->left;
    }
    return root;
}

struct node *delete(struct node *root,int model_number)
{
    if(root==NULL)return NULL;
    if(root->model_number>model_number)
    {
        root->left=delete(root->left,model_number);

    }
    if(root->model_number<model_number)
    {
        root->right=delete(root->right,model_number);

    }
    else return root;
    if(root->left==NULL)
    {
        struct node *temp=root->right;
        root->model_number=temp->model_number;
    }
    else if(root->right==NULL)
    {
        struct node *temp=root->left;
        root->model_number=temp->model_number;
    }
    else{
        struct node *temp=minimum(root->right);
        root->right=delete(root->right,temp->model_number);
        return temp;

    }

}

struct node *search2(struct node *root,int model_number)
{
    if(root==NULL)return NULL;
    if(root->model_number>model_number)
    {
        search2(root->left,model_number);
    }
    else if(root->model_number<model_number)
    {
        search2(root->right,model_number);
    }
    return root;
    
}
struct node *modify(struct node *root,int model_number,int price)
{
    if(root==NULL)return NULL;
    struct node *root=search2(root,model_number);
    root->price=price;
    return root;

}
void inorder(struct node *root)
{
    inorder(root->left);
    printf("%d %s %d",root->model_number,root->model_name,root->price);
    inorder(root->right);


}
void preorder(struct node *root)
{
    printf("%d %s %d",root->model_number,root->model_name,root->price);
    preorder(root->left);
    preorder(root->right);

}
void postorder(struct node *root)
{
    postorder(root->left);
    postorder(root->right);
    printf("%d %s %d",root->model_number,root->model_name,root->price);

}
struct node *modify(struct node *root,int model_number,int new_price)
{

}
int main()
{
    char choice;
    int model_number,price;
    char model_name[100];
    struct node *root=NULL;
    while(scanf(" %c",&choice))
    {
        switch(choice)
        {
            case 'a':scanf("%d%s%d",&model_number,model_name,&price);
                     root=Add(root,model_number,model_name,price);
                     break;
            case 'i':inorder(root);
                     break;
            case 'p':preorder(root);
                     break;
            case 't':postorder(root);
                     break;
            case 'm':scanf("%d%d",&model_number,&price);
                     root=modify(root,model_number,price);
                     break;
            case 'd':scanf("%d",&model_number);
                     root=delete(root,model_number);
                     break;
            case 's':scanf("%d",&model_number);
                     struct node *temp=search2(root,model_number);
                     printf("%d%s%d",root->model_number,root->model_name,root->price);
                     break;
            case 'e':return 0;
                     

        }

    }
    return 0;

}
