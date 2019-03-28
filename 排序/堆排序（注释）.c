#include<stdio.h>

//
void sift(int r[],int k,int m) {
    int t = r[k],i = k,j = 2 * i,finished = 0;//finished为是否调整完毕的标志位，i为双亲结点下标，j为左孩子下标，m为结点总数

    while(j <= m && !finished) {//没有调整完毕，并且下标没有超过结点总数
        if(j + 1 <= m && r[j] < r[j + 1])   j++;//j指向孩子结点里面较大的结点
        if(t >= r[j])   finished = 1;//若双亲结点的值较大，则调整结束
        else {//否则，将孩子结点里较大的值赋给双亲结点，i为当前的双亲结点，j同样指向其左孩子结点
            r[i] = r[j];
            i = j;
            j = 2 * i;
        }
    }
    r[i] = t;//t赋给r[i]
}

void crt_heap(int r[],int n) {
    int i;
    for(i = n / 2;i >= 1;i--)   //从第一个非叶子结点开始，自下而上调整堆
        sift(r,i,n);
}

void HeapSort(int r[],int n) {
    int i,b;
    crt_heap(r,n);//创建初始堆
    for(i = n ;i > 1;i--) {//第一个元素和最后一个元素交换，重新调整堆，且已经交换后的最后一个元素不参加堆调整
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
        scanf("%d",&r[i]);//初始化待排序数列
    }
    HeapSort(r,n);//调用堆排序
    for(i = 1;i <= n;i++) {
        printf("%d ",r[i]);//输出排序后的数列
    }

    return 0;
}
