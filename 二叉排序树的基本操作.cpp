#include<stdio.h>
#include<malloc.h>
#define TRUE 1
#define FALSE 0
typedef struct BiTNode    /*定义树的结点结构*/
{
    int data;            /*由数据和左右孩子指针构成*/
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
typedef int Status;
Status SearchBST(BiTree T,int key)   /*在树中查找目标函数*/
{
    if(!T)     /*如果没找到返回0以表示false*/
    {
        return 0;
    }
    else if(key==T->data) /*找到*/
    {
        return 1;
    }
    else if(key<T->data)
        return SearchBST(T->lchild,key);/*小于则向左子树查找*/
    else
        return SearchBST(T->rchild,key);/*大于则向右子树查找*/
}
int InsertBST(BiTree *T,int e)  /*插入函数*/
{
    if(*T==NULL)/*根节点定义*/
    {
        (*T)=(BiTree)malloc(sizeof(BiTNode));
        (*T)->data=e;
        (*T)->lchild=(*T)->rchild=NULL;
    return 1;
    }
    if(e==(*T)->data) /*重复不插入*/
        return 0;
    else if(e<(*T)->data)
        return InsertBST(&(*T)->lchild,e);
    else
        return InsertBST(&(*T)->rchild,e);
}
void CreateBST(BiTree *T,int *a,int n)      /*建树函数*/
{
    int i=0;
    (*T)=NULL;
    for(i=0;i<n;i++)
        InsertBST(T,a[i]);
}
int main()
{
    int i,n,k,x,v;
    BiTree T;

    int *a;
    scanf("%d%d",&n,&k);
    a=(int *)malloc(sizeof(int)*n);   /*动态分配*/
    for(i=0;i<n;i++)
            scanf("%d",&a[i]);
    CreateBST(&T,a,n);
    for(i=0;i<k;i++)
    {
        scanf("%d",&x);
        v=SearchBST(T,x);
        if(v==1)
                printf("1 ");
        else
                printf("0 ");
    }
    return 0;
}
