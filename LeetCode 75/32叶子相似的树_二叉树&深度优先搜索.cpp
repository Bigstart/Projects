/*
请考虑一棵二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个 叶值序列 。

举个例子，如上图所示，给定一棵叶值序列为 (6, 7, 4, 9, 8) 的树。
         3
        /  \
      5      1
     / \     / \  
    6   2    9   8
       / \
      7   4

如果有两棵二叉树的叶值序列是相同，那么我们就认为它们是 叶相似 的。
如果给定的两个根结点分别为 root1 和 root2 的树是叶相似的，则返回 true；否则返回 false 。

示例 1：
输入：root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]

         3                             
        /  \
      5      1
     / \     / \  
    6   2    9   8
       / \
      7   4

          3
        /  \
      5      1
     / \     / \
    6   7    4   2
                / \
               9   8

输出：true

示例 2：
输入：root1 = [1,2,3], root2 = [1,3,2]
输出：false

提示：

给定的两棵树结点数在 [1, 200] 范围内
给定的两棵树上的值在 [0, 200] 范围内
*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 定义二叉树的节点
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 遍历二叉树获取叶值序列
void getLeafValues(TreeNode* root, vector<int>& leafValues) {
    if (!root) return;

    if (!root->left && !root->right) {
        // 当前节点是叶子节点
        leafValues.push_back(root->val);
    }

    // 递归遍历左右子树
    getLeafValues(root->left, leafValues);
    getLeafValues(root->right, leafValues);
}

// 判断两棵二叉树是否是叶相似的
bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> leafValues1, leafValues2;

    // 获取两个树的叶值序列
    getLeafValues(root1, leafValues1);
    getLeafValues(root2, leafValues2);

    // 判断叶值序列是否相同
    return leafValues1 == leafValues2;
}

int main() {
    // 示例 1
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->right->left = new TreeNode(9);
    root1->right->right = new TreeNode(8);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);

    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(1);
    root2->left->left = new TreeNode(6);
    root2->left->right = new TreeNode(7);
    root2->right->left = new TreeNode(4);
    root2->right->right = new TreeNode(2);
    root2->right->right->left = new TreeNode(9);
    root2->right->right->right = new TreeNode(8);

    cout << "示例 1 结果: " << (leafSimilar(root1, root2) ? "true" : "false") << endl;

    // 示例 2
    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);

    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(3);
    root4->right = new TreeNode(2);

    cout << "示例 2 结果: " << (leafSimilar(root3, root4) ? "true" : "false") << endl;

    // 释放内存
    // ...（释放每个节点的内存）

    return 0;
}
