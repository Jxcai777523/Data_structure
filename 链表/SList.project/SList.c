#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"
void PrintSList(SLnode* head)//先写出打印链表的函数，用于测试代码
{
	SLnode* p = head;
	while (p)
	{
		printf("%d->", p->data);
		p = p->nextnode;
	}
	printf("NULL\n");
}
SLnode* Createnewnode(SLdatatype n)//一个创建新的节点的函数
{
	SLnode* newnode = (SLnode*)malloc(sizeof(SLnode));
	if (newnode == NULL)
	{
		perror("malloc error");
		exit(1);
	}
	newnode->data = n;
	newnode->nextnode = NULL;
	return newnode;
}
void SListpushback(SLnode** head, SLdatatype n)
{
	assert(head!= NULL);
	//有空链表还有非空链表两种情况
	SLnode* newnode= Createnewnode(n);
	SLnode* pr = *head;
	if (*head == NULL)//如果是空链表
	{
		*head = newnode;
		return;
	}
	else
	{
		while ((pr)->nextnode)
		{
			pr = (pr)->nextnode;
		}
		(pr)->nextnode = newnode;
	}
}
void SListpushfront(SLnode** head, SLdatatype n)
{
	assert(head);
	SLnode* newnode = Createnewnode(n);
	newnode->nextnode = *head;
	*head = newnode;
}
void SListpopback(SLnode** head)
{
	assert(head);
	if ((*head)->nextnode == NULL)//这里如果只有一个节点就直接释放该节点
	{
		free(*head);
	}
	else//否则就找到最后一个节点，然后释放它，然后把前面节点的next指针指向NULL
	{
		SLnode* pcur = (*head)->nextnode;
		SLnode* bfpcur = *head;
		while (pcur->nextnode)
		{
			bfpcur = bfpcur->nextnode;
			pcur = pcur->nextnode;
		}
		free(pcur);
		bfpcur->nextnode = NULL;
	}
}
void SListpopfront(SLnode** head)
{
	assert(*head);
	SLnode* ppr=*head;
	(*head) = (*head)->nextnode;
	free(ppr);
}
SLnode* SListfind(SLnode* head, SLdatatype n)
{
	SLnode* p = head;
	while (p)
	{
		if (p->data == n)
		{
			return p;
		}
		p = p->nextnode;
	}
	return NULL;
}
void SListinsert(SLnode** head, SLnode* pos, SLdatatype n)
{
	assert(head);
	SLnode* pnew = Createnewnode(n);
	SLnode* pcur=*head;
	if (pos == *head)
	{
		pnew->nextnode = *head;
		*head = pnew;
		//SListpushfront(head, n);
	}
	else
	{
		while (pcur->nextnode != pos)
		{
			pcur = pcur->nextnode;
		}
		pcur->nextnode = pnew;
		pnew->nextnode = pos;
	}
}
void SListinsertAfter(SLnode* pos, SLdatatype n)
{
	assert(pos);
	SLnode* pnew = Createnewnode(n);
	SLnode* pcur = pos->nextnode;
	pos->nextnode = pnew;
	if (pcur)
		pnew->nextnode = pcur;
	else
		pnew->nextnode = NULL;
}
void SListdelete(SLnode** head, SLnode* pos)
{
	assert(head);
	SLnode* pcur=*head;
	if (*head== pos)
	{
		*head = (*head)->nextnode;
		free(pos);
	}
	else
	{
		while (pcur->nextnode != pos)
		{
			pcur = pcur->nextnode;
		}
		pcur->nextnode = pos->nextnode;
		free(pos);
	}
}
void SListdeleteAfter(SLnode* pos)
{
	assert(pos && pos->nextnode);
	if ((pos->nextnode)->nextnode == NULL)
	{
		free(pos->nextnode);
		pos->nextnode = NULL;
		return;
	}
	SLnode* pcur = (pos->nextnode)->nextnode;
	free(pos->nextnode);
	pos->nextnode = pcur;
}
void SListdestroy(SLnode** head)
{
	assert(head);
	SLnode* pcur = *head;
	while (pcur)
	{
		SLnode* ptmp = pcur;
		pcur = pcur->nextnode;
		free(ptmp);
	}
	*head = NULL;
}