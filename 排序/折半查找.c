#include<stdio.h>
#include<stdlib.h>
#define Max 1000

//�۰�����
//��һ��˳������飨����������ֳ�����
//����ֵ�ĶԱȣ���ѡ���Եļ�������
//ֱ���ҵ�Ϊֹ

typedef struct {
    int key;
}RecordType;
//��������

typedef struct {
    RecordType r[Max];
    int length;
}RecordList;
//�������ͱ�
//ע�⣬����Ϊ�����

int BinSrch(RecordList l,int k) {
    int low = 0,mid;
    int high = l.length;
    //��ʼ��low��high���ֱ���ͷβ

    while(low < high) {
        mid = (low + high) / 2;
        if(l.r[mid].key < k) low = mid + 1;//����ֵ����ֵ�󣬹����Ұ��
        else high = mid;                   //�����������
    }

    if(l.r[low].key == k) {//�ҵ���
        return low;
    }
    else return -1;//û���ҵ�ʱ

}

int main() {
    int p,n,x;
    int i;
    RecordList l;
    scanf("%d %d",&n,&p);//����n��ֵ,����p��ֵ
    for(i = 0;i < n;i++) {
        scanf("%d",&l.r[i].key);
    }
    for(i = 0;i < p;i++) {
        scanf("%d",&x);
        printf("%d ",BinSrch(l,x));
    }
    printf("\n");
    return 0;
}
