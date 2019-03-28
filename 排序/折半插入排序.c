#include<stdio.h>
#include<stdlib.h>
#define Max 1000

//折半插入排序
//把数组的第一个设为哨位，用于数据的保存
//在第i次循环中，1~（i-1）是已经排好了的数组
//这一次循环只需要把这第i个数插入到其中
//形成一个1~i有序的数组
//一直重复到i = n，完成排序

int a[Max];
//设置为全局的数组，方便调用
//必须是有序数组


//折半插入
void Binsort(int a[],int n) {
    int x,i,j,low,high,mid;
    for(i = 1;i < n;i++) {//从第二个元素开始
        x = a[i];//x来暂时保存
        low = 0;
        high = i - 1;
        //low,high由0到i-1，而在循环中排序
        //则第i次循环时，前0到i-1已经排序完成了

        while(low <= high) {
            mid = (low + high) / 2;
            if(x < a[mid])  high = mid - 1;//比中值大，则被划入左半部分
            else low = mid + 1;            //否则划入右半部分
        }
    }

    //在前i-1的基础上，加上第i个元素
    for(j = i - 1;j >= low;j--) {
        a[j + 1] = a[j];//依次前移，腾出第i个的空间
    }
    a[low] = x;//找到位置，插入第i个元素
            //注意此处的low不再是0了
}

int main() {
    int i,n;
    scanf("%d",&n);//输入n个数字
    for(i = 0;i < n;i++) {
        scanf("%d",&a[i]);
    }

    //折半插入排序
    Binsort(a,n);

    //排序后输出
    for(i = 0;i < n;i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
