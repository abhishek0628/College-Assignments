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
    if(n==NULL)return 0;
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

//method 1
// struct q
// {
//     int rear;
//     int front;
//     struct node *arr[100];
// };
// struct q *form()
// {
//     struct q *q = (struct q *)malloc(sizeof(struct q));
//     if(!q)return NULL;
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
//     if(isempty(q))return NULL;
//     return q->arr[q->front++];
// }
// struct q *push(struct node *root, struct q *q)
// {
//     if(q->rear>100)return NULL;
//     q->arr[q->rear++] = root;
//     return q;
// }

// float averageofodd(struct node *root, int l)
// {
//     if(root==NULL)return 0;
//     int count = 0;
    
//     struct q *q=form();
//     q = push(root, q);
//     q = push(NULL, q);
//     int p = 0;
//     int arr[100];
//     int j = 0;
//     float sum = 0;
//     while (!isempty(q))
//     {
//         struct node *temp = pop(q);
//         if (temp == NULL)
//         {
//             p++;
//             if (!isempty(q))
//             {
//                 q=push(NULL,q);
                
//             }
//             continue;
//         }
        
//             if (l == p)
//             {
//                 arr[j++] = temp->data;
//                 // if(temp->data%2==1)
//                 // {
//                 //     count++;
//                 //     sum=sum+temp->data;
//                 // }
//             }
//             if (temp->left)
//                 q = push(temp->left, q);
//             if (temp->right)
//                 q = push(temp->right, q);
        
//     }
//     for (int i = 0; i < j; i++)
//     {
       
//         if (arr[i] % 2 == 1)
//         {
//             count++;
//             sum = sum + arr[i];
//         }
//     }
//     return count>0?sum / count:0.0;
// }


//method 2

void compute_odd(struct node *root,int curr_level,int target_level,float *sum,int *count)
{
    if(root==NULL)return ;
    if(curr_level==target_level && root->data%2==1)
    {
        (*count)++;
        (*sum)=(*sum)+root->data;
    }
    compute_odd(root->left,curr_level+1,target_level,sum,count);
    compute_odd(root->right,curr_level+1,target_level,sum,count);
}
float averageofodd(struct node *root,int level)
{
    if(root==NULL)return 0;
    float sum=0;
    int count =0;
    compute_odd(root,0,level,&sum,&count);
    if(count==0)return 0;
    return sum/count;
}


void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
int main()
{
    int data;
    int l;
    char ch;
    struct node *root = NULL;
    while (scanf(" %c",&ch) != EOF)
    {
        switch (ch)
        {
        case 'i':
            
            scanf("%d", &data);
            root=insert(root, data);
            
            break;
        case 'p':
            postorder(root);
            printf("\n");
            break;
        case 'a':
           
            scanf("%d", &l);
            printf("%0.1f\n", averageofodd(root, l));
            break;
        case 'e':
            return 0;
        }
    }
    
    return 0;
}
