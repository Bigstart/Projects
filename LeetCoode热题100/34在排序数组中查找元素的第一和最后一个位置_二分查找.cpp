/*
给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

 

示例 1：
输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]

示例 2：
输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]

示例 3：
输入：nums = [], target = 0
输出：[-1,-1]
 

提示：
0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums 是一个非递减数组
-109 <= target <= 109
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	// 用于找到第一个大于等于target的位置
	int binarySearch(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right) {
			int mid = (right - left) / 2 + left;
			if (nums[mid] < target) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		return left;
	}

	vector<int> searchRange(vector<int>& nums, int target) {
		int left = binarySearch(nums, target); // 找到第一个大于等于target的位置
		int right = binarySearch(nums, target + 1) - 1; // 找到第一个大于target的位置的前一个位置

		if (left >= nums.size() || nums[left] != target) {
			return { -1, -1 }; // 目标值不存在于数组中
		}

		return { left, right };
	}
};

int main() {
	Solution sol;

	// 示例 1
	vector<int> nums1 = { 5, 7, 7, 8, 8, 10 };
	int target1 = 8;
	vector<int> result1 = sol.searchRange(nums1, target1);
	cout << "Example 1: [5, 7, 7, 8, 8, 10] Target: 8 -> Result: [" << result1[0] << ", " << result1[1] << "]" << endl;

	// 示例 2
	vector<int> nums2 = { 5, 7, 7, 8, 8, 10 };
	int target2 = 6;
	vector<int> result2 = sol.searchRange(nums2, target2);
	cout << "Example 2: [5, 7, 7, 8, 8, 10] Target: 6 -> Result: [" << result2[0] << ", " << result2[1] << "]" << endl;

	// 示例 3
	vector<int> nums3;
	int target3 = 0;
	vector<int> result3 = sol.searchRange(nums3, target3);
	cout << "Example 3: [] Target: 0 -> Result: [" << result3[0] << ", " << result3[1] << "]" << endl;

	return 0;
}
