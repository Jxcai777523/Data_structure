#define _CRT_SECURE_NO_WARNINGS
#include"List.h"
Listnode* BuyNode(ListdataType x)//因为后面会有尾插、头插，所以写一个函数来创建节点
{
	Listnode* node = (Listnode*)malloc(sizeof(Listnode));
	if (node == NULL)
	{
		perror("malloc error");
		exit(1);
	}
	node->data = x;
	node->prev = node->next = node;
	return node;
}
void PrintList(Listnode* head)
{
	Listnode* pcur = head->next;
	while (pcur != head)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}
Listnode* InitList()
{
	Listnode* head = BuyNode(-1);
	return head;
}
void Listpushback(Listnode* head, ListdataType x)
{
	assert(head);
	Listnode* newnode = BuyNode(x);
	Listnode* pcur = head->prev;
	newnode->prev = pcur;
	newnode->next = head;
	pcur->next = newnode;
	head->prev = newnode;
}
void Listpushfront(Listnode* head, ListdataType x)
{
	assert(head);
	Listnode* newnode = BuyNode(x);
	Listnode* pcur = head->next;
	newnode->prev = head;
	newnode->next = pcur;
	pcur->prev = newnode;
	head->next = newnode;
}
void Listpopback(Listnode* head)
{
	assert(head && head->next != head);
	Listnode* del = head->prev;
	del->prev->next = head;
	head->prev = del->prev;
	free(del);
	del = NULL;
}
void Listpopfront(Listnode* head)
{
	assert(head && head->next != head);
	Listnode* del = head->next;
	del->next->prev = head;
	head->next = del->next;
}
Listnode* Listfind(Listnode* head, ListdataType x)
{
	Listnode* pcur = head->next;
	while (pcur != head)
	{
		if (pcur->data == x)
		{
			printf("找到了\n");
			return pcur;
		}
		pcur = pcur->next;
	}
	printf("链表中没有找到%d\n", x);
	return NULL;
}
void Listinsert(Listnode* pos, ListdataType x)
{
	assert(pos);
	Listnode* newnode = BuyNode(x);
	newnode->next = pos->next;
	pos->next->prev = newnode;
	newnode->prev = pos;
	pos->next = newnode;
}
void Listdelete(Listnode* pos)
{
	assert(pos);
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
	free(pos);
	pos = NULL;
}
void Listdestroy(Listnode* head)
{
	assert(head);
	Listnode* pcur = head->next;
	while (pcur != head)
	{
		Listnode* del = pcur;
		pcur = pcur->next;
		free(del);
		del = NULL;
	}
	free(pcur);
	pcur = head = NULL;
}