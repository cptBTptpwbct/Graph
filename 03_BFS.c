#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define MAX 10
typedef struct node
{
	int nV;
	int nE;
	int Graph[MAX][MAX];
}MyGraph;

typedef struct  Node
{
	int val;
	struct Node *pNext;
}Mylist;

typedef struct Quene
{
	Mylist *top;
	Mylist *tail;
	int Count;
}MyQueue;

void q_Push(MyQueue *queue,int val)
{
	Mylist *node = NULL;
	if(queue==NULL )
	{
		printf("队列不存在！！！！！！！\n");
		return ;
	}
	 node = (Mylist*)malloc(sizeof(Mylist));
	node->pNext = NULL;
	node->val = val;
	if(queue->top==NULL) 
		queue->top = node;
	else 
		queue->tail->pNext = node;
	queue->tail = node;
	queue->Count++;
}

int q_Pop(MyQueue *queue)
{
	Mylist *pTemp = NULL;
	int nNum ;
	if(queue == NULL )
	{
		printf("栈不存在！！！！！！！\n");
		return -1;
	}
	 nNum = queue->top->val;
	pTemp = queue->top;
	queue->top = queue->top->pNext;
	free(pTemp);
	queue->Count--;
	pTemp = NULL;
	if(queue->Count==0)
		queue->tail = NULL;
	return nNum;
}

void q_Init(MyQueue **queue)
{
	if(queue == NULL) return ;
	*queue = (MyQueue *)malloc(sizeof(MyQueue));
	(*queue)->top = NULL;
	(*queue)->tail = NULL;
	(*queue)->Count = 0;
}
void q_Clear(MyQueue *queue)
{
	if(queue == NULL) return ;
	q_Pop(queue);
}

void q_Destory(MyQueue **queue)
{
	if(queue == NULL) return ;
	q_Clear(*queue);
	free(*queue);
	*queue = NULL;
}
Mylist *q_GetTop(MyQueue *queue)
{
	if(queue == NULL) 
	{
		printf("栈不存在！！！！！！！\n");
		return NULL;
	}
	return queue->top;
}
int q_GetCount(MyQueue *queue)
{
	if(queue == NULL) return -1;
	return queue->Count;
}
int q_IsEmpty(MyQueue *queue)
{
	if(queue == NULL) return -1;
	return queue->Count==0?1:0;
}
MyGraph *CreateGraph()
{
	int i=0,j=0;
	int nVi;
	int nVj;
	MyGraph *graph = (MyGraph*)malloc(sizeof(MyGraph));
	memset(graph,0,sizeof(MyGraph));
	printf("请输入定点个数和边的个数\n");
	scanf_s("%d",&(graph->nV));
	scanf_s("%d",&(graph->nE));
	for(i=0;i<graph->nE;i++)
	{
		printf("输入边值\n");
		scanf_s("%d%d",&nVi,&nVj);
		if(nVi<=10&&nVi>=1||nVj<=10&&nVj>=1)
		{
			if(graph->Graph[nVi][nVj] == 0)
			{
				graph->Graph[nVi][nVj] = 1;
				graph->Graph[nVj][nVi] = 1;
			}
		}
		else
		{
			printf("值错误\n");
			i--;
		}
	}
	for(i=1;i<=graph->nV;i++)
	{
		for(j=1;j<=graph->nV;j++)
		{
			printf("%d ",graph->Graph[i][j]);
		}
		printf("\n");
	}
	return graph;
}
void BFS(int nV,int vis[],MyGraph *graph)
{
	int i;
	int temp = 0;
	MyQueue *pQueue;
	if(nV>graph->nV) return ;
	q_Init(&pQueue);
	vis[nV]=1;
	q_Push(pQueue,nV);
	while(!q_IsEmpty(pQueue))
	{
		nV = q_Pop(pQueue);
		printf("%d ",nV);
		for(i=1;i<=graph->nV;i++)
		{
			if(vis[i]==0&&graph->Graph[nV][i]==1)
			{
				vis[i]=1;
				q_Push(pQueue,i);
			}
		}
	}
}
int main()
{
	MyGraph *graph = NULL;
	int vis[MAX] = {0};
	graph = CreateGraph();
	BFS(1,vis,graph);
	printf("\n");
	system("pause");
	return ;
}