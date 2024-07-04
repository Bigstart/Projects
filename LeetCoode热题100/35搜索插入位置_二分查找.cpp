/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。


示例 1:
输入: nums = [1,3,5,6], target = 5
输出: 2

示例 2:
输入: nums = [1,3,5,6], target = 2
输出: 1

示例 3:
输入: nums = [1,3,5,6], target = 7
输出: 4


提示:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums 为 无重复元素 的 升序 排列数组
-104 <= target <= 104
*/


#include <iostream>
#include <vector>

class Solution {
public:
	int searchInsert(std::vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;

		while (left <= right) {
			int mid = left + (right - left) / 2;

			//这里还可以这样写    int mid = ((right - left) >> 1)+left;
			//好处是 当两个值过大时 可以避免内存溢出
			//如果 left = 2^31 - 1，right = 2^31 - 1，那么 (left + right) 就会溢出


			if (nums[mid] == target) {
				return mid;  // 找到目标值，直接返回索引
			}
			else if (nums[mid] < target) {
				left = mid + 1;  // 目标值在右侧
			}
			else {
				right = mid - 1;  // 目标值在左侧
			}
		}

		// 如果没有找到目标值，返回插入位置，即左指针的位置
		return left;
	}
};

int main() {
	Solution sol;
	std::vector<int> nums1 = { 1, 3, 5, 6 };
	int target1 = 5;
	std::cout << "Target 5, Output: " << sol.searchInsert(nums1, target1) << std::endl;

	std::vector<int> nums2 = { 1, 3, 5, 6 };
	int target2 = 2;
	std::cout << "Target 2, Output: " << sol.searchInsert(nums2, target2) << std::endl;

	std::vector<int> nums3 = { 1, 3, 5, 6 };
	int target3 = 7;
	std::cout << "Target 7, Output: " << sol.searchInsert(nums3, target3) << std::endl;

	return 0;
}
