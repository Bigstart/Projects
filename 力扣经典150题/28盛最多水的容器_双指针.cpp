/*
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

说明：你不能倾斜容器。



示例 1：



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
#include <vector> // 包含 vector 容器的头文件
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int maxValue = 0;
		int left = 0;
		int right = height.size() - 1;

		while (left < right) {
			// 计算当前容器的面积
			int currentArea = (right - left) * min(height[left], height[right]);
			// 更新最大面积
			maxValue = max(maxValue, currentArea);
			if (height[left] > height[right]) {
				right--;
			}
			else {
				left++;
			}
		}

		return maxValue;
	}
};

int main() {
	// 创建一个 Solution 类的实例
	Solution solution;

	// 创建一个 vector 容器存储输入数据
	vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 }; // 示例输入数据

	// 调用解决方案函数并输出结果
	int result = solution.maxArea(height);
	cout << "最大的容器面积为: " << result << endl;

	return 0;
}
