#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
   int data;
   struct Node *next;
}Node,*LinkList;
//创建大小为n的链表 
void Create(Node *L)
{
    Node *s;
    int n,a;
    scanf("%d",&n);
    while(n--)
    {
       scanf("%d",&a);
       s=(Node *)malloc(sizeof(Node));
       s->data=a;
       s->next=L->next;
       L->next=s;
    }
}
//头插法实现插入 
void Insert(LinkList L,int i,int e)
{
    int j=0;
    Node *p,*s;
    if(i<=0) printf("insert fail\n");
    p=L;
    while((j<i-1)&&(p->next!=NULL))
    {
        p=p->next;
        j++;
    }
    if(j<i-1)
    {
        printf("insert fail\n");
    }
    else
    {
        s=(Node*)malloc(sizeof(Node));
        s->data=e;
        s->next=p->next;
        p->next=s;
        printf("insert OK\n");
    }
}
//获得所在位置的数据 
void Get(LinkList L,int i)
{
    int j=0;
    Node *p;
    if(i<=0) printf("get fail\n");
    p=L;
    while((j<i)&&(p->next!=NULL))
    {
        p=p->next;
        j++;
    }
    if(i==j)
    {
        printf("%d\n",p->data);
    }
    else
    {
        printf("get fail\n");
    }
}
//删除输入位置的数据 
void Delete(LinkList L,int i)
{
    int j=0;
    Node *p,*s;
    p=L;
    while((j<i-1)&&(p->next!=NULL))
    {
        p=p->next;
        j++;
    }
    if(j<i-1) printf("delete fail\n");
    else
    {
       s=p->next;
       p->next=s->next;
       free(s);
       printf("delete OK\n");
   }
}
//输出链表数据 
void Show(LinkList L)
{
   Node *p;
   p=L->next;
   if(p==NULL)
      printf("Link list is empty");
   while(p!=NULL)
   {
       printf("%d ",p->data);
       p=p->next;
   }
    printf("\n");
}
int main()
{
   int m;
   char s[10];
   Node *L;
   L=(Node*)malloc(sizeof(Node));
   L->next=NULL;
   Create(L);
   scanf("%d",&m);
   while(m--)
   {
       scanf("%s",s);
       if(s[0]=='i')
        {
            int i,e;
            scanf("%d%d",&i,&e);
            Insert(L,i,e);
        }
         
        else if(s[0]=='g'&&s[1]=='e')
        {
            int i;
            scanf("%d",&i);
            Get(L,i);
        }
        else if(s[0]=='d')
        {
            int i;
            scanf("%d",&i);
            Delete(L,i);
        }
         else if(s[0]=='s'&&s[1]=='h')
            Show(L);
    }
    return 0;
}
