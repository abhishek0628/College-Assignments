#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;

};
struct node *create(int data)
{
    struct node *root=(struct node *)malloc(sizeof(struct node));
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    return root;
}
struct node *buildTree(int l,int h,int *preorder,int *preindex,int *inorder)
{
    if(l>h)return NULL;
    int key=preorder[(*preindex)];
    (*preindex)++;
    struct node *root=create(key);
    if(l==h)return root;
    int i;
    for(i=l;i<=h;i++)
    {
        if(inorder[i]==key)break;
    }
    root->left=buildTree(l,i-1,preorder,preindex,inorder);
    root->right=buildTree(i+1,h,preorder,preindex,inorder);
    return root;


}
void postorder(struct node *root)
{
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
int leafsum(struct node *root)
{
    int sum=0;
    if(root==NULL)return 0;
    if(root->left==NULL &&root->right==NULL)
    {
        sum=sum+root->data;
    }
    sum=sum+leafsum(root->left);
    sum=sum+leafsum(root->right);
    return sum;
}
int main()
{
    struct node *root=NULL;
    int n;
    scanf("%d",&n);
    int *inorder=(int *)malloc(sizeof(int )*n);
    int *preorder=(int *)malloc(sizeof(int )*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&preorder[i]);
    }
    for(int i=0;i<n;i++)
    {
        scapnf("%d",&inorder[i]);
    }
    int preindex=0;
    root=buildTree(0,n-1,preorder,&preindex,inorder);
    char choice;
    while(scanf(" %c",&choice)!=EOF)
    {
        switch(choice)
        {
            case 'p':postorder(root);
                     printf("\n");
                     break;
            case 's':printf("%d\n",leafsum(root));
                     break;
            case 'e':return 0;         
        }
    }
    return 0;
}