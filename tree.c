#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct root
{
    int data;
    struct root *llink;
    struct root *rlink;
};
int COUNT=10;
void insert(struct root *r,int k)
{
    if(k<r->data && r->llink==NULL)
    {
        struct root *t=malloc(sizeof(struct root));
        t->data=k;
        t->llink=NULL;
        t->rlink=NULL;
        r->llink=t;
        return;
    }
    if(k>r->data && r->rlink==NULL)
    {
        struct root *t=malloc(sizeof(struct root));
        t->data=k;
        t->llink=NULL;
        t->rlink=NULL;
        r->rlink=t;
        return;
    }
    if(k<r->data)
        insert(r->llink,k);
    if(k>r->data)
        insert(r->rlink,k);
}
struct root *ord_del(struct root *r)
{
    if(r->llink==NULL)
        return r;
    struct root *t=ord_del(r->llink);
    if(t->llink==NULL && t->rlink==NULL && r->llink->data==t->data)//leaf
    {
        r->llink=NULL;
        return t;
    }
    if(t->llink==NULL && t->rlink!=NULL)//having right child
    {
       r->llink=t->rlink;
       return t;
    }
    return t;
}
struct root *del(struct root *r,int k)
{
    if(r->data==k && r->llink==NULL && r->rlink==NULL)//leaf
        return NULL;
    if(r->data==k && (r->llink==NULL && r->rlink!=NULL))//having right child
        return r->rlink;
    if(r->data==k && (r->llink!=NULL && r->rlink==NULL))//having left child
        return r->llink;
    if(r->data==k && r->llink!=NULL && r->rlink!=NULL)//having both child
    {
        struct root *t=ord_del(r->rlink);
        if(r->rlink->data==t->data)
        {
            r->rlink=t->rlink==NULL?NULL:t->rlink;
        }
        r->data=t->data;
        return r;
    }
    if(k<r->data)
        r->llink=del(r->llink,k);
    if(k>r->data)
        r->rlink=del(r->rlink,k);
    return r;
}
void print2DUtil(struct root *root, int space)
{
    if (root == NULL)
        return;
    space += COUNT;
    print2DUtil(root->rlink, space);
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    print2DUtil(root->llink, space);
}
void print2D(struct root *root)
{
    print2DUtil(root, 0);
}
struct root* srch(struct root *r,int k)
{
    if(r->llink==NULL && r->rlink==NULL)
      return NULL;
    if(r->llink->data==k)
      return r;    
    if(r->rlink->data==k)
      return r;
    if(k<r->data)
      return srch(r->llink,k);
    if(k>r->data)
      return srch(r->rlink,k);
    return r;
}
void ord(struct root *r,int ch)
{
    if(r==NULL)
        return;
    switch(ch)
    {
        case 1:ord(r->llink,1);
               printf("%d\t",r->data);
               ord(r->rlink,1);
               break;
        case 2:printf("%d\t",r->data);
               ord(r->llink,2);
               ord(r->rlink,2);
               break;
        case 3:ord(r->llink,3);
               ord(r->rlink,3);
               printf("%d\t",r->data);
               break;      
    }
}
int allNodes(struct root *r)//including root node
{
    if(r==NULL)
      return 1;
    return allNodes(r->llink)+allNodes(r->rlink) ;
}
int leafNodes(struct root *r)
{
    int ct=0;
    if(r==NULL)
       return 0;
    if(r->llink==NULL && r->rlink==NULL)
       return 1;
    ct+=leafNodes(r->llink)+leafNodes(r->rlink);
    return ct;
}
int height(struct root *r)
{
    if(r==NULL)
       return 1;
    return fmax(height(r->llink),height(r->rlink))+1;
}
void main()
{
    int k,c,aN,lN,h;
    struct root *r1;
    struct root *r=malloc(sizeof(struct root));
    printf("enter the value of root node\n");
    scanf("%d",&r->data);
    printf("1.Build Tree\n2.Delete\n3.Display\n4.Search\n5.Inorder Traversal\n6.Preorder Trarversal\n7.Postorder Traversal\n8.Count of different types of nodes\n9.Height of tree\n10.Exit");
    while(1)
    {
        printf("Choice\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("enter insertion element\n");
                   scanf("%d",&k);
                   insert(r,k);
                   break;
            case 2:printf("enter deletion element\n");
                   scanf("%d",&k);
                   r1=srch(r,k);
                   if(r1==NULL)
                      printf("element !found\n");
                   else
                   {
                        r=del(r,k);
                        printf("deletion\n");
                        print2D(r);
                    }
                    break;
            case 3:print2D(r);
                   break;
            case 4:printf("enter search element\n");
                   scanf("%d",&k);
                   if(k==r->data)
                       printf("Element is root node!\n");
                    else
                    {
                       r1=srch(r,k);
                       if(r1==NULL)
                           printf("element !found\n");
                        else
                        {
                            int i=r1->llink->data==k?1:0;
                            i==1?printf("Left Child of %d\n",r1->data):printf("Right Child of %d\n",r1->data);
                        }                        
                    }
                    break;
            case 5:printf("Inorder is\n");
                   ord(r,1);
                   printf("\n");
                   break;
            case 6:printf("Preorder is\n");
                   ord(r,2);
                   printf("\n");
                   break;
            case 7:printf("Postorder is\n");
                   ord(r,3);
                   printf("\n");
                   break;
            case 8:aN=allNodes(r);
                   lN=leafNodes(r);
                   printf("Leaf Nodes: %d\n",lN);
                   printf("Non Leaf Nodes: %d\n",(aN-lN-1));
                   break;
            case 9:h=height(r);
                   printf("Height of tree: %d\n",(h-1));
                   break;
            case 10:exit(0);
        }
    }
}