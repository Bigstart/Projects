/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长
子串
 的长度。



示例 1:

输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。


提示：

0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成
*/


#include <iostream>
#include <string>
#include <unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int n = s.length();
        std::unordered_set<char> charSet;
        int maxLength = 0, left = 0, right = 0;

        while (right < n) {
            // 如果右边界字符已经在集合中，移动左边界直到不再有重复字符
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }

            // 将右边界字符加入集合，更新最大长度
            charSet.insert(s[right]);
            maxLength = std::max(maxLength, right - left + 1);
            right++;
        }

        return maxLength;
    }
};

int main() {
    Solution solution;

    // 示例输入
    std::string s1 = "abcabcbb";
    std::string s2 = "bbbbb";
    std::string s3 = "pwwkew";

    // 调用方法计算结果
    int result1 = solution.lengthOfLongestSubstring(s1);
    int result2 = solution.lengthOfLongestSubstring(s2);
    int result3 = solution.lengthOfLongestSubstring(s3);

    // 输出结果
    std::cout << "输入: " << s1 << std::endl;
    std::cout << "输出: " << result1 << std::endl;
    std::cout << std::endl;

    std::cout << "输入: " << s2 << std::endl;
    std::cout << "输出: " << result2 << std::endl;
    std::cout << std::endl;

    std::cout << "输入: " << s3 << std::endl;
    std::cout << "输出: " << result3 << std::endl;

    return 0;
}





//还有一种方法 是利用两个指针的    不是滑动窗口

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 字符串长度
        int n = s.length();
        if (n <= 1) {
            return n;
        }

        int left = 0; // 左指针初始化
        int right = 0; // 右指针初始化
        unordered_set<char> table; // 用于存储字符的哈希集合
        int res = 0; // 结果初始化
        
        // 遍历字符串
        while (right < n) {
            // 如果当前字符不在集合中，则加入集合并移动右指针
            if (table.find(s[right]) == table.end()) {
                table.insert(s[right]);
                right++;
                // 更新最长子串的长度
                res = max(res, right - left);
            } else {
                // 如果当前字符已经在集合中，则移除左指针的字符并移动左指针
                table.erase(s[left]);
                left++;
            }
        }
        
        return res; // 返回结果
    }
};
