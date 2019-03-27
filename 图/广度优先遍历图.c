#include<stdio.h>
#include<stdlib.h>
#define MVN 50
#define True 1
#define False 0
#define Error -1
#define OK 1
#define Max 50

//广度优先遍历
//从广度方面探索，尽可能延伸
//“探索所有可能性”
//本题采用了队列，来保存访问节点情况
//先探索一个节点的所有可能性，把它的所有邻接点入队
//探索完一个节点后，则元素出队探索同一广度上的另一个节点
//如此反复，最后完成遍历

//循环顺序队列
typedef struct {
    int elem[Max];
    int front;
    int rear;
}SeqQueue;

//元素信息
typedef char VertexData;

//顶点情况
typedef struct ArcNode {
    int adj;
}ArcNode;

//图的定义
typedef struct {
    VertexData vertex[MVN];//顶点向量
    ArcNode arcs[MVN][MVN];//邻接矩阵
    int vexnum,arcnum;//顶点数和弧数
}AdjMaxtrix;

//节点走过标记
int visited[MVN];

//队列初始化
void InitQueue(SeqQueue *q) {//此时队列还未定义，需要传址
    q->front = q->rear = 0;//前后均无元素
}

//入队
int EnterQueue(SeqQueue *q,int x) {//对队列产生实质影响
    if((q->rear + 1)%Max == q->front) {//队列已满
        return False;
    }
    q->elem[q->rear] = x;//从尾部加入队列
    q->rear = (q->rear) % Max;//未指针后移，注意是循环队列
    return True;

}

//出队
void DeleteQueue(SeqQueue *q,int *x) {//同理传址，*x也传址来保存被删的数
    if(q->front == q->rear) {//队列已空
        return False;
    }
    *x = q->elem[q->front];//取出元素，保存在x中
    q->front = (q->front + 1) % Max;//头指针后移，队列减少
    return True;
}

//判定为空队列
int Empty(SeqQueue q) {
    if(q.front == q.rear){
        return True;
    }
    else return False;
}

//创建图
void CreateDN(AdjMaxtrix *G) {//注意传址，此时图还未创建
    int i,j,weight;
    scanf("%d",&G->vexnum);//输入顶点数
    for(i = 0;i < G->vexnum;i++) {
        for(j = 0;j < G->vexnum;j++) {
            scanf("%d",&weight);//输入边的权值
            G->arcs[i][j].adj = weight;
        }
    }
}

//访问节点
void visit(int i) {
    printf("%d",i);
}

//求第一个邻接点
int FirstAdjVertex(AdjMaxtrix g,int v) {
    int vj;
    for(vj = 0;vj < g.vexnum;vj++) {//从第一个结点开始找
        if(!visited[vj] && g.arcs[v][vj].adj == 1) {//如果vj还没被访问，而且点v可以到达
            break;//则跳出循环
        }
    }
    if(!visited[vj] && g.arcs[v][vj].adj == 1 && vj < g.vexnum)  return vj;//最终找到的合法的vj
                                                                  //就是首个邻接点
    else return Error;//没找到首个邻接点
}

//求下一个邻接点
//在上述首个邻接点没找到时，就要退回去找邻接点了
//这里找的是v相对于w的下一个邻接点
//不过两个代码相同
int NextAdjVertex(AdjMaxtrix g,int v,int w) {
    int vj;
    for(vj = 0;vj < g.vexnum;vj++) {//从头开始找
        if(!visited[vj] && g.arcs[v][vj].adj == 1){
            break;
        }
    }
    if(!visited[vj] && g.arcs[v][vj].adj == 1 && g.vexnum)  return vj;
    else return Error;
}

//广度优先遍历
void BFS(AdjMaxtrix g,int v0) {//从v0开始遍历
    int v,w;
    visit(v0);//先从v0开始
    visited[v0] = True;//置为被访问
    SeqQueue q;
    InitQueue(&q);//队列初始化
    EnterQueue(&q,v0);//v0入队
    while(!Empty(q)) {//只要队列里还有值
        DeleteQueue(&q,&v);//队头元素出队，以此为起点继续遍历
        w = FirstAdjVertex(g,v);//找到首个邻接点
        while(w != -1) {//当v还有没被访问过的邻接点时
            if(!visited[w]) {
                visit(w);//访问它
                visited[w] = True;
                EnterQueue(&q,w);//探索的广度延伸到当前的w点
            }
            w = NextAdjVertex(g,v,w);//找到q除了w以外的另一个邻接点
        }
    }
}

int main() {
    AdjMaxtrix G;
    CreateDN(&G);//初始化
    BFS(G,0);//从第0个开始遍历

    return 0;
}
