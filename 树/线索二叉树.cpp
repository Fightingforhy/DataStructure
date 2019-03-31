#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100 
 
char array[N];
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
 
void Visit(BiTree T);//中序输出 
void InOrder(BiTree T);//中序遍历 
 
int CreateBiTree(BiTree &T,int &index,int &n){//按先序序列创建二叉树
    if(index >= n){
        return 0;
    }
    //按先序次序输入二叉树中结点的值（一个字符），空格表示空树
    if(array[index] == ' '){
        T = NULL;
        index++;
    }
    else{
        T = (BiTree)malloc(sizeof(BiTNode));        
        T->data = array[index];//生成根结点
        index++;
        CreateBiTree(T->lchild,index,n);//构造左子树
        CreateBiTree(T->rchild,index,n);//构造右子树
    }
    return 0;
}
 
void Visit(BiTree T){
    printf("%c ",T->data);
}
 
//中序遍历
void InOrder(BiTree T){
    if(T != NULL){
        InOrder(T->lchild);//访问左子结点      
        Visit(T);//访问根节点    
        InOrder(T->rchild);//访问右子结点
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
