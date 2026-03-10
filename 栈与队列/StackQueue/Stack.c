#define _CRT_SECURE_NO_WARNINGS
#include"Stack.h"
void StackInit(stack* pst)
{
	assert(pst!= NULL);
	pst->arr = NULL;
	//这里的top指向的是栈顶元素的下一个位置
	pst->top = pst->capacity = 0;
}
void StackDestroy(stack* pst)
{
	assert(pst!= NULL);
	if (pst->arr)
		free(pst->arr);
	pst->arr = NULL;
	pst->top = pst->capacity = 0;
}
void StackPush(stack* pst, Stackdatatype data)
{
	assert(pst!= NULL);
	//首先判断栈空间是否已经满了
	if (pst->top == pst->capacity)
	{
		int newcapacity = (pst->capacity == 0)? 4 : 2 * pst->capacity;
		//这里在原来的基础上进行扩容
		Stackdatatype* newarr = (Stackdatatype*)realloc
		(pst->arr,newcapacity * sizeof(Stackdatatype));
		if (newarr == NULL)
		{
			perror("malloc failed");
			exit(1);
		}
		//对相关数据进行更新
		pst->arr = newarr;
		pst->capacity = newcapacity;
	} 
	//栈空间未满，直接存入数据
		
	pst->arr[pst->top++] = data;
}
void Stackpop(stack* pst)
{
	assert(pst!= NULL);
	assert(pst->top != 0);
	pst->top--;
}
Stackdatatype StackTop(stack* pst)
{
	assert(pst!= NULL&&pst->top!= 0);
	return pst->arr[pst->top - 1];
}
bool Stackempty(stack* pst)
{
	assert(pst!= NULL);
	return pst->top == 0;
}
int Stacksize(stack* pst)
{
	assert(pst!= NULL);
	return pst->top;
}

