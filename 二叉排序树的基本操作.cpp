#include<stdio.h>
#include<malloc.h>
#define TRUE 1
#define FALSE 0
typedef struct BiTNode    /*�������Ľ��ṹ*/
{
    int data;            /*�����ݺ����Һ���ָ�빹��*/
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
typedef int Status;
Status SearchBST(BiTree T,int key)   /*�����в���Ŀ�꺯��*/
{
    if(!T)     /*���û�ҵ�����0�Ա�ʾfalse*/
    {
        return 0;
    }
    else if(key==T->data) /*�ҵ�*/
    {
        return 1;
    }
    else if(key<T->data)
        return SearchBST(T->lchild,key);/*С����������������*/
    else
        return SearchBST(T->rchild,key);/*������������������*/
}
int InsertBST(BiTree *T,int e)  /*���뺯��*/
{
    if(*T==NULL)/*���ڵ㶨��*/
    {
        (*T)=(BiTree)malloc(sizeof(BiTNode));
        (*T)->data=e;
        (*T)->lchild=(*T)->rchild=NULL;
    return 1;
    }
    if(e==(*T)->data) /*�ظ�������*/
        return 0;
    else if(e<(*T)->data)
        return InsertBST(&(*T)->lchild,e);
    else
        return InsertBST(&(*T)->rchild,e);
}
void CreateBST(BiTree *T,int *a,int n)      /*��������*/
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
    a=(int *)malloc(sizeof(int)*n);   /*��̬����*/
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
