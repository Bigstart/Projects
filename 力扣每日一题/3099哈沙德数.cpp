/*
如果一个整数能够被其各个数位上的数字之和整除，则称之为 哈沙德数（Harshad number）。
给你一个整数 x 。如果 x 是 哈沙德数 ，则返回 x 各个数位上的数字之和，否则，返回 -1 。


示例 1：
输入： x = 18
输出： 9
解释：
x 各个数位上的数字之和为 9 。18 能被 9 整除。因此 18 是哈沙德数，答案是 9 。

示例 2：
输入： x = 23
输出： -1
解释：
x 各个数位上的数字之和为 5 。23 不能被 5 整除。因此 23 不是哈沙德数，答案是 -1 。


提示：
1 <= x <= 100
*/


#include <iostream>

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int s = 0;
        for (int y = x; y; y /= 10) {
            s = s + y % 10;
        }

        if (x % s) {
            return -1;
        }
        return s;
    }
};

int main() {
    Solution sol;
    
    // 测试用例
    int num1 = 18;
    int num2 = 19;
    int num3 = 21;
    
    std::cout << "sumOfTheDigitsOfHarshadNumber(" << num1 << ") = " << sol.sumOfTheDigitsOfHarshadNumber(num1) << std::endl;
    std::cout << "sumOfTheDigitsOfHarshadNumber(" << num2 << ") = " << sol.sumOfTheDigitsOfHarshadNumber(num2) << std::endl;
    std::cout << "sumOfTheDigitsOfHarshadNumber(" << num3 << ") = " << sol.sumOfTheDigitsOfHarshadNumber(num3) << std::endl;
    
    return 0;
}
