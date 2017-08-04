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

//新节点neww前插入链表ph中
void insert_head(struct node *ph, struct node *neww)
{
	
	neww->pNext = ph->pNext;                 //新节点next指针指向原来第一个有效节点地址

	if (ph->pNext != NULL)
	{
		ph->pNext->pPrev = neww;             //原来第一个有效节点pPrev指向新节点地址

	}
	                 
	ph->pNext = neww;                        //头节点next指针指向新节点地址
	neww->pPrev = ph;                        //新节点pPrev指向头节点 

	
}

//后向遍历一个双链表
void ergodic_linkedlist(struct node *ph)
{
	struct node *p = ph;
	printf("————————开始遍历————————\n");
	while (NULL != p->pNext)
	{
		p = p->pNext;
		printf("data = %d.\n", p->data);
	}
	printf("————————遍历结束————————\n");	

}

//前向遍历一个链表，参数pTail指向末尾
void forward_ergodic_linkedlist(struct node *pTail)
{
	struct node *p = pTail;
	printf("————————开始遍历————————\n");
	while (NULL != p->pPrev)
	{
		printf("data = %d.\n", p->data);
		p = p->pPrev;
	}
	printf("————————遍历结束————————\n");
}



int main(void)
{
	struct node *pHeader = create_node(0);       //头指针
	

	//insert_tail(pHeader, create_node(11));
	//insert_tail(pHeader, create_node(12));
	//insert_tail(pHeader, create_node(13));

	insert_head(pHeader, create_node(11));
	insert_head(pHeader, create_node(12));
	insert_head(pHeader, create_node(13));


	//遍历
	//printf("node 1 data: %d.\n", pHeader->pNext->data);
	//printf("node 1 data: %d.\n", pHeader->pNext->pNext->data);
	//printf("node 1 data: %d.\n", pHeader->pNext->pNext->pNext->data);



	ergodic_linkedlist(pHeader);

	struct node *p = pHeader->pNext->pNext->pNext;
	forward_ergodic_linkedlist(p);



	return 0;

}