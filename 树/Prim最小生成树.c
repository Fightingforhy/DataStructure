#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define maxnum 50
#define infinity 32768//表示极大值无穷

//Prim法求最小生成树
//从任一节点出发，一次加入一个节点及其对应的最小边
//最终实现包含所有节点，和它们的最小边
//即最小生成树

//图的定义
typedef struct {
    int vertex[maxnum];//图的顶点数组
    int arc[maxnum][maxnum];//图的边矩阵
    int vertenum;//顶点个数
    int arcnum;//边的个数
}graph;

//辅助数组，声明为全局变量，便于调用
struct {
    int adjvex;//记录最小边的顶点编号
    int lowcost;//记录该最小边的长度
}closedge[maxnum];

//创建图
void createGraph(graph *g) {//图还未创建，注意传址
    scanf("%d",&g->vertenum);//输入顶点个数
    int i,j;
    //初始化邻接矩阵
    for(i = 0;i < g->vertenum;i++) {
        for(j = 0;j < g->vertenum;j++) {
            scanf("%d",&g->arc[i][j]);//为各点添加边
            if(g->arc[i][j] == 0) {
                g->arc[i][j] = infinity;//未给边赋值时，认为两点间是没有边的
            }
        }
    }
}

//利用Prim法创建最小树
void minispantree_prim(graph *gn,int u) {//调用函数时，注意是传入指针
                                         //从顶点u出发
    int i,e,sum = 0,v,min,j,k;
    closedge[u].lowcost = 0;//首先把顶点u纳入树中

    //初始化closedge数组，得出每条边与的顶点u的边长
    for(i = 0;i < gn->vertenum;i++) {
        if(i != u) {//
            closedge[i].adjvex = u;//与u相邻时
            closedge[i].lowcost = gn->arc[u][i];//此时的边长
        }
    }

    //从第一个点开始，创建最小树
    for(e = 1;e <= gn->vertenum - 1;e++) {//直到最后一个点
        min = infinity;//初始化最小值min
        for(j = 0;j < gn->vertenum;j++) {//在剩余的顶点中找到代价最小的点k
                                         //此处是对树的所有顶点进行遍历
                                         //不过之后通过条件筛选
            if(closedge[j].lowcost != 0 && closedge[j].lowcost < min) {
                                                        //代价为0说明该点已经在树内了
                min = closedge[j].lowcost;//更新最小值
                v = j;//更新最小点
            }
        }
        u = closedge[j].adjvex;//u表示最小权值的边
        sum += gn->arc[u][v];//代价中加上这边的权值
        closedge[v].lowcost = 0;//将此点纳入树中

        for(i = 0;i < gn->vertenum;i++) {//接下来更新closedge数组
            if(gn->arc[v][i] < closedge[i].lowcost) {//若该点到第i个点的距离比原来的小
                closedge[i].lowcost = gn->arc[v][i];//则更新这条边
                closedge[i].adjvex = v;
            }
        }
    }
    printf("%d",sum);//输出总代价
}

int main() {
    graph *g;//创建图指针，便于高效利用空间
    g = (graph*)malloc(sizeof(graph));
    createGraph(g);
    minispantree_prim(g,0);
    printf("\n");
    return 0;
}
