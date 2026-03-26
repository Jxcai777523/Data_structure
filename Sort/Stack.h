#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef int Stackdatatype;
typedef struct stack
{
	Stackdatatype* arr;
	int top;
	int capacity;
}stack;
//栈的初始化以及销毁
void StackInit(stack* pst);
void StackDestroy(stack* pst);
//入栈出栈
void StackPush(stack* pst,Stackdatatype data);
void Stackpop(stack* pst);
Stackdatatype StackTop(stack* pst);//取栈顶元素
//判空
bool Stackempty(stack* pst);
//获取个数
int Stacksize(stack* pst);