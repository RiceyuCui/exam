#include <stdio.h>
#include <stdlib.h>
#include <string>
struct node 
{
	int data;
	struct node *pNext;
};
int main(void)
{
	struct node *pHeader = NULL;

	//创建一个链表节点
	struct node *p = (struct node *)malloc(sizeof(struct node));
	if (NULL == p)
	{
		printf("malloc error.\n");
		return -1;
	}
	memset(p, 0, sizeof(struct node));
	p->data = 1;
	p->pNext = NULL;
	pHeader = p;

	struct node *p1 = (struct node *)malloc(sizeof(struct node));
	if (NULL == p1)
	{
		printf("malloc error.\n");
		return -1;
	}
	memset(p1, 0, sizeof(struct node));
	p1->data = 2;
	p1->pNext = NULL;
	p->pNext= p1;

	struct node *p2 = (struct node *)malloc(sizeof(struct node));
	if (NULL == p2)
	{
		printf("malloc error.\n");
		return -1;
	}
	memset(p2, 0, sizeof(struct node));
	p2->data = 3;
	p2->pNext = NULL;
	p1->pNext= p2;

	printf("node1 data: %d.\n", pHeader->data);
	printf("node2 data: %d.\n", pHeader->pNext->data);
	printf("node3 data: %d.\n", pHeader->pNext->pNext->data);



}