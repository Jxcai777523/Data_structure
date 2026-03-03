#define _CRT_SECURE_NO_WARNINGS
#include"List.h"
void Test01()//测试初始化、打印、创建节点函数功能
{
	Listnode* head = NULL;
	head = InitList();
	Listnode* node1 = BuyNode(1);
	Listnode* node2 = BuyNode(2);
	Listnode* node3 = BuyNode(3);
	Listnode* node4 = BuyNode(4);
	head->next=node1;
	node1->prev=head;
	node1->next=node2;
	node2->prev=node1;
	node2->next=node3;
	node3->prev=node2;
	node3->next=node4;
	node4->prev=node3;
	node4->next=head;
	PrintList(head);
}
void Test02()//测试插入节点、删除节点函数功能
{
	Listnode* head=InitList();
	Listpushback(head, 1);
	Listpushback(head, 2);
	Listpushback(head, 3);
	Listpushfront(head, 4);
	PrintList(head);
	Listpopback(head);
	PrintList(head);
	Listpopfront(head);
	PrintList(head);
	Listpopfront(head);
	PrintList(head);
	Listpopfront(head);
	PrintList(head);
	Listpopfront(head);
	PrintList(head);
}
void Test03()
{
	Listnode* head = InitList();
	Listpushback(head, 1);
	Listpushback(head, 2);
	Listpushback(head, 3);
	Listpushback(head, 4);
	Listinsert(Listfind(head, 4), 10);
	PrintList(head);
	Listdestroy(head);
	head = NULL;
}
int main()
{
	//Test01();
	//Test02();
	Test03();
	return 0;
}