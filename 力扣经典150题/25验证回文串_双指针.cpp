/*
如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。

字母和数字都属于字母数字字符。

给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。



示例 1：

输入: s = "A man, a plan, a canal: Panama"
输出：true
解释："amanaplanacanalpanama" 是回文串。
示例 2：

输入：s = "race a car"
输出：false
解释："raceacar" 不是回文串。
示例 3：

输入：s = " "
输出：true
解释：在移除非字母数字字符之后，s 是一个空字符串 "" 。
由于空字符串正着反着读都一样，所以是回文串。


提示：

1 <= s.length <= 2 * 105
s 仅由可打印的 ASCII 字符组成
*/

#include <string>
#include <cctype> // 包含用于字符处理的标准库头文件
#include <iostream>

class Solution {
public:
	bool isPalindrome(std::string s) {
		for (char& c : s) {
			c = tolower(c);
		}

		//使用双指针法进行判断
		int left = 0;  
		int right = s.length() - 1;
		while (left < right) {
			while (left < right && !isalnum(s[left])) {
				left++;
			}

			while (left < right && !isalnum(s[right])) {
				right--;
			}
			if (s[left] != s[right]) {
				return false;
			}
			left++;
			right--;
		}
		return true;
	}
};




int main() {
	Solution solution;

	// 测试示例 1
	std::string s1 = "A man, a plan, a canal: Panama";
	std::cout << "Example 1: " << (solution.isPalindrome(s1) ? "true" : "false") << std::endl;

	// 测试示例 2
	std::string s2 = "race a car";
	std::cout << "Example 2: " << (solution.isPalindrome(s2) ? "true" : "false") << std::endl;

	// 测试示例 3
	std::string s3 = " ";
	std::cout << "Example 3: " << (solution.isPalindrome(s3) ? "true" : "false") << std::endl;

	return 0;
}
