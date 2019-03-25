#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct
{
    int a[100];
    int top;
}Seqstack1;
typedef struct
{
    char a[100];
    int top;
}Seqstack2;
 
int preceed(char a);
void operators(Seqstack1 *s,char a);
void push1(Seqstack1 *s,int x)
{
    s->top++;
    s->a[s->top]=x;
}
void push2(Seqstack2 *s,char x)
{
    s->top++;
    s->a[s->top]=x;
}
int pop1(Seqstack1 *s)
{
    int x;
    x=s->a[s->top];
    s->top--;
    return x;
}
char pop2(Seqstack2 *s)
{
    char x;
     x=s->a[s->top];
    s->top--;
    return x;
}
int preceed(char a)
{
    if(a=='*'||a=='/')return 3;
    if(a=='+'||a=='-')return 2;
    if(a=='('||a==')')return 4;
}
void operators(Seqstack1 *s,char a)
{
    int x=pop1(s);
    int y=pop1(s);
    int z;
    if(a=='+')
    {
        z=x+y;
        push1(s,z);
    }
    else if(a=='-')
    {
        z=y-x;
        push1(s,z);
    }
    else if(a=='*')
    {
        z=x*y;
        push1(s,z);
    }
    else
    {
        z=y/x;
   
        push1(s,z);
    }
}
int main()
{
    Seqstack1 *s1;
    Seqstack2 *s2;
    s1=(Seqstack1*)malloc(sizeof(Seqstack1));
    s2=(Seqstack2*)malloc(sizeof(Seqstack2));
    int i,j,k,m,n,x,temp1,temp2;
    char s[100];
    int length;
    while(scanf("%s",s)!=EOF)
    {
        i=0;
        s1->top=-1;
        s2->top=-1;
        length=strlen(s);
        while(i<length-1)
        {
  
            if(s2->top==-1&&(s[i]=='+'||s[i]=='-'||s[i]=='/'||s[i]=='*'))
            {
                push2(s2,s[i]);
                i++;
            }
  
            else if(s[i]=='+'||s[i]=='-'||s[i]=='/'||s[i]=='*')
            {
                if(preceed(s2->a[s2->top])<preceed(s[i]))
                {
                    i++;
                    push1(s1,s[i]-'0');
                    operators(s1,s[i-1]);
                    i++;
                }
                else
                {
                    push2(s2,s[i]);
                    i++;
                }
            }
  
            else if(s[i]=='('||s[i]==')')
            {
   
                 if(s[i]=='(')
                {
                    temp1=s2->top;
                    temp2=s1->top;
                    push2(s2,s[i]);
                    j=s1->top;
                    m=s2->top;
                    i++;
                }
                  else
                {
                   k=s1->top;
                   n=s2->top;
                   x=0;
                   while(j<k)
                   {
                       if(s2->a[m+1]=='+')
                       {
                           x=s1->a[j+1]+s1->a[j+2]+x;
                           j=j+2;
                           m++;
                       }
                        else if(s2->a[m+1]=='-')
                       {
                           x=s1->a[j+1]-s1->a[j+2]+x;
                           j=j+2;
                           m++;
                       }
                        else if(s2->a[m+1]=='*')
                       {
                           x=s1->a[j+1]*s1->a[j+2]+x;
                           j=j+2;
                           m++;
                       }
                       else if (s2->a[m+1]=='/')
                       {
                           x=s1->a[j+1]/s1->a[j+2]+x;
                           j=j+2;
                           m++;
                       }
                         }
                   i++;
                   s2->top=temp1;
                   s1->top=temp2;
                   push1(s1,x);
                }
            }
             else
            {
                if(s[i+1]-'0'>=0&&s[i+1]-'0'<=9)
                {
                    push1(s1,(s[i]-'0')*10+s[i+1]-'0');
                    i++;
                }
                else
                {
                    push1(s1,s[i]-'0');
                }
                i++;
            }
        }
        if(s2->top>1)
        {
            operators(s1,s2->a[s2->top]);
            s2->top--;
        }
        if(s2->top==1)
        {
            x=0;
            if(preceed(s2->a[0])==preceed(s2->a[1]))
            {
                 if(s2->a[0]=='+')
                 {
                     x=s1->a[0]+s1->a[1];
                 }
                 if(s2->a[0]=='-')
                 {
                     x=s1->a[0]-s1->a[1];
                 }
                 if(s2->a[0]=='*')
                 {
                     x=s1->a[0]*s1->a[1];
                 }
                 if(s2->a[0]=='/')
                 {
                     x=s1->a[0]/s1->a[1];
                 }
                  if(s2->a[1]=='+')
                 {
                     x=x+s1->a[s1->top];
                 }
                 if(s2->a[1]=='-')
                 {
                     x=x-s1->a[s1->top];
                 }
                 if(s2->a[1]=='*')
                 {
                     x=x*s1->a[s1->top];
                 }
                 if(s2->a[1]=='/')
                 {
                     x=x/s1->a[s1->top];
                 }
                  printf("%d\n",x);
            }
            else
            {
                x=0;
                if(s2->a[0]=='*')
                {
                    x=s1->a[0]*s1->a[1];
                }
                if(s2->a[0]=='/')
                {
                    x=s1->a[0]/s1->a[1];
                }
                if(s2->a[1]=='+')
                {
                    x=x+s1->a[2];
                }
                if(s2->a[1]=='-')
                {
                    x=x-s1->a[2];
                }
               printf("%d\n",x);
            }
        }
        if(s2->top==0)
        {
            x=0;
             if(s2->a[0]=='+')
                 {
                     x=s1->a[0]+s1->a[1];
                 }
                 if(s2->a[0]=='-')
                 {
                     x=s1->a[0]-s1->a[1];
                 }
                 if(s2->a[0]=='*')
                 {
                     x=s1->a[0]*s1->a[1];
                 }
                 if(s2->a[0]=='/')
                 {
                     x=s1->a[0]/s1->a[1];
                 }
                 printf("%d\n",x);
        }
            memset(s1->a,0,sizeof(s1->a));
            memset(s2->a,0,sizeof(s2->a));
            memset(s,0,sizeof(s));
    }
    return 0;
}
