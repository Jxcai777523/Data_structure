#define _CRT_SECURE_NO_WARNINGS
#include"BinaryTreeList.h"
//int size;
//int TreeSize(Btnode* root)//ÓÃÇ°Ðò±éÀú
//{
//	if (root == NULL)
//		return;
//	size++;
//	TreeSize(root->left);
//	TreeSize(root->right);
//	return size;
//}
Btnode* Buynode(BtDataType x)
{
	Btnode* node = (Btnode*)malloc(sizeof(Btnode));
	node->data = x;
	node->left = node->right = NULL;
	return node;
}

void Test01(Btnode* node1)
{
	PrevOrder(node1);
	printf("\n");
	MiddleOrder(node1);
	printf("\n");
	BackOrder(node1);
	printf("\n");
}
int main()
{
	Btnode* node1 = Buynode(1);
	Btnode* node2 = Buynode(2);
	Btnode* node3 = Buynode(3);
	Btnode* node4 = Buynode(4);
	Btnode* node5 = Buynode(5);
	Btnode* node6 = Buynode(6);
	node1->left = node2;
	node2->left = node3;
	node1->right = node4;
	node4->left = node5;
	node4->right = node6;
	Test01(node1);
	printf("%d\n", TreeSize(node1));//6
	printf("%d\n", TreeleafSize(node1));//4
	printf("%d\n", TreeHight(node1));//3
	printf("%d\n", TreeKlevelSize(node1,3));//
	/*TreeSize(node1);
	printf("%d\n",size);
	size = 0;
	printf("%d", TreeSize(node2));*/
	return 0;
}