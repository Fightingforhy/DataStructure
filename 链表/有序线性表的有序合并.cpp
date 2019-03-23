#include<stdio.h>
int main(){
    int m,n;
    int i,j;
    while(scanf("%d",&m)!=EOF){
        int a[m];
        for(i=0;i<m;i++){
            scanf("%d",&a[i]);
        }
        scanf("%d",&n);
        int b[n];
        for(j=0;j<n;j++){
            scanf("%d",&b[j]);
        }
        int sum[m+n];
        for(i=0;i<m+n;i++){
            if(i<m){
                sum[i]=a[i];
            }
            else
            {
                sum[i]=b[i-m];
            }
        }
        int temp;
        for(i=0;i<m+n-1;i++){
            for(j=i+1;j<m+n;j++){
                if(sum[j]<sum[i]){
                    temp=sum[i];
                    sum[i]=sum[j];
                    sum[j]=temp;
                }
            }
        }
        for(i=0;i<m+n;i++){
            if(i<m+n-1)
            printf("%d ",sum[i]);
            else
            printf("%d",sum[i]);
        }
        printf("\n"); 
    }
}
