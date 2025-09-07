#include <stdlib.h>
#include <stdio.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
    int height;
};
struct node *create(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = NULL;
    newnode->height = 1;
    return newnode;
}
int max(int a, int b)
{
    return a > b ? a : b;
}
int height(struct node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}
struct node *leftrotate(struct node *x)
{
    struct node *y = x->right;
    struct node *t = y->left;
    y->left = x;
    x->right = t;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}
struct node *rightrotate(struct node *x)
{
    struct node *y = x->left;
    struct node *t = y->right;
    y->right = x;
    x->left = t;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}
int balance(struct node *root)
{
    return height(root->left) - height(root->right);
}
struct node *insert(struct node *root, int data)
{
    if (root == NULL)
        return create(data);
    if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        return root;
    }
    root->height = max(height(root->right), height(root->left)) + 1;
    int bf = balance(root);
    if (bf > 1 && root->left->data > data)
    {
        return rightrotate(root);
    }
    if (bf < -1 && data > root->right->data)
    {
        return leftrotate(root);
    }
    if (bf > 1 && root->left->data < data)
    {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    if (bf < -1 && root->right->data > data)
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}


void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
// struct q
// {
//     int rear;
//     int front;
//     struct node *arr[100];
// };
// struct q *form()
// {
//     struct q *q = (struct q *)malloc(sizeof(struct q));
//     if (!q)
//         return NULL;
//     q->rear = 0;
//     q->front = 0;
//     return q;
// }
// int isempty(struct q *q)
// {

//     return q->rear == q->front;
// }
// struct node *pop(struct q *q)
// {
//     if (isempty(q))
//         return NULL;
//     return q->arr[q->front++];
// }
// struct q *push(struct node *root, struct q *q)
// {
//     if (q->rear > 100)
//         return NULL;
//     q->arr[q->rear++] = root;
//     return q;
// }

// int secondmax(struct node *root)
// {
//     if (root == NULL)
//         return 0;
//     int count = 0;

//     struct q *q = form();
//     q = push(root, q);
//     // q = push(NULL, q);
//     int p = 0;
//     int arr[100];
//     int j = 0;
//     float sum = 0;
//     while (!isempty(q))
//     {
//         struct node *temp = pop(q);

//         if (root != NULL && temp->left == NULL && temp->right == NULL)
//         {
//             arr[j++] = temp->data;
//         }
//         if (temp->left)
//             q = push(temp->left, q);
//         if (temp->right)
//             q = push(temp->right, q);
//     }

//     return arr[j - 2];
// }
int isleaf(struct node *root)
{
    if(root==NULL)return 1;
    if(root->left==NULL && root->right==NULL)
    {
        return 1;
    }
    return 0;
}
struct node *search(struct node *root,int data)
{
    if(root==NULL)return NULL;
    if(root->data==data)return root;
    struct node *left=search(root->left,data);
    if(left!=NULL)return left;
    return search(root->right,data);

}
int max2(int *arr,int n)
{
    int maxx=arr[0];
    for(int i=0;i<n;i++)
    {
        if(maxx<arr[i])
        {
            maxx=arr[i];
        }

    }
    return maxx;
}
int smax(int *arr,int n )
{
   int maxx=max2(arr,n);
   int smaxx=arr[0];
   int found=0;
   for(int i=0;i<n;i++)
   {
    if(arr[i]<maxx)
    {
        if(found==0||arr[i]>smaxx)
        {
            smaxx=arr[i];
            found=1;
        }

    }

   }
   return found?smaxx:-1;

}
void leaves(struct node *root,int *arr,int *index)
{
    if(root==NULL)return;
    if(isleaf(root))
    {
        arr[(*index)++]=root->data;
    }
    leaves(root->left,arr,index);
    leaves(root->right,arr,index);
}
int secondmax(struct node *root)
{
    int *arr=(int *)malloc(sizeof(int)*100);
    int index=0;
    leaves(root,arr,&index);
    return smax(arr,index);
}
int main()
{
    int data;
    int l;
    char ch;
    struct node *root = NULL;
    while (scanf(" %c", &ch) != EOF)
    {
        switch (ch)
        {
        case 'i':

            scanf("%d", &data);
            root = insert(root, data);

            break;
        case 'p':
            postorder(root);
            printf("\n");
            break;
        case 's':

            printf("%d\n", secondmax(root));
            break;
        case 'e':
            return 0;
        }
    }

    return 0;
}