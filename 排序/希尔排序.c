#include<stdio.h>
#include<stdlib.h>

//ϣ������
//����һ��delta���飬��ʾ���
//����delta��ԭ�����Ϊ����С��
//�ڸ���С��������
//���ϼ���delta��ֵ������׼����
void si(int *h,int length,int delta) {
    int i,j;
    for(i = 1 + delta;i <= length;i++) {
    //��һλ�ÿ���Ϊ��λ������������
        if(h[i] < h[i - delta]) {//С�����е�һ�����ֱ�������һ��Сʱ
                                 //��Ҫ��С�������ֱ�Ӳ�������
            h[0] = h[i];//��h[0]����h[i]
            //�������Լ��Ϊdelta��С�����������
            //����h[i]���Ա���h[i]������������
            for(j = i - delta;j > 0 && h[0] < h[j];j -= delta) {
                h[j + delta] = h[j];//�Ӻ���ǰ������С����������
            }
            h[j + delta] = h[0];//��С�����е�һ��������h[i]
        }
    }
}

void shellsort(int *h,int length,int delta[],int n) {
    int i;
    //����delta������ж������
    for(i = 0;i <= n;i++) {
        si(h,length,delta[i]);
    }
}

int main() {
    int n,i,*h,delta[20],d;
    scanf("%d",&i);//����i������
    h = (int *)malloc(i*sizeof(int));//��̬��������
    for(n = 1;n <= i;n++) {//��һλ������������������λ
        scanf("%d",&h[n]);
    }

    //����delta����(Ҳ�����Լ��ֶ�����)
    d = i;
    for(n = 0;d > 1;n++) {
        delta[n] = (d / 3) + 1;
        d = d / 3 + 1;
    }
    delta[n] = d;//���һ����Ϊ1

    shellsort(h,i,delta,n);
    for(n = 1;n <= i;n++) {
        printf("%d ",h[n]);
    }
    return 0;

}
