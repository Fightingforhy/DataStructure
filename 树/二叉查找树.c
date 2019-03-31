#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int key;
    struct node *lchild,*rchild;//���Һ��ӽڵ�
}BSTNode,*BSTree;//BSTNodeΪһ�����ڵ㣬*BSTreeΪ����ָ��

//����
void InsertBst(BSTree *bst,int key) {//���������Ӱ�죬ע�⴫ַ
    BSTree s;//�ڵ�s���ڱ��������ҵ�Ӧ�������λ��
    if(*bst == NULL) {//��Ϊ�սڵ�ʱ
        s = (BSTNode*)malloc(sizeof(BSTNode));
        s->key = key;
        s->lchild = s->rchild = NULL;//��ʼ��
        *bst = s;//��ʱ����ָ��ֱ��ָ��s
    }
    else if(key < (*bst)->key)//�ȸýڵ��ֵСʱ��������������������
        InsertBst(&((*bst)->lchild),key);
    else if(key > (*bst)->key)//�ȸýڵ��ֵ��ʱ��������������������
        InsertBst(&((*bst)->rchild),key);
}

//������
void CreateBST(BSTree *bst,int n) {//��ʱΪ������ע�⴫ַ,һ������n��ֵ
    int key;
    *bst = NULL;
    while(n--) {
        scanf("%d",&key);
        InsertBst(bst,key);//bstΪ�ڵ�ָ�룬������ǵ�ַ
    }
}



//����
BSTree SearchBST(BSTree bst,int key) {
    if(!bst)//�鵽���ǿ���������ʧ�ܣ�ʱ
        return NULL;
    else if(bst->key == key)//���ҳɹ�
        return bst;
    else if(bst->key > key)//��ǰֵ�Ȳ���ֵ��ʱ��������������������
        return SearchBST(bst->lchild,key);
    else//��ǰֵ�Ȳ���ֵСʱ��������������������
        return SearchBST(bst->rchild,key);
}

int main() {
    int i,x,n,p;
    BSTree t;
    scanf("%d %d",&n,&p);//���й�n��ֵ����p�β���
    CreateBST(&t,n);//������
    for(i = 0;i < p;i++) {
        scanf("%d",&x);
        if(SearchBST(t,x) == NULL)//����ʧ��
            printf("0");
        else//���ҳɹ�
            printf("1");
    }
    printf("\n");
    return 0;
}
