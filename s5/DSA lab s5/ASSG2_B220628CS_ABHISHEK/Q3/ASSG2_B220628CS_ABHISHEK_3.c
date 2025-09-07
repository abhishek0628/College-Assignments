//problem
/*
3. You are given a Parenthesis representation (Refer Part A of Assignment 1 ) of a non-empty AVL
tree T with unique keys n, where n ∈[1, 107].
Implement a menu-driven program that performs the following operations on the AVL tree T.
Operations
(a) AVL SeqInsert(T, [n1, n2, ..., nk]): Insert a sequence of keys [n1, n2, ..., nk] into the AVL tree
T . Perform necessary rotations to maintain AVL properties after each insertion. After all in-
sertions, print the paranthesis representation of resulting AVL tree.
(b) AVL RangeDelete(T, n1, n2): Delete all keys in the AVL tree T that are within the range
[n1, n2] (inclusive). Perform necessary rotations to maintain AVL properties after each de-
letion. After performing all deletions, print the total number of nodes deleted and preorder
traversal of the tree T after all deletions.
(c) AVL SuccessorP ath(T, n): For a given key n, find its inorder successor in T . Print the path
from the root to the inorder successor (including the successor itself). If n does not exist or
has no successor, return the height of T.
(d) AVL SubtreeSum(T, n): For a given key n, print the sum of all keys in the subtree rooted
at n and the parenthesis representation of the corresponding subtree rooted at n. If n is not
present in T , print−1.
(e) AVL FindClosest(T, n): Given a key n, find and print the closest key in T (the key with
the minimum absolute difference from n). If there are multiple such keys present, print the
smallest among them. If n is not found in T , or the closest key of n is not present (T has only
one node and it is n), then print−1.
Note: closest key of n cannot be itself.
Input Format
• First line of the input contains a space separated Parenthesis representation of a non-empty
AVL tree T with key values, n ∈[1, 107].
• Each subsequent line contains a character from {‘a’, ‘b’, ‘c’, ‘d’, ‘e’, ‘g’}followed by zero or
more positive integers n.
• Character ‘a’ is followed by a space-separated sequence of positive integers [n1, n2, . . . , nk].
Perform AV L SeqInsert(T, [n1, n2, ..., nk]) operation.
• Character ‘b’ is followed by two positive integers, separated by a space. Perform
AVL RangeDelete(T, n1, n2) operation.
• Character ‘c’ is followed by a positive integer n, separated by a space. Perform
AVL SuccessorP ath(T, n) operation.
• Character ‘d’ is followed by a positive integer n, separated by a space. Perform
AVL SubtreeSum(T, n) operation.
• Character ‘e’ is followed by a positive integer n, separated by a space. Perform
AVL FindClosest(T, n) operation.
• Character ‘g’ is to terminate the sequence of operations.
Output Format
• The output (if any) of each command should be printed on a separate line. However, no
output is printed for ‘g’.
• For option ‘a’: Print a space-separated parenthesis representation of the resulting AVL tree
after all the insertions.
• For option ‘b’: Print a space-separated sequence of integers representing the total number of
nodes deleted followed by the preorder traversal of the tree T after all the deletions. Print -1
if there are no nodes within the range in T to be deleted.
• For option ‘c’: Print the sequence of keys of nodes in the path from the root to the inorder
successor of n, separated by a space. If n does not exist or has no successor in T , print the
height of T.
• For option ‘d’: Print the sum of all keys in the subtree rooted at n followed by the parenthesis
representation of T , separated by a space. If n is not present, print -1.
• For option ‘e’: Print the closest key of n in T . Print -1 if n or its closest key is not present
in T.
Sample test case 1
Input:
23 ( 10 ( 9 ( 7 ) ( ) ) ( 15 ( 11 ) ( 17 ) ) ) ( 45 ( 30 ) ( 67 ) )
a 4 14 21
b 30 67
c 11
e 32
d 10
c 23
d 55
e 10
g
Output:
15 ( 10 ( 7 ( 4 ) ( 9 ) ) ( 11 ( ) ( 14 ) ) ) ( 23 ( 17 ( ) ( 21 ) ) ( 45 ( 30 ) ( 67 ) ) )
3 15 10 7 4 9 11 14 21 17 23
15 10 11 14
-1
3
-1
55 10 ( 7 ( 4 ) ( 9 ) ) ( 11 ( ) ( 14 ) )
9
*/

//solution
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct AVLNode {
    int key;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
} AVLNode;

int height(AVLNode *N) {
    return N ? N->height : 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

AVLNode* newNode(int key) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; 
    return node;
}

AVLNode* search(AVLNode *root, int key) {
    if (root == NULL) return NULL;
    if (root->key < key) return search(root->right, key);
    return search(root->left, key);
}

AVLNode* Tree(const char** s) {
    if (**s == '\0' || **s == ')') return NULL;
    
    int num = 0;
    while (isdigit(**s)) {
        num = num * 10 + (**s - '0');
        (*s)++;
    }
    
    AVLNode* node = newNode(num);
    
    if (**s == '(') {
        (*s)++;  
        node->left = Tree(s);
        (*s)++;  
        if (**s == '(') {
            (*s)++;  
            node->right = Tree(s);
            (*s)++;  
        }
    }
    
    return node;
}

AVLNode* buildTree(const char* s) {
    return Tree(&s);
}

void printParenthesis(AVLNode* root) {
    if (root == NULL) return;
    
    printf("%d ", root->key);
    
    if (root->left || root->right) {
        printf("( ");
        printParenthesis(root->left);
        printf(") ");
        
        if (root->right) {
            printf("( ");
            printParenthesis(root->right);
            printf(") ");
        }
    }
}

AVLNode* rightRotate(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode* leftRotate(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(AVLNode *N) {
    return N ? height(N->left) - height(N->right) : 0;
}

AVLNode* insert(AVLNode* node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    else return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key) return rightRotate(node);
    if (balance < -1 && key > node->right->key) return leftRotate(node);
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(AVLNode *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

AVLNode* minValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current->left != NULL) current = current->left;
    return current;
}

AVLNode* deleteNode(AVLNode* root, int key) {
    if (root == NULL) return root;

    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL || root->right == NULL) {
            AVLNode *temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else *root = *temp; 
            free(temp);
        } else {
            AVLNode* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL) return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

AVLNode* upperBound(AVLNode *root, int key) {
    AVLNode *current = root;
    AVLNode *candidate = NULL;
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

void inorderTraversal(AVLNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

void postorderTraversal(AVLNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->key);
    }
}

void displayElements(AVLNode *root) {
    if (root == NULL) {
        printf("-1\n");
        return;
    }
    if (root->right) displayElements(root->right);
    printf("%d ", root->key);
    if (root->left) displayElements(root->left);
}

void AVL_SeqInsert(AVLNode** root, int keys[], int n) {
    for (int i = 0; i < n; i++) {
        *root = insert(*root, keys[i]);
    }
    printParenthesis(*root);
    printf("\n");
}

AVLNode* Delete(AVLNode* root, int n1, int n2, int *deleteCount) {
    if (root == NULL) return root;

    root->left = Delete(root->left, n1, n2, deleteCount);
    root->right = Delete(root->right, n1, n2, deleteCount);

    if (root->key >= n1 && root->key <= n2) {
        (*deleteCount)++;
        root = deleteNode(root, root->key);
    }

    if (root == NULL) return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

AVLNode* inorderSuccessor(AVLNode* root, AVLNode* n) {
    if (n->right != NULL) return minValueNode(n->right);

    AVLNode* succ = NULL;
    while (root != NULL) {
        if (n->key < root->key) {
            succ = root;
            root = root->left;
        } else if (n->key > root->key) {
            root = root->right;
        } else {
            break;
        }
    }
    return succ;
}

void SuccessorPath(AVLNode* root, int n) {
    AVLNode* node = root;
    AVLNode* successor = NULL;

    while (node != NULL) {
        if (n < node->key) {
            node = node->left;
        } else if (n > node->key) {
            node = node->right;
        } else {
            successor = inorderSuccessor(root, node);
            break;
        }
    }

    if (node == NULL) {
        printf("%d\n", (height(root) - 1));
        return;
    }

    if (successor != NULL) {
        AVLNode* temp = root;
        while (temp != NULL && temp->key != successor->key) {
            printf("%d ", temp->key);
            if (successor->key < temp->key)
                temp = temp->left;
            else
                temp = temp->right;
        }
        printf("%d\n", successor->key);
    } else {
        printf("%d\n", height(root) - 1);
    }
}

int subtreeSum(AVLNode* node) {
    if (node == NULL) return 0;
    return node->key + subtreeSum(node->left) + subtreeSum(node->right);
}

AVLNode* findNode(AVLNode* root, int key) {
    AVLNode* current = root;
    while (current != NULL) {
        if (key < current->key)
            current = current->left;
        else if (key > current->key)
            current = current->right;
        else
            return current;
    }
    return NULL;
}

void SubtreeSum(AVLNode* root, int n) {
    AVLNode* node = findNode(root, n);

    if (node == NULL) {
        printf("-1\n");
        return;
    }

    int sum = subtreeSum(node);
    printf("%d ", sum);
    printParenthesis(node);
    printf("\n");
}

void findClosest(AVLNode* current, int n, int* closest) {
    if (current == NULL) return;

    if (abs(n - *closest) > abs(n - current->key)) {
        *closest = current->key;
    }

    if (n < current->key)
        findClosest(current->left, n, closest);
    else
        findClosest(current->right, n, closest);
}

int Closest(AVLNode* root, int n) {
    AVLNode* node = findNode(root, n);
    if (node == NULL) return -1;
    
    int closest = -1;
    
    if (node != NULL) {
        int foundClosest = -1;
        if (node->left != NULL) {
            findClosest(node->left, n, &foundClosest);
        }
        if (node->right != NULL) {
            findClosest(node->right, n, &foundClosest);
        }
        return (foundClosest != -1) ? foundClosest : -1;
    } else {
        findClosest(root, n, &closest);
        return closest != n ? closest : -1;
    }
}

int main() {
    char input[100000];
    fgets(input, sizeof(input), stdin);
    
    char* cleanInput = input;
    char* writePtr = input;
    while (*cleanInput) {
        if (*cleanInput != ' ') {
            *writePtr++ = *cleanInput;
        }
        cleanInput++;
    }
    *writePtr = '\0';  

    AVLNode* tree = buildTree(input);
    AVLNode* root = tree;
    char command;
    int n1, n2;
    int keys[1000];
    int numKeys;

    while (scanf(" %c", &command) != EOF) {
        switch (command) {
            case 'a':
                numKeys = 0;
                while (scanf("%d", &keys[numKeys]) == 1) {
                    numKeys++;
                    if (getchar() == '\n')
                        break;
                }
                AVL_SeqInsert(&root, keys, numKeys);
                break;

            case 'b':
                scanf("%d %d", &n1, &n2);
                {
                    int deleteCount = 0;
                    root = Delete(root, n1, n2, &deleteCount);
                    if (deleteCount > 0) {
                        printf("%d ", deleteCount);
                        preOrder(root);
                    } else {
                        printf("-1");
                    }
                    printf("\n");
                }
                break;

            case 'c':
                scanf("%d", &n1);
                SuccessorPath(root, n1);
                break;

            case 'd':
                scanf("%d", &n1);
                SubtreeSum(root, n1);
                break;

            case 'e':
                scanf("%d", &n1);
                printf("%d\n", Closest(root, n1));
                break;

            default:
                printf("Invalid command\n");
                break;
        }
    }

    return 0;
}
