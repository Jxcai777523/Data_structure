#define _CRT_SECURE_NO_WARNINGS
#include"Sort.h"
void PrintArr(int* arr, int n)
{
	for (int i = 0;i < n;i++)
	{
		printf("%d ", arr[i]);
	}
}
void Testspeed()
{
	srand(time(NULL));//先生成一个随机种子
	const int N = 1000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);
	for (int i = 0;i < N;i++)
	{
		a1[i] = rand();
		a2[i] = a3[i] = a4[i] = a5[i] = a6[i] = a7[i] = a1[i];
	}
	int begin1 = clock();
	BubbleSort(a1, N);
	int end1 = clock();
	printf("BubbleSort:%d\n", end1 - begin1);

	int begin2 = clock();
	InsertSort(a1, N);
	int end2 = clock();
	printf("InsertSort:%d\n", end2 - begin2);

	int begin3 = clock();
	HeapSort(a1, N);
	int end3 = clock();
	printf("HeapSort: %d\n", end3 - begin3);

	int begin4 = clock();
	ShellSort(a1, N);
	int end4 = clock();
	printf("ShellSort: %d\n", end4 - begin4);
}
int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	//BubbleSort(arr, 9);
	//InsertSort(arr, 9);
	SelectSort(arr, 9);
	/*ShellSort(arr, 9);*/
	PrintArr(arr,9);
	//Testspeed();
	return 0;
}