#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include"LQueue.h"
int main()
{
	printf("1.入队		2.出队		3.遍历\n");
	printf("                        \n");
	printf("4.查询队头	5.队列长度	6.清空\n");
	printf("                        \n");
	printf("7.退出操作  8.          9.    \n");
	int i;
	printf("选择你的操作：");
	scanf_s("%d", &i);
	LQueue* Q = (LQueue*)malloc(sizeof(LQueue));
	InitLQueue(Q);
	void* e=NULL;
	while (i!=7)
	{
		if (i == 1)
		{
			int *j,a;
			printf("入队数据：");
			scanf_s("%d", &a);
			j = &a;
			e=j;
			EnLQueue(Q,e);
		}
		if (i == 2)
		{
			DeLQueue(Q);
		}
		if (i == 3)
		{
			TraverseLQueue(Q,LPrint);
		}		
		if (i == 4)
		{
			GetHeadLQueue(Q, e);
			if (GetHeadLQueue(Q, e))
			{
				LPrint(e);
			}
			else { printf("当前队列无数据！\n"); }
		}
		if (i == 5)
		{
			printf("%d\n",LengthLQueue(Q));
		}
		if (i == 6)
		{
			ClearLQueue(Q);
		}
		printf("选择你的操作：");
		scanf_s("%d", &i);
	}

	DeLQueue(Q);
	free(Q);
	return 0;
}