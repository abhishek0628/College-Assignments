#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

struct tnode *makeLeafNode(int n, char *addr)
{
    struct tnode *temp;
    temp = (struct tnode *)malloc(sizeof(struct tnode));
    temp->op = NULL;
    temp->val = n;
    strcpy(temp->addr, addr);
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode *makeOperatorNode(char c, struct tnode *l, struct tnode *r, char *addr)
{
    struct tnode *temp;
    temp = (struct tnode *)malloc(sizeof(struct tnode));
    temp->op = malloc(sizeof(char));
    *(temp->op) = c;
    temp->left = l;
    temp->right = r;
    strcpy(temp->addr, addr);
    return temp;
}

int evaluate(struct tnode *t)
{
    if (t->op == NULL)
    {
        return t->val;
    }
    else
    {
        switch (*(t->op))
        {
        case '+':
            return evaluate(t->left) + evaluate(t->right);
            break;
        case '-':
            return evaluate(t->left) - evaluate(t->right);
            break;
        case '*':
            return evaluate(t->left) * evaluate(t->right);
            break;
        case '/':
            return evaluate(t->left) / evaluate(t->right);
            break;
        }
    }
}