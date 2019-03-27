#include<stdio.h>
#include<stdlib.h>
#define m 50

//�Ͻ�˹�����㷨
//����������ͼ
//�ӵ�һ����㿪ʼ����������ڵ�����·��
//�ڵ㵽��������޷��ִ�ʱ������Ϊ����
//ÿ���¼���һ���ڵ㣬����һ�����·��
//�����нڵ����������Ȼ�����������·����

//���岻ͬ��ͼ����
typedef enum {dg,dn,udg,udn}graphkind;

typedef char vertexdata;//�ڵ�����

//ͼ�и���
typedef struct arcnode {
    int adj;
}arcnode;

//ͼ����
typedef struct {
    vertexdata vertex[m];//���������
    arcnode arcs[m][m];//�������ϵ�Ȩֵ
    int vexnum,arcnum;//�������ͻ�����
    graphkind kind;//ͼ������
}adjmatrix;

//�Ͻ�˹�����㷨,����s������㵽�õ����̾���
void Dijkstra(adjmatrix l,int *s) {
    int i,j,k;
    int dist[m][m];//��������,��Ȩֵ

    //��ʼ��
    for(i = 0;i < l.vexnum;i++) {
        for(j = 0;j < l.vexnum;j++) {
            dist[i][j] = l.arcs[i][j].adj;//��ʼ������·��Ȩֵ
        }
    }

    //��ԭ�е�·���ϼ���ڵ�k
    //����ѭ���������Եļ���
    for(k = 0;k < l.vexnum;k++) {
        for(i = 0;i < l.vexnum;i++) {
            for(j = 0;j < l.vexnum;j++) {
                //��i�㵽j���·��
                //���;��k��ʱ�����뷴������
                //��ʱ��Ҫ������̾�����
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    //Ѱ·��ɺ󣬽��в���
    for(i = 0;i < l.vexnum;i++) {
        if(dist[*s][i] == 999) {//��s�ڵ�û��·������i�ڵ㣨���������·����
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
    scanf("%d",&n);//һ��n������
    scanf("%d",&s);//������ҵĵ�
    l.vexnum = n;

    for(i = 0;i < n;i++) {
        for(j = 0;j < n;j++) {
            scanf("%d",&k);
            if(i != j &&k == 0) {//�ڵ㵽�������Ϊ0����������Ӱ�죬Ϊ���ּ�Ϊ����
                                 //����0ʱ����ζ�������غϣ�ͬ����Ϊ����
                l.arcs[i][j].adj = 999;
            }
            else l.arcs[i][j].adj = k;
        }
    }
    Dijkstra(l,&s);
}
