/*
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
示例 1：

输入：s = "abc", t = "ahbgdc"
输出：true
示例 2：

输入：s = "axc", t = "ahbgdc"
输出：false
*/

#include <iostream>
#include <string>

bool isSubsequence(const std::string& s, const std::string& t) {
    int sIndex = 0;

    // 遍历字符串 t
    for (char c : t) {
        // 如果当前字符匹配，则移动 s 的索引
        if (s[sIndex] == c) {
            sIndex++;
        }
    }

    // 如果 s 的索引已经到达末尾，说明 s 是 t 的子序列
    return sIndex == s.length();
}

int main() {
    std::string s1 = "abc";
    std::string t1 = "ahbgdc";
    std::cout << std::boolalpha << isSubsequence(s1, t1) << std::endl; // 输出 true

    std::string s2 = "axc";
    std::string t2 = "ahbgasdfffdc";
    std::cout << std::boolalpha << isSubsequence(s2, t2) << std::endl; // 输出 false

    return 0;
}

