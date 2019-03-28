#include<stdio.h>
int main(){
   int m,n;
   int i,j;
   int a[200],b[200];
   while(scanf("%d",&m)!=EOF)
   {
      for(i=0;i<m;i++)
      {
         scanf("%d",&a[i]);
      }
      scanf("%d",&n);
      for(j=0;j<n;j++)
      {
        scanf("%d",&b[j]);
      }
      for(i=0;i<m;i++)
      {
        printf("%d ",a[i]);
      }
      printf("\n");
      for(j=0;j<n;j++)
      {
        printf("%d ",b[j]);
      }
      printf("\n");
      for(j=0;j<n;j++)
      {
        for(i=0;i<m;i++)
        {
          if(a[i]==b[j])
          {
            break;
          }
          if(i==m-1)
          {
            a[m]=b[j];
            m++;
          }
        }
        for(i=0;i<m;i++)
        printf("%d ",a[i]);
        printf("\n");
      }
      printf("\n");
   }
   return 0;
}
