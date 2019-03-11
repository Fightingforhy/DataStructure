#include<iostream>
using namespace std;
#define M 50
typedef struct
{
    char vexs[M];
    int arcs[M][M];
    int vexnum,arcnum;
}Graph;

int visited[M];
void Create(Graph *g,int n)
{
    int i,j,k;
    g->vexnum=n;
    for (i=0;i<g->vexnum;++i)
        for (j=0;j<g->vexnum;++j)
        {
            cin>>k;
            g->arcs[i][j]=k;
            g->arcs[j][i]=g->arcs[i][j];
        }
}

void DepthFirstSearch(Graph g,int v)
{
    int i;
    cout<<v<<" ";
    visited[v]=1;
    for (i=0;i<g.vexnum;i++)
        if ( (g.arcs[v][i]!=0) && (!visited[i]) )
            DepthFirstSearch(g,i);
}

void DFSTraverse(Graph g)
{
    int v,c;
    for (v=0;v<g.vexnum;++v)
        visited[v]=0;
    for (v=0;v<g.vexnum;++v)
    {
        c=0;
        if (!visited[v])
        {
            c=1;
            DepthFirstSearch(g,v);
        }
        if (c==1)
            cout<<endl;
    }
}
int main()
{
    Graph g;
    int n;
    cin>>n;
    Create(&g,n);
    DFSTraverse(g);
    return 0;
}
