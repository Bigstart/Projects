/*
两数之和 II - 输入有序数组
给你一个下标从 1 开始的整数数组 numbers ，该数组已按 非递减顺序排列  ，请你从数组中找出满足相加之和等于目标数 target 的两个数。如果设这两个数分别是 numbers[index1] 和 numbers[index2] ，则 1 <= index1 < index2 <= numbers.length 。

以长度为 2 的整数数组 [index1, index2] 的形式返回这两个整数的下标 index1 和 index2。

你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。

你所设计的解决方案必须只使用常量级的额外空间。

 
示例 1：

输入：numbers = [2,7,11,15], target = 9
输出：[1,2]
解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。返回 [1, 2] 。
示例 2：

输入：numbers = [2,3,4], target = 6
输出：[1,3]
解释：2 与 4 之和等于目标数 6 。因此 index1 = 1, index2 = 3 。返回 [1, 3] 。
示例 3：

输入：numbers = [-1,0], target = -1
输出：[1,2]
解释：-1 与 0 之和等于目标数 -1 。因此 index1 = 1, index2 = 2 。返回 [1, 2] 。
 

提示：

2 <= numbers.length <= 3 * 104
-1000 <= numbers[i] <= 1000
numbers 按 非递减顺序 排列
-1000 <= target <= 1000
仅存在一个有效答案

*/

#include <iostream>
#include <vector>

using namespace std;

// 定义函数，寻找满足条件的两个数的下标
vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0;             // 定义左指针，指向数组的开头
    int right = numbers.size() - 1;  // 定义右指针，指向数组的末尾

    while (left < right) {
        int sum = numbers[left] + numbers[right];  // 计算当前左右指针所指的两个数的和

        if (sum == target) {
            return { left + 1, right + 1 };  // 如果和等于目标数，返回两个数的下标
        }
        else if (sum < target) {
            left++;  // 如果和小于目标数，增加左指针以增加和
        }
        else {
            right--;  // 如果和大于目标数，减小右指针以减小和
        }
    }

    return {};  // 如果没有找到满足条件的两个数，返回空数组
}

int main() {
    vector<int> numbers = { 2, 7, 11, 15 };  // 输入有序数组
    int target = 9;  // 目标和

    vector<int> result = twoSum(numbers, target);  // 调用函数找到满足条件的两个数的下标

    if (!result.empty()) {
        cout << "满足条件的下标为：" << result[0] << " 和 " << result[1] << endl;
    }
    else {
        cout << "没有找到满足条件的数" << endl;
    }

    return 0;
}
