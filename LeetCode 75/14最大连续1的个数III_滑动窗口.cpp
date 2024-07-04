/*
给定一个二进制数组 nums 和一个整数 k，如果可以翻转最多 k 个 0 ，则返回 数组中连续 1 的最大个数 。

示例 1：
输入：nums = [1,1,1,0,0,0,1,1,1,1,0], K = 2
输出：6
解释：[1,1,1,0,0,1,1,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 6。

示例 2：
输入：nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
输出：10
解释：[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 10。

提示：
1 <= nums.length <= 105
nums[i] 不是 0 就是 1
0 <= k <= nums.length
*/

#include <iostream>
#include <vector>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int left = 0, zeroCount = 0, maxLength = 0;

    for (int right = 0; right < nums.size(); ++right) {
        // 如果当前元素为 0，增加 zeroCount 计数
        if (nums[right] == 0) {
            zeroCount++;
        }

        // 当窗口内 0 的数量超过了 k，移动左指针 left
        while (zeroCount > k) {
            // 如果窗口左边界元素为 0，减少 zeroCount 计数
            if (nums[left] == 0) {
                zeroCount--;
            }
            // 移动左指针，缩小窗口
            left++;
        }

        // 计算当前窗口长度，并更新最大长度 maxLength
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    // 示例输入
    vector<int> nums1 = { 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0 };
    int k1 = 2;

    vector<int> nums2 = { 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1 };
    int k2 = 3;

    // 调用函数并输出结果
    cout << "示例 1 输出: " << longestOnes(nums1, k1) << endl;
    cout << "示例 2 输出: " << longestOnes(nums2, k2) << endl;

    return 0;
}
