/*
             A
           /    \
	  B      C
	/       /  \
       D       E    F
	\          /
	  G       H
先序遍历   结果是A B D G C E F H
*/


#include<iostream>
#include <vector>
using namespace std; // 添加这行

struct BinaryNode   //定义一个结构体用于保存当前结点信息
{
	char ch;   //数据域
	struct BinaryNode* lChild;   //左子树指针
	struct BinaryNode* rChild;   //右子树指针
};

void Forwardrecursion(struct BinaryNode* root)  //先序递归遍历
{
	if (root == NULL)
	{
		return;  
	}
	std::cout << root->ch<<" ";  //用于打印当前指针指向的数据域中存放的数据
	Forwardrecursion(root->lChild);  //按照先序遍历的顺序，现在指针应该指向左子树节点
	Forwardrecursion(root->rChild);  //按照先序遍历的顺序，最后指针应该指向右子树节点
}

void InitializeBinaryTree()  //初始化二叉树，调用线序递归遍历函数
{
	struct BinaryNode nodeA = { 'A',NULL,NULL };//定义一个node A的结构体，有三个成员变量赋值，ch=A
	struct BinaryNode nodeB = { 'B',NULL,NULL };
	struct BinaryNode nodeC = { 'C',NULL,NULL };
	struct BinaryNode nodeD = { 'D',NULL,NULL };
	struct BinaryNode nodeE = { 'E',NULL,NULL };
	struct BinaryNode nodeF = { 'F',NULL,NULL };
	struct BinaryNode nodeG = { 'G',NULL,NULL };
	struct BinaryNode nodeH = { 'H',NULL,NULL };

	//建立关系
	nodeA.lChild = &nodeB;   //将A的左值针指向节点B
	nodeA.rChild = &nodeC;   //将A的右值针指向节点C

	nodeB.lChild = &nodeD;

	nodeD.rChild = &nodeG;

	nodeC.lChild = &nodeE;
	nodeC.rChild = &nodeF;

	nodeF.lChild = &nodeH;

	//递归遍历
	Forwardrecursion(&nodeA);
}


int main()
{
	InitializeBinaryTree();
}
