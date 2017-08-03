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

//尾部插入节点（有空节点）
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

//头部插入节点
void insert_head(struct node *ph, struct node *neww)
{	
	neww->pNext = ph->pNext;
	ph->pNext = neww;
	ph->data ++;
	
}

//遍历单链表
void traverse(struct node *ph)
{
	struct node *p = ph;	
	printf("开始遍历\n");
	while (NULL != p->pNext)
	{	
		p = p->pNext;  
		printf("node data: %d.\n", p->data);
		
	}
	printf("完了\n");
}

//从链表ph删除节点 待删除节点特征为数据区等于data
//返回值：当找到并且成功删除节点返回0 否则返回-1
int delete_node(struct node *ph, int data)
{
	struct node *p = ph;
	struct node *pPrev = NULL;
	while (NULL != p->pNext)
	{
		pPrev = p;
		p = p->pNext;
		if (p->data == data)
		{
			if (p->pNext == NULL)
			{
				pPrev->pNext = NULL;
				free(p);
			}
			else
			{
				pPrev->pNext = p->pNext;
				free(p);
			}

			return 0;
		}

	}
	printf("没找到这个节点.\n");
	return -1;
}

int main(void)
{
	struct node *pHeader = creat_node(0);
	insert_head(pHeader, creat_node(13));
	insert_head(pHeader, creat_node(12));
	insert_head(pHeader, creat_node(11));	


	printf("Header node data: %d.\n", pHeader->data);

	traverse(pHeader);
	delete_node(pHeader, 11);
	printf("----------删除后--------\n");
	traverse(pHeader);


	/**************************************
	printf("node1 data: %d.\n", pHeader->pNext->data);
	printf("node2 data: %d.\n", pHeader->pNext->pNext->data);
	printf("node3 data: %d.\n", pHeader->pNext->pNext->pNext->data);
	****************************/

	return 0;

}