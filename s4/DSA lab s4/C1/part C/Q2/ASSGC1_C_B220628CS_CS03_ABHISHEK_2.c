//problem
/*
2. You are tasked with implementing a hash table using chaining as the collision resolution method.
The hash table should support the following functions:
(a) insert(hashTable,key): Inserts the (integer) key at a certain index obtained from the hash
function below, if there are any collisions, use chaining. Maintain the sorted order while
chaining. If the key is already present in the hash table, then print -1.
index=(key)Mod(TableSize) or key%TableSize.
(b) search(hashTable,key): Searches for the key in the hash table. If the key is found,
prints(space-separated) the index at which it is stored in the hash table and also its po-
sition in the chain. If the key is not found then print -1.
Eg: search(15)
Hash Table: < index, chain >
4 : 8−> N U LL
5 : 5−> 15−> 25−> N U LL
.
.
.
.
o/p: 5(index) 2(position in chain)
(c) delete(hashTable,key): Deletes the key from the hash table and prints(space-separated) the
index at which it is stored in the hash table and also its position in the chain. If the key
is not found then print -1.
(d) update(hashTable,oldKey,newKey): Updates the oldKey in the hash table with newKey
by deleting the oldKey and inserting the newKey and prints(space-separated) the index
at which the oldKey is stored in the hash table and also its position in the chain. If the
oldKey is not found or the newKey is already present in the hash table then print -1.
(e) printElementsInChain(hashTable,index): prints all the elements(in sorted order, space-
separated) present in the chain at index in the hash table. If the slot is empty print -1.
Input Format:
• The first line contains an integer (TableSize), which tells the hash table size.
• Each line of input starts with a character from the menu list [’i’,’d’,’u’,’s’,’p’,’e’] followed
by an integer(s), which specify the key(s) or Index, respectively.
• Input ‘i’ followed by an integer (key) calls the function insert(hashTable,key).
• Input ‘d’ followed by an integer (key) calls the function delete(hashTable,key).
• Input ’u’ followed by two integers oldKey and newKey calls the function update(hashTable,oldKey,
newKey).
• Input ‘s’ followed by an integer(key) calls the function search(hashTable,key).
• Input ‘p’ followed by an integer(0 <=index<TableSize) calls the function printElementsIn-
Chain(hashTable,index).
• Input ‘e’ terminates the execution of the program.
• All the inputs in a line are separated by space and the integer inputs are positive numbers.
Output Format:
• A line may contain -1.
• The output of the result of any menu is printed in a new line with a space between each
integer.
Sample Input 1:
5
i 1
i 5
i 10
i 15
i 20
p 0
s 15
d 15
u 15 25
p 4
e
Sample Output 1:
5 15 20
0 2
0 2
-1
-1
Sample Input 2:
7
i 1
i 2
i 3
i 4
i 5
i 12
p 5
u 12 25
p 5
u 12 25
u 5 25
d 25
s 12
i 5
e
Sample Output 2:
5 12
5 2
5
-1
-1
3 1
-1
-1
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