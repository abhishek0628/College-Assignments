//problem
/*
2. You are asked to implement a data structure that mimics the functionality of an ordered map K
using an AVL Tree.
• Ordered map K
– An ordered map, also known as a map or dictionary, is a data structure that stores
a collection of key-value pairs. Unlike a regular hash map, an ordered map maintains
the elements in such a way that the keys in sorted order, allowing efficient retrieval of
elements in a sorted sequence based on their keys.
Implement the following Operations:
(a) M ain(): Read the choice from the console and call the following functions appropriately:
(b) Insert(K, key, value): Inserts a key-value pair into the ordered map K.
(c) U pperBound(K, key): Among all those elements in K having the key not less than the
given key, print the key-value pair of the one with the minimum key.
(d) F ind(K, key): Searches for a key in the ordered map K.
(e) Size(K): Prints the number of key-value pairs in ordered map K.
(f) Empty(K): Check whether the ordered map is empty or not K.
(g) DisplyElements(K): Display all the keys in the ordered map K in descending order.
Input format:
• Each line contains a character from {‘i’, ‘u’, ‘f ’, ‘s’, ‘e’, ‘d’, ‘t’ } followed by one or two
positive integers.
• Character ‘i’ followed by two positive integers key and value separated by a space, calls the
function insert(K, key, value). if the entered key already exists, update its corresponding
value.
• Character ‘u’ followed by a positive integer key calls the function U pperBound(K, key).
• Character ‘f ’ followed by a positive integer key calls the function F ind(K, key).
• Character ‘s’ calls the function Size(K).
• Character ‘e’ calls the function Empty(K).
• Character ‘d’ calls the function DisplyElements(K).
• Character ‘t’ terminates the execution of the program.
Output Format
• The output (if any) of each command should be printed on a separate line. However, no
output is printed for ‘i’ and ‘t’.
• For option ‘u’, on calling U pperBound(K, key), if such elements are present then print the
key-value pair of the first element with not less than the given key separated by a space,
otherwise print -1.
• For option ‘f ’, if the entered key is found then print the key-value pair separated by a space,
otherwise print -1.
• For option ‘s’, print the number of key-value pairs in the ordered map or print 0 if K is empty.
• For option ‘e’, Prints 1 if the ordered map is empty, otherwise prints 0.
• For option ‘d’, Prints the keys in K in descending order separated by a space, print -1 if the
ordered map is empty.
Sample test case 1
Input:
e
i 1 10
i 2 20
i 3 30
i 4 40
u 3
u 5
f 3
f 1
s
d
i 1 100
i 10 1
f 1
s
d
e
t
Output:
1
3 30
-1
3 30
1 10
4
4 3 2 1
1 100
5
0
10 4 3 2 1
*/

//solution
#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    int value;
    int height;
    struct node *left;
    struct node *right;
    struct node *parent;
};

struct node *createNode(int key, int value) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = key;
    node->value = value;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

int height(struct node *root) {
    if (root == NULL)
        return 0;
    return root->height;
}

int getBalance(struct node *root) {
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

struct node *rightRotate(struct node *y) {
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    return x;
}

struct node *leftRotate(struct node *x) {
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y;
}

struct node *insert(struct node *root, int key, int value) {
    if (root == NULL)
        return createNode(key, value);

    if (key < root->key)
        root->left = insert(root->left, key, value);
    else if (key > root->key)
        root->right = insert(root->right, key, value);
    else {
        root->value = value;
        return root;
    }

    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

struct node *minValueNode(struct node *root) {
    struct node *current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct node *find(struct node *root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (root->key < key)
        return find(root->right, key);
    return find(root->left, key);
}

int printAncestors(struct node *root, int key) {
    if (root == NULL)
        return 0;

    if (root->key == key) {
        printf("%d ", root->key);
        return 1;
    }

    if (printAncestors(root->left, key) || printAncestors(root->right, key)) {
        printf("%d ", root->key);
        return 1;
    }

    return 0;
}

struct node *upperBound(struct node *root, int key) {
    struct node *current = root;
    struct node *candidate = NULL;
    while (current != NULL) {
        if (current->key >= key) {
            candidate = current;
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return candidate;
}

int size(struct node *root) {
    if (root == NULL)
        return 0;
    return 1 + size(root->left) + size(root->right);
}

void Postorder(struct node *root) {
    if (root == NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ", root->key);
}

int empty(struct node *root) {
    return root == NULL ? 1 : 0;
}

void displayElements(struct node *root) {
    if (root == NULL) {
        printf("-1\n");
        return;
    }
    if (root->right)
        displayElements(root->right);
    printf("%d ", root->key);
    if (root->left)
        displayElements(root->left);
}

int main() {
    struct node *root = NULL;
    char command;
    int key, value;

    while (scanf(" %c", &command) && command != 't') {
        switch (command) {
        case 'i':
            scanf("%d %d", &key, &value);
            root = insert(root, key, value);
            break;
        case 'u':
            scanf("%d", &key);
            struct node *ubNode = upperBound(root, key);
            if (ubNode)
                printf("%d %d\n", ubNode->key, ubNode->value);
            else
                printf("-1\n");
            break;
        case 'f':
            scanf("%d", &key);
            struct node *foundNode = find(root, key);
            if (foundNode)
                printf("%d %d\n", foundNode->key, foundNode->value);
            else
                printf("-1\n");
            break;
        case 's':
            printf("%d\n", size(root));
            break;
        case 'e':
            printf("%d\n", empty(root));
            break;
        case 'd':
            displayElements(root);
            printf("\n");
            break;
        default:
            printf("Invalid command\n");
            break;
        }
    }

    return 0;
}
