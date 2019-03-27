#include<stdio.h>
#include<stdlib.h>
#define MVN 50
#define True 1
#define False 0
#define Error -1
#define OK 1
#define Max 50

//������ȱ���
//�ӹ�ȷ���̽��������������
//��̽�����п����ԡ�
//��������˶��У���������ʽڵ����
//��̽��һ���ڵ�����п����ԣ������������ڽӵ����
//̽����һ���ڵ����Ԫ�س���̽��ͬһ����ϵ���һ���ڵ�
//��˷����������ɱ���

//ѭ��˳�����
typedef struct {
    int elem[Max];
    int front;
    int rear;
}SeqQueue;

//Ԫ����Ϣ
typedef char VertexData;

//�������
typedef struct ArcNode {
    int adj;
}ArcNode;

//ͼ�Ķ���
typedef struct {
    VertexData vertex[MVN];//��������
    ArcNode arcs[MVN][MVN];//�ڽӾ���
    int vexnum,arcnum;//�������ͻ���
}AdjMaxtrix;

//�ڵ��߹����
int visited[MVN];

//���г�ʼ��
void InitQueue(SeqQueue *q) {//��ʱ���л�δ���壬��Ҫ��ַ
    q->front = q->rear = 0;//ǰ�����Ԫ��
}

//���
int EnterQueue(SeqQueue *q,int x) {//�Զ��в���ʵ��Ӱ��
    if((q->rear + 1)%Max == q->front) {//��������
        return False;
    }
    q->elem[q->rear] = x;//��β���������
    q->rear = (q->rear) % Max;//δָ����ƣ�ע����ѭ������
    return True;

}

//����
void DeleteQueue(SeqQueue *q,int *x) {//ͬ��ַ��*xҲ��ַ�����汻ɾ����
    if(q->front == q->rear) {//�����ѿ�
        return False;
    }
    *x = q->elem[q->front];//ȡ��Ԫ�أ�������x��
    q->front = (q->front + 1) % Max;//ͷָ����ƣ����м���
    return True;
}

//�ж�Ϊ�ն���
int Empty(SeqQueue q) {
    if(q.front == q.rear){
        return True;
    }
    else return False;
}

//����ͼ
void CreateDN(AdjMaxtrix *G) {//ע�⴫ַ����ʱͼ��δ����
    int i,j,weight;
    scanf("%d",&G->vexnum);//���붥����
    for(i = 0;i < G->vexnum;i++) {
        for(j = 0;j < G->vexnum;j++) {
            scanf("%d",&weight);//����ߵ�Ȩֵ
            G->arcs[i][j].adj = weight;
        }
    }
}

//���ʽڵ�
void visit(int i) {
    printf("%d",i);
}

//���һ���ڽӵ�
int FirstAdjVertex(AdjMaxtrix g,int v) {
    int vj;
    for(vj = 0;vj < g.vexnum;vj++) {//�ӵ�һ����㿪ʼ��
        if(!visited[vj] && g.arcs[v][vj].adj == 1) {//���vj��û�����ʣ����ҵ�v���Ե���
            break;//������ѭ��
        }
    }
    if(!visited[vj] && g.arcs[v][vj].adj == 1 && vj < g.vexnum)  return vj;//�����ҵ��ĺϷ���vj
                                                                  //�����׸��ڽӵ�
    else return Error;//û�ҵ��׸��ڽӵ�
}

//����һ���ڽӵ�
//�������׸��ڽӵ�û�ҵ�ʱ����Ҫ�˻�ȥ���ڽӵ���
//�����ҵ���v�����w����һ���ڽӵ�
//��������������ͬ
int NextAdjVertex(AdjMaxtrix g,int v,int w) {
    int vj;
    for(vj = 0;vj < g.vexnum;vj++) {//��ͷ��ʼ��
        if(!visited[vj] && g.arcs[v][vj].adj == 1){
            break;
        }
    }
    if(!visited[vj] && g.arcs[v][vj].adj == 1 && g.vexnum)  return vj;
    else return Error;
}

//������ȱ���
void BFS(AdjMaxtrix g,int v0) {//��v0��ʼ����
    int v,w;
    visit(v0);//�ȴ�v0��ʼ
    visited[v0] = True;//��Ϊ������
    SeqQueue q;
    InitQueue(&q);//���г�ʼ��
    EnterQueue(&q,v0);//v0���
    while(!Empty(q)) {//ֻҪ�����ﻹ��ֵ
        DeleteQueue(&q,&v);//��ͷԪ�س��ӣ��Դ�Ϊ����������
        w = FirstAdjVertex(g,v);//�ҵ��׸��ڽӵ�
        while(w != -1) {//��v����û�����ʹ����ڽӵ�ʱ
            if(!visited[w]) {
                visit(w);//������
                visited[w] = True;
                EnterQueue(&q,w);//̽���Ĺ�����쵽��ǰ��w��
            }
            w = NextAdjVertex(g,v,w);//�ҵ�q����w�������һ���ڽӵ�
        }
    }
}

int main() {
    AdjMaxtrix G;
    CreateDN(&G);//��ʼ��
    BFS(G,0);//�ӵ�0����ʼ����

    return 0;
}
