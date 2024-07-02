/*
给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。

 

示例 1：
输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]

示例 2：
输入：root = [2,1,3]
输出：[2,3,1]

示例 3：
输入：root = []
输出：[]
 

提示：

树中节点数目范围在 [0, 100] 内
-100 <= Node.val <= 100
*/


#include <iostream>
#include <queue>

// 二叉树节点定义
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 解决方案类
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr) {
			return nullptr;
		}
		TreeNode* left = invertTree(root->left);
		TreeNode* right = invertTree(root->right);
		root->left = right;
		root->right = left;

		return root;
	}
};

// 辅助函数，用于层序遍历打印二叉树
void printTree(TreeNode* root) {
	if (root == nullptr) {
		return;
	}
	std::queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode* node = q.front();
		q.pop();
		if (node != nullptr) {
			std::cout << node->val << " ";
			q.push(node->left);
			q.push(node->right);
		}
		else {
			std::cout << "null ";
		}
	}
	std::cout << std::endl;
}

int main() {
	// 创建二叉树
	TreeNode* root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(9);

	// 打印原始树
	std::cout << "Original tree: ";
	printTree(root);

	// 翻转二叉树
	Solution solution;
	TreeNode* invertedRoot = solution.invertTree(root);

	// 打印翻转后的树
	std::cout << "Inverted tree: ";
	printTree(invertedRoot);

	// 释放内存（简单起见，此处不处理循环引用问题）
	delete root->left->left;
	delete root->left->right;
	delete root->right->left;
	delete root->right->right;
	delete root->left;
	delete root->right;
	delete root;

	return 0;
}
