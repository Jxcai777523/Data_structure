#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int QListdataType;
typedef struct QListNode   //这里是队列的节点结构
{
	struct QListNode* next;
	QListdataType data;
}Qnode;
//这里是队列的结构,这里是为了方便后面的操作,所以使用了结构体
//包含了队列的头指针,尾指针,队列的大小
//否则我们需要多次遍历操作才能实现队列
typedef struct Queue
{
	Qnode* phead;
	Qnode* ptail;
	int size;
}Que;
//队列的初始化以及销毁函数
void QueInit(Que* pq);
void QueDestroy(Que* pq);
//队列的入队操作
void Quepush(Que* pq, QListdataType data);
//队列的出队操作
void Quepop(Que* pq);
//队列的判空操作
bool QueEmpty(Que* pq);
//队列的长度
int QueSize(Que* pq);
QListdataType S(Que* pq);//队头
QListdataType Queback(Que* pq);//队尾

