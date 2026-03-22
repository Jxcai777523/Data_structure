#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void BubbleSort(int* arr,int n);
void InsertSort(int* arr,int n);
void HeapSort(int* arr,int n);
void BuildHeap(int* arr,int n);
void AdjustDown(int* arr,int size,int parent);
void ShellSort(int* arr, int n);
void 