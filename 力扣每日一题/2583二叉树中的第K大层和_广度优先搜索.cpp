/*
给你一棵二叉树的根节点 root 和一个正整数 k 。

树中的 层和 是指 同一层 上节点值的总和。

返回树中第 k 大的层和（不一定不同）。如果树少于 k 层，则返回 -1 。

注意，如果两个节点与根节点的距离相同，则认为它们在同一层。

 

示例 1：
          5
        /   \
       8      9
     /  \   /   \
    2    1  3    7
  /   \
 4     6

输入：root = [5,8,9,2,1,3,7,4,6], k = 2
输出：13
解释：树中每一层的层和分别是：
- Level 1: 5
- Level 2: 8 + 9 = 17
- Level 3: 2 + 1 + 3 + 7 = 13
- Level 4: 4 + 6 = 10
第 2 大的层和等于 13 。

示例 2：
     1
    /
   2
  /
 3


输入：root = [1,2,null,3], k = 1
输出：3
解释：最大的层和是 3 。
 

提示：

树中的节点数为 n
2 <= n <= 105
1 <= Node.val <= 106
1 <= k <= n
*/

#include <queue>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;

// 定义树的节点结构
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int kthLargestLevelSum(TreeNode* root, int k) {
	if (root == nullptr) return -1; // 空树，返回 -1

	std::queue<TreeNode*> q;
	q.push(root);
	std::vector<long long> levelSums; // 存储每一层的层和

	while (!q.empty()) {
		int size = q.size();
		long long levelSum = 0;
		for (int i = 0; i < size; ++i) {
			TreeNode* curr = q.front();
			q.pop();
			levelSum += curr->val;
			if (curr->left)
			{ 
				q.push(curr->left); 
			}
			if (curr->right) 
			{ 
				q.push(curr->right); 
			}
		}
		levelSums.push_back(levelSum); // 将当前层的层和存入数组
	}

	std::sort(levelSums.rbegin(), levelSums.rend()); // 对层和数组进行降序排序

	if (k > levelSums.size()) return -1; // k 大于树的层数，返回 -1

	return levelSums[k - 1]; // 返回第 k 大的层和


}

// 示例用法
int main() {
	// 示例 1
	TreeNode* root1 = new TreeNode(5);
	root1->left = new TreeNode(8);
	root1->right = new TreeNode(9);
	root1->left->left = new TreeNode(2);
	root1->left->right = new TreeNode(1);
	root1->right->left = new TreeNode(3);
	root1->right->right = new TreeNode(7);
	root1->left->left->left = new TreeNode(4);
	root1->left->left->right = new TreeNode(6);

	int k1 = 2;
	int result1 = kthLargestLevelSum(root1, k1);
	std::cout << "示例 1 结果：" << result1 << std::endl;

	// 示例 2
	TreeNode* root2 = new TreeNode(1);
	root2->left = new TreeNode(2);
	root2->left->right = new TreeNode(3);

	int k2 = 1;
	int result2 = kthLargestLevelSum(root2, k2);
	std::cout << "示例 2 结果：" << result2 << std::endl;

	return 0;
}
