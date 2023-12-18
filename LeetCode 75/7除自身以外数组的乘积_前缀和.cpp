/*
给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
请 不要使用除法，且在 O(n) 时间复杂度内完成此题。

示例 1:
输入: nums = [1,2,3,4]
输出: [24,12,8,6]

示例 2:
输入: nums = [-1,1,0,-3,3]
输出: [0,0,9,0,0]

提示：
2 <= nums.length <= 105
-30 <= nums[i] <= 30
保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内
*/

#include <vector>
#include <iostream>
#include <vector>

std::vector<int> productExceptSelf(std::vector<int>& nums) {
	int n = nums.size();

	//创建左侧乘积数组和右侧乘积数组
	std::vector<int> left(n, 1);  //初始化左侧乘积数组为1
	std::vector<int> right(n, 1);  //初始化右侧乘积数组为1

	//计算左侧乘积数组
	for (int i = 1; i < n; ++i) {
		left[i] = left[i - 1] * nums[i - 1];  
	}
	//计算右侧
	for (int i = n - 2; i >= 0; --i) {
		right[i] = right[i + 1] * nums[i + 1];
	}
	std::vector<int> answer(n);
	for (int i = 0; i < n; ++i) {
		answer[i] = left[i] * right[i];
	}
	return answer;
}


int main() {
	std::vector<int> nums1 = { 1, 2, 3, 4 };
	std::vector<int> result1 = productExceptSelf(nums1);

	std::cout << "Result for nums1: ";
	for (int num : result1) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

	std::vector<int> nums2 = { -1, 1, 0, -3, 3 };
	std::vector<int> result2 = productExceptSelf(nums2);

	std::cout << "Result for nums2: ";
	for (int num : result2) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

	return 0;
}