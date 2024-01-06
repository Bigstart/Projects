/*
给定一个经过编码的字符串，返回它解码后的字符串。
编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

示例 1：
输入：s = "3[a]2[bc]"
输出："aaabcbc"

示例 2：
输入：s = "3[a2[c]]"
输出："accaccacc"

示例 3：
输入：s = "2[abc]3[cd]ef"
输出："abcabccdcdcdef"

示例 4：
输入：s = "abc3[cd]xyz"
输出："abccdcdcdxyz"

提示：
1 <= s.length <= 30
s 由小写英文字母、数字和方括号 '[]' 组成
s 保证是一个 有效 的输入。
s 中所有整数的取值范围为 [1, 300]
*/


#include <iostream>
#include <stack>
#include <string>



//字符串可以使用   isdigit() 和 isalpha() 函数来检查字符是数字还是字母
class Solution {
public:
    std::string decodeString(std::string s) {
        // 用于存放数字的栈
        std::stack<int> numStack; 

        // 用于存放字符串的栈
        std::stack<std::string> strStack; 

        std::string currentStr = ""; // 当前的字符串
        int num = 0; // 当前的数字

        for (char c : s) {

            // 如果是数字字符
            if (isdigit(c)) { 
                num = num * 10 + (c - '0'); // 计算数字
            }
            else if (isalpha(c)) {        // 如果是字母字符
                currentStr += c; // 拼接字符串
            }
            else if (c == '[') { // 如果是左括号
                numStack.push(num); // 将数字入栈，用于记录重复次数
                strStack.push(currentStr); // 将当前字符串入栈
                num = 0; // 重置数字
                currentStr = ""; // 重置字符串
            }
            else if (c == ']') { // 如果是右括号
                int repeatTimes = numStack.top(); // 获取重复次数
                numStack.pop(); // 弹出数字栈顶元素
                std::string temp = "";
                for (int i = 0; i < repeatTimes; ++i) { // 构造重复字符串
                    temp += currentStr;
                }
                currentStr = strStack.top() + temp; // 结合栈顶的字符串和重复字符串
                strStack.pop(); // 弹出字符串栈顶元素
            }
        }
        return currentStr; // 返回最终解码结果
    }
};

int main() {
    std::string input1 = "3[a]2[bc]";
    std::string input2 = "3[a2[c]]";
    std::string input3 = "20[abc]3[cd]ef";
    std::string input4 = "abc3[cd]xyz";

    Solution solution;
    std::cout << "Output 1: " << solution.decodeString(input1) << std::endl; // 输出：aaabcbc
    std::cout << "Output 2: " << solution.decodeString(input2) << std::endl; // 输出：accaccacc
    std::cout << "Output 3: " << solution.decodeString(input3) << std::endl; // 输出：abcabccdcdcdef
    std::cout << "Output 4: " << solution.decodeString(input4) << std::endl; // 输出：abccdcdcdxyz

    return 0;
}
