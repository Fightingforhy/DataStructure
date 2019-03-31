#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define maxnum 50
#define infinity 32768//��ʾ����ֵ����

//Prim������С������
//����һ�ڵ������һ�μ���һ���ڵ㼰���Ӧ����С��
//����ʵ�ְ������нڵ㣬�����ǵ���С��
//����С������

//ͼ�Ķ���
typedef struct {
    int vertex[maxnum];//ͼ�Ķ�������
    int arc[maxnum][maxnum];//ͼ�ı߾���
    int vertenum;//�������
    int arcnum;//�ߵĸ���
}graph;

//�������飬����Ϊȫ�ֱ��������ڵ���
struct {
    int adjvex;//��¼��С�ߵĶ�����
    int lowcost;//��¼����С�ߵĳ���
}closedge[maxnum];

//����ͼ
void createGraph(graph *g) {//ͼ��δ������ע�⴫ַ
    scanf("%d",&g->vertenum);//���붥�����
    int i,j;
    //��ʼ���ڽӾ���
    for(i = 0;i < g->vertenum;i++) {
        for(j = 0;j < g->vertenum;j++) {
            scanf("%d",&g->arc[i][j]);//Ϊ������ӱ�
            if(g->arc[i][j] == 0) {
                g->arc[i][j] = infinity;//δ���߸�ֵʱ����Ϊ�������û�бߵ�
            }
        }
    }
}

//����Prim��������С��
void minispantree_prim(graph *gn,int u) {//���ú���ʱ��ע���Ǵ���ָ��
                                         //�Ӷ���u����
    int i,e,sum = 0,v,min,j,k;
    closedge[u].lowcost = 0;//���ȰѶ���u��������

    //��ʼ��closedge���飬�ó�ÿ������Ķ���u�ı߳�
    for(i = 0;i < gn->vertenum;i++) {
        if(i != u) {//
            closedge[i].adjvex = u;//��u����ʱ
            closedge[i].lowcost = gn->arc[u][i];//��ʱ�ı߳�
        }
    }

    //�ӵ�һ���㿪ʼ��������С��
    for(e = 1;e <= gn->vertenum - 1;e++) {//ֱ�����һ����
        min = infinity;//��ʼ����Сֵmin
        for(j = 0;j < gn->vertenum;j++) {//��ʣ��Ķ������ҵ�������С�ĵ�k
                                         //�˴��Ƕ��������ж�����б���
                                         //����֮��ͨ������ɸѡ
            if(closedge[j].lowcost != 0 && closedge[j].lowcost < min) {
                                                        //����Ϊ0˵���õ��Ѿ���������
                min = closedge[j].lowcost;//������Сֵ
                v = j;//������С��
            }
        }
        u = closedge[j].adjvex;//u��ʾ��СȨֵ�ı�
        sum += gn->arc[u][v];//�����м�����ߵ�Ȩֵ
        closedge[v].lowcost = 0;//���˵���������

        for(i = 0;i < gn->vertenum;i++) {//����������closedge����
            if(gn->arc[v][i] < closedge[i].lowcost) {//���õ㵽��i����ľ����ԭ����С
                closedge[i].lowcost = gn->arc[v][i];//�����������
                closedge[i].adjvex = v;
            }
        }
    }
    printf("%d",sum);//����ܴ���
}

int main() {
    graph *g;//����ͼָ�룬���ڸ�Ч���ÿռ�
    g = (graph*)malloc(sizeof(graph));
    createGraph(g);
    minispantree_prim(g,0);
    printf("\n");
    return 0;
}
