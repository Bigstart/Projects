/*
给定一个二叉树 root ，返回其最大深度。

二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。

 

示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：3

示例 2：
输入：root = [1,null,2]
输出：2
 

提示：
树中节点的数量在 [0, 104] 区间内。
-100 <= Node.val <= 100
*/


#include <iostream>
#include <queue>
using namespace std;

// 二叉树节点的定义
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 计算二叉树的最大深度
int maxDepth(TreeNode* root) {
	if (root == nullptr) {
		return 0;
	}
	// 递归计算左子树和右子树的最大深度
	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);
	// 当前节点的最大深度是左子树和右子树的最大深度中的较大者加一
	return max(leftDepth, rightDepth) + 1;


	/*  更简易一些的方法
	if(root==nullptr)
	{
        return 0;
    }
    return max(maxDepth(root->left),maxDepth(root->right))+1;

	*/

}

// 辅助函数，用于从数组构建二叉树
TreeNode* buildTree(vector<int>& nodes) {
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

// 主函数
int main() {
	vector<int> nodes1 = { 3, 9, 20, -1, -1, 15, 7 };
	TreeNode* root1 = buildTree(nodes1);
	cout << "二叉树1的最大深度: " << maxDepth(root1) << endl; // 输出 3

	vector<int> nodes2 = { 1, -1, 2 };
	TreeNode* root2 = buildTree(nodes2);
	cout << "二叉树2的最大深度: " << maxDepth(root2) << endl; // 输出 2

	// 清理内存（这里简单处理，未做完整内存管理）
	delete root1;
	delete root2;

	return 0;
}
