#define _CRT_SECURE_NO_WARNINGS
#include"Heep.h"
void HeapInit(Hp* hp)
{
	assert(hp);
	hp->arr = NULL;
	hp->capacity = hp->size = 0;
}
void HeapDestroy(Hp* hp)
{
	assert(hp);
	free(hp->arr);
	hp->arr = NULL;
	hp->size = hp->capacity = 0;
}
void Swap(HeapdataType* n1, HeapdataType* n2)
{
	HeapdataType tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}
//插入数据后如果堆的结构被破坏，那么就需要进行向上调整
//观察原堆的结构，如果插入之前是小堆,那么就将小的向上调整
//如果插入之前是大堆，那么将向上调整的代码中的>改为<。
//我们这里都是小堆
void AdjustUp(HeapdataType* arr,int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (arr[parent] > arr[child])
		{
			Swap(&arr[parent], &arr[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapPush(Hp* hp, HeapdataType x)
{
	assert(hp);
	if (hp->size == hp->capacity)//如果空间满了，对数组进行扩容
	{
		int newcapacity = hp->capacity == 0 ? 4 : 2 * hp->capacity;
		HeapdataType* newarr = (HeapdataType*)realloc
		(hp->arr, sizeof(HeapdataType) * newcapacity);
		if (newarr == NULL)
		{
			perror("realloc failed");
			return;
		}
		hp->arr = newarr;
		hp->capacity = newcapacity;
	}
	hp->arr[hp->size++] = x;
	AdjustUp(hp->arr, hp->size - 1);
}
void AdjustDown(HeapdataType* arr, int size, int parent)
{
	//因为我们要找出左右孩子中较小的那一个进行交换
	//我们先假设左孩子是较小的那一个
	int child = 2 * parent + 1;
	while (child < size)
	{
		if (child + 1 < size && arr[child + 1] < arr[child])
		{
			child++;
		}
		if (arr[child] < arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapPop(Hp* hp)
{
	assert(hp);
	assert(hp->size>0);//确保其中至少有一个元素
	//为了保证不同时改变左右子树的结构，我们将第一个元素与最后一个元素交换
	Swap(&hp->arr[0], &hp->arr[hp->size - 1]);
	hp->size--;
	//交换之后，我们需要将第一个元素进行向下调整，保证堆结构的完整性
	AdjustDown(hp->arr, hp->size, 0);
}
HeapdataType HeapTop(Hp* hp)
{
	assert(hp);
	assert(hp->size > 0);
	return hp->arr[0];
}
int HeapSize(Hp* hp)
{
	assert(hp);
	return hp->size;
}
bool HeapEmpty(Hp* hp)
{
	assert(hp);
	return hp->size == 0;
}


