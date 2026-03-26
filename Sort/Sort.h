#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include"Stack.h"
void BubbleSort(int* arr,int n);
void InsertSort(int* arr,int n);
void HeapSort(int* arr,int n);
void BuildHeap(int* arr,int n);
void AdjustDown(int* arr,int size,int parent);
void ShellSort(int* arr, int n);
void SelectSort(int* arr, int n);
void QuickSort(int* arr, int left, int right);
void QuickSort2(int* arr, int left, int right);
void QuickSort3(int* arr, int left, int right);
void QuickSortNonR(int* arr, int left, int right);