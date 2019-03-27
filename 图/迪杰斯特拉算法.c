#include<stdio.h>
#include<stdlib.h>
#define m 50

//迪杰斯特拉算法
//适用于有向图
//从第一个结点开始，算出到各节点的最短路径
//节点到自身或者无法抵达时，距离为无穷
//每回新加入一个节点，更新一次最短路径
//把所有节点遍历过后，自然就有最后的最短路径了

//定义不同的图类型
typedef enum {dg,dn,udg,udn}graphkind;

typedef char vertexdata;//节点数据

//图中各点
typedef struct arcnode {
    int adj;
}arcnode;

//图定义
typedef struct {
    vertexdata vertex[m];//各点的向量
    arcnode arcs[m][m];//各个弧上的权值
    int vexnum,arcnum;//顶点数和弧个数
    graphkind kind;//图的种类
}adjmatrix;

//迪杰斯特拉算法,输入s输出各点到该点的最短距离
void Dijkstra(adjmatrix l,int *s) {
    int i,j,k;
    int dist[m][m];//辅助数组,算权值

    //初始化
    for(i = 0;i < l.vexnum;i++) {
        for(j = 0;j < l.vexnum;j++) {
            dist[i][j] = l.arcs[i][j].adj;//初始化各个路径权值
        }
    }

    //在原有的路径上加入节点k
    //不断循环，尝试性的加入
    for(k = 0;k < l.vexnum;k++) {
        for(i = 0;i < l.vexnum;i++) {
            for(j = 0;j < l.vexnum;j++) {
                //由i点到j点的路径
                //如果途经k点时，距离反而更近
                //这时就要更新最短距离了
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    //寻路完成后，进行查找
    for(i = 0;i < l.vexnum;i++) {
        if(dist[*s][i] == 999) {//当s节点没有路径到达i节点（不存在最短路径）
            printf("-1 ");
        }
        else {
            printf("%d ",dist[*s][i]);
        }
    }
}

int main() {
    int n,i,j,k,s;
    adjmatrix l;
    scanf("%d",&n);//一共n个顶点
    scanf("%d",&s);//输入查找的点
    l.vexnum = n;

    for(i = 0;i < n;i++) {
        for(j = 0;j < n;j++) {
            scanf("%d",&k);
            if(i != j &&k == 0) {//节点到自身距离为0，不受输入影响，为区分记为无穷
                                 //输入0时，意味着两点重合，同样记为无穷
                l.arcs[i][j].adj = 999;
            }
            else l.arcs[i][j].adj = k;
        }
    }
    Dijkstra(l,&s);
}
