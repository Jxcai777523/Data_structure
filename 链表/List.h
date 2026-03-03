#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int ListdataType;
typedef struct ListNode 
{
	ListdataType data;
	struct ListNode* next;
	struct ListNode* prev;
}Listnode;
Listnode* BuyNode(ListdataType x);
Listnode* InitList(); //链表初始化，其实就是让链表只含有一个头节点
void PrintList(Listnode* head);//打印链表
void Listpushback(Listnode* head, ListdataType x);//尾插数据
void Listpushfront(Listnode* head, ListdataType x);//头插数据，在第一个有效数据之前插入
void Listpopback(Listnode* head);//尾删
void Listpopfront(Listnode* head);//头删
Listnode* Listfind(Listnode* head, ListdataType x);//在链表中查找数据，返回第一个匹配的节点
void Listinsert(Listnode* pos, ListdataType x);//在指定位置之后插入数据
void Listdelete(Listnode* pos);//删除指定位置的数据
void Listdestroy(Listnode* head);//销毁链表