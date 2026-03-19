#define _CRT_SECURE_NO_WARNINGS
#include"BinaryTreeList.h"
#include"Queue.h"
//int size;
//int TreeSize(Btnode* root)//用前序遍历
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
//层序遍历
//这里需要用到堆，所以我们添加一下Queue.h,以及Queue.c文件
//就是找到对应的文件夹，将其复制到本项目的文件中
//然后为了节约空间同时达到将树的节点放进堆的目的，我们将堆的类型修改为Btnode*
void LevelOrder(Btnode* root)
{
	Que q;
	QueInit(&q);
	if (root != NULL)
		Quepush(&q,root);//把树的根节点放进队列
	while (!QueEmpty(&q))
	{
		Btnode* front = Quefront(&q);//取队头元素，为了后面进行访问左右节点
		Quepop(&q);
		printf("%d ", front->data);
		if (front->left)
			Quepush(&q, front->left);
		if (front->right)
			Quepush(&q, front->right);
	}
	QueDestroy(&q);
}
bool BinaryTreeComplete(Btnode* root)
{
	Que q;
	QueInit(&q);
	if (root)
		Quepush(&q,root);
	while (!QueEmpty(&q))
	{
		Btnode* front = Quefront(&q);
		Quepop(&q);
		if (front == NULL)
		{
			break;
		}
		Quepush(&q, front->left);//空节点也进队
		Quepush(&q, front->right);
	}
	while (!QueEmpty(&q))
	{
		Btnode* front = Quefront(&q);
		Quepop(&q);
		if (front != NULL)
		{
			QueDestroy(&q);
			return false;
		}
	}
	return true;

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
	LevelOrder(node1);
	if (BinaryTreeComplete(node1))
		printf("YES\n");
	else
		printf("No\n");
	/*TreeSize(node1);
	printf("%d\n",size);
	size = 0;
	printf("%d", TreeSize(node2));*/
	return 0;
}