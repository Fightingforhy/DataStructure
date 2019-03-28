#include<stdio.h>
#include<stdlib.h>
#define Max 1000

//折半排序
//把一个顺序的数组（！！！）拆分成两半
//根据值的对比，再选择性的继续二分
//直到找到为止

typedef struct {
    int key;
}RecordType;
//数据类型

typedef struct {
    RecordType r[Max];
    int length;
}RecordList;
//数据类型表
//注意，必须为有序表

int BinSrch(RecordList l,int k) {
    int low = 0,mid;
    int high = l.length;
    //初始化low，high，分别是头尾

    while(low < high) {
        mid = (low + high) / 2;
        if(l.r[mid].key < k) low = mid + 1;//查找值比中值大，归入右半边
        else high = mid;                   //否则归入左半边
    }

    if(l.r[low].key == k) {//找到了
        return low;
    }
    else return -1;//没有找到时

}

int main() {
    int p,n,x;
    int i;
    RecordList l;
    scanf("%d %d",&n,&p);//输入n个值,查找p个值
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
