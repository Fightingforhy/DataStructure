#include<stdio.h>
#include<stdlib.h>
#define Max 100000

//��������
//ÿ�������ѡȡ�����һ������
//��ɵ���������ʹ�ø����ִ����м�
//�ظ��˹������տ����������
//���������˶��ֲ��ҵ�˼·�͵ݹ�ķ������������

//һ������
int QKPass(int r[],int low,int high) {
    int x;
    x = r[low];
    //��һ�������У��ѵ�һ��Ԫ����Ϊ�ؼ����ݣ���x����
    //һ���������ʱ����x[low]С�Ķ��ᵽ��ߣ���x[low]��Ķ��ᵽ�ұ�

    while(low < high) {//��ǰ����ָ��δ��ͷʱ
        while(low < high && r[high] > x) {//�Ӻ���ǰ�ҵ�һ����xС����
            high--;
        }

        if(low < high) {
            r[low] = r[high];//r[low]��ֵ�Ѿ���x�����ˣ�����Ϊ�գ���r[high]��ֵ����
                             //֮��r[high]����Ϊ���ˣ���highָ�벻���ƶ�
            low++;//low����
        }
        while(low < high && r[low] < x) {//��ǰ�����ҵ�һ����x�����
            low++;//��������ʼ�ƶ�lowָ��
        }
        if(low < high) {
            r[high] = r[low];//����r[high]������r[low]
            high--;//highǰ��
        }

    }
    r[low] = x;//���r[low] = r[high]������Ϊ�գ���һ��ʼ��ֵ�ָ�
    return low;//��ʱlowΪ������е�
}

//��������
void QKSort(int r[],int low,int high) {
    int pos;
    if(low < high) {
        pos = QKPass(r,low,high);//��������������е㣬��ɵ�һ������
        QKSort(r,low,pos-1);//ǰ�벿������
        QKSort(r,pos+1,high);//��벿������
    }
}

int main() {
    int i,n,r[Max];
    scanf("%d",&n);//����n������
    for(i = 1;i <= n;i++) {//0��λ�������֣���Ϊ��λ
        scanf("%d",&r[i]);
    }
    QKSort(r,1,n);//�ӵ�һ������n������
    for(i= 1;i <= n;i++) {
        printf("%d ",r[i]);
    }
    return 0;
}
