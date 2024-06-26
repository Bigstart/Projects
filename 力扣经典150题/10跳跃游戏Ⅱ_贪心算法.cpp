/*
给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。

每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:

0 <= j <= nums[i] 
i + j < n
返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。

 

示例 1:

输入: nums = [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
示例 2:

输入: nums = [2,3,0,1,4]
输出: 2
 

提示:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
题目保证可以到达 nums[n-1]
*/


#include <iostream>
#include <vector>
#include <algorithm> // 添加<algorithm>头文件

using namespace std;

/**
 * @brief 计算到达 nums[n - 1] 的最小跳跃次数
 *
 * @param nums 输入的整数数组
 * @return int 最小跳跃次数
 */
int jump(vector<int>& nums) {
	int n = nums.size();
	if (n < 2) return 0;

	int jumps = 0; // 跳跃次数
	int current_end = 0; // 当前跳跃的最大范围
	int farthest = 0; // 能达到的最远位置

	for (int i = 0; i < n - 1; ++i) {
		// 更新能达到的最远位置
		farthest = max(farthest, i + nums[i]);

		// 如果到达了当前跳跃的终点，增加跳跃次数，并更新当前跳跃的终点
		if (i == current_end) {
			jumps++;
			current_end = farthest;
		}

		// 如果当前跳跃终点已经到达或超过最后一个位置，跳出循环
		if (current_end >= n - 1) break;
	}

	return jumps;
}

int main() {
	// 示例1
	vector<int> nums1 = { 2, 3, 1, 1, 4 };
	cout << "示例1结果: " << jump(nums1) << endl; // 输出: 2

	// 示例2
	vector<int> nums2 = { 2, 3, 0, 1, 4 };
	cout << "示例2结果: " << jump(nums2) << endl; // 输出: 2

	// 你可以添加更多测试用例来验证代码
	return 0;
}
