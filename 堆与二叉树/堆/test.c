#define _CRT_SECURE_NO_WARNINGS
#include"Heep.h"
void Heaptest01()
{
	int a[] = { 4,2,8,1,5,6,9,7,3,2,23,55,232,66,222,33,7,1,66,3333,999 };
	Hp hp;
	HeapInit(&hp);
	for (size_t i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		HeapPush(&hp, a[i]);
	}
	int i=0;
	while (!HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
}
//建堆
/*
for (int i = 1;i < sizeof(arr) / sizeof(int);i++)
{
     AdjustUp(arr,i);
}
*/
void Heapsort(int* arr,size_t n)
{
	//创建一个堆
	for (int i = 1;i < n;i++)
	{
		AdjustUp(arr, i);
	}
	//升序，建大堆
	//降序，建小堆，就是把AdjustDown,中的符号换一下
	int end = n - 1;
	while (end > 0)
	{
		Swap(arr, &arr[end]);
		AdjustDown(arr,end,0);
		end--;
	}
}
int main()
{
	int arr[] = { 2,4,5,7,9,46,46,25,15,6,4654,6, };
	size_t n = sizeof(arr) / sizeof(int);
	Heapsort(arr,n);
	//Heaptest01();
}