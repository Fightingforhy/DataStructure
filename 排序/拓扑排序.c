#include<stdio.h>
#include<stdlib.h>

//��������
//�����������޻�ͼ
//�ؼ�����Ѱ�����Ϊ0�ĵ�
//��������Ψһ

//˳��ջ����
typedef struct {
    int elem[100];
    int top;
}Stack;

//ͼ����
typedef struct {
    int v;//�ڵ�
    int arcs[50][50];//�ڽӾ���
}AdjM;

//��������
int visited[50];

//��ʼ��ջ
void InitStack(Stack *s) {//�˴�s��δ������ע�⴫ַ
    s->top = -1;
}

//�ж�ջ��
int Empty(Stack s) {
    if(s.top = -1)  return 1;
    else return 0;
}

//��ջ
void Push(Stack *s,int x) {//��Ϊ��˳��ջ��Ҫע�⴫ַ
    s->top++;//��Ϊ��ʼ��top=-1�����Զ�Ҫ����ָ���ٴ�ֵ
    s->elem[s->top] = x;
}

//��ջ
void Pop(Stack *s,int *x) {//ע�⴫ַ��xҲ�Ǵ�ַ�������ջ����
    *x = s->elem[s->top];//����ջ�෴���������������ָ��
    s->top--;
}

//�����ڽӾ���
void CreateM(AdjM *g) {//��ʱͼg��δ������ע�⴫ַ
    int i,j;
    scanf("%d",&g->v);//������
    for(i = 0;i < g->v;i++) {
        for(j = 0;j < g->v;j++) {
            scanf("%d",&g->arcs[i][j]);//�����ڽӾ���
        }
    }
}

//��������
void TopuSort(AdjM g) {
    Stack s;
    InitStack(&s);//��ʼ��ջ
    int du[50];//��¼ÿ�������Ⱥ�
    int i,j,x;

    for(i = 0;i < g.v;i++) {
        du[i] = 0;//��ʼ��
    }

    //���ø������
    for(i = 0;i < g.v;i++) {
        for(j = 0;j < g.v;j++) {
            if(g.arcs[i][j] == 1) {//�ڽӾ�����ֵ��˵��������ͨ
                du[j]++;//�õ���ȼ�1
            }
        }
    }

    for(i = 0;i < g.v;i++) {
        if(du[i] == 0) {//�����Ϊ0����ջ
            Push(&s,i);
        }
    }

    while(!Empty(s)) {//ջδ��ʱ
        Pop(&s,&x);//��ջ��������x��,�������˵�
        printf("%d ",x);
        for(i = 0;i < g.v;i++) {//��ͷ��ʼ����
            if(du[i] > 0 && g.arcs[x][i] == 1) {//����ڵ�x���Ե��ڵ�i
                                                //��ô�ڽڵ�x�Ѿ���������ʱ��
                                                //�ڵ�i�������Ȼ����1
                du[i]--;
                if(du[i] == 0)  Push(&s,i);     //��i�ڵ�����Ҳ��0ʱ
                                                //˵���ڵ�iҲ���Ա�������
                                                //���Խ�����ջ
            }
        }

    }
}

int main() {
    AdjM g;
    CreateM(&g);//��ʼ��
    TopuSort(g);//����

    return 0;
}
