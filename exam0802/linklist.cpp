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

int main(void)
{
	struct node *pHeader = NULL;
	
	pHeader = creat_node(1);
	pHeader->pNext = creat_node(255);
	pHeader->pNext->pNext = creat_node(911);
	

	printf("node1 data: %d.\n", pHeader->data);
	printf("node2 data: %d.\n", pHeader->pNext->data);
	printf("node3 data: %d.\n", pHeader->pNext->pNext->data);



}