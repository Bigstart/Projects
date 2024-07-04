/*
给你一个整数数组 nums 和一个整数 k 。
每一步操作中，你需要从数组中选出和为 k 的两个整数，并将它们移出数组。
返回你可以对数组执行的最大操作数。


示例 1：
输入：nums = [1,2,3,4], k = 5
输出：2
解释：开始时 nums = [1,2,3,4]：
- 移出 1 和 4 ，之后 nums = [2,3]
- 移出 2 和 3 ，之后 nums = []
不再有和为 5 的数对，因此最多执行 2 次操作。

示例 2：
输入：nums = [3,1,3,4,3], k = 6
输出：1
解释：开始时 nums = [3,1,3,4,3]：
- 移出前两个 3 ，之后nums = [1,4,3]
不再有和为 6 的数对，因此最多执行 1 次操作。

提示：
1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= 109
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 定义一个函数，计算数组中能组成和为给定 k 的最大操作数
int maxOperations(vector<int>& nums, int k) {
    // 创建一个无序哈希表，用于存储数组中每个数字的出现频率
    unordered_map<int, int> freq;
    int count = 0; // 记录操作次数

    // 遍历数组
    for (int num : nums) {
        int complement = k - num; // 计算当前数字的补数
        // 如果补数存在于哈希表中并且频率大于 0，则找到了一对数字，可以执行操作
        if (freq.find(complement) != freq.end() && freq[complement] > 0) {
            count++; // 增加操作次数
            freq[complement]--; // 减少补数的频率
        }
        else {
            freq[num]++; // 增加当前数字的频率
        }
    }

    return count; // 返回操作次数
}

int main() {
    vector<int> nums1 = { 1, 2, 3, 4 };
    int k1 = 5;
    cout << "数组 [1, 2, 3, 4] 中最多可执行的操作次数为：" << maxOperations(nums1, k1) << endl;

    vector<int> nums2 = { 3, 1, 3, 4, 3 };
    int k2 = 6;
    cout << "数组 [3, 1, 3, 4, 3] 中最多可执行的操作次数为：" << maxOperations(nums2, k2) << endl;

    return 0;
}
