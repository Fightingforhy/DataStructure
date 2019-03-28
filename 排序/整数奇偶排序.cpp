#include<stdio.h>
int main(){
    int a[10];
    while(scanf("%d%d%d%d%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9])!=EOF){
        int i,j;
        int temp=0;
        int count=-1;
        int x;
        int b[10];
        for(i=0;i<10;i++){
            if(a[i]%2!=0){
                count++;
                b[count]=a[i];
            }
        }
        x=count+1;
        for(i=0;i<10;i++){
            if(a[i]%2==0){
                count++;
                b[count]=a[i];
            }
        }
        for(i=0;i<x-1;i++){
            for(j=i+1;j<x;j++){
                if(b[j]>b[i])
                {
                    temp=b[i];
                    b[i]=b[j];
                    b[j]=temp;
                }
            }
        }
        for(i=x;i<9;i++){
            for(j=i+1;j<10;j++){
                if(b[j]<b[i]){
                    temp=b[i];
                    b[i]=b[j];
                    b[j]=temp;
                }
            }
        }
        for(i=0;i<10;i++){
            if(i<9){
                printf("%d ",b[i]);
            }
            else{
                printf("%d",b[i]);
            }
        }
        printf("\n");
    }
    return 0;
} 
