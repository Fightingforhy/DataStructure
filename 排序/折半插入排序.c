#include<stdio.h>
#include<stdlib.h>
#define Max 1000

//�۰��������
//������ĵ�һ����Ϊ��λ���������ݵı���
//�ڵ�i��ѭ���У�1~��i-1�����Ѿ��ź��˵�����
//��һ��ѭ��ֻ��Ҫ�����i�������뵽����
//�γ�һ��1~i���������
//һֱ�ظ���i = n���������

int a[Max];
//����Ϊȫ�ֵ����飬�������
//��������������


//�۰����
void Binsort(int a[],int n) {
    int x,i,j,low,high,mid;
    for(i = 1;i < n;i++) {//�ӵڶ���Ԫ�ؿ�ʼ
        x = a[i];//x����ʱ����
        low = 0;
        high = i - 1;
        //low,high��0��i-1������ѭ��������
        //���i��ѭ��ʱ��ǰ0��i-1�Ѿ����������

        while(low <= high) {
            mid = (low + high) / 2;
            if(x < a[mid])  high = mid - 1;//����ֵ���򱻻�����벿��
            else low = mid + 1;            //�������Ұ벿��
        }
    }

    //��ǰi-1�Ļ����ϣ����ϵ�i��Ԫ��
    for(j = i - 1;j >= low;j--) {
        a[j + 1] = a[j];//����ǰ�ƣ��ڳ���i���Ŀռ�
    }
    a[low] = x;//�ҵ�λ�ã������i��Ԫ��
            //ע��˴���low������0��
}

int main() {
    int i,n;
    scanf("%d",&n);//����n������
    for(i = 0;i < n;i++) {
        scanf("%d",&a[i]);
    }

    //�۰��������
    Binsort(a,n);

    //��������
    for(i = 0;i < n;i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
