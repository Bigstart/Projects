/*
给你一棵根为 root 的二叉树，请你返回二叉树中好节点的数目。 
「好节点」X 定义为：从根到该节点 X 所经过的节点中，没有任何节点的值大于 X 的值。
示例 1：

     3
   /   \
  1     4
 /     / \
4     1   5

输入：root = [3,1,4,3,null,1,5] 
输出：4
解释：图中蓝色节点为好节点。
根节点 (3) 永远是个好节点。
节点 4 -> (3,4) 是路径中的最大值。
节点 5 -> (3,4,5) 是路径中的最大值。
节点 3 -> (3,1,3) 是路径中的最大值。

示例 2：
     3
    /
   3
  / \
 4   2

输入：root = [3,3,null,4,2]
输出：3
解释：节点 2 -> (3, 3, 2) 不是好节点，因为 "3" 比它大。
示例 3：

输入：root = [1]
输出：1
解释：根节点是好节点。


提示：

二叉树中节点数目范围是 [1, 10^5] 。
每个节点权值的范围是 [-10^4, 10^4] 。
*/


#include <iostream>
#include <algorithm>

using namespace std;

// 定义二叉树的节点
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 深度优先搜索遍历二叉树，并计算好节点的数目
void dfs(TreeNode* node, int maxValue, int& count) {
    if (!node) return;

    // 如果当前节点的值大于等于路径中的最大值，它是一个好节点
    if (node->val >= maxValue) {
        count++;
        maxValue = node->val;  // 更新路径中的最大值
    }

    // 递归遍历左右子树
    dfs(node->left, maxValue, count);
    dfs(node->right, maxValue, count);
}

// 计算二叉树中好节点的数目
int goodNodes(TreeNode* root) {
    int count = 0;
    dfs(root, INT_MIN, count);  // 初始最大值设为负无穷
    return count;
}

int main() {
    // 示例 1
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);
    root1->left->left = new TreeNode(3);
    root1->right->left = new TreeNode(1);
    root1->right->right = new TreeNode(5);

    cout << "示例 1 结果: " << goodNodes(root1) << endl;

    // 示例 2
    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(2);

    cout << "示例 2 结果: " << goodNodes(root2) << endl;

    // 示例 3
    TreeNode* root3 = new TreeNode(1);

    cout << "示例 3 结果: " << goodNodes(root3) << endl;

    // 释放内存
    // ...（释放每个节点的内存）

    return 0;
}
