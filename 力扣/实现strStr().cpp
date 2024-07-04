/*
给两个字符串 haystack 和 needle 
在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
如果 needle 不是 haystack 的一部分，则返回  -1 。

示例 1：
输入：haystack = "sadbutsad", needle = "sad"
输出：0
解释："sad" 在下标 0 和 6 处匹配。
第一个匹配项的下标是 0 ，所以返回 0 。

示例 2：
输入：haystack = "leetcode", needle = "leeto"
输出：-1
解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。

提示：
1 <= haystack.length, needle.length <= 104
haystack 和 needle 仅由小写英文字符组成

*/


#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle) {

    int m = haystack.size();
    int n = needle.size();

    for (int i = 0; i <= m - n; i++)
    {
        int j = 0;
        while (j < n && haystack[i + j] == needle[j])
        {
            j++;
        }
        if (j == n)
        {
            return i;
        }
    }
    return -1;
}

int main() {
    string haystack = "fdsadbutsad";
    string needle = "sad";
    int result = strStr(haystack, needle);
    cout << "匹配项的下标是：" << result << endl;

    haystack = "leetcode";
    needle = "leeto";
    result = strStr(haystack, needle);
    cout << "匹配项的下标是：" << result << endl;

    return 0;
}
