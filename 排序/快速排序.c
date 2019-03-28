#include<stdio.h>
#include<stdlib.h>
#define Max 100000

//快速排序
//每次排序会选取数组的一个数字
//完成单次排序后会使得该数字处于中间
//重复此过程最终可以完成排序
//本题利用了二分查找的思路和递归的方法，详见代码

//一趟排序
int QKPass(int r[],int low,int high) {
    int x;
    x = r[low];
    //在一趟排序中，把第一个元素作为关键数据，用x保存
    //一次排序完成时，比x[low]小的都会到左边，比x[low]大的都会到右边

    while(low < high) {//当前后两指针未碰头时
        while(low < high && r[high] > x) {//从后往前找第一个比x小的数
            high--;
        }

        if(low < high) {
            r[low] = r[high];//r[low]的值已经用x保存了，可视为空，把r[high]的值移入
                             //之后r[high]可视为空了，而high指针不再移动
            low++;//low后移
        }
        while(low < high && r[low] < x) {//从前往后找第一个比x大的数
            low++;//接下来开始移动low指针
        }
        if(low < high) {
            r[high] = r[low];//再用r[high]来保存r[low]
            high--;//high前移
        }

    }
    r[low] = x;//最后r[low] = r[high]，内容为空，把一开始的值恢复
    return low;//此时low为数组的中点
}

//快速排序
void QKSort(int r[],int low,int high) {
    int pos;
    if(low < high) {
        pos = QKPass(r,low,high);//返回整个数组的中点，完成第一次排序
        QKSort(r,low,pos-1);//前半部分排序
        QKSort(r,pos+1,high);//后半部分排序
    }
}

int main() {
    int i,n,r[Max];
    scanf("%d",&n);//输入n个数字
    for(i = 1;i <= n;i++) {//0号位不存数字，作为哨位
        scanf("%d",&r[i]);
    }
    QKSort(r,1,n);//从第一个到第n个排序
    for(i= 1;i <= n;i++) {
        printf("%d ",r[i]);
    }
    return 0;
}
