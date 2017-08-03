#include <stdio.h>
#include <stdlib.h>
#include <string>
struct node 
{
	int data;
	struct node *pNext;
};

//�������ڵ㲿�ַ�װ�ɺ���
struct node * creat_node(int data)
{
	struct node *p = (struct node *)malloc(sizeof(struct node));
	if (NULL == p)
	{
		printf("malloc error.\n");
		return NULL;
	}
	memset(p, 0, sizeof(struct node));
	p->data = data;
	p->pNext = NULL;
	return p;
}

//β������ڵ㣨�пսڵ㣩
void insert_tail(struct node *ph, struct node *neww)
{
	struct node *p = ph;
	int cnt = 0;

	while (NULL != p->pNext)
	{
		p = p->pNext;
		cnt ++;
	}
	p->pNext = neww;

	ph->data = cnt + 1;

}

//ͷ������ڵ�
void insert_head(struct node *ph, struct node *neww)
{	
	neww->pNext = ph->pNext;
	ph->pNext = neww;
	ph->data ++;
	
}

//����������
void traverse(struct node *ph)
{
	struct node *p = ph;
	printf("��ʼ����\n");
	while (NULL != p->pNext)
	{
		p = p->pNext;
		printf("node data: %d.\n", p->data);
		
	}
	printf("����\n");
}

int main(void)
{
	struct node *pHeader = creat_node(0);
	insert_head(pHeader, creat_node(13));
	insert_head(pHeader, creat_node(12));
	insert_head(pHeader, creat_node(11));	


	printf("Header node data: %d.\n", pHeader->data);

	traverse(pHeader);

	/**************************************
	printf("node1 data: %d.\n", pHeader->pNext->data);
	printf("node2 data: %d.\n", pHeader->pNext->pNext->data);
	printf("node3 data: %d.\n", pHeader->pNext->pNext->pNext->data);
	****************************/



}