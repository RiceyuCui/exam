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

//�½ڵ�newwǰ��������ph��
void insert_head(struct node *ph, struct node *neww)
{
	
	neww->pNext = ph->pNext;                 //�½ڵ�nextָ��ָ��ԭ����һ����Ч�ڵ��ַ

	if (ph->pNext != NULL)
	{
		ph->pNext->pPrev = neww;             //ԭ����һ����Ч�ڵ�pPrevָ���½ڵ��ַ

	}
	                 
	ph->pNext = neww;                        //ͷ�ڵ�nextָ��ָ���½ڵ��ַ
	neww->pPrev = ph;                        //�½ڵ�pPrevָ��ͷ�ڵ� 

	
}

//�������һ��˫����
void ergodic_linkedlist(struct node *ph)
{
	struct node *p = ph;
	printf("������������������ʼ��������������������\n");
	while (NULL != p->pNext)
	{
		p = p->pNext;
		printf("data = %d.\n", p->data);
	}
	printf("����������������������������������������\n");	

}

//ǰ�����һ����������pTailָ��ĩβ
void forward_ergodic_linkedlist(struct node *pTail)
{
	struct node *p = pTail;
	printf("������������������ʼ��������������������\n");
	while (NULL != p->pPrev)
	{
		printf("data = %d.\n", p->data);
		p = p->pPrev;
	}
	printf("����������������������������������������\n");
}

//������ph��ɾ���ڵ㣬�ڵ���������data
int delete_node(struct node *ph, int data)
{
	struct node *p = ph;
	while (NULL != p->pNext)
	{
		p = p->pNext;

		//�жϵ�ǰ�ڵ��ǲ���Ҫɾ�����Ǹ�
		if (p->data == data)
		{
			//β�ڵ�
			if (NULL == p->pNext)
				p->pPrev->pNext = NULL;
			//��ͨ�ڵ�
			else
			{
				p->pPrev->pNext = p->pNext;
				p->pNext->pPrev = p->pPrev;
			}

			free(p);
			return 0;
		}
	}
	printf("δ�ҵ�\n");

	return -1;
}



int main(void)
{
	struct node *pHeader = create_node(0);       //ͷָ��
	

	//insert_tail(pHeader, create_node(11));
	//insert_tail(pHeader, create_node(12));
	//insert_tail(pHeader, create_node(13));

	insert_head(pHeader, create_node(11));
	insert_head(pHeader, create_node(12));
	insert_head(pHeader, create_node(13));


	//����
	//printf("node 1 data: %d.\n", pHeader->pNext->data);
	//printf("node 1 data: %d.\n", pHeader->pNext->pNext->data);
	//printf("node 1 data: %d.\n", pHeader->pNext->pNext->pNext->data);



	ergodic_linkedlist(pHeader);

	//struct node *p = pHeader->pNext->pNext->pNext;
	//forward_ergodic_linkedlist(p);

	delete_node(pHeader, 12);

	ergodic_linkedlist(pHeader);

	return 0;

}