#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define inf 0x3f3f3f3f
int m[55][55];
int dis[55];
bool vis[55];
int n,s;
void dijsktra()
{
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)
        dis[i]=m[s][i];
    vis[s]=1;
    dis[s]=0;
    for(int i=0;i<n;i++)
    {
        int v;
        int temp=inf;
        for(int j=0;j<n;j++)
            if(!vis[j]&&dis[j]<temp)
            {
                v=j;
                temp=dis[j];
            }
        vis[v]=1;
        for(int j=0;j<n;j++)
        {
            if(!vis[j]&&(dis[v]+m[v][j])<dis[j])
                dis[j]=dis[v]+m[v][j];
        }
    }
}
int main()
{
    int temp;
    scanf("%d%d",&n,&s);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
    {
        scanf("%d",&temp);
        if(temp==0)
            m[i][j]=inf;
        else
            m[i][j]=temp;
    }
    dijsktra();
    for(int i=0;i<n;i++)
        if(i!=s)
    {
        if(dis[i]>=inf)
            printf("-1 ");
        else
            printf("%d ",dis[i]);
    }
    printf("\n");
    return 0;
}
