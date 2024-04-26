/*
给你一个由 n 个元素组成的整数数组 nums 和一个整数 k 。
请你找出平均数最大且 长度为 k 的连续子数组，并输出该最大平均数。
任何误差小于 10-5 的答案都将被视为正确答案。

示例 1：
输入：nums = [1,12,-5,-6,50,3], k = 4
输出：12.75
解释：最大平均数 (12-5-6+50)/4 = 51/4 = 12.75

示例 2：
输入：nums = [5], k = 1
输出：5.00000

提示：
n == nums.length
1 <= k <= n <= 105
-104 <= nums[i] <= 104
*/

#include <iostream>
#include <vector>

using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    double sum = 0;
    int n = nums.size();

    // 计算初始的前 k 个元素的和
    for (int i = 0; i < k; ++i) {
        sum += nums[i];
    }

    double maxSum = sum;

    // 滑动窗口，依次向右移动
    for (int i = k; i < n; ++i) {
        sum += nums[i] - nums[i - k]; // 窗口右移，更新窗口内的和
        maxSum = max(maxSum, sum); // 更新最大和
    }

    return maxSum / k; // 返回最大平均数
}

int main() {
    vector<int> nums1 = { 1, 12, -5, -6, 50, 3 };
    int k1 = 4;
    cout << "最大平均数为：" << findMaxAverage(nums1, k1) << endl;

    vector<int> nums2 = { 5 };
    int k2 = 1;
    cout << "最大平均数为：" << findMaxAverage(nums2, k2) << endl;

    return 0;
}
