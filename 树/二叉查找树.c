#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int key;
    struct node *lchild,*rchild;//左右孩子节点
}BSTNode,*BSTree;//BSTNode为一般树节点，*BSTree为顶部指针

//插入
void InsertBst(BSTree *bst,int key) {//对整体产生影响，注意传址
    BSTree s;//节点s用于遍历树，找到应当插入的位置
    if(*bst == NULL) {//当为空节点时
        s = (BSTNode*)malloc(sizeof(BSTNode));
        s->key = key;
        s->lchild = s->rchild = NULL;//初始化
        *bst = s;//此时顶部指针直接指向s
    }
    else if(key < (*bst)->key)//比该节点的值小时，进入左子树继续插入
        InsertBst(&((*bst)->lchild),key);
    else if(key > (*bst)->key)//比该节点的值大时，进入右子树继续插入
        InsertBst(&((*bst)->rchild),key);
}

//创建树
void CreateBST(BSTree *bst,int n) {//此时为空树，注意传址,一共传入n个值
    int key;
    *bst = NULL;
    while(n--) {
        scanf("%d",&key);
        InsertBst(bst,key);//bst为节点指针，本身就是地址
    }
}



//查找
BSTree SearchBST(BSTree bst,int key) {
    if(!bst)//查到的是空树（查找失败）时
        return NULL;
    else if(bst->key == key)//查找成功
        return bst;
    else if(bst->key > key)//当前值比查找值大时，进入左子树继续查找
        return SearchBST(bst->lchild,key);
    else//当前值比查找值小时，进入右子树继续查找
        return SearchBST(bst->rchild,key);
}

int main() {
    int i,x,n,p;
    BSTree t;
    scanf("%d %d",&n,&p);//树中共n个值，做p次查找
    CreateBST(&t,n);//创建树
    for(i = 0;i < p;i++) {
        scanf("%d",&x);
        if(SearchBST(t,x) == NULL)//查找失败
            printf("0");
        else//查找成功
            printf("1");
    }
    printf("\n");
    return 0;
}
