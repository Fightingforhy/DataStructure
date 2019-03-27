#include<stdio.h>
#include<stdlib.h>
#define MVN 50
#define True 1
#define False 0
#define Error -1

//深度优先遍历
//由小到大 ，有路就走，走哪是哪
//“一条路走到底”
//利用递归和路径判断数组
//对所有的路径进行尝试，比较无赖的做法

typedef char VertexData;

//矩阵中的点
typedef struct ArcNode {
    int adj;
}ArcNode;

//定义图
typedef struct {
    VertexData vertex[MVN];//顶点向量
    ArcNode arcs[MVN][MVN];//邻接矩阵
    int vexnum,arcnum;     //图的顶点数和弧数
}AdjMaxtrix;

//被走过节点标记
int visited[MVN];

//创建图
void CreateDN(AdjMaxtrix *G) {//注意传址，创建图
    int i,j,k,weight;
    VertexData v1,v2;
    scanf("%d",&G->vexnum);//输入顶点数

    //遍历矩阵，增加权值
    for(i = 0;i < G->vertex;i++) {
        for(j = 0;j < G->vertex;j++) {
            scanf("%d",&weight);
            G->arcs[i][j].adj = weight;//输入各边的权值
        }
    }
}

//走过节点
void visit(int i) {
    printf("\n");
}

void DFS(AdjMaxtrix g,int v0) {//从v0点开始遍历
    int vj;
    visit(v0);
    visited[v0] = True;
    for(vj = 0;vj < g.vexnum;vj++) {//从0号开始
        if(!visited[vj] && g.arcs[v0][vj].adj == 1) {//如果没走过vj，而且有路径可以走
                                                     //那就走过vj，并且接下来以vj为起点走
            DFS(g,vj);//递归寻路
        }
    }

}

int main() {
    int i;
    AdjMaxtrix G;
    CreateDN(&G);//初始化创建
    DFS(G,0);//从第0个开始遍历

    return 0;
}
