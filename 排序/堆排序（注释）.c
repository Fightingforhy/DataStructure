#include<stdio.h>

//
void sift(int r[],int k,int m) {
    int t = r[k],i = k,j = 2 * i,finished = 0;//finishedΪ�Ƿ������ϵı�־λ��iΪ˫�׽���±꣬jΪ�����±꣬mΪ�������

    while(j <= m && !finished) {//û�е�����ϣ������±�û�г����������
        if(j + 1 <= m && r[j] < r[j + 1])   j++;//jָ���ӽ������ϴ�Ľ��
        if(t >= r[j])   finished = 1;//��˫�׽���ֵ�ϴ����������
        else {//���򣬽����ӽ����ϴ��ֵ����˫�׽�㣬iΪ��ǰ��˫�׽�㣬jͬ��ָ�������ӽ��
            r[i] = r[j];
            i = j;
            j = 2 * i;
        }
    }
    r[i] = t;//t����r[i]
}

void crt_heap(int r[],int n) {
    int i;
    for(i = n / 2;i >= 1;i--)   //�ӵ�һ����Ҷ�ӽ�㿪ʼ�����¶��ϵ�����
        sift(r,i,n);
}

void HeapSort(int r[],int n) {
    int i,b;
    crt_heap(r,n);//������ʼ��
    for(i = n ;i > 1;i--) {//��һ��Ԫ�غ����һ��Ԫ�ؽ��������µ����ѣ����Ѿ�����������һ��Ԫ�ز��μӶѵ���
        b = r[1];
        r[1] = r[i];
        r[i] = b;
        sift(r,1,i - 1);
    }
}

int main() {
    int r[100001],i,n;
    scanf("%d",&n);
    for(i = 1;i <= n;i++) {
        scanf("%d",&r[i]);//��ʼ������������
    }
    HeapSort(r,n);//���ö�����
    for(i = 1;i <= n;i++) {
        printf("%d ",r[i]);//�������������
    }

    return 0;
}
