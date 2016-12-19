//#include<stdio.h>
//#include<stdlib.h>
//#include<windows.h>
//#define MAX 10
//typedef struct Node
//{
//	int nV;
//	int nE;
//	int Graph[MAX][MAX];
//}MyGraph;
//
//MyGraph *CreateGraph()
//{
//	int i=0,j=0;
//	int nVi;
//	int nVj;
//	MyGraph *graph = (MyGraph*)malloc(sizeof(MyGraph));
//	memset(graph,0,sizeof(MyGraph));
//	printf("请输入定点个数和边的个数\n");
//	scanf_s("%d",&(graph->nV));
//	scanf_s("%d",&(graph->nE));
//	for(i=0;i<graph->nE;i++)
//	{
//		printf("输入边值\n");
//		scanf_s("%d%d",&nVi,&nVj);
//		if(nVi<=10&&nVi>=1||nVj<=10&&nVj>=1)
//		{
//			if(graph->Graph[nVi][nVj] == 0)
//			{
//				graph->Graph[nVi][nVj] = 1;
//				graph->Graph[nVj][nVi] = 1;
//			}
//		}
//		else
//		{
//			printf("值错误\n");
//			i--;
//		}
//	}
//	for(i=1;i<=graph->nV;i++)
//	{
//		for(j=1;j<=graph->nV;j++)
//		{
//			printf("%d ",graph->Graph[i][j]);
//		}
//		printf("\n");
//	}
//	return graph;
//}
//void DFS(int nV,int vis[],MyGraph *graph)
//{
//	int i;
//	printf("%d ",nV);
//	vis[nV]=1;
//	for(i=1;i<=graph->nV;i++)
//	{
//		if(vis[i]==0&&graph->Graph[nV][i]==1)
//		{
//			DFS(i,vis,graph);
//		}
//	}
//}
//int main()
//{
//	MyGraph *graph = NULL;
//	int vis[MAX] = {0};
//	graph = CreateGraph();
//	DFS(5,vis,graph);
//	printf("\n");
//	system("pause");
//	return ;
//}