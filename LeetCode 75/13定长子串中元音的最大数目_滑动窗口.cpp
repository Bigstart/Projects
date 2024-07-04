/*
给你字符串 s 和整数 k 。
请返回字符串 s 中长度为 k 的单个子字符串中可能包含的最大元音字母数。
英文中的 元音字母 为（a, e, i, o, u）。

示例 1：
输入：s = "abciiidef", k = 3
输出：3
解释：子字符串 "iii" 包含 3 个元音字母。

示例 2：
输入：s = "aeiou", k = 2
输出：2
解释：任意长度为 2 的子字符串都包含 2 个元音字母。

示例 3：
输入：s = "leetcode", k = 3
输出：2
解释："lee"、"eet" 和 "ode" 都包含 2 个元音字母。

示例 4：
输入：s = "rhythms", k = 4
输出：0
解释：字符串 s 中不含任何元音字母。

示例 5：
输入：s = "tryhard", k = 4
输出：1
 
提示：
1 <= s.length <= 10^5
s 由小写英文字母组成
1 <= k <= s.length
*/

#include <string>
#include <iostream>
#include <unordered_set>
using namespace std;

int maxVowels(string s, int k) {
	int maxCount = 0; // 最大元音字母数量
	unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u' }; // 元音字母集合
	int count = 0; // 当前窗口内的元音字母数量

	// 计算初始窗口内的元音字母数量
	for (int i = 0; i < k; ++i) {
		if (vowels.count(s[i])) {
			count++; // 如果当前字符是元音字母，则数量加一
		}
	}
	maxCount = count; // 初始窗口内的元音字母数量为当前最大值

	// 使用滑动窗口计算最大元音字母数量
	for (int i = k; i < s.length(); ++i) {
		if (vowels.count(s[i])) {
			count++; // 如果新增加的字符是元音字母，则数量加一
		}
		if (vowels.count(s[i - k])) {
			count--; // 如果移出窗口的字符是元音字母，则数量减一
		}
		maxCount = max(maxCount, count); // 更新最大元音字母数量
	}

	return maxCount; // 返回最大元音字母数量
}


int main() {
	string s = "abciiidef"; // 测试用例字符串
	int k = 3; // 测试用例长度

	cout << "输入: s = \"" << s << "\", k = " << k << endl;
	int result = maxVowels(s, k); // 调用函数得到结果
	cout << "输出: " << result << endl;

	return 0;
}