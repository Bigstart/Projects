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
#include <vector>
#include <string> // 包含字符串头文件
#include <sstream> // 包含字符串流头文件

using namespace std;

// 二叉树节点的定义
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 翻转二叉树的函数
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

// 辅助函数，用于从数组构建二叉树
TreeNode* buildTree(const vector<int>& nodes) {
	if (nodes.empty() || nodes[0] == -1) return nullptr;

	TreeNode* root = new TreeNode(nodes[0]);
	queue<TreeNode*> q;
	q.push(root);
	int i = 1;

	while (!q.empty() && i < nodes.size()) {
		TreeNode* current = q.front();
		q.pop();

		if (i < nodes.size() && nodes[i] != -1) {
			current->left = new TreeNode(nodes[i]);
			q.push(current->left);
		}
		i++;

		if (i < nodes.size() && nodes[i] != -1) {
			current->right = new TreeNode(nodes[i]);
			q.push(current->right);
		}
		i++;
	}

	return root;
}

// 辅助函数，用于层序遍历打印二叉树
void printTree(TreeNode* root) {
	if (root == nullptr) {
		cout << "[]" << endl;
		return;
	}

	queue<TreeNode*> q;
	q.push(root);
	vector<string> result;

	while (!q.empty()) {
		TreeNode* current = q.front();
		q.pop();
		if (current) {
			result.push_back(to_string(current->val));
			q.push(current->left);
			q.push(current->right);
		}
		else {
			result.push_back("null");
		}
	}

	// 移除末尾的 "null"
	while (!result.empty() && result.back() == "null") {
		result.pop_back();
	}

	cout << "[";
	for (size_t i = 0; i < result.size(); ++i) {
		cout << result[i];
		if (i != result.size() - 1) {
			cout << ",";
		}
	}
	cout << "]" << endl;
}

// 主函数
int main() {
	vector<int> nodes1 = { 4, 2, 7, 1, 3, 6, 9 };
	TreeNode* root1 = buildTree(nodes1);
	cout << "原始二叉树1: ";
	printTree(root1);
	root1 = invertTree(root1);
	cout << "翻转后的二叉树1: ";
	printTree(root1);

	vector<int> nodes2 = { 2, 1, 3 };
	TreeNode* root2 = buildTree(nodes2);
	cout << "原始二叉树2: ";
	printTree(root2);
	root2 = invertTree(root2);
	cout << "翻转后的二叉树2: ";
	printTree(root2);

	vector<int> nodes3 = {};
	TreeNode* root3 = buildTree(nodes3);
	cout << "原始二叉树3: ";
	printTree(root3);
	root3 = invertTree(root3);
	cout << "翻转后的二叉树3: ";
	printTree(root3);

	return 0;
}
