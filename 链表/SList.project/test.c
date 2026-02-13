#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"
void test()
{
	/*SLnode* head = (SLnode*)malloc(sizeof(SLnode));
	head->data = 1;
	SLnode* node1 = (SLnode*)malloc(sizeof(SLnode));
	node1->data = 2;
	SLnode* node2 = (SLnode*)malloc(sizeof(SLnode));
	node2->data = 3;
	SLnode* node3 = (SLnode*)malloc(sizeof(SLnode));
	node3->data = 4;
	head->nextnode=node1;
	node1->nextnode=node2;
	node2->nextnode=node3;
	node3->nextnode=NULL;
	SListpushback(&head, 5);
	PrintSList(head);*/
	//上面是创建了一个单链表，并对其进行打印，判断单链表的创建是否正确
	SLnode* head = NULL;
	SListpushback(&head, 1);
	SListpushback(&head, 2);
	SListpushback(&head, 3);
	SListpushfront(&head, 4);
	//PrintSList(head);
	//SListpopfront(&head);
	//PrintSList(head);
	/*SListpopfront(&head);
	PrintSList(head);
	SListpopfront(&head);
	PrintSList(head);
	SListpopfront(&head);*/
	PrintSList(head);
	//4->1->2->3->NULL
	SLnode* node = SListfind(head, 2);
	//SListinsertAfter(node, 4);
	SListdeleteAfter(node);
	PrintSList(head);
	SListdestroy(&head);
}
int main()
{
	test();
	return 0;
}
