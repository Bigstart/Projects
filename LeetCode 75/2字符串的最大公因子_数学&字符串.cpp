/*
对于字符串 s 和 t，只有在 s = t + ... + t（t 自身连接 1 次或多次）时，我们才认定 “t 能除尽 s”。
给定两个字符串 str1 和 str2 。返回 最长字符串 x，要求满足 x 能除尽 str1 且 x 能除尽 str2 。


示例 1：
输入：str1 = "ABCABC", str2 = "ABC"
输出："ABC"

示例 2：
输入：str1 = "ABABAB", str2 = "ABAB"
输出："AB"

示例 3：
输入：str1 = "LEET", str2 = "CODE"
输出：""

提示：
1 <= str1.length, str2.length <= 1000
str1 和 str2 由大写英文字母组成
*/

#include <iostream>
#include <string>

using namespace std;

string gcdOfStrings(string str1, string str2) {
    if (str1 + str2 != str2 + str1) {
        return "";
    }

    int len1 = str1.length();
    int len2 = str2.length();
    int gcd = 1;
    while (len2 != 0)  //辗转相除法
    {
        int temp = len2;
        len2 = len1 % len2;
        len1 = temp;
    }
    return str1.substr(0, len1);   
    //substr() 是 C++ 标准库中 std::string 类的成员函数之一，用于获取字符串的子串。
    //string substr (size_t pos, size_t len) const;
        //pos：子串的起始位置（索引）。从零开始计数。
        //len：子串的长度。
}

int main() {
    string str1 = "AAAAA";
    string str2 = "AA";

    string result = gcdOfStrings(str1, str2);
    cout << "最长公因子为: " << result << endl;

    return 0;
}
