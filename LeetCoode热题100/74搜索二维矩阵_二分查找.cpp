/*
给你一个满足下述两条属性的 m x n 整数矩阵：

每行中的整数从左到右按非严格递增顺序排列。
每行的第一个整数大于前一行的最后一个整数。
给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。

 
示例 1：
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出：true

示例 2：
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
输出：false
 

提示：
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/


#include <iostream>
#include <vector>

class Solution {
public:
	bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
		int m = matrix.size();
		int n = matrix[0].size();

		// 从右上角开始查找
		int row = 0;
		int col = n - 1;

		while (row < m && col >= 0) {
			if (matrix[row][col] == target) {
				return true; // 找到目标值
			}
			else if (matrix[row][col] < target) {
				row++; // 目标值在当前行下方
			}
			else {
				col--; // 目标值在当前列左侧
			}
		}

		return false; // 没有找到目标值
	}
};

int main() {
	Solution sol;
	std::vector<std::vector<int>> matrix1 = {
		{1, 3, 5, 7},
		{10, 11, 16, 20},
		{23, 30, 34, 60}
	};
	int target1 = 3;
	std::cout << "Target 3, Output: " << std::boolalpha << sol.searchMatrix(matrix1, target1) << std::endl;

	std::vector<std::vector<int>> matrix2 = {
		{1, 3, 5, 7},
		{10, 11, 16, 20},
		{23, 30, 34, 60}
	};
	int target2 = 13;
	std::cout << "Target 13, Output: " << std::boolalpha << sol.searchMatrix(matrix2, target2) << std::endl;

	return 0;
}
