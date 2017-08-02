#include <stdio.h>
#include <stdlib.h>
#include <string>
struct node 
{
	int data;
	struct node *pNext;
};

//将创建节点部分封装成函数
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

//尾部插入节点（无空节点）
void insert_tail(struct node *ph, struct node *neww)
{
	struct node *p = ph;

	while (NULL != p->pNext)
	{
		p = p->pNext;
	}
	p->pNext = neww;

}

int main(void)
{
	struct node *pHeader = creat_node(1);
	insert_tail(pHeader, creat_node(22));
	insert_tail(pHeader, creat_node(32));

	printf("node1 data: %d.\n", pHeader->data);
	printf("node2 data: %d.\n", pHeader->pNext->data);
	printf("node3 data: %d.\n", pHeader->pNext->pNext->data);



}