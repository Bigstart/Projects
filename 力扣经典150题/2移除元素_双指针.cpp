/*
给你一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，并返回移除后数组的新长度。
不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

 
示例 1：
输入：nums = [3,2,2,3], val = 3
输出：2, nums = [2,2]
解释：函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。

示例 2：
输入：nums = [0,1,2,2,3,0,4,2], val = 2
输出：5, nums = [0,1,3,0,4]

提示：
0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100
*/

#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int j = 0; 
    //其实就是移动右指针  左指针的个数代表数组长度  右指针指向的进行判断
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != val) {
            nums[j] = nums[i]; // 将非val元素放入nums[j]的位置
            ++j; // 移动指针j
        }
    }

    return j; 
}

int main() {
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    int len = removeElement(nums, val);

    cout << "移除元素后的新长度为: " << len << endl;
    cout << "nums数组的前" << len << "个元素为: ";
    for (int i = 0; i < len; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
