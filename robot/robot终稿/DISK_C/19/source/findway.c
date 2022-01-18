#include "title.h"
/***************************************************************
�����б�1.���еĻ�������
            void InitQueue(LinkQueue *Q)     //�ӵĳ�ʼ��
            void DestroyQueue(LinkQueue *Q)  //���ٶ�
            int IsEmpty(LinkQueue Q)         //�ж϶��Ƿ�Ϊ��
            void EnQueue(LinkQueue *Q, QElemtype e)     //���
            void DeQueue(LinkQueue *Q, QElemtype *e)    //����
           2.ͼ�Ļ�������
            int CreateGraph(Graph G)         //ͼ�ĳ�ʼ�����ݸ�����ͼ��������ķ�ʽ����ͼ
            int FindAdjVex(Graph const G, const int n, int k, QElemtype *adjvex)    //Ѱ��ĳ����ͼ�е��ڽӵ�
            int LocateVex(Graph const G, const int n, Axis V)                       //����ĳ�������ֵ��ȷ���õ���ͼ�е�����
            int FindWay(Graph const G, PathType *path, const int n, Axis V0, Axis Vt)   //Dijkstra�㷨�ҵ���V0��Vt�����·��
           3.ջ�Ļ�������
            void InitStack(LkStack *S)      //ջ�ĳ�ʼ��
            void DestroyStack(LkStack *S)   //����ջ
            void Push(LkStack *S, SElemtype e)  //��ջ����
            void Pop(LkStack *S, SElemtype *e)  //��ջ����
***************************************************************/

//�����ָ����ɶӵĳ�ʼ������������������һ���ӽڵ㣬���ö�ͷ����βָ��ýڵ�
void InitQueue(LinkQueue *Q)
{
    Q->rear = (QueuePtr)malloc(sizeof(Qnode));     //ָ��ͷ�ڵ㣬��������Ϣ
    Q->front = Q->rear;

    if(!Q->front)    //����ʧ��
    {
        overflow_box(500, 500);
    }

    Q->front->next = NULL;
}

//�����ָ�����ٶӣ�������Ԫ��������Ӻ��ͷŽڵ�ռ䣬ֱ���ӿ�
void DestroyQueue(LinkQueue *Q)     //�Ӷ�ͷ��ʼ����β�ߣ�һ�����ͷ�
{
    while(Q->front)  //�ӻ�����
    {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
}

//���ݶ�ͷ����β�Ƿ�ָ��ͬһ�ڵ㣬�ж϶��Ƿ�Ϊ��
int IsEmpty(LinkQueue Q)
{
    if(Q.front == Q.rear)    //��ͷ����β�غϣ����Ƕӿ�
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//������e���棬����ӣ�����һ���ӽڵ㣬���Ԫ��e��Ϣ�󣬲��ڶ�β
void EnQueue(LinkQueue *Q, QElemtype e) //e�����β
{
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(Qnode));
    if(!p)
    {
        overflow_box(500, 500);
    }
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;    //���ӵ���β
    Q->rear = Q->rear->next;          //��β�����ƶ�
}

//��ͷԪ�س��ӣ�����ָ��e�����ͷԪ�ص���Ϣ��Ȼ���ͷŶ�ͷ�ڵ�
void DeQueue(LinkQueue *Q, QElemtype *e)
{
    QueuePtr p;
    if(Q->front == Q->rear)
    {
        return ;        //�ӿգ�ɾ��ʧ�ܣ��˳�����
    }
    p = Q->front->next;
    *e = p->data;        //����Ҫ���ӵ�����
	Q->front->next = p->next;    //���׺���
	if(Q->rear == p)     //ɾ��֮�󣬶ӿ�
    {
        Q->rear = Q->front;
    }
    free(p);    //ɾ���Ժ��Ӧ���ͷ�ԭ���
    p = NULL;
}

/*********�ӵĻ�������������������ͼ*************/
//���������G����main��������������������ͼ��ÿ����ͨ�е������Ž������С��ṹ����������һ��ָ�룬���Ρ�������˳��ָ�����ͨ�е��ڽӵ�
int CreateGraph(Graph G)
{
    int i, j, k = 0;
    LNode *p = NULL, *last = NULL;      //p��ÿ�μӵ���ʱ�ڵ㣬lastָ��ÿ��G[k]�ӵ���������һ���ڵ�
    const char unaccessible[16][19]={
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},  //��һ��
                                {1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1},
                                {1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1},
                                {1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                                {1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                                {1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                                {1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                                {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                                {1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
                                {1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
                                {1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1},
                                {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},  //��16��
                            };

    /*�����ڽ�����������ͼ����Ϣ*/
    for(i = 1; i < 15; i++) //�߽�϶���ͨ�����˷�ʱ��ȥ������
    {
        for(j = 1; j < 18; j++)//�߽�϶���ͨ�����˷�ʱ��ȥ������
        {
            if(!unaccessible[i][j])   //��������ͨ������ӵ�ͼ�С�����ͨ��������
            {
                //��G[k]��ʼ����k����
                G[k].x = i;
                G[k].y = j;
                G[k].next = NULL;
                last = G[k].next;	//��ʼ��ָ��G[k]��һλ����NULL�������Լ򻯺���Ĳ���
                //�����ж��ұߡ���ߡ����桢����ɲ�����ͨ��
                if(i < 14 && !unaccessible[i+1][j])    //�ұ��з����ҿ�������ͨ�У��Զ�ȥ���˱߽磨i+1С��15��ȷ���˲�����ʵ���磩
                {
                    p = (LNode *)malloc(sizeof(LNode));	//Ϊp����ռ�
					if(!p)
					{
						overflow_box(500,500);
						getch();
						exit(1);
					}
                    p->x = i+1;			//��ʼ��p��p��G[k]���ұߵĵ������
                    p->y = j;
                    p->direction = 1;   //��¼�����ʾp����G[k]�ұ�
                    p->next = NULL;
                    if(!last)		//������ǵ�һ���ڽӵ���G[k].nextֱ������ȥ������last
					{
						G[k].next = p;
					}
					else
					{
						last->next = p;
					}
                    last = p;   //�����ǲ��ǵ�һ����㣬last����ָ��p����Ϊlastָ�����һ��
                }

                if(i > 1 && !unaccessible[i-1][j])    //����з����ҿ�������ͨ�У��Զ�ȥ���˱߽磨i-1>0��ȷ�������ҷ��ʣ�
                {
                    p = (LNode *)malloc(sizeof(LNode));
					if(!p)
					{
						overflow_box(500,500);
						getch();
						exit(1);
					}
                    p->x = i-1;     //��ʼ��p��p��G[k]����ߵĵ������
                    p->y = j;
                    p->direction = 2;   //��¼�����ʾp����G[k]���
                    p->next = NULL;
                    if(!last)		//������ǵ�һ���ڽӵ���G[k].nextֱ������ȥ������last
					{
						G[k].next = p;
					}
					else
					{
						last->next = p;
					}
                    last = p;   //�����ǲ��ǵ�һ����㣬last����ָ��p����Ϊlastָ�����һ��
                }

                if(j > 1 && !unaccessible[i][j-1])    //���棬�Զ�ȥ���˱߽磨j-1>0������Խ�磩
                {
                    p = (LNode *)malloc(sizeof(LNode));
					if(!p)
					{
						overflow_box(500,500);
						getch();
						exit(1);
					}
                    p->x = i;       //��ʼ��p��p��G[k]������ĵ������
                    p->y = j-1;
                    p->direction = 3;    //��¼�����ʾp����G[k]����
                    p->next = NULL;
                    if(!last)		//������ǵ�һ���ڽӵ���G[k].nextֱ������ȥ������last
					{
						G[k].next = p;
					}
					else
					{
						last->next = p;
					}
                    last = p;   //�����ǲ��ǵ�һ����㣬last����ָ��p����Ϊlastָ�����һ��
                }

                if(j < 17 && !unaccessible[i][j+1])    //���棬�Զ�ȥ���˱߽磨j+1<18������Խ�磩
                {
                    p = (LNode *)malloc(sizeof(LNode));
					if(!p)
					{
						overflow_box(500,500);
						getch();
						exit(1);
					}
                    p->x = i;       //��ʼ��p��p��G[k]������ĵ������
                    p->y = j+1;
                    p->direction = 4;   //��¼�����ʾp����G[k]����
                    p->next = NULL;
                    if(!last)		//������ǵ�һ���ڽӵ���G[k].nextֱ������ȥ������last
					{
						G[k].next = p;
					}
					else
					{
						last->next = p;
					}
                    last = p;   //�����ǲ��ǵ�һ����㣬last����ָ��p����Ϊlastָ�����һ��
                }

                k++;            //ͼ�и���+1
            }
        }
    }
    return k;   //����G��Ԫ�صĸ���
}

//��ڲ���������k��adjvex[4]���飬������������δ���G[k]�ҡ����ϡ����ĸ�����Ŀ�ͨ���ڽӵ���G�е�����
//�������ܣ���G[k]��G�е��ڽӵ㣬������adjvex[4]�У��ŵ���x��y����
int FindAdjVex(Graph const G, const int n, int k, QElemtype *adjvex)
{    //adjvex�е�һ�����������ҵ��ڽӵ㣬�ڶ��������Դ����ơ�n��ͼ�е�ĸ�����k���ڽӱ��е��±�
    int i, j;       //i������ʾadjvex���±꣬j��ʾLocateVex�ķ���ֵ
    LNode *p = NULL;
    Axis V;

    p = G[k].next;	//ָ��G�ĵ�һ���ڽӵ�
    if(!p)      //û���ڽӵ�
    {
        return 0;       //ͼ��������㣬����û�ڽӵ�
    }

    while(p)   //p�ǿգ�û��ĩβ
    {
        i = p->direction - 1;    //������棬direction�Ǵ�1��ʼ�ģ���i�����±꣬��0��ʼ
        V.x = p->x;				//V����p����ĵ㣬Ҳ��G[k]���ڽӵ�
        V.y = p->y;
        p = p->next;			//�����ƣ�����һ���ڽӵ�
        j = LocateVex(G, n, V); //��V��G�еı��
        adjvex[i] = j;
    }
    return 1;           //�ҵ����ڽӵ�
}

//Ѱ��V��G�еı��
int LocateVex(Graph const G, const int n, Axis V)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(G[i].x == V.x && G[i].y == V.y)
        {
            return i;						//G���ҵ�V��󣬰�V��G�е��±귵��
        }
    }

    return -1;  //û�ҵ�
}

//��ڲ�����·��path�����V0,�յ�Vt��ͼG��G��Ԫ�ظ���n
//�������ܣ�����Dijkstra�㷨�õ��������·��path
///�õ�path֮������ջ�ٳ�ջ���͵õ���������Ҫ�Ĵ�V0��Vt��·��
int FindWay(Graph const G, PathType *path, const int n, Axis V0, Axis Vt)
{
    int i, j, w, *dist, v0, vt;   //v0��vt��V0��Vt��G�е��±꣬w���м����±�
    LinkQueue Q;
    QElemtype k, adjvex[4]; //adjvex���������±꣬��Ҫ��ӳ��ӵģ�������ڶӵ�Ԫ������
    InitQueue(&Q);

    v0 = LocateVex(G, n, V0);
    vt = LocateVex(G, n, Vt);
    if(v0 == -1 || vt == -1)        //��ʼ�㡢��ֹ����󣬲�����ֱ���˳�������ɶҲ����
    {
        return 0;       //error
    }
    dist = (int *)malloc(n * sizeof(int));
    for(i = 0; i < n; i++)
    {
        dist[i] = -1;
        path[i].former = -1;
    }
    dist[v0] = 0;

    EnQueue(&Q, v0);
    while(!IsEmpty(Q))
    {   //ÿ��Ԫ�س���ǰ��adjvex���³�ʼ����Ԫ�س��Ӻ�������ڽӵ�ʱҪ��
        adjvex[0] = -1;
        adjvex[1] = -1;
        adjvex[2] = -1;
        adjvex[3] = -1;
        DeQueue(&Q, &k);    //k�Ƕ���Ԫ�أ�������ŵ�����ͼG�еı��
        if(FindAdjVex(G, n, k, adjvex)) //û�ڽӵ�Ļ�����0��ֱ������������еĻ��������򴢴����ڽӵ�ı������adjvex����
        {
            for(j = 0; j < 4; j++)      //�������ĸ��������
            {
                if((w = adjvex[j]) != -1)   //˵��������������·ͨ��k��w����ڽӵ�
                {
                    if(dist[w] == -1)       //˵������·������ͨ�ģ���û�����ʹ�
                    {
                        dist[w] = dist[k] + 1;  //V0��W����̾����� V0��K����̾���+1
                        path[w].former = k;          //w��·������k��һ��
                        path[w].direction = j + 1;  //��¼������k����ĵ�������һ�����ģ������������ģ��ȵ�
                        EnQueue(&Q, w);             //��dist�б�ǹ����������

                    }

                    if(w == vt)         //�ҵ��յ��ˣ����˷�ʱ���������
                    {
                        path[v0].former=-1;
                        DestroyQueue(&Q);   //ʹ����ϣ��ͷ��Խ�Լ�ڴ�
                        free(dist);
                        dist = NULL;
                        return 1;;
                    }
                }
            }
        }
    }
}

/****ջ****/
//ջ�����ý����ڽ�path���򣬲���Ҫ�������������ֻд�ĸ�����

//��ʼ��ջ
void InitStack(LkStack *S)
{
    S->bottom = (SNode *)malloc(sizeof(SNode));     //����ͷ���
    if(!S->bottom)
    {
        overflow_box(500, 500);
    }
    S->top = S->bottom;       //�ÿ�
}

//����ջ
void DestroyStack(LkStack *S)
{
    SNode *p;
    while(S->top != S->bottom)  //ջ��û��
    {
        p = S->top;
        S->top = p->next;
        free(p);
    }
    p = NULL;

}

//��ջ
void Push(LkStack *S, SElemtype e)
{
    SNode *p;
    p = (SNode *)malloc(sizeof(SNode));
    p->data = e;
    p->next = S->top;
    S->top = p;
}

//��ջ
void Pop(LkStack *S, SElemtype *e)
{
    SNode *p;
    p = S->top;
    S->top = p->next;
    *e = p->data;
    free(p);
    p = NULL;
}








