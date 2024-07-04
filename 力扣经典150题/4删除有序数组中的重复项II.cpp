/*
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，
使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。


示例 1：
输入：nums = [1,1,1,2,2,3]
输出：5, nums = [1,1,2,2,3]
解释：函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3。 不需要考虑数组中超出新长度后面的元素。

示例 2：
输入：nums = [0,0,1,1,1,1,2,3,3]
输出：7, nums = [0,0,1,1,2,3,3]
解释：函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3。不需要考虑数组中超出新长度后面的元素。

提示
1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
nums 已按升序排列
*/

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n <= 2) return n;

    int count = 2; // 初始化新数组长度为 2，因为前两个元素一定是要保留的
    for (int i = 2; i < n; ++i) {
        if (nums[i] != nums[count - 2]) {
            nums[count] = nums[i];
            ++count;
            //当前元素 nums[i] 与倒数第二个保留的元素 nums[count - 2] 不相等，就将当前元素复制到 nums[count] 的位置
        }
    }
    return count;


    //int slow = 2, fast = 2;
    //while (fast < n) {
    //    if (nums[slow - 2] != nums[fast]) {
    //        nums[slow] = nums[fast];
    //        ++slow;
    //    }
    //    ++fast;
    //}
    //return slow;

}

int main() {
    vector<int> nums = { 1, 1, 1, 2, 2, 3 };

    int length = removeDuplicates(nums);

    cout << "New Length: " << length << endl;
    cout << "Modified Array: ";
    for (int i = 0; i < length; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
