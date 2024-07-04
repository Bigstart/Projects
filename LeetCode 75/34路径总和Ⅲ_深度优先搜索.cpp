
/*
给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。

路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。



示例 1：
      10
     /  \
    5   -3
   / \    \
  3   2    11
 / \   \
3  -2   1

输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
输出：3
解释：和等于 8 的路径有 3 条，如图所示。
示例 2：

输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：3


提示:

二叉树的节点个数的范围是 [0,1000]
-109 <= Node.val <= 109
-1000 <= targetSum <= 1000
*/

#include <iostream>

using namespace std;

// 定义二叉树的节点
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 深度优先搜索遍历二叉树，并计算满足条件的路径数目
int dfs(TreeNode* node, int targetSum) {
    if (!node) {
        return 0;
    }

    // 以当前节点为起点的路径数目
    int count = 0;

    // 从当前节点出发的路径是否满足条件
    if (node->val == targetSum) {
        count++;
    }

    // 递归遍历左右子树，并累加路径数目
    count += dfs(node->left, targetSum - node->val);
    count += dfs(node->right, targetSum - node->val);

    return count;
}

// 计算二叉树中路径和等于目标和的路径数目
int pathSum(TreeNode* root, int targetSum) {
    if (!root) {
        return 0;
    }

    // 以当前节点为起点的路径数目
    int countFromNode = dfs(root, targetSum);

    // 递归调用左右子树
    int countFromLeft = pathSum(root->left, targetSum);
    int countFromRight = pathSum(root->right, targetSum);

    // 总路径数目为三者之和
    return countFromNode + countFromLeft + countFromRight;

   
}

int main() {
    // 示例 1
    TreeNode* root1 = new TreeNode(10);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(-3);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(2);
    root1->right->right = new TreeNode(11);
    root1->left->left->left = new TreeNode(3);
    root1->left->left->right = new TreeNode(-2);
    root1->left->right->right = new TreeNode(1);

    cout << "示例 1 结果: " << pathSum(root1, 8) << endl;

    // 示例 2
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(4);
    root2->right = new TreeNode(8);
    root2->left->left = new TreeNode(11);
    root2->left->left->left = new TreeNode(7);
    root2->left->left->right = new TreeNode(2);
    root2->right->left = new TreeNode(13);
    root2->right->right = new TreeNode(4);
    root2->right->right->left = new TreeNode(5);
    root2->right->right->right = new TreeNode(1);

    cout << "示例 2 结果: " << pathSum(root2, 22) << endl;

    // 释放内存
    // ...（释放每个节点的内存）

    return 0;
}



/*
思路与算法

我们首先想到的解法是穷举所有的可能，我们访问每一个节点 node，
检测以 node 为起始节点且向下延深的路径有多少种。
我们递归遍历每一个节点的所有可能的路径，然后将这些路径数目加起来即为返回结果。

我们首先定义 rootSum(p,val)表示以节点p为起点向下且满足路径总和为val的路径数目。
我们对二叉树上每个节点p求出 rootSum(p,targetSum)，然后对这些路径数目求和即为返回结果。

我们对节点p求rootSum(p,targetSum)时，以当前节点p为目标路径的起点递归向下进行搜索。
假设当前的节点p的值为val，我们对左子树和右子树进行递归搜索，
对节点p的左孩子节点pl​求出 rootSum(pl,targetSum−val)​
以及对右孩子节点pr求出 rootSum(pr,targetSum−val)。

节点p的 rootSum(p,targetSum)即等于 rootSum(pl,targetSum−val)​与 rootSum(pr,targetSum−val)之和，

同时我们还需要判断一下当前节点p的值是否刚好等于 targetSum

我们采用递归遍历二叉树的每个节点p，对节点p求 rootSum(p,val)，然后将每个节点所有求的值进行相加求和返回。

*/