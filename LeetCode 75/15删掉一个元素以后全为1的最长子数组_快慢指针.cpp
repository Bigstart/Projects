/*
给你一个二进制数组 nums ，你需要从中删掉一个元素。
请你在删掉元素的结果数组中，返回最长的且只包含 1 的非空子数组的长度。
如果不存在这样的子数组，请返回 0 。

提示 1：
输入：nums = [1,1,0,1]
输出：3
解释：删掉位置 2 的数后，[1,1,1] 包含 3 个 1 。

示例 2：
输入：nums = [0,1,1,1,0,1,1,0,1]
输出：5
解释：删掉位置 4 的数字后，[0,1,1,1,1,1,0,1] 的最长全 1 子数组为 [1,1,1,1,1] 。

示例 3：
输入：nums = [1,1,1]
输出：2
解释：你必须要删除一个元素。

提示：
1 <= nums.length <= 105
nums[i] 要么是 0 要么是 1 。
*/

#include <vector>
#include <algorithm>
#include<iostream>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int left = 0;
        int right = 0;
        int countzero = 0;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[right] == 0)
            {
                ++countzero;
            }
            while (countzero > 1) {
                if (nums[left] == 0) {
                    --countzero;
                }
                left++;
            }
            maxLen = std::max(maxLen, right - left);
            ++right;
        }
        return maxLen;
    }
};

// 测试
int main() {
    Solution solution;
    std::vector<int> nums1 = { 1, 1, 0, 1 };
    std::vector<int> nums2 = { 0, 1, 1, 1, 0, 1, 1, 0, 1 };
    std::vector<int> nums3 = { 1, 1, 1 };

    int result1 = solution.longestSubarray(nums1);
    int result2 = solution.longestSubarray(nums2);
    int result3 = solution.longestSubarray(nums3);

    // 输出最长全1子数组长度
    std::cout << "最长全1子数组长度1：" << result1 << std::endl;
    std::cout << "最长全1子数组长度2：" << result2 << std::endl;
    std::cout << "最长全1子数组长度3：" << result3 << std::endl;

    return 0;
}
