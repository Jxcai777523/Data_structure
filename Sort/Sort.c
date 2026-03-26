#define _CRT_SECURE_NO_WARNINGS
#include"Sort.h"

void BubbleSort(int* arr, int n)
{
	for (int i = 0;i < n;i++)
	{
		int flag = 0;
		for (int j = 1;j < n - i;j++)
		{
			if (arr[j - 1] > arr[j])
			{
				int tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			return;
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
//第一版，未进行优化
//hoare
//void QuickSort(int* arr, int left, int right)
//{
//	if (left >= right)
//		return;
//	int pkey = left;
//	int begin = left, end = right;
//	while (begin < end)
//	{
//		while (begin<end && arr[end]>=arr[pkey])
//		{
//			end--;
//		}
//		while (begin<end && arr[begin]<=arr[pkey])
//		{
//			begin++;
//		}
//		Swap(&arr[begin], &arr[end]);
//	}
//	Swap(&arr[begin], &arr[pkey]);
//	QuickSort(arr, left, begin - 1);
//	QuickSort(arr, begin+1,right);
//}

//我们的pkey指向left right mid,三个数中间值
//int Getmidnum(int* arr,int left, int right)//可能会有溢出风险
//{
//	int mid = (left + right) / 2;
//	int max = arr[left];
//	if (arr[mid] >arr[left])
//		max = arr[mid];
//	if (arr[right] >arr[left])
//		max = arr[right];
//	int min = arr[left];
//	if (arr[mid] < min)
//		min = arr[mid];
//	if (arr[right] < min)
//		min =arr[right];
//	int ret = arr[left]-max+arr[right]-min+arr[mid];
//	return ret;
//}
//第二版
int Getmidnum(int* arr,int left, int right)
{
	int mid = left + (right-left) / 2;
	if (arr[mid] > arr[left])
	{
		if (arr[mid] < arr[right])
			return mid;
		else if (arr[left] > arr[right])
			return left;
		else
			return right;
	}
	else
	{
			if (arr[mid] > arr[right])
				return mid;
			else if (arr[left] < arr[right])
				return left;
			else
				return right;
	}
}
void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
		return;
	int pkey = Getmidnum(arr,left,right);
	Swap(&arr[pkey], &arr[left]);
	pkey = left;
	int begin = left, end = right;
	if (end - begin + 1 < 10)
	{
		InsertSort(arr + left, end - begin + 1);
	}
	else
	{
		while (begin < end)
		{
			while (begin < end && arr[end] >= arr[pkey])
			{
				end--;
			}
			while (begin < end && arr[begin] <= arr[pkey])
			{
				begin++;
			}
			Swap(&arr[begin], &arr[end]);
		}
		Swap(&arr[begin], &arr[pkey]);
		QuickSort(arr, left, begin - 1);
		QuickSort(arr, begin + 1, right);
	}
}
int QuickSort1(int* arr, int left, int right)
{
	int pkey = Getmidnum(arr, left, right);
	Swap(&arr[pkey], &arr[left]);
	pkey = left;
	int begin = left, end = right;
	while (begin < end)
	{
		while (begin < end && arr[end] >= arr[pkey])
		{
			end--;
		}
		while (begin < end && arr[begin] <= arr[pkey])
		{
			begin++;
		}
		Swap(&arr[begin], &arr[end]);
	}
	Swap(&arr[begin], &arr[pkey]);
	return begin;
}
//快速排序（挖坑法）
void QuickSort2(int* arr, int left, int right)
{
	if (left >= right)
		return;
	int begin = left, end = right;
	int key = arr[left];//在左边形成一个坑位
	while (begin < end)
	{
		while (begin < end && arr[end] >= key)
		{
			end--;
		}
		arr[begin] = arr[end];//填坑
		while (begin < end && arr[begin] <= key)
		{
			begin++;
		}
		arr[end] = arr[begin];//填坑
	}
	int pmeet = begin;
	arr[pmeet] = key;
	QuickSort2(arr, left, pmeet - 1);
	QuickSort2(arr, pmeet + 1, right);
}
//双指针法
void QuickSort3(int* arr, int left, int right)
{
	if (left >= right)
		return;
	int pkey = Getmidnum(arr, left, right);
	Swap(&arr[pkey], &arr[left]);
	pkey = left;
	int prev = left, cur = prev + 1;
	while (cur <= right)//当cur没有越界
	{
		if (arr[cur] < arr[pkey])
		{
			prev++;
			Swap(&arr[prev], &arr[cur]);
		}
		cur++;
	}
	int pmeet = prev;
	Swap(&arr[pkey], &arr[prev]);
	QuickSort3(arr, left, pmeet - 1);
	QuickSort3(arr, pmeet + 1, right);
}
//非递归算法
void QuickSortNonR(int* arr,int left,int right)
{
	stack st;
	StackInit(&st);
	StackPush(&st, right);
	StackPush(&st, left);
	while (!Stackempty(&st))
	{
		int begin = StackTop(&st);//左端点
		Stackpop(&st);
		int end = StackTop(&st);//右端点
		Stackpop(&st);
		int pmeet=QuickSort1(arr, begin, end);
		//这里就需要把分好的区的端点入栈
		// [left, pmeet-1] pmeet [pmeet+1, right]
		if (end > pmeet + 1)
		{
			StackPush(&st, end);
			StackPush(&st, pmeet+1);
		}
		if (begin < pmeet - 1)//保证有两个点
		{
			StackPush(&st, pmeet - 1);//右端点先进，左端点就会先出
			StackPush(&st, begin);
		}
	}
	StackDestroy(&st);
}
void _MergeSort(int* arr, int* tmp, int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	//递归进行分割
	//分割的区间为[left,mid],[mid+1,right]
	_MergeSort(arr, tmp, left, mid);
	_MergeSort(arr, tmp, mid + 1, right);
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;

}
void MergeSort(int* arr,int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc failed");
		return;
	}
	_MergeSort(arr, tmp, 0, n - 1);

	free(tmp);
	tmp == NULL;
}