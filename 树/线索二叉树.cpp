#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100 
 
char array[N];
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
 
void Visit(BiTree T);//������� 
void InOrder(BiTree T);//������� 
 
int CreateBiTree(BiTree &T,int &index,int &n){//���������д���������
    if(index >= n){
        return 0;
    }
    //�������������������н���ֵ��һ���ַ������ո��ʾ����
    if(array[index] == ' '){
        T = NULL;
        index++;
    }
    else{
        T = (BiTree)malloc(sizeof(BiTNode));        
        T->data = array[index];//���ɸ����
        index++;
        CreateBiTree(T->lchild,index,n);//����������
        CreateBiTree(T->rchild,index,n);//����������
    }
    return 0;
}
 
void Visit(BiTree T){
    printf("%c ",T->data);
}
 
//�������
void InOrder(BiTree T){
    if(T != NULL){
        InOrder(T->lchild);//�������ӽ��      
        Visit(T);//���ʸ��ڵ�    
        InOrder(T->rchild);//�������ӽ��
    }
}
 
int main()
{
    int len,index;
    while(gets(array)){
        BiTree T;
        len = strlen(array);
        index = 0;
        CreateBiTree(T,index,len);
        index = 0;
        InOrder(T);
        printf("\n");
    }
    return 0;
}
