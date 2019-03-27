#include <cstdio>
#include <algorithm>
using namespace std;
const int inf=1e9;
const int maxn=200;
int n,dis[maxn][maxn];
 
void floyd(){
 
    for(int k=0;k<n;k++)
 
        for(int i=0;i<n;i++)
 
            for(int j=0;j<n;j++)
 
                if(dis[i][k]!=inf&&dis[k][j]!=inf&&dis[i][k]+dis[k][j]<dis[i][j])
 
                    dis[i][j]=dis[i][k]+dis[k][j];
 
}
 
  
 
int main(){
 
        scanf("%d",&n);
 
        fill(dis[0],dis[0]+maxn*maxn,inf);
 
        for(int i=0;i<n;i++) dis[i][i]=0;
 
        for(int i=0;i<n;i++){
 
            for(int j=0;j<n;j++){
 
                int x;
 
                scanf("%d",&x);
 
                if(x) dis[i][j]=x;
 
            }
 
        }
 
        floyd();
 
        for(int i=0;i<n;i++){
 
            for(int j=0;j<n;j++){
 
                if(dis[i][j]!=inf) printf("%d ",dis[i][j]);
 
                else printf("-1 ");
 
            }
 
            printf("\n");
 
        }
 
    return 0;
 
}
