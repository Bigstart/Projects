/*
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。



示例 1：

输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
示例 2：

输入：nums = [1]
输出：1
示例 3：

输入：nums = [5,4,-1,7,8]
输出：23


提示：

1 <= nums.length <= 105
-104 <= nums[i] <= 104
*/

#include <iostream>
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int pre = 0;
        int maxAns = nums[0];
        for (const auto& x : nums) {
            pre = std::max(pre + x, x);
            maxAns = std::max(maxAns, pre);
        }
        return maxAns;
    }
};

int main() {
    std::vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    Solution solution;
    int result = solution.maxSubArray(nums);
    std::cout << "最大子数组和为: " << result << std::endl;
    return 0;
}