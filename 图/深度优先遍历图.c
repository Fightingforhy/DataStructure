#include<stdio.h>
#include<stdlib.h>
#define MVN 50
#define True 1
#define False 0
#define Error -1

//������ȱ���
//��С���� ����·���ߣ���������
//��һ��·�ߵ��ס�
//���õݹ��·���ж�����
//�����е�·�����г��ԣ��Ƚ�����������

typedef char VertexData;

//�����еĵ�
typedef struct ArcNode {
    int adj;
}ArcNode;

//����ͼ
typedef struct {
    VertexData vertex[MVN];//��������
    ArcNode arcs[MVN][MVN];//�ڽӾ���
    int vexnum,arcnum;     //ͼ�Ķ������ͻ���
}AdjMaxtrix;

//���߹��ڵ���
int visited[MVN];

//����ͼ
void CreateDN(AdjMaxtrix *G) {//ע�⴫ַ������ͼ
    int i,j,k,weight;
    VertexData v1,v2;
    scanf("%d",&G->vexnum);//���붥����

    //������������Ȩֵ
    for(i = 0;i < G->vertex;i++) {
        for(j = 0;j < G->vertex;j++) {
            scanf("%d",&weight);
            G->arcs[i][j].adj = weight;//������ߵ�Ȩֵ
        }
    }
}

//�߹��ڵ�
void visit(int i) {
    printf("\n");
}

void DFS(AdjMaxtrix g,int v0) {//��v0�㿪ʼ����
    int vj;
    visit(v0);
    visited[v0] = True;
    for(vj = 0;vj < g.vexnum;vj++) {//��0�ſ�ʼ
        if(!visited[vj] && g.arcs[v0][vj].adj == 1) {//���û�߹�vj��������·��������
                                                     //�Ǿ��߹�vj�����ҽ�������vjΪ�����
            DFS(g,vj);//�ݹ�Ѱ·
        }
    }

}

int main() {
    int i;
    AdjMaxtrix G;
    CreateDN(&G);//��ʼ������
    DFS(G,0);//�ӵ�0����ʼ����

    return 0;
}
