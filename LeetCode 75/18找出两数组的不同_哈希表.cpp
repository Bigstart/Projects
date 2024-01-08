/*
给你两个下标从 0 开始的整数数组 nums1 和 nums2 ，请你返回一个长度为 2 的列表 answer ，其中：
answer[0] 是 nums1 中所有 不 存在于 nums2 中的 不同 整数组成的列表。
answer[1] 是 nums2 中所有 不 存在于 nums1 中的 不同 整数组成的列表。
注意：列表中的整数可以按 任意 顺序返回。

示例 1：
输入：nums1 = [1,2,3], nums2 = [2,4,6]
输出：[[1,3],[4,6]]
解释：
对于 nums1 ，nums1[1] = 2 出现在 nums2 中下标 0 处，然而 nums1[0] = 1 和 nums1[2] = 3 没有出现在 nums2 中。因此，answer[0] = [1,3]。
对于 nums2 ，nums2[0] = 2 出现在 nums1 中下标 1 处，然而 nums2[1] = 4 和 nums2[2] = 6 没有出现在 nums2 中。因此，answer[1] = [4,6]。

示例 2：

输入：nums1 = [1,2,3,3], nums2 = [1,1,2,2]
输出：[[3],[]]
解释：
对于 nums1 ，nums1[2] 和 nums1[3] 没有出现在 nums2 中。由于 nums1[2] == nums1[3] ，二者的值只需要在 answer[0] 中出现一次，故 answer[0] = [3]。
nums2 中的每个整数都在 nums1 中出现，因此，answer[1] = [] 。

提示：
1 <= nums1.length, nums2.length <= 1000
-1000 <= nums1[i], nums2[i] <= 1000
*/


#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
* unordered_set
唯一性： unordered_set 中的元素是唯一的，不会存在重复的值。
无序性： 元素在 unordered_set 中没有特定的顺序，与它们被插入的顺序无关。这与 set 不同，后者会按照一定的排序规则来存储元素。
快速查找： 由于内部使用哈希表实现，unordered_set 具有快速的查找性能。平均情况下，查找、插入和删除操作的时间复杂度为 O(1)。

std::unordered_set<int> mySet; // 创建一个存储整数的空unordered_set
mySet.insert(5); // 向unordered_set中插入元素5
mySet.insert(10); // 向unordered_set中插入元素10
mySet.erase(5); // 从unordered_set中删除值为5的元素

for (const auto &element : mySet) {
    // 遍历unordered_set中的所有元素
    // element 为当前遍历到的元素的值
}
*/
vector<vector<int>> findDisappearedNumbers(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());

    vector<int> diff1, diff2;

    for (int num : nums1) {
        if (set2.find(num) == set2.end()) {
            //如果find未找到则返回end()   这表示在num1中有 但是在num2中没有的值 推入diff1
            diff1.push_back(num);
        }
    }

    for (int num : nums2) {
        if (set1.find(num) == set1.end()) {
            diff2.push_back(num);
        }
    }

    return { diff1, diff2 };
}

int main() {
    // 在这里填充测试用例
    vector<int> nums1 = { 1, 2, 3 };
    vector<int> nums2 = { 2, 4, 6 };

    vector<vector<int>> answer = findDisappearedNumbers(nums1, nums2);

    cout << "answer[0]: ";
    for (int num : answer[0]) {
        cout << num << " ";
    }
    cout << endl;

    cout << "answer[1]: ";
    for (int num : answer[1]) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
