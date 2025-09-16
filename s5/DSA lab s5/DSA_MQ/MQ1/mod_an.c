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
struct node *findparent(struct node *root,struct node *target)
{
    if(root==NULL|| root==target)return NULL;
    
    if(root->left==target ||root->right==target)
    {
        return root;
    }
    struct node *left=findparent(root->left,target);
    if(left!=NULL)return left;
    return findparent(root->right,target);

}
int getlevel(struct node *root,struct node *target,int level)
{
    if(root==NULL)return -1;
    if(root==target)return level;

    int left=getlevel(root->left,target,level+1);
    if(left!=-1)return left;
    return getlevel(root->right,target,level+1);
}
struct node *search(struct node *root,int data)
{
    if(root==NULL)return NULL;
    if(root->data==data)return root;
    struct node *left=search(root->left,data);
    if(left!=NULL)return left;
    return search(root->right,data);
}
int cousin(struct node *root,int x,int y)
{
    if(root==NULL)return 0;
    struct node *x1=search(root,x);
    struct node *y1=search(root,y);
    struct node *x2=findparent(root,x1);
    struct node *y2=findparent(root,y1);
    int x3=getlevel(root,x1,0);
    int y3=getlevel(root,y1,0);
    if(x3==y3 && y2!=x2)
    {
        return 1;
    }
    return 0;
}
int main()
{
    struct node *root=NULL;
    int n,x,y;
    scanf("%d",&n);
    int *inorder=(int *)malloc(sizeof(int )*n);
    int *preorder=(int *)malloc(sizeof(int )*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&preorder[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&inorder[i]);
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
            case 'c':scanf("%d%d",&x,&y);
                    int r=cousin(root,x,y);
                    if(r==1)
                    {
                        printf("yes\n");
                    }
                    else printf("no\n");
                     break;
            case 'e':return 0;         
        }
    }
    return 0;
}