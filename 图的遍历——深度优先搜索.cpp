#include <iostream>
#define MVNum 55
#define MaxInt 32767
using namespace std;

typedef struct
{
    char vexs[MVNum];
    int arcs[MVNum][MVNum];
    int vexnum,arcnum;
}AMGraph;

void CreateUDN(AMGraph &G)
{
    cin>>G.vexnum;
    int i,j,k;
    for(i=0;i<G.vexnum;++i)
        for(j=0;j<G.vexnum;++j){

            cin>>k;
            G.arcs[i][j]=k;
            G.arcs[j][i]=G.arcs[i][j];
        }
}
bool visited[MVNum];

void DfsAM(AMGraph G,int v)
{
    cout<<v<<" ";visited[v]=true;
    for(int w=0;w<G.vexnum;w++)
        if((G.arcs[v][w]!=0)&&(!visited[w])) DfsAM(G,w);
}
void DfsTraverse(AMGraph G)
{
    int v;
    for(v=0;v<G.vexnum;++v)
        visited[v]=false;
    for(v=0;v<G.vexnum;++v) if(!visited[v]) DfsAM(G,v);
}
int main()
{
    AMGraph G;
    CreateUDN(G);
    DfsTraverse(G);
    cout<<endl;
    return 0;
}
