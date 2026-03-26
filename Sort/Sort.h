#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include"Stack.h"
void BubbleSort(int* arr,int n);
void InsertSort(int* arr,int n);
void HeapSort(int* arr,int n);
void ShellSort(int* arr, int n);
void SelectSort(int* arr, int n);
void QuickSort(int* arr, int left, int right);//Hoare
void QuickSort2(int* arr, int left, int right);//挖坑
void QuickSort3(int* arr, int left, int right);//双指针
void QuickSortNonR(int* arr, int left, int right);//非递归实现快排