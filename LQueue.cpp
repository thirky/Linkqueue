#include"LQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

void InitLQueue(LQueue* Q)
{
	Q->front = (Node*)malloc(sizeof(Node));
	Q->front->next = NULL;
	Q->length = 0;
}

void DestoryLQueue(LQueue* Q)
{
	Node* p1 = Q->front;
	Node* p2 = NULL;
	while (p1->next != NULL)
	{
		p2 = p1->next;
		free(p1);
		p1 = p2;
	}
	free(p1);
}

Status IsEmptyLQueue(const LQueue* Q)
{
	if (Q->length == 0)
	{
		return TRUE;
	}
	return FALSE;
}

Status GetHeadLQueue(LQueue* Q, void* e)
{
	if (IsEmptyLQueue(Q))
	{
		return FALSE;
	}
	e = Q->front->next->data;
	return TRUE;
}

int LengthLQueue(LQueue* Q)
{
	return Q->length;
}

Status EnLQueue(LQueue* Q, void* data)
{
	Node* p1 = Q->front;
	while (p1->next != NULL)
	{
		p1 = p1->next;
	}
	Node* p2 = (Node*)malloc(sizeof(Node));
	p2->data = data;
	p2->next = NULL;
	p1->next = p2;
	Q->length++;
	return TRUE;
}

Status DeLQueue(LQueue* Q)
{
	if (IsEmptyLQueue(Q))
	{
		return FALSE;
	}
	Node* p;
	p = Q->front->next;
	Q->front->next = p->next;
	free(p);
	Q->length--;
	return TRUE;
}

void ClearLQueue(LQueue* Q)
{
	if (IsEmptyLQueue(Q))
	{
		printf("当前队列已空，无法清空\n");
	}
	else
	{
		Q->length = 0;
		Node* p1;
		Node* p2;
		p1 = Q->front->next;
		while (p1->next != NULL)
		{
			p2 = p1->next;
			free(p1);
			p1 = p2;
		}
		free(p1);
		Q->front->next = NULL;
	}
}

Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q))
{
	if (IsEmptyLQueue(Q) == TRUE)
	{
		printf("当前无数据！\n");
		return FALSE;
	}
	Node* p;
	for (p = Q->front->next; p->next != NULL; p = p->next)
	{
		foo(p->data);
	}
	foo(p->data);
	return TRUE;
}
void LPrint(void* q)
{
	printf("%d\n", *(int*)q);
}