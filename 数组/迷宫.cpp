#include<stdio.h>
#include<stdlib.h>
int x,y;
int a,b;
int falg=0;
int t[15][15];
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
char mp[15][15];
  
int move(int x,int y)
{
    if(x<1||x>10||y<1||y>10) return 0;
    if(t[x][y]==1)  return 0;
    if(mp[x][y]=='#'||mp[x][y]=='*')  return 0;
    return 1;
}
void pri(int x,int y)
{
    if(falg==1) return;
    if(mp[x][y]=='E')
    {
        mp[x][y]='*';
        falg=1;
        return;
    }
    t[x][y]=1;
    mp[x][y]='*';
    int i;
    for(i=0;i<4;i++)
    {
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(move(tx,ty))
            pri(tx,ty);
        if(falg==1)
            return ;
    }
    t[x][y]=0;
    mp[x][y]='!';
}
int main()
{
    int i,j;
    for(i=1;i<=10;i++)
    {
      for(j=1;j<=10;j++)
      {
        t[i][j]=0;
        scanf("%c",&mp[i][j]);
        if(mp[i][j]=='S')
        {
            x=i;
            y=j;
        }
        else if(mp[i][j]=='E')
        {
            a=i;
            b=j;
        }
      }
      getchar();
    }
    pri(x,y);
    for(i=1;i<=10;i++)
    {
        for(j=1;j<=10;j++)
            printf("%c",mp[i][j]);
        printf("\n");
    }
    return 0;
}
