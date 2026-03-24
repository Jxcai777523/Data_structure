#define _CRT_SECURE_NO_WARNINGS
#include"Sort.h"

void BubbleSort(int* arr, int n)
{
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n - i;j++)
		{
			if (arr[j - 1] > arr[j])
			{
				int tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
void InsertSort(int* arr, int n)//时间复杂度O(n^2)
{
	for (int i = 0;i < n - 1;i++)//这里i最多为n-2,因为要保证后面的tmp不越界
	{
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0)//从0到end都看成有序的
		{
			if (arr[end] > tmp)
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		arr[end+1] = tmp;//这里需要注意
	}
}
void Swap(int* n1, int* n2)
{
	int tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}
void BuildHeap(int* arr,int  n)
{

	for (int i = (n - 1 - 1) / 2;i >= 0;i--)
	{
		AdjustDown(arr, n, i);
	}
}
void AdjustDown(int* arr, int size, int parent)
{
	//因为我们要找出左右孩子中较小的那一个进行交换
	//我们先假设左孩子是较小的那一个
	int child = 2 * parent + 1;
	while (child < size)
	{
		if (child + 1 < size && arr[child + 1] > arr[child])
		{
			child++;
		}
		if (arr[child] > arr[parent])
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
void HeapSort(int* arr,int n)//堆排序
{
	BuildHeap(arr, n);
	int end = n - 1;
	while (end > 0)
	{
		Swap(arr, &arr[end]);
		AdjustDown(arr, end, 0);
		end--;
	}
}
void ShellSort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0;i < n - gap;i++)
		{
			int end = i;
			int tmp = arr[end + gap];
			for (end;end >= 0;end -= gap)
			{
				if (arr[end] > tmp)
				{
					arr[end + gap] = arr[end];
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
	}
	/*int gap = 5;
	for (int i = 0;i < n - gap;i+=gap)
	{
		int end = i;
		int tmp = arr[end + gap];
		while (end >= 0)
		{
			if (arr[end] > tmp)
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			else
			{
				break;
			}
		}
		arr[end + gap] = tmp;
	}*/
}
void SelectSort(int* arr, int n)
{
	/*int begin = 0, end = n - 1;
	int pmin = begin;
	while (begin < end)
	{
		for (int i = begin;i <n;i++)
		{
			if (arr[i] < arr[pmin])
			{
				pmin = i;
			}
		}
		Swap(&arr[begin], &arr[pmin]);
		begin++;
	}*/
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int pmin = begin, pmax = end;
		for (int i = begin;i <= end;i++)
		{
			if (arr[pmin] > arr[i])
			{
				pmin = i;
			}
			if (arr[pmax] < arr[i])
			{
				pmax = i;
			}
		}
		Swap(&arr[begin], &arr[pmin]);
		if (pmax == begin)
			pmax = pmin;
		Swap(&arr[end], &arr[pmax]);
		begin++;
		end--;
	}
}