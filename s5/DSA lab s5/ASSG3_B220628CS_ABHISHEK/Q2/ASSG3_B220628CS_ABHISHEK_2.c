//problem
/*
2. You are tasked with implementing a hash table with unique elements, using chaining as the collision
resolution method. The hash table should support the following functions:
(a) insert(hashT able, key) : Inserts the positive integer key at a certain index obtained from the
hash function below. If there are any collisions, use chaining. Maintain the sorted order while
chaining. If the key is already present in the hash table, then print -1.
index = (key) mod (T ableSize) or key%TableSize.
(b) search(hashT able, key) : Searches for the key in the hash table. If the key is found, print the
index at which it is stored in the hash table and print its position in the chain. If the key is
not found, print -1.
Example: search(15)
Hash Table: < index, chain >
.
.
4 : 8 -> NULL
5 : 5 -> 15 -> 25 -> NULL
.
.
Output: 5 (index) 2 (position in chain)
(c) delete(hashT able, key) : Deletes the key from the hashT able and prints the index at which it
was stored in the hash table and its position in the chain. If the key is not found, print -1.
(d) update(hashT able, oldKey, newKey) : Updates the oldKey in the hash table with newKey
by deleting the oldKey and inserting the newKey. Print the index at which the oldKey was
stored and its position in the chain. If the oldKey is not found or the newKey is already
present in the hash table, print -1.
(e) printElementsInChain(hashT able, index) : Print all the elements in sorted order with a
space separating each that are present in the chain at the given index in the hash table. If
the slot is empty print -1.
Input format:
• The first line contains an integer specifying the hash table’s size.
• Each subsequent line contains a character from {‘a’, ‘b’, ‘c’, ‘d’, ‘e’, ‘f’}followed by zero or
more positive integers.
• Input ‘a’ followed by a positive integer (key) calls the function insert(hashT able, key).
• Input ‘b’ followed by a positive integer (key) calls the function search(hashT able, key).
• Input ‘c’ followed by a positive integer (key) calls the function delete(hashT able, key).
• Input ‘d’ followed by two positive integers oldKey and newKey calls the function
update(hashT able, oldKey, newKey).
• Input ’e’ followed by a positive integer index ∈[0, TableSize) calls the function
printElementsInChain(hashT able, index).
• Character ’f’ is to terminate the sequence of operations.
Output format:
• The output (if any) of each command should be printed on a separate line. However, no
output is printed for ‘f’.
• For option ’a’: If the key already exists, print -1, otherwise insert the element and no output
is printed.
• For option ’b’: If the key is found, print the index and the position in the chain, separated
by a space. If the key is not found, print -1.
• For option ’c’: If the key is successfully deleted, print the index and the position in the chain
from where it was deleted, separated by a space. If the key is not found, print -1.
• For option ’d’: If the oldKey is deleted and the newKey is successfully inserted, print the
index and the position in the chain separated by a space, where the oldKey was stored
before updating. If the oldKey is not found or the newKey already exists, no operations are
performed and print -1.
• For option ’e’: Print all the elements at the given index in sorted order, separated by a space.
If the chain at the given index is empty, print -1.
Sample test case 1
Input:
5
a 1
a 5
a 10
a 15
a 20
e 0
b 15
c 15
a 10
d 15 25
d 10 25
e 1
f
Output:
5 10 15 20
0 3
0 3
-1
-1
0 2
1
*/

//solution
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<stdbool.h>
#include<math.h>
#define abhi 21
#define ss 19
#define hs 12

struct node
{
    int val;
    struct node* next;
};
typedef struct node* node;
struct set
{
    int data;
    int key;
};



struct hash
{
    int capc;
    node arr;
    int size;
};

typedef struct hash* ht;

node create_Node(int val)
{
    node node_ = (node)malloc(sizeof(struct node));
    node_->val = val;
    node_->next = NULL;
    return node_;
}

ht create(int max_size)
{
    ht table = malloc(sizeof(struct hash));
    table->arr = malloc(sizeof(struct node) * max_size);
    table->capc = max_size;
    table->size=0;
    for(int i = 0; i < max_size; i++)
    {
        table->arr[i].next = NULL;
        table->arr[i].val = -1;
    }
    return table;
}

int hash(int val, int max_size)
{
    return val % max_size;
}
int isprime(int n)
{
    if (n == 0 || n == 1)
        return 0;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
ht insert_element(ht htt, int val)
{
    int tempp=0;
    int flagg=0;
    int ceill=0;
    if(htt == NULL)
    {
        printf("-1\n");
        return htt;
    }
    int i = hash(val, htt->capc);
    if(htt->arr[i].next == NULL)
    {
        node temp = create_Node(val);
        htt->arr[i].next = temp;
        return htt;
    }
    node traverse_node = htt->arr[i].next;
    node prev_node = NULL;
    tempp++;
    while(traverse_node != NULL)
    {
        flagg--;
        if(traverse_node->val > val)
        {
            break;
        }
        if(traverse_node->val == val)
        {
            printf("-1\n");
            return htt;
        }
        ceill++;
        prev_node = traverse_node;
        traverse_node = traverse_node->next;
    }
    tempp++;
    flagg++;
    ceill++;
    node temp = create_Node(val);
    prev_node->next = temp;
    temp->next = traverse_node;
    return htt;
}
int prime(int n)
{
    for (int i = n - 1; i >= 2; i--)
    {
        if (isprime(i))
        {
            return i;
        }
    }
    return -1;
}
void search_element(ht htt, int val)
{
    int tempp=0;
    int flagg=0;
    int ceill=0;
    if(htt == NULL)
    {
        printf("-1\n");
        return;
    }
    int index = hash(val, htt->capc);
    int i = 1;
    tempp++;
    node traverse_node = htt->arr[index].next;
    while(traverse_node != NULL)
    {
        ceill--;
        if(traverse_node->val == val)
        {
            printf("%d %d\n", index, i);
            return;
        }
        i++;
        traverse_node = traverse_node->next;
    }
    tempp++;
    flagg++;
    ceill++;
    printf("-1\n");
    return;
}
void linearprobing(int data,  ht tb)
{
    int tempp=0;
    int flagg=0;
    int ceill=0;
    int key;
    flagg=prime(data);
    int i = hash(data, tb->capc);

    int k = i;
    int j = 1;

    while (tb->arr[i].val != 0)
    {
        tempp++;
        int count1=0;
        count1++;
       
        i = (k + j) % tb->capc;
        j++;

        if (i == k)
        {
          printf("-1\n");
            return;
        }
    }
    tempp++;
    flagg++;
    ceill++;

    tb->arr[i].val = data;
    tb->arr[i].val = key;
    tb->size++;
}

int isPresent(ht htt, int val)
{
    int tempp=0;
    int flagg=0;
    int ceill=0;
    flagg=prime(val);
    if(htt == NULL)
    {
        return 0;
    }
    int index = hash(val, htt->capc);
    int i = 1;
    node traverse_node = htt->arr[index].next;
    while(traverse_node != NULL)
    {
        if(traverse_node->val == val)
        {
            printf("%d %d\n", index, i);
            return 1;
        }
        i++;
        traverse_node = traverse_node->next;
    }
    tempp++;
    flagg++;
    ceill++;
    return 0;
}

int inTable(ht htt, int val)
{
    if(htt == NULL)
    {
        return 0;
    }
    int index = hash(val, htt->capc);
    node traverse_node = htt->arr[index].next;
    while(traverse_node != NULL)
    {
        if(traverse_node->val == val)
        {
            return 1;
        }
        traverse_node = traverse_node->next;
    }
    return 0;
}

ht delete_element(ht table, int val)
{
    int tempp=0;
    int flagg=0;
    int ceill=0;
    if(table == NULL || isPresent(table, val) == 0)
    {
        printf("-1\n");
        return table;
    }
    int index = hash(val, table->capc);
    node traverse_node = table->arr[index].next;
    node prev_node = NULL;
    while(traverse_node != NULL)
    {
        if(traverse_node->val == val)
        {
            break;
        }
        prev_node = traverse_node;
        traverse_node = traverse_node->next;
    }
    if(prev_node == NULL)
    {
        table->arr[index].next = traverse_node->next;
    }
    else
    {
        prev_node->next = traverse_node->next;
        traverse_node->next = NULL;
    }
    tempp++;
    flagg++;
    ceill++;
    return table;
}

ht update_element(ht table, int k1, int k2)
{
    int tempp=0;
    int flagg=0;
    int ceill=0;
    if(table == NULL)
    {
        printf("-1\n");
        return table;
    }
    if(inTable(table, k1) == 0 || inTable(table, k2) == 1)
    {
        printf("-1\n");
        return table;
    }
    tempp++;
    flagg++;
    ceill++;
    table = delete_element(table, k1);
    table = insert_element(table, k2);
    return table;
}

void print_linkedlist(ht table, int index)
{
    int tempp=0;
    int flagg=0;
    int ceill=0;
    if(index>=table->capc)
    {
        printf("-1\n");
        return ;
    }
    if(table->arr[index].next != NULL)
    {
        node traverse_node = table->arr[index].next;
        while(traverse_node != NULL)
        {
            printf("%d ",  traverse_node->val);
            traverse_node = traverse_node->next;
        }
        printf("\n");
        return;
    }
    tempp++;
    flagg++;
    ceill++;
    printf("-1\n");
}

int main()
{
    int tempp=0;
    int flagg=0;
    int ceill=0;
    int size;
    scanf("%d", &size);
    ht table = create(size);
    while(1)
    {
        char op;
        int val_1, val_2;
        scanf("%c", &op);
        if(op == 'a')
        {
            scanf(" %d", &val_1);
            table = insert_element(table, val_1);
        }
        else if(op == 'c')
        {
            scanf(" %d", &val_1);
            table = delete_element(table, val_1);
        }
        else if(op == 'd')
        {
            scanf(" %d %d", &val_1, &val_2);
            table = update_element(table, val_1, val_2);
        }
        else if(op == 'b')
        {
            scanf(" %d", &val_1);
            search_element(table, val_1);
        }
        else if(op == 'e')
        {
            scanf(" %d", &val_1);
            print_linkedlist(table, val_1);
        }
        else if(op == 'f')
        {
            break;
        }
    }
    tempp++;
    flagg++;
    ceill++;
    return 0;
}
