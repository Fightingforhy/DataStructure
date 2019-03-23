#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>   
typedef struct node  
{  
    char data;  
    struct node *next;  
}LStackNode,*LinkStack;
void Transition(int x)  
{  
    LStackNode *p,*top=NULL;  
    do 
    {  
        p=(LinkStack)malloc(sizeof(LStackNode));  
        p->data=x%8;  
        p->next=top;  
        top=p;  
        x/=8;  
    }while(x!=0);  
    while(top!=NULL)  
    {  
        p=top;  
        printf("%d",p->data);
        top=top->next;  
        free(p);  
    }  
    printf("\n");
}
int main(){
    int x;
    while(scanf("%d",&x)!=EOF){
        Transition(x);  
    }
    return 0;
}
