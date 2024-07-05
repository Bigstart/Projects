/*
n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。

你需要按照以下要求，给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻两个孩子评分更高的孩子会获得更多的糖果。
请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。

 

示例 1：

输入：ratings = [1,0,2]
输出：5
解释：你可以分别给第一个、第二个、第三个孩子分发 2、1、2 颗糖果。
示例 2：

输入：ratings = [1,2,2]
输出：4
解释：你可以分别给第一个、第二个、第三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这满足题面中的两个条件。
 

提示：

n == ratings.length
1 <= n <= 2 * 104
0 <= ratings[i] <= 2 * 104
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;

        // 用于记录每个孩子的糖果数，初始化为1，因为每个孩子至少分配到1个糖果
        vector<int> candies(n, 1);

        // 从左到右遍历，确保每个孩子的评分高于前一个孩子时，糖果数比前一个孩子多
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // 从右到左遍历，确保每个孩子的评分高于后一个孩子时，糖果数比后一个孩子多
        // 并且在两个条件中取最大值
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        /*
        candies[i + 1] + 1 表示当前孩子 i 应该至少比右边孩子 i + 1 多 1 颗糖果。
        但是由于我们在左到右遍历时已经更新过一次 candies[i]，因此当前的 candies[i] 可能已经满足条件或者更高了。
        这里使用 max(candies[i], candies[i + 1] + 1) 的原因是：
        如果 candies[i] 已经比 candies[i + 1] + 1 大，那么保持 candies[i] 不变。
        如果 candies[i] 比 candies[i + 1] + 1 小，那么更新 candies[i] 为 candies[i + 1] + 1。
        */

        // 计算总的糖果数
        int totalCandies = 0;
        for (int candy : candies) {
            totalCandies += candy;
        }

        return totalCandies;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> ratings1 = { 1, 0, 2 };
    cout << "输入：ratings = [1, 0, 2]" << endl;
    cout << "输出：" << solution.candy(ratings1) << endl; // 输出 5

    // 示例 2
    vector<int> ratings2 = { 1, 2, 2 };
    cout << "输入：ratings = [1, 2, 2]" << endl;
    cout << "输出：" << solution.candy(ratings2) << endl; // 输出 4

    return 0;
}
