/*
给你一个整数数组 arr，请你帮忙统计数组中每个数的出现次数。
如果每个数的出现次数都是独一无二的，就返回 true；否则返回 false。

示例 1：
输入：arr = [1,2,2,1,1,3]
输出：true
解释：在该数组中，1 出现了 3 次，2 出现了 2 次，3 只出现了 1 次。没有两个数的出现次数相同。

示例 2：
输入：arr = [1,2]
输出：false
示例 3：

输入：arr = [-3,0,1,-3,1,1,1,-3,10,0]
输出：true

提示：
1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000
*/

#include <unordered_map>
#include <unordered_set>
#include <vector>

bool uniqueOccurrences(std::vector<int>& arr) {
    std::unordered_map<int, int> countMap;
    // 统计每个数字出现的次数
    for (int num : arr) {
        countMap[num]++;
    }

    std::unordered_set<int> occurrences;
    // 检查次数是否独一无二
    for (const auto& pair : countMap) {
        if (occurrences.find(pair.second) != occurrences.end()) {
            return false; // 如果出现次数不是独一无二的，返回false
        }
        occurrences.insert(pair.second);
    }
    return true;
}


#include <iostream>
#include <vector>

// uniqueOccurrences 函数的实现（此处省略，可参考之前的代码实现）

int main() {
    std::vector<int> arr1 = { 1, 2, 2, 1, 1, 3,88,88,88,88,88,88 };
    std::vector<int> arr2 = { 1, 2 };
    std::vector<int> arr3 = { -3, 0, 1, -3, 1, 1, 1, -3, 10, 0 };

    std::cout << std::boolalpha; // 使得输出 true/false 而不是 1/0

    std::cout << "arr1 结果: " << uniqueOccurrences(arr1) << std::endl; // 输出 true
    std::cout << "arr2 结果: " << uniqueOccurrences(arr2) << std::endl; // 输出 false
    std::cout << "arr3 结果: " << uniqueOccurrences(arr3) << std::endl; // 输出 true

    return 0;
}
