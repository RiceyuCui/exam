#include <stdio.h>
#include <stdlib.h>
//˫����ڵ�
struct node 
{
	int data;
	struct node *pPrev;
	struct node *pNext;
};

//��������
struct node * create_node(int data)
{
	struct node *p = (struct node *)malloc(sizeof(struct node));
	if (NULL == p)
	{
		printf("malloc error.\n");
		return NULL;
	}
	p->data = data;
	p->pNext = NULL;
	p->pPrev = NULL;
	return p;
}

//�½ڵ�new��������phβ��
void insert_tail(struct node *ph, struct node *neww)
{
	//��һ�����ߵ�����β�ڵ�
	struct node *p = ph;
	while (NULL != p->pNext)
	{
		p = p->pNext;
	}
	//ѭ��������p��ָ��ԭ�����һ���ڵ�

	//�ڶ��������½ڵ����ԭ��β�ڵ��ĩβ
	p->pNext = neww;
	neww->pPrev = p;
}
int main(void)
{
	struct node *pHeader = create_node(0);       //ͷָ��

	insert_tail(pHeader, create_node(11));
	insert_tail(pHeader, create_node(12));
	insert_tail(pHeader, create_node(13));

	//����
	printf("node 1 data: %d.\n", pHeader->pNext->data);
	printf("node 1 data: %d.\n", pHeader->pNext->pNext->data);
	printf("node 1 data: %d.\n", pHeader->pNext->pNext->pNext->data);

}