#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include"LQueue.h"
int main()
{
	printf("1.���		2.����		3.����\n");
	printf("                        \n");
	printf("4.��ѯ��ͷ	5.���г���	6.���\n");
	printf("                        \n");
	printf("7.�˳�����  8.          9.    \n");
	int i;
	printf("ѡ����Ĳ�����");
	scanf_s("%d", &i);
	LQueue* Q = (LQueue*)malloc(sizeof(LQueue));
	InitLQueue(Q);
	void* e=NULL;
	while (i!=7)
	{
		if (i == 1)
		{
			int *j,a;
			printf("������ݣ�");
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
			else { printf("��ǰ���������ݣ�\n"); }
		}
		if (i == 5)
		{
			printf("%d\n",LengthLQueue(Q));
		}
		if (i == 6)
		{
			ClearLQueue(Q);
		}
		printf("ѡ����Ĳ�����");
		scanf_s("%d", &i);
	}

	DeLQueue(Q);
	free(Q);
	return 0;
}