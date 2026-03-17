#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int BtDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BtDataType data;
}Btnode;

void PrevOrder(Btnode* root);
void MiddleOrder(Btnode* root);
void BackOrder(Btnode* root);
int TreeSize(Btnode* root);
int TreeleafSize(Btnode* root);
int TreeHight(Btnode* root);
int TreeKlevelSize(Btnode* root, int k);
Btnode* FindTreenode(Btnode* root, BtDataType x);