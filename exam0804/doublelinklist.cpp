#include <stdio.h>
#include <stdlib.h>
//双链表节点
struct node 
{
	int data;
	struct node *pPrev;
	struct node *pNext;
};

//创建链表
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

//新节点new插入链表ph尾部
void insert_tail(struct node *ph, struct node *neww)
{
	//第一步，走到链表尾节点
	struct node *p = ph;
	while (NULL != p->pNext)
	{
		p = p->pNext;
	}
	//循环结束后p就指向原来最后一个节点

	//第二部，将新节点插入原来尾节点的末尾
	p->pNext = neww;
	neww->pPrev = p;
}
int main(void)
{
	struct node *pHeader = create_node(0);       //头指针

	insert_tail(pHeader, create_node(11));
	insert_tail(pHeader, create_node(12));
	insert_tail(pHeader, create_node(13));

	//遍历
	printf("node 1 data: %d.\n", pHeader->pNext->data);
	printf("node 1 data: %d.\n", pHeader->pNext->pNext->data);
	printf("node 1 data: %d.\n", pHeader->pNext->pNext->pNext->data);

}