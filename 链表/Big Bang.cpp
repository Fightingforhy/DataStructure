#include<stdio.h>
#include<string.h>
struct BigBang
{
    char name[30][30];
    int last;
} BigBang;
 
//实现插入功能
void Insert(int a,char b[30])
{
    int i;
    BigBang.last++;
    for(i=BigBang.last;i>a;i--)
    {
      strcpy(BigBang.name[i],BigBang.name[i-1]);
    }
    strcpy(BigBang.name[a],b);
}
 
//实现删除功能
void Delete(int a)
{
    int i;
    for(i=a;i<BigBang.last;i++)
    { 
      strcpy(BigBang.name[i],BigBang.name[i+1]);
    } 
    BigBang.last--;
}
 
//查找并返回所在位置 
int Search(char b[30])
{
    int a=-1;
    int i;
    for(i=0;i<=BigBang.last;i++)
    {
        if(strcmp(BigBang.name[i],b)==0)
        {
            a=i;
            break;
        }
    }
    return a;
}
int main()
{
    BigBang.last=-1;
    char st[30];
    while(scanf("%s",st)!=EOF)
    {
        if(st[0]=='i'&&st[1])    //根据输入字符串的首字母，判断是插入、删除、查找 
        {
            int a;
            char b[30];
            scanf("%d",&a);
            scanf("%s",b);
            Insert(a-1,b);
        }
        else if(st[0]=='s'&&st[1]=='e')
        {
            char b[30];
            scanf("%s",b);
            printf("%d\n",Search(b)+1);
        }
        else if(st[0]=='d')
        {
            char b[30];
            scanf("%s",b);
            int a=Search(b);
            Delete(a);
        }
        else if(st[0]=='s'&&st[1]=='h')
        {
          int i;
          for(i=0;i<=BigBang.last;i++)
            printf("%s ",BigBang.name[i]);
          printf("\n");
        }
    }
    return 0;
}
