#define _CRT_SECURE_NO_WARNINGS
#include"Queue.h"
void QueInit(Que* pq)
{
	assert(pq != NULL);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}
bool QueEmpty(Que* pq)
{
	return pq->size == 0;
}
void QueDestroy(Que* pq)
{
	assert(pq != NULL);
	Qnode* pcur =pq->phead;
	while (pcur)
	{
		Qnode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	pq->size = 0;
	pq->phead = pq->ptail = NULL;
}
void Quepush(Que* pq, QListdataType data)
{
	assert(pq!=NULL);
	Qnode* newnode = (Qnode*)malloc(sizeof(Qnode));
	if (newnode == NULL)
	{
		perror("malloc failed");
		return;
	}
	newnode->data = data;
	newnode->next = NULL;
	if (pq->size==0)//如果一个节点都没有，就需要对头节点也进行更新
		pq->phead = pq->ptail = newnode;
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	pq->size++;
}
void Quepop(Que* pq)
{
	//这里要保证队列中至少要有一个节点
	assert(pq != NULL&&pq->phead!=NULL);
	if (pq->size == 1)//如果只有一个节点
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
		pq->size = 0;
		return;
	}
	Qnode* next = pq->phead->next;
	free(pq->phead);
	pq->phead = next;
	pq->size--;
}
int QueSize(Que* pq)
{
	return pq->size;
}
QListdataType Quefront(Que* pq)
{
	assert(pq != NULL && pq->size != 0);
	return pq->phead->data;
}
QListdataType Queback(Que* pq)
{
	assert(pq != NULL && pq->size != 0);
	return pq->ptail->data;
}