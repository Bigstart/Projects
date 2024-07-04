/*
给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。

 

示例 1：
输入：root = [1,null,2,3]
输出：[1,3,2]

示例 2：
输入：root = []
输出：[]

示例 3：
输入：root = [1]
输出：[1]
 

提示：
树中节点数目在范围 [0, 100] 内
-100 <= Node.val <= 100
*/

#include <iostream>
#include <vector>
using namespace std;

// 定义二叉树节点结构
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 中序遍历函数，递归实现
void inorderTraversalHelper(TreeNode* root, vector<int>& result) {
	if (root == nullptr) {
		return;
	}
	inorderTraversalHelper(root->left, result); // 遍历左子树
	result.push_back(root->val); // 访问根节点
	inorderTraversalHelper(root->right, result); // 遍历右子树
}

// 中序遍历接口函数
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> result;
	inorderTraversalHelper(root, result);
	return result;
}

int main() {
	// 示例1：root = [1,null,2,3]
	TreeNode* root1 = new TreeNode(1);
	root1->right = new TreeNode(2);
	root1->right->left = new TreeNode(3);

	vector<int> result1 = inorderTraversal(root1);
	for (int val : result1) {
		cout << val << " ";
	}
	cout << endl;

	// 示例2：root = []
	TreeNode* root2 = nullptr;
	vector<int> result2 = inorderTraversal(root2);
	for (int val : result2) {
		cout << val << " ";
	}
	cout << endl;

	// 示例3：root = [1]
	TreeNode* root3 = new TreeNode(1);
	vector<int> result3 = inorderTraversal(root3);
	for (int val : result3) {
		cout << val << " ";
	}
	cout << endl;

	return 0;
}
