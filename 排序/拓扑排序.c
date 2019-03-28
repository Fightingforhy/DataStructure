#include<stdio.h>
#include<stdlib.h>

//拓扑排序
//适用于有向无环图
//关键在于寻找入度为0的点
//排序结果不唯一

//顺序栈定义
typedef struct {
    int elem[100];
    int top;
}Stack;

//图定义
typedef struct {
    int v;//节点
    int arcs[50][50];//邻接矩阵
}AdjM;

//访问数组
int visited[50];

//初始化栈
void InitStack(Stack *s) {//此处s还未创建，注意传址
    s->top = -1;
}

//判断栈空
int Empty(Stack s) {
    if(s.top = -1)  return 1;
    else return 0;
}

//入栈
void Push(Stack *s,int x) {//因为是顺序栈，要注意传址
    s->top++;//因为初始化top=-1，所以都要先移指针再传值
    s->elem[s->top] = x;
}

//出栈
void Pop(Stack *s,int *x) {//注意传址，x也是传址来保存出栈数字
    *x = s->elem[s->top];//与入栈相反，先输出数字再移指针
    s->top--;
}

//创建邻接矩阵
void CreateM(AdjM *g) {//此时图g还未创建，注意传址
    int i,j;
    scanf("%d",&g->v);//顶点数
    for(i = 0;i < g->v;i++) {
        for(j = 0;j < g->v;j++) {
            scanf("%d",&g->arcs[i][j]);//建立邻接矩阵
        }
    }
}

//拓扑排序
void TopuSort(AdjM g) {
    Stack s;
    InitStack(&s);//初始化栈
    int du[50];//记录每个点的入度和
    int i,j,x;

    for(i = 0;i < g.v;i++) {
        du[i] = 0;//初始化
    }

    //设置各点入度
    for(i = 0;i < g.v;i++) {
        for(j = 0;j < g.v;j++) {
            if(g.arcs[i][j] == 1) {//邻接矩阵有值，说明两点连通
                du[j]++;//该点入度加1
            }
        }
    }

    for(i = 0;i < g.v;i++) {
        if(du[i] == 0) {//若入度为0，入栈
            Push(&s,i);
        }
    }

    while(!Empty(s)) {//栈未空时
        Pop(&s,&x);//出栈，保存在x中,即经过此点
        printf("%d ",x);
        for(i = 0;i < g.v;i++) {//从头开始遍历
            if(du[i] > 0 && g.arcs[x][i] == 1) {//如果节点x可以到节点i
                                                //那么在节点x已经被经过的时候
                                                //节点i的入度自然减少1
                du[i]--;
                if(du[i] == 0)  Push(&s,i);     //当i节点的入度也是0时
                                                //说明节点i也可以被访问了
                                                //所以将其入栈
            }
        }

    }
}

int main() {
    AdjM g;
    CreateM(&g);//初始化
    TopuSort(g);//排序

    return 0;
}
