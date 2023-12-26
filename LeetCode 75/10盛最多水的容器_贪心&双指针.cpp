/*
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
返回容器可以储存的最大水量。

输入：[1,8,6,2,5,4,8,3,7]
输出：49 
解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

示例 2：
输入：height = [1,1]
输出：1
 
提示：
n == height.length
2 <= n <= 105
0 <= height[i] <= 104
*/

#include <iostream>
#include <vector>

int maxArea(std::vector<int>& height) {
    int maxwater = 0;
    int left = 0;
    int right = height.size() - 1;

    while (left < right) {
        int temp  = (right - left) * std::min(height[left], height[right]);

        if (maxwater< temp) {
            maxwater = temp;
        }
        if (height[left] > height[right]) {
            right--;
        }
        else {
            left++;
        }
    }
    return maxwater;
}

int main() {
    std::vector<int> heights1 = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    std::cout << "最大的容器容量为: " << maxArea(heights1) << std::endl; // 输出：49

    std::vector<int> heights2 = { 1, 1 };
    std::cout << "最大的容器容量为: " << maxArea(heights2) << std::endl; // 输出：1

    return 0;
}
