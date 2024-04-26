/*
给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。

示例 1：
输入：nums = [3,2,3]
输出：3

示例 2：
输入：nums = [2,2,1,1,1,2,2]
输出：2

提示：
n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109

*/


#include <vector>
#include <iostream>
#include <vector>
int majorityElement(std::vector<int>& nums) {
    int count = 0;
    int candidate;
    //摩尔投票法
    /*
    会议大厅站满了投票代表，每个都有一个牌子上面写着自己所选的候选人的名字。
    然后选举意见不合的(所选的候选人不同)两个人，会打一架，并且会同时击倒对方。
    显而易见，如果一个人拥有的选票比其它所有人加起来的选票还要多的话，
    这个候选人将会赢得这场“战争”，当混乱结束，最后剩下的那个代表(可能会有多个)将会来自多数人所站的阵营。
    但是如果所有参加候选人的选票都不是大多数(选票都未超过一半)，
    那么最后站在那的代表(一个人)并不能代表所有的选票的大多数。
    因此，当某人站到最后时，需要统计他所选的候选人的选票是否超过一半(包括倒下的)，来判断选票结果是否有效。 
    */
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        if (num == candidate) {
            count++;
        }
        else {
            count--;
        }
    }

    return candidate;
}




// 在这里插入 majorityElement 函数

int main() {
    // 测试样例
    std::vector<int> nums1 = { 3, 2, 3 };
    std::cout << "示例 1 输出：" << majorityElement(nums1) << std::endl;

    std::vector<int> nums2 = { 1,1,2,3,1,4,1,};
    std::cout << "示例 2 输出：" << majorityElement(nums2) << std::endl;

    return 0;
}

