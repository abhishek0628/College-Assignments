// problem
/*
1. A Singly linked list L is a data structure in which the objects are arranged in a linear order.
Each node of a Singly linked list L is an object with an attribute key and one pointer attribute,
next. Given a node x in the list, x.next points to its successor in the linked list. An attribute
L.head points to the first node of the list.
Write a menu driven program to implement an unsorted Singly linked list L. Your program
must contain the following functions:
(In the function prototypes, L, k, x and y denote a Singly Linked List, an integer and nodes of L
respectively. All operations should be done in a single pass and all keys are distinct).
• Main() - repeatedly reads a character ‘f ’, ‘t’, ‘a’, ‘b’, ‘d’, ‘i’, ‘l’, ‘s’ or ‘e’ from the terminal
and calls the sub-functions appropriately until character ‘e’ is entered.
• CREATE-NODE(k) - creates a new node with key k and pointer next of node points to
NULL. This procedure returns a pointer to the new node.
• LIST-INSERT-FRONT(L, x) - inserts x to the front of L.
• LIST-INSERT-TAIL(L, x) - inserts x as the last node of L.
• LIST-INSERT-AFTER(L, x, y) - inserts the node x after the node y in L.
Hint: First invoke LIST-SEARCH() function to locate the node y.
• LIST-INSERT-BEFORE(L, x, y) - inserts the node x before the node y in L.
Hint: Insertion of a node x before a node y can be done by locally storing a pointer to the
current node before moving to the next node.
• LIST-DELETE(L, x) - deletes the node x from L.
Hint: First invoke LIST-SEARCH() function to locate the node x.
• LIST-DELETE-FIRST(L) - deletes the first node from L.
• LIST-DELETE-LAST(L) - deletes the last node from L.
• LIST-SEARCH(L, k) - searches for a node with key k in L by doing a simple linear search,
and if found, returns a pointer to this node. If a node with key k is not present in the list, or
if the list is empty, the procedure returns N IL.
• LIST-DISPLAY(L) - prints the list L
• LIST-REVERSE(L) - reverses the list and prints it.
• LIST-REVERSE-EVEN(L) - reverses the order of the elements in the even positions of the
list and prints it (starting the index with one).
Note:- For every INSERT operation, the node x is created by calling CREATE-NODE() function.
Input format:
• Each line contains a character from ‘f ’, ‘t’, ‘a’, ‘b’, ‘d’, ‘i’, ‘l’, ‘s’, ‘r’, ‘ds’, ‘re’ or ‘e’ followed
by zero, one or two integers. The integers, if given, are in the range [−106
, 106].
• Character ‘f ’ is followed by an integer separated by space. In this operation, the node with
this integer as key is inserted to the front of L.
• Character ‘t’ is followed by an integer separated by space. In this operation, the node with
this integer as key is inserted to the tail of L.
• Character ‘a’ is followed by two integers separated by space. In this operation, the node with
the first integer as key is inserted after the node with second integer as key.
• Character ‘b’ is followed by two integers separated by space. In this operation, the node with
the first integer as key is inserted before the node with second integer as key.
• Character ‘d’ is followed by an integer separated by space. In this operation, the node with
this integer as key is deleted from L and the deleted node’s key is printed.
• Character ‘i’ is to delete the first node from L and print the deleted node’s key.
• Character ‘l’ is to delete the last node from L and print the deleted node’s key.
• Character ‘s’ is followed by an integer separated by space. This operation is to find the node
with this integer as key in L.
• Character ‘r’ This operation is to reverse the list L and to print it.
• Character ‘ds’ This operation is to print the list L.
• Character ‘re’ This operation is to reverse the elements in the even positions of the list L and
to print the new list, starting the index with one.
• Character ‘e’ is to ‘exit’ from the program.
Output Format:
• The output (if any) of each command should be printed on a separate line.
• For options ‘d’, ‘i’ and ‘l’ , print the deleted node’s key. If a node with the input key is not
present in L or L is empty, then print−1.
• For option ‘s’, if the key is present in L, then print 1. If key is not present in L or L is empty,
then print−1.
Sample Input :
f 7
t 10
a 11 7
b 12 11
d 10
i
l
s 12
s 6
t 15
f 14
f 20
ds
r
re
e
Sample Output:
10
7
11
1
-1
20 14 12 15
15 12 14 20
15 20 14 12
*/
#include<stdio.h>
struct node{
    int data;
    struct node *next;
};
struct node *create(int data)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
struct node **insertbeg(struct node **list,int data)
{
    struct node *newnode=createnode(data);
    if(list==NULL);
    {
        *list=newnode;
        return list;
    }
    newnode->next=*list;
    *list=newnode;
    return *list;

}
struct node *insertlast(struct node *list,int data)
{
    struct node *newnode=createnode(data);
    if(list==NULL)
    {
        list=newnode;
        return list;
    }
    struct node *temp=list;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    return list;
}
struct node **deletebeg(struct node **list)
{
    if(list==NULL)return NULL;
    *list=(*list)->next;
    return list;
}
struct node *deletelast(struct node *list)
{
    if(list==NULL)return NULL;
    struct node *temp=list;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    return list;

}
int main()
{
    return 0;
}
