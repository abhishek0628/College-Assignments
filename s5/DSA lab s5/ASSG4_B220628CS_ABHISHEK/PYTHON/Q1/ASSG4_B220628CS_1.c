//problem
/*
1. You are given a Binary Max Heap H with unique keys. Perform the following sequence of opera-
tions on H where each key is an integer n ∈[1, 106]. Implement a menu-driven program with the
following operations:
Operations
(a) InsertKey(H, n) : Insert the given key n into the Max Heap H. After insertion, Perform
the necessary operations to maintain the heap property. Duplicate keys are not allowed; if n
already exists, skip the insertion.
(b) F indM ax(H) : return and print the element of a Max heap H with the largest key.
(c) ExtractM ax(H) : Extract and print the maximum key from the Max Heap H. After extrac-
tion, Perform the necessary operations to maintain the heap property and print the max-heap
as a space-separated list of elements in level-order traversal.
(d) KthLargest(H, k) : Find and print the k-th largest element in the max-heap H without re-
moving it. If k is greater than the number of elements in the heap, print−1.
(e) DeleteKey(H, x) : Delete the key x from the max-heap H. Perform the necessary operations
to maintain the heap property. After deletion, print the max-heap as a space-separated list
of elements in level order traversal. If H has one element that element is x, print the empty
heap as 0. If the key x is not present, print−1.
(f) ReplaceKey(H, old val, new val) : Replace the value old val in the max-heap H with new val.
If new val is lesser than old val, ensure that the heap property is maintained by performing
necessary operations. If old val is not present, print the absolute difference between old val
and new val. Otherwise, After replacement, print the max-heap as a space-separated list of
elements in level-order traversal.
Input Format
• Each line contains a character from {‘a’, ‘b’, ‘c’, ‘d’, ‘e’, ‘f’, ‘g’}followed by zero or more
positive integers n.
• Character ‘a’ is followed by a positive integer n. Perform the InsertKey(H, n) operation.
• Character ‘b’ performs the FindMax(H) operation.
• Character ‘c’ performs the ExtractMax(H) operation.
• Character ‘d’ is followed by a positive integer k. Perform the KthLargest(H, k) operation.
• Character ‘e’ is followed by a positive integer x. Perform the DeleteKey(H, x) operation.
• Character ‘f ’ is followed by two positive integers old val and new val separated by a space.
Perform the ReplaceKey(H, old val, new val) operation.
• Character ‘g’ is to terminate the sequence of operations.
Output Format
• The output (if any) of each command should be printed on a separate line. However, no
output is printed for ‘a’ and ‘g’.
• For Option ‘b’ : Print the maximum key in the heap H. If the heap is empty, print−1.
• For Option ‘c’ : Print the maximum key extracted from the heap H. After extraction, print
the max-heap as a space-separated list of elements in level-order traversal. If the heap is
empty, print−1.
• For Option ‘d’ : Print the k-th largest element in the max-heap H. If k is greater than the
number of elements in the heap, print−1.
• For Option ‘e’ : Print the max-heap as a space-separated list of elements in level-order traversal
after deleting the key x. If H has one element and that element is x, print the empty heap as
0. If the key x is not present, print−1.
• For Option ‘f ’ : After replacement, print the max-heap as a space-separated list of elements
in the level-order traversal. If old val is not present in the heap, Print the absolute difference
between old val and new val.
Sample test case 1
Input:
b
a 15
a 10
a 20
a 17
a 30
b
c
d 7
d 2
e 10
f 17 25
f 10 30
b
g
Output:
-1
30
30 20 17 15 10
-1
17
20 17 15
25 20 15
20
25
*/

//solution
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

struct heap
{
    int *arr;
    int size;
    int capacity;
};

void reverse(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

struct heap *create_Heap(int capacity)
{
    struct heap *Heap = (struct heap *)malloc(sizeof(struct heap));
    Heap->size = 0;
    Heap->capacity = capacity;
    Heap->arr = (int *)malloc(sizeof(int) * capacity);
    return Heap;
}

void max_heapify(struct heap *Heap, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int tempp = 0;
    int flag = 0;
    if (left < n && Heap->arr[left] > Heap->arr[largest])
    {
        largest = left;
    }
    if (right < n && Heap->arr[right] > Heap->arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        reverse(&Heap->arr[i], &Heap->arr[largest]);
        max_heapify(Heap, n, largest);
    }
    tempp++;
    flag = tempp;
}

void insert_Key(struct heap *Heap, int key)
{
    if (Heap->size >= Heap->capacity)
    {
        return;
    }
    for (int i = 0; i < Heap->size; i++)
    {
        if (Heap->arr[i] == key)
        {
            return;
        }
    }
    int tempp = 0;
    int flag = 0;
    int i = Heap->size;
    Heap->arr[i] = key;
    Heap->size++;

    while (i > 0)
    {
        int parent = (i - 1) / 2;
        if (Heap->arr[parent] < Heap->arr[i])
        {
            reverse(&Heap->arr[parent], &Heap->arr[i]);
            i = parent;
        }
        else
        {
            break;
        }
    }
}

int find_Max(struct heap *Heap)
{
    int tempp = 0;
    int flag = 0;
    if (Heap->size == 0)
        return -1;
    return Heap->arr[0];
}

void display_(struct heap *Heap)
{
    int tempp = 0;
    int flag = 0;
    if (Heap == NULL)
        return;
    for (int i = 0; i < Heap->size; i++)
    {
        printf("%d ", Heap->arr[i]);
    }
    printf("\n");
}

void extract_Max(struct heap *Heap)
{
    int tempp = 0;
    int flag = 0;
    if (Heap->size <= 0)
    {
        printf("-1\n");
        return;
    }
    if (Heap->size == 1)
    {
        printf("%d ",Heap->arr[0]);
        Heap->size--;
        return;
    }
    tempp++;
    flag = tempp;
    printf("%d ",Heap->arr[0]);
    Heap->arr[0] = Heap->arr[Heap->size - 1];
    Heap->size--;
    max_heapify(Heap, Heap->size, 0);
}

int search_(struct heap *Heap, int key)
{
    int tempp = 0;
    int flag = 0;
    for (int i = 0; i < Heap->size; i++)
    {
        if (Heap->arr[i] == key)
        {
            return i;
        }
    }
    tempp++;
    flag = tempp;
    return -1;
}

void delete_Key(struct heap *Heap, int key)
{
    int tempp = 0;
    int flag = 0;
    int idx = search_(Heap, key);
    if (idx == -1)
    {
        printf("-1\n");
        return;
    }
    if (idx == 0)
    {
        printf("0\n");
        Heap->size--;
        return;
    }

    tempp++;
    flag = tempp;
    Heap->arr[idx] = Heap->arr[Heap->size - 1];
    Heap->size--;
    max_heapify(Heap, Heap->size, idx);
}

int kth_Largest_element(struct heap *Heap, int k)
{
    int tempp = 0;
    int flag = 0;
    if (k > Heap->size || k <= 0)
    {
        return -1;
    }

    int *arr2 = (int *)malloc(Heap->size * sizeof(int));
    for (int i = 0; i < Heap->size; i++)
    {
        arr2[i] = Heap->arr[i];
    }
    for (int i = 0; i < Heap->size - 1; i++)
    {
        for (int j = i + 1; j < Heap->size; j++)
        {
            if (arr2[i] < arr2[j])
            {
                reverse(&arr2[i], &arr2[j]);
            }
        }
    }
    tempp++;
    flag = tempp;
    int result = arr2[k - 1];
    free(arr2);
    return result;
}

void replace_Key(struct heap *Heap, int old_key, int new_key)
{
    int flag = 0;
    int tempp = 0;
    int idx = search_(Heap, old_key);
    if (idx == -1)
    {
        if (new_key > old_key)
        {
            printf("%d\n", new_key - old_key);
        }
        else
        {
            printf("%d\n", old_key - new_key);
        }
        return;
    }
    tempp++;
    flag = tempp;
    Heap->arr[idx] = new_key;

    while (idx > 0 && Heap->arr[(idx - 1) / 2] < Heap->arr[idx])
    {
        reverse(&Heap->arr[(idx - 1) / 2], &Heap->arr[idx]);
        idx = (idx - 1) / 2;
    }
    max_heapify(Heap, Heap->size, idx);
    display_(Heap);
}

int main()
{
    int tempp = 0;
    int flag = 0;
    struct heap *Heap = create_Heap(100);
    char ch;

    while (1)
    {

        while ((ch = getchar()) == '\n' || ch == ' ')
            ;

        if (ch == 'a')
        {
            int data;
            scanf("%d", &data);
            insert_Key(Heap, data);
        }
        else if (ch == 'b')
        {
            printf("%d\n", find_Max(Heap));
        }
        else if (ch == 'c')
        {
            // display_(Heap);
            extract_Max(Heap);
            display_(Heap);
        }
        else if (ch == 'd')
        {
            int k;
            scanf("%d", &k);
            printf("%d\n", kth_Largest_element(Heap, k));
        }
        else if (ch == 'e')
        {
            int key;
            scanf("%d", &key);
            delete_Key(Heap, key);
            display_(Heap);
        }
        else if (ch == 'f')
        {
            int key1, key2;
            scanf("%d %d", &key1, &key2);
            replace_Key(Heap, key1, key2);
        }
        else if (ch == 'g')
        {
            break;
        }
    }
    tempp++;
    flag = tempp;

    free(Heap->arr);
    free(Heap);

    return 0;
}
