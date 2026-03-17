#define _CRT_SECURE_NO_WARNINGS
#include"BinaryTreeList.h"
void PrevOrder(Btnode* root)
{
	if (root == NULL)//如果根节点是空，那么返回上层函数
	{
		printf("N ");
		return;
	}
	else
		printf("%d ", root->data);

	PrevOrder(root->left);
	PrevOrder(root->right);
}
void MiddleOrder(Btnode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	MiddleOrder(root->left);
	printf("%d ", root->data);
	MiddleOrder(root->right);
}
void BackOrder(Btnode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	BackOrder(root->left);
	BackOrder(root->right);
	printf("%d ", root->data);
}
int TreeSize(Btnode* root)//看成根+左子树+右子树
{
	return root == NULL ? 0 : 1 + TreeSize(root->left) + TreeSize(root->right);
}
int TreeleafSize(Btnode* root)
{
	if (root == NULL)
		return;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return TreeleafSize(root->left) + TreeleafSize(root->right);
}
int TreeHight(Btnode* root)
{
	if (root == NULL)
		return 0;
	int ret1 = TreeHight(root->left);
	int ret2 = TreeHight(root->right);
	return ret1 > ret2 ? ret1 + 1 : ret2 + 1;//这里不要忘记加上第一层
	//return TreeHighr(root->left)>TreeHighr(root->right)?
	// TreeHighr(root->left):TreeHighr(root->right)
	//这里如果用这种，当递归层数很深时，如果要进行多次比较，就需要重新再运行函数，且运行多次
	//时间复杂度大大增加了，所以这里直接保存大小
}
int TreeKlevelSize(Btnode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return TreeKlevelSize(root->left, k - 1) + TreeKlevelSize(root->right, k - 1);
}
Btnode* FindTreenode(Btnode* root, BtDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	Btnode* ret1 = FindTreenode(root->left, x);
	if (ret1)
		return ret1;
	Btnode* ret2 = FindTreenode(root->right, x);
	return ret2;
}