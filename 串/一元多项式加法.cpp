#include<string.h>
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct Polynode
{
    int coef,exp;
    struct Polynode *next;
} Polynode,*Polylist;

Polylist PolyCreate(char x[])
{
    Polylist    head=(Polylist) malloc( sizeof(Polynode) );
    Polylist    q=head;
    head->next=NULL;
    int len=strlen( x );
     int length_ = strlen( x );
    int i = 0, d = 0;
    char cNum[100], eNum[100];
    while ( i < length_ )
    {
        d = 0;
        Polylist p = (Polylist) malloc( sizeof(Polynode) );
        while ( x[i] == ' ' && i < length_ )
            i++;
        while ( x[i] != ' ' && i < length_ )
            cNum[d++] = x[i++];
        cNum[d] = '\0';
        p->coef = atoi( cNum );
        d = 0;
        while ( x[i] == ' ' && i < length_ )
            i++;
        while ( x[i] != ' ' && i < length_ )
            eNum[d++] = x[i++];
        eNum[d] = '\0';
        p->exp = atoi( eNum );
        q->next = p;
        p->next = NULL;
        q = q->next;
    }
    return(head);
}

void PolyAdd(Polylist a,Polylist b)
{
    Polynode *p,*q,*tail,*temp;
    int sum;
    p=a->next;
    q=b->next;
    tail=a;
    while(p!=NULL&&q!=NULL)
    {
        if(p->exp>q->exp)
        {
            tail->next=p;
            tail=p;
            p=p->next;
        }
        else if(p->exp==q->exp)
        {
            sum=p->coef+q->coef;
            if(sum!=0)
            {
                p->coef=sum;
                tail->next=p;
                tail=p;
                p=p->next;
                temp=q;
                q=q->next;
                free(temp);
            }
            else
            {
                temp=p;
                p=p->next;
                free(temp);
                temp=q;
                q=q->next;
                free(temp);
            }
        }
        else
        {
            tail->next=q;
            tail=q;
            q=q->next;
        }
    }
    if(p!=NULL)
    tail->next=p;
    else
        tail->next=q;
}
void ShowList(Polylist L)
{
     Polylist q;
     q=L->next;
     printf("%d ",q->coef);
     printf("%d ",q->exp);
    while(q->next!=NULL)
    {
        q=q->next;
        printf("%d ",q->coef);
        printf("%d ",q->exp);

    }
    printf("\n");
}
main()
{
    char    a[201], b[201];
    Polylist k,l;
    while(gets(a)!=NULL)
    {
        gets(b);
       k=PolyCreate(a);
       l=PolyCreate(b);
       PolyAdd(k,l);
      ShowList(k);
    }
}
