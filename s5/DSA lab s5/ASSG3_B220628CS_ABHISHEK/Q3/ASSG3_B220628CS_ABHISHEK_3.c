//problem
/*
3. Open addressing is a method for handling collisions in hashing. The three different methods for
open addressing are linear probing, quadratic probing, and double hashing. A brief description of
the three methods are given below:
• In linear probing, the function h′(k) used to calculate the next location during a collision
is:
h′(k) = (h(k) + i) mod N, i = 1, 2, . . .
• In quadratic probing, the function h′(k) used to calculate the next location during a collision
is:
h′(k) = h(k) + i2 mod N, i = 1, 2, . . .
• In the double hashing scheme:
– The primary hash function is:
h1(k) = k mod N
where N is the table size.
– The secondary hash function is:
h2(k) = R−(k mod R)
where R is the largest prime number less than the table size, N.
– Double hashing can be done using:
h′(k) = (h1(k) + i ×h2(k)) mod N, i = 0, 1, 2, . . .
Write a menu-driven program to implement the operations outlined below in a hash table. Note
that the operations described below take the hash table as the parameter.
Operations
(a) LinearP robing(hashT able): The input keys should be inserted into the hash table in the
prescribed order using linear probing. If a collision occurs, use the linear probing function
to find the next available slot. Print the indices where the keys are stored (in the insertion
order) and the number of collisions that occurred during the insertion.
(b) QuadraticP robing(hashT able): The input keys should be inserted into the hash table in
the prescribed order using quadratic probing. If a collision occurs, use the quadratic probing
function to find the next available slot. Print the indices where the keys are stored (in the
insertion order) and the number of collisions that occurred during the insertion.
(c) DoubleHashing(hashT able): The input keys should be inserted into the hash table in the
prescribed order using double hashing. Use the primary and secondary hash functions as de-
scribed, and resolve collisions using the double hashing function. Print the indices where the
keys are stored (in the insertion order) and the number of collisions that occurred during the
insertion.
Input format:
• The first line contains two space-separated positive integers N, m where N specifies the size
of the hash table and m specifies the number of positive integers intended to be inserted,
respectively.
• The second line contains a sequence of m positive integers, separated by a space. representing
the keys to be inserted.
• Each subsequent line contains a character from {‘a’, ‘b’, ‘c’, ‘d’ }.
• Character ’a’ perform LinearP robing(hashT able) operation.
• Character ’b’ perform QuadraticP robing(hashT able) operation.
• Character ’c’ perform DoubleHashing(hashT able) operation.
• Character ’d’ is to terminate the sequence of operations.
Output format:
• The output (if any) of each command should be printed on a separate line. However, no
output is printed for ‘d’.
• For option ’a’: Print the indices where the keys are stored in a single line separated by a
space, and print the total number of collisions that occurred during insertion in the next line.
• For option ’b’: Print the indices where the keys are stored in a single line separated by a
space, and print the total number of collisions that occurred during insertion in the next line.
• For option ’c’: Print the indices where the keys are stored in a single line separated a by
space, and print the total number of collisions that occurred during insertion in the next line.
Sample test case 1
Input:
7 6
76 93 40 47 10 55
a
b
c
d
Output:
6 2 5 0 3 1
4
6
2
6 2 5 0 3 1
6 2 5 1 3 4
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
int count1 = 0;
int count2 = 0;
int count3 = 0;
struct set
{
    int data;
    int key;
};

struct hashtable
{
    int size;
    int capacity;
    struct set *array;
};
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

struct hashtable *create(int capacity)
{
    struct hashtable *ht = (struct hashtable *)malloc(sizeof(struct hashtable));
    ht->capacity = capacity;
    ht->size = 0;
    ht->array = (struct set *)malloc(sizeof(struct set) * capacity);
    for (int i = 0; i < ht->capacity; i++)
    {
        ht->array[i].data = 0;
        ht->array[i].key = 0;
    }
    return ht;
}

int hash(int key, int n)
{
    return key % n;
}

int hash2(int key, int r) {
    return r - (key % r);
}

void linearprobing(int data,  struct hashtable *ht)
{
    int tempp=0;
    int flagg=0;
    int ceill=0;
    int key;
    int i = hash(data, ht->capacity);

    int k = i;
    int j = 1;

    while (ht->array[i].data != 0)
    {
        count1++;
       
        i = (k + j) % ht->capacity;
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

    ht->array[i].data = data;
    ht->array[i].key = key;
    ht->size++;
}
void quadraticprobing(int data ,struct hashtable *ht)
{
    int tempp=0;
    int flagg=0;
    int ceill=0;
    int key;
    int i = hash(data, ht->capacity);

    int originalIndex = i;
    int j = 1;

    while (ht->array[i].data != 0)
    {
        count2++;
       
        i = (originalIndex + j * j) % ht->capacity;
        j++;

        if (i == originalIndex)
        {
            printf("-1\n");
            return;
        }
    }
    tempp++;
    flagg++;
    ceill++;

    ht->array[i].data = data;
    ht->array[i].key = key;
    ht->size++;
}

void doublehashing(int data, struct hashtable *ht) 
{
    int tempp=0;
    int flagg=0;
    int ceill=0;
    int r = prime(ht->capacity);
    int i = hash(data, ht->capacity);
    int k = i;
    int j = 1;
    int h2 = hash2(data, r);

    while (ht->array[i].data != 0) {
        count3++;
        i = (k + j * h2) % ht->capacity;
        j++;

        if (i == k) {
            printf("-1\n");
            return;
        }
    }
    tempp++;
    flagg++;
    ceill++;

    ht->array[i].data = data;
    ht->array[i].key = data;
    ht->size++;
}
void remove_(struct hashtable *ht,int data)
{
    int tempp=0;
    
    int flagg=prime(data);
    int index=hash(data,ht->capacity);
    if(ht->array[index].data==data)
    {
        ht->array[index].data=0;
        ht->array[index].key=0;
    }
    flagg++;
    tempp++;
    return ;
}

void display(int arr[],int n,struct hashtable *ht)
{
    int tempp=0;
    int flagg=0;
    int ceill=0;
     for (int k = 0; k < n; k++) {
        int data = arr[k];
        for (int i = 0; i < ht->capacity; i++) {
            if (ht->array[i].data == data) {
                printf("%d ", i);
                break;
            }
        }
    }
    tempp++;
    flagg++;
    ceill++;
}

int main()
{   int tempp=0;
    int flagg=0;
    int ceill=0;
    
    int n;
    int size, j = 0;
    int arr[100];
    char str[1000];
    scanf("%d %d\n", &size, &n);
    struct hashtable *ht1=create(size);
    struct hashtable *ht2=create(size);
    struct hashtable *ht3=create(size);

    fgets(str, 100, stdin);
    int val = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ' || i == strlen(str) - 1)
        {
            arr[j++] = val;
            val = 0;
            continue;
        }
        val = val * 10 + str[i] - '0';
    }

    char ch;

    while (1)
    {
        scanf("%c", &ch);
        if (ch == 'a')
        {
            tempp++;
            for(int i=0;i<n;i++)
            linearprobing(arr[i],  ht1);
            display(arr,n,ht1);
            printf("\n%d\n",count1);
            flagg--;
        }
        else if (ch == 'b')
        {
            tempp--;
            for(int i=0;i<n;i++)
            quadraticprobing(arr[i],  ht2);
            display(arr,n,ht2);
            printf("\n%d\n",count2);
            flagg++;
        }
        else if (ch == 'c')
        {
            ceill++;
            for(int i=0;i<n;i++)
            doublehashing(arr[i],  ht3);
            display(arr,n,ht3);
            printf("\n%d\n",count3);
            tempp++;
        }
        else if (ch == 'd')
        {
            break;
        }
    }
    tempp++;
    flagg++;
    ceill++;

    return 0;
}
