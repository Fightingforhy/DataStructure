#include<stdio.h>
#include<stdlib.h>
typedef struct DNode
{
    int data;
    struct DNode *next,*prior;
} DNode;
/*void Create(DNode *&L)
{
    L=(DNode *)malloc(sizeof(DNode));
    L->prior = L;
    L->next = L;
}*/
void Show(DNode *L)
{
    DNode *p;
    p=L->next;
    int i=0;
    while(p!=L)
    {
        if(i++)
        {
            putchar(' ');
        }
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
}
void Insert(DNode *L,int i,int e)
{
    DNode *q,*qlen;
    q=L;
    qlen=L->next;
    int num=0;
    while(qlen!=L)
    {
        num++;
        qlen=qlen->next;
    }
    int j=1;
    while(j<i)
    {
        j++;
        q=q->next;
    }
    if(i>num+1||i<1)//越界
       return ;
    DNode *s;
    s=(DNode *)malloc (sizeof(DNode));
    s->data = e;
 
    s->next = q->next;
    s->prior = q;
    q->next = s;
    q->next->prior = s;
    return ;
}
void Delete (DNode *L,int i)
{
    DNode *q,*qlen;
    qlen=L->next;
    q=L;
    int num=0;
    while(qlen!=L)
    {
        qlen=qlen->next;
        num++;
    }
    if(i<1||i>num)//越界
    {
        return ;
    }
    int j=0;
    while(j<i-1)
    {
        q=q->next;
        j++;
    }
    DNode *qfree;
    qfree= q->next;
    q->next=qfree->next;
    qfree->next->prior=q;
    free(qfree);
 
}
int main ()
{
    int n;
    DNode *L;
    L=(DNode *)malloc(sizeof(DNode));
    L->prior = L;
    L->next = L;
    while(scanf("%d",&n)!=EOF)
    {
        switch(n)
        {
        case 0:
        {
            Show(L);
            break;
        }
        case 1:
        {
            int i,e;
            scanf("%d%d",&i,&e);
            Insert(L,i,e);
            break;
        }
        case 2:
        {
            int i;
            scanf("%d",&i);
            Delete(L,i);
            break;
        }
        default:
            break;
        }
 
    }
    return 0;
}
