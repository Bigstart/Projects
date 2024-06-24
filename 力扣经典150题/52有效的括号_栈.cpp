/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
 

示例 1：

输入：s = "()"
输出：true
示例 2：

输入：s = "()[]{}"
输出：true
示例 3：

输入：s = "(]"
输出：false
 

提示：

1 <= s.length <= 104
s 仅由括号 '()[]{}' 组成
*/


#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>

bool isValid(const std::string& s) {
    std::stack<char> stack;
    std::unordered_map<char, char> matching_bracket = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        }
        else {
            if (stack.empty() || stack.top() != matching_bracket[ch]) {
                return false;  // 括号不匹配
            }
            stack.pop();
        }
    }

    return stack.empty();  // 检查是否所有括号都匹配
}

int main() {
    // 示例测试
    std::string s1 = "()";
    std::string s2 = "()[]{}";
    std::string s3 = "(]";

    std::cout << "s1: " << s1 << " -> " << (isValid(s1) ? "true" : "false") << std::endl;
    std::cout << "s2: " << s2 << " -> " << (isValid(s2) ? "true" : "false") << std::endl;
    std::cout << "s3: " << s3 << " -> " << (isValid(s3) ? "true" : "false") << std::endl;

    return 0;
}
