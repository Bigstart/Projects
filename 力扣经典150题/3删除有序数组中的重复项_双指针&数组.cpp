/*
给你一个 非严格递增排列 的数组 nums ，
请你原地删除重复出现的元素，使每个元素 只出现一次 ，
返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。
然后返回 nums 中唯一元素的个数。

考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：
更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。nums 的其余元素与 nums 的大小不重要。
返回 k 。


示例 1：
输入：nums = [1,1,2]
输出：2, nums = [1,2,_]
解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。


示例 2：
输入：nums = [0,0,1,1,1,2,2,3,3,4]
输出：5, nums = [0,1,2,3,4]
解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。


提示：
1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
nums 已按 非严格递增 排列
*/

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {

    if (nums.empty())
    {
        return 0;
    }
    int  j = 0;
    //j是左指针 指向当前数  i是右指针 指向下一个进行判断
    for (int i = 1; i < nums.size(); i++) {
        if (nums[j] != nums[i]) {
            j++;
            //如果不相等，左指针+1 进行赋值       
            nums[j] = nums[i];
        }
    }
    return j+1;

}

int main() {
    vector<int> nums = { 1, 1, 2 };

    int k = removeDuplicates(nums);

    cout << "唯一元素的个数为: " << k << endl;
    cout << "nums数组的前" << k << "个元素为: ";
    for (int i = 0; i < k; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
