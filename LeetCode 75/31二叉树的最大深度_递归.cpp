#include <iostream>
#include <algorithm> // 用于 max 函数
using namespace std;

// 重新定义二叉树节点的结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // 如果根节点为空，深度为0
        if (root == nullptr) {
            return 0;
        }

        // 递归计算左子树和右子树的深度
        //maxDepth 函数来计算当前节点的左子树深度
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // 返回当前节点的深度，为左右子树深度的最大值加1
        return max(leftDepth, rightDepth) + 1;
        
        //每次递归结束时都会返回当前节点的深度，而且每次返回时都加上了1。
        // 这个1表示当前节点存在，因此需要将当前节点计入深度。

        //如果你在递归过程中返回了三次，那么每次返回都代表了一层。
        // 所以，最终的返回值就是整个树的深度，表示树的最深层次。

    }
};

int main() {
    // 创建示例二叉树
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->left->left = new TreeNode(5);
    root->left->left = new TreeNode(9);

    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // 创建 Solution 实例
    Solution solution;

    // 调用 maxDepth 方法计算最大深度
    int depth = solution.maxDepth(root);

    // 输出结果
    cout << "二叉树的最大深度为：" << depth << endl;

    // 释放动态分配的内存
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
