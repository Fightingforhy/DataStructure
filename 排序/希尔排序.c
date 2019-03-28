#include<stdio.h>
#include<stdlib.h>

//希尔排序
//设立一个delta数组，表示间隔
//利用delta把原数组分为几个小组
//在各个小组内排序
//不断减少delta的值，来精准排序
void si(int *h,int length,int delta) {
    int i,j;
    for(i = 1 + delta;i <= length;i++) {
    //第一位置空作为哨位，不参与排序
        if(h[i] < h[i - delta]) {//小数组中的一个数字比它的上一个小时
                                 //就要对小数组进行直接插入排序
            h[0] = h[i];//用h[0]保存h[i]
            //接下来对间隔为delta的小数组进行排序
            //保存h[i]，以便用h[i]来保存其他数
            for(j = i - delta;j > 0 && h[0] < h[j];j -= delta) {
                h[j + delta] = h[j];//从后往前，交换小数组中两数
            }
            h[j + delta] = h[0];//把小数组中第一个数换回h[i]
        }
    }
}

void shellsort(int *h,int length,int delta[],int n) {
    int i;
    //利用delta数组进行多次排序
    for(i = 0;i <= n;i++) {
        si(h,length,delta[i]);
    }
}

int main() {
    int n,i,*h,delta[20],d;
    scanf("%d",&i);//输入i个数字
    h = (int *)malloc(i*sizeof(int));//动态分配数组
    for(n = 1;n <= i;n++) {//第一位不保存数，用于做哨位
        scanf("%d",&h[n]);
    }

    //设置delta数组(也可以自己手动输入)
    d = i;
    for(n = 0;d > 1;n++) {
        delta[n] = (d / 3) + 1;
        d = d / 3 + 1;
    }
    delta[n] = d;//最后一个必为1

    shellsort(h,i,delta,n);
    for(n = 1;n <= i;n++) {
        printf("%d ",h[n]);
    }
    return 0;

}
