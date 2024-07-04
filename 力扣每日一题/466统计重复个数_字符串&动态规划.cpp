/*
定义 str = [s, n] 表示 str 由 n 个字符串 s 连接构成。

例如，str == ["abc", 3] =="abcabcabc" 。
如果可以从 s2 中删除某些字符使其变为 s1，则称字符串 s1 可以从字符串 s2 获得。

例如，根据定义，s1 = "abc" 可以从 s2 = "abdbec" 获得，仅需要删除加粗且用斜体标识的字符。
现在给你两个字符串 s1 和 s2 和两个整数 n1 和 n2 。
由此构造得到两个字符串，其中 str1 = [s1, n1]、str2 = [s2, n2] 。
请你找出一个最大整数 m ，以满足 str = [str2, m] 可以从 str1 获得。

示例 1：
输入：s1 = "acb", n1 = 4, s2 = "ab", n2 = 2
输出：2

示例 2：
输入：s1 = "acb", n1 = 1, s2 = "acb", n2 = 1
输出：1

提示：
1 <= s1.length, s2.length <= 100
s1 和 s2 由小写英文字母组成
1 <= n1, n2 <= 106
*/

#include <iostream>
#include <string>

using namespace std;

// 定义函数，找出重复次数最多的 m
int getMaxRepetitions(string s1, int n1, string s2, int n2) {
	int len1 = s1.length();
	int len2 = s2.length();
	int cnt2 = 0;
	int idx = 0;

	// 外层循环遍历 s1 的重复次数 n1
	for (int i = 0; i < n1; ++i) {
		// 内层循环遍历 s1 中的字符
		for (int j = 0; j < len1; ++j) {
			if (s1[j] == s2[idx]) {
				++idx;// 匹配成功，移动 s2 的匹配位置
				if (idx == len2) {
					cnt2++;  // 如果 s2 的匹配位置移动到末尾，重置为 s2 的开头
					idx = 0;
				}
			}
		}
	}
	return cnt2 / n2;// 返回最大整数 m
}

// 主函数，用于测试 getMaxRepetitions 函数
int main() {
	string s1 = "movelight";
	int n1 = 10;
	string s2 = "mt";
	int n2 = 2;

	int result = getMaxRepetitions(s1, n1, s2, n2);
	cout << "输出：" << result << endl; // 打印输出结果

	return 0;
}
