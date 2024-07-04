/*
给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。


示例 1:
输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右轮转 1 步: [7,1,2,3,4,5,6]
向右轮转 2 步: [6,7,1,2,3,4,5]
向右轮转 3 步: [5,6,7,1,2,3,4]

示例 2:
输入：nums = [-1,-100,3,99], k = 2
输出：[3,99,-1,-100]
解释:
向右轮转 1 步: [99,-1,-100,3]
向右轮转 2 步: [3,99,-1,-100]


提示：

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
*/

#include <vector>
#include<iostream>

void rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n; //  取模   确保 k 在 [0, n) 范围内

    // 创建一个额外的数组来存储旋转后的结果
    std::vector<int> result(n);

    // 将 nums 中的元素根据旋转后的位置存储到 result 数组中
    for (int i = 0; i < n; ++i) {
        result[(i + k) % n] = nums[i];
        //偏移量
        /*
        假设数组长度 n 为 7，我们要将数组向右旋转 k = 3 步。那么根据上面的偏移量公式：

        当 i = 0 时，(0 + 3) % 7 = 3 % 7 = 3，即原来下标为 0 的元素被旋转到了下标为 3 的位置。
        当 i = 1 时，(1 + 3) % 7 = 4 % 7 = 4，即原来下标为 1 的元素被旋转到了下标为 4 的位置。
        */
    }

    // 将 result 数组中的元素复制回原始数组 nums
    nums = result;
}

void printVector(const std::vector<int>& nums) {
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
int main() {
    std::vector<int> nums1 = { 1, 2, 3, 4, 5, 6, 7 };
    int k1 = 3;
    rotate(nums1, k1);
    std::cout << "示例 1 输出：";
    printVector(nums1);

    std::vector<int> nums2 = { -1, -100, 3, 99 };
    int k2 = 2000;
    rotate(nums2, k2);
    std::cout << "示例 2 输出：";
    printVector(nums2);

    return 0;
}