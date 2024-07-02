/*
给你一个字符串 s ，请你反转字符串中 单词 的顺序。

单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。

注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

 

示例 1：
输入：s = "the sky is blue"
输出："blue is sky the"

示例 2：
输入：s = "  hello world  "
输出："world hello"
解释：反转后的字符串中不能存在前导空格和尾随空格。

示例 3：
输入：s = "a good   example"
输出："example good a"
解释：如果两个单词间有多余的空格，反转后的字符串需要将单词间的空格减少到仅有一个。
 

提示：
1 <= s.length <= 104
s 包含英文大小写字母、数字和空格 ' '
s 中 至少存在一个 单词
*/





#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>


// 反转字符串中的单词
std::string reverseWords(const std::string& s) {
	// 使用字符串流将输入字符串分割为单词
	std::istringstream stream(s);
	std::vector<std::string> words;
	std::string word;

	// 逐个读取单词并存储在向量中
	while (stream >> word) {
		words.push_back(word);
	}

	// 反转向量中的单词顺序
	std::reverse(words.begin(), words.end());

	// 使用字符串流重新拼接单词
	std::ostringstream result;

	//std::ostringstream 是 C++ 标准库中的一个类，继承自 std::ostream
	//std::ostream 类重载了运算符 <<，使得可以将各种类型的数据（如字符串、整数、浮点数等）插入到流中
	//std::ostringstream 具体来说是一个输出字符串流，它将数据插入到一个内部的 std::string 对象中。

	for (size_t i = 0; i < words.size(); ++i) {
		if (i != 0) {
			result << " ";  // 添加空格分隔符
		}
		result << words[i];
	}

	// 返回拼接后的字符串
	return result.str();

	//.str() 是 std::ostringstream 类的一个成员函数，用来返回流中当前保存的字符串
}


int main() {
	// 示例输入
	std::string s1 = "the sky is blue";
	std::string s2 = "  hello world  ";
	std::string s3 = "a good   example";

	// 打印输出结果
	std::cout << "输入: \"" << s1 << "\"\n输出: \"" << reverseWords(s1) << "\"" << std::endl;
	std::cout << "输入: \"" << s2 << "\"\n输出: \"" << reverseWords(s2) << "\"" << std::endl;
	std::cout << "输入: \"" << s3 << "\"\n输出: \"" << reverseWords(s3) << "\"" << std::endl;

	return 0;
}

