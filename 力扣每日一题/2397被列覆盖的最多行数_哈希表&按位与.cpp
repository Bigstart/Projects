/*
给你一个下标从 0 开始、大小为 m x n 的二进制矩阵 matrix ；
另给你一个整数 numSelect，表示你必须从 matrix 中选择的 不同 列的数量。
如果一行中所有的 1 都被你选中的列所覆盖，则认为这一行被 覆盖 了。
形式上，假设 s = {c1, c2, ...., cnumSelect} 是你选择的列的集合。对于矩阵中的某一行 row ，如果满足下述条件，则认为这一行被集合 s 覆盖：

对于满足 matrix[row][col] == 1 的每个单元格 matrix[row][col]（0 <= col <= n - 1），col 均存在于 s 中，或者
row 中 不存在 值为 1 的单元格。
你需要从矩阵中选出 numSelect 个列，使集合覆盖的行数最大化。

返回一个整数，表示可以由 numSelect 列构成的集合 覆盖 的 最大行数 。

示例 1：

输入：matrix = [[0,0,0],[1,0,1],[0,1,1],[0,0,1]], numSelect = 2
输出：3
0 0 0
1 0 1
0 1 1
0 0 1
选择 s = {0, 2} 。
- 第 0 行被覆盖，因为其中没有出现 1 。
- 第 1 行被覆盖，因为值为 1 的两列（即 0 和 2）均存在于 s 中。
- 第 2 行未被覆盖，因为 matrix[2][1] == 1 但是 1 未存在于 s 中。
- 第 3 行被覆盖，因为 matrix[2][2] == 1 且 2 存在于 s 中。
因此，可以覆盖 3 行。
另外 s = {1, 2} 也可以覆盖 3 行，但可以证明无法覆盖更多行。

示例 2：
输入：matrix = [[1],[0]], numSelect = 1
1
0
输出：2
解释：
选择唯一的一列，两行都被覆盖了，因为整个矩阵都被覆盖了。
所以我们返回 2 。

提示：
m == matrix.length
n == matrix[i].length
1 <= m, n <= 12
matrix[i][j] 要么是 0 要么是 1
1 <= numSelect <= n
*/


#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxCoveredRows(vector<vector<int>>& matrix, int numSelect) {
        int m = matrix.size();       // 获取矩阵的行数
        int n = matrix[0].size();    // 获取矩阵的列数

        int maxRows = 0; // 记录最大覆盖行数

        //(1 << n) 代表是2的n次方

        for (int mask = 0; mask < (1 << n); ++mask) { // 遍历所有可能的列的选择组合
            unordered_set<int> selectedCols; // 用unordered_set来存储当前选中的列

            for (int j = 0; j < n; ++j) {
                if ((mask >> j) & 1) {         // 按位与运算  检查当前列是否被选中       如果 mask 是 111，右移一位后变成了 011。
                    selectedCols.insert(j);    // 如果被选中，加入selectedCols中
                }
            }
            //涉及到二进制的按位与运算还有左移右移  
            /*
              1010
            & 1100
             ______ 
              1000
            */
            

            int coveredRows = 0; // 记录当前选中列能覆盖的行数
            for (const auto& row : matrix) { // 遍历矩阵的每一行
                bool isCovered = true; // 假设当前行被覆盖

                for (int j = 0; j < n; ++j) {
                    if (row[j] == 1 && selectedCols.find(j) == selectedCols.end()) { // 如果当前行有1但对应列未被选中
                        isCovered = false; // 当前行未被覆盖
                        break;
                    }
                }

                if (isCovered) { // 如果当前行被覆盖
                    ++coveredRows; // 覆盖行数加一
                }
            }

            if (coveredRows > maxRows && selectedCols.size() == numSelect) { // 如果覆盖行数大于最大覆盖行数并且选中列数量符合要求
                maxRows = coveredRows; // 更新最大覆盖行数
            }
        }

        return maxRows; // 返回最大覆盖行数
    }
};



int main() {
    Solution sol;

    // 示例 1
    vector<vector<int>> matrix1 = {
        {0, 0, 0},
        {1, 0, 1},
        {0, 1, 1},
        {0, 0, 1}
    };
    int numSelect1 = 2;
    int result1 = sol.maxCoveredRows(matrix1, numSelect1);
    std::cout << "示例 1 结果: " << result1 << std::endl;

    // 示例 2
    vector<vector<int>> matrix2 = {
        {1},
        {0}
    };
    int numSelect2 = 1;
    int result2 = sol.maxCoveredRows(matrix2, numSelect2);
    std::cout << "示例 2 结果: " << result2 << std::endl;

    return 0;
}