/*
给你一个下标从 0 开始、大小为 n x n 的整数矩阵 grid ，
返回满足 Ri 行和 Cj 列相等的行列对 (Ri, Cj) 的数目。

如果行和列以相同的顺序包含相同的元素（即相等的数组），则认为二者是相等的。

示例 1：
输入：grid = [[3,2,1],[1,7,6],[2,7,7]]
输出：1
解释：存在一对相等行列对：
- (第 2 行，第 1 列)：[2,7,7]

示例 2：
输入：grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
输出：3
解释：存在三对相等行列对：
- (第 0 行，第 0 列)：[3,1,2,2]
- (第 2 行, 第 2 列)：[2,4,2,2]
- (第 3 行, 第 2 列)：[2,4,2,2]

提示：

n == grid.length == grid[i].length
1 <= n <= 200
1 <= grid[i][j] <= 105
*/


#include <vector>
#include<iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    int countEqualRowColumnPairs(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::unordered_map<std::string, int> rowMap, colMap;
        int count = 0;

        for (int i = 0; i < n; ++i) {
            std::string rowStr = "", colStr = "";
            for (int j = 0; j < n; ++j) {
                rowStr += std::to_string(grid[i][j]) + ",";
                colStr += std::to_string(grid[j][i]) + ",";
                //std::to_string将不同类型的变量转换为对应的字符串形式。
                //将整数、浮点数或其他基本类型转换为字符串
            }
            rowMap[rowStr]++;
            colMap[colStr]++;
        }

        for (auto& row : rowMap) {
            count += row.second * colMap[row.first];
            //colMap[row.first] 是检索存储列的哈希表中的键为 row.first 对应的值
        }

        return count;
    }
};



int main() {
    Solution solution;
    std::vector<std::vector<int>> grid = { {3, 2, 1}, {1, 7, 6}, {2, 7, 7} };

    int result = solution.countEqualRowColumnPairs(grid);
    std::cout << "满足条件的行列对数目为：" << result << std::endl;

    return 0;
}
