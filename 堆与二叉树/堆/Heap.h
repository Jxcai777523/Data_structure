#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int HeapdataType;
typedef struct Heap
{
	HeapdataType* arr;
	int size;//这里的size指向最后一个元素的下一个位置，初始化时置为0
	int capacity;
}Hp;
void HeapInit(Hp* hp);
void HeapDestroy(Hp* hp);
void Swap(HeapdataType* n1, HeapdataType* n2);
void AdjustUp(HeapdataType* arr,int child);
void HeapPush(Hp* hp, HeapdataType x);
void AdjustDown(HeapdataType* arr, int size, int parent);
void HeapPop(Hp* hp);
HeapdataType HeapTop(Hp* hp);
int HeapSize(Hp* hp);
bool HeapEmpty(Hp* hp);

