/*
给你一棵以 root 为根的二叉树，二叉树中的交错路径定义如下：

选择二叉树中 任意 节点和一个方向（左或者右）。
如果前进方向为右，那么移动到当前节点的的右子节点，否则移动到它的左子节点。
改变前进方向：左变右或者右变左。
重复第二步和第三步，直到你在树中无法继续移动。
交错路径的长度定义为：访问过的节点数目 - 1（单个节点的路径长度为 0 ）。

请你返回给定树中最长 交错路径 的长度。



示例 1：

    1
     \
      1
     / \
    1   1
   / \   \
  1   1   1
   \
    1
   /
  1


输入：root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]
输出：3
解释：蓝色节点为树中最长交错路径（右 -> 左 -> 右）。
示例 2：

       1
      / \
     1   1
       / \
      1   1
         /
        1


输入：root = [1,1,1,null,1,null,null,1,1,null,1]
输出：4
解释：蓝色节点为树中最长交错路径（左 -> 右 -> 左 -> 右）。
示例 3：

输入：root = [1]
输出：0


提示：

每棵树最多有 50000 个节点。
每个节点的值在 [1, 100] 之间。
*/


#include <iostream>
#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        int maxLen = 0;
        dfs(root->left, true, 1, maxLen);  // 左子树，方向为true（左），当前长度为1
        dfs(root->right, false, 1, maxLen);  // 右子树，方向为false（右），当前长度为1
        return maxLen;
    }

private:
    void dfs(TreeNode* node, bool isLeft, int curLen, int& maxLen) {
        if (!node) return;

        // 更新最大长度
        maxLen = std::max(maxLen, curLen);

        if (isLeft) {
            // 从左子树到右子树
            dfs(node->right, false, curLen + 1, maxLen);
            // 重置长度
            dfs(node->left, true, 1, maxLen);
        }
        else {
            // 从右子树到左子树
            dfs(node->left, true, curLen + 1, maxLen);
            // 重置长度
            dfs(node->right, false, 1, maxLen);
        }
    }
};

int main() {
    // 构造二叉树（以示例1为例）
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(1);
    root->right->left->left = new TreeNode(1);
    root->right->left->right = new TreeNode(1);
    root->right->right->right = new TreeNode(1);
    root->right->left->left->right = new TreeNode(1);
    root->right->left->left->right->left = new TreeNode(1);

    // 创建Solution对象
    Solution solution;

    // 计算最长交错路径
    int result = solution.longestZigZag(root);

    // 输出结果
    std::cout << "最长交错路径长度：" << result << std::endl;

    return 0;
}
