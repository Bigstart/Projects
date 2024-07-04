//单指针 并且开辟了内存空间

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// 定义一个函数，接收一个字符串作为输入，反转其中单词的顺序后返回结果字符串
string reverseWords(string s) {
    // 使用istringstream来分割原始字符串
    istringstream ss(s);
    vector<string> words;  // 创建一个字符串向量，用于存储分割后的单词
    string word;

    // 将分割的单词存入vector
    while (ss >> word) {  // 通过istringstream按空格分割字符串
        words.push_back(word);  // 将每个分割后的单词存入vector
    }

    // 构建翻转后的字符串
    string result;
    for (int i = words.size() - 1; i >= 0; i--) {  // 从最后一个单词开始遍历
        result += words[i];  // 将单词添加到结果字符串中
        if (i > 0) {
            result += " ";  // 在单词之间添加空格，除了最后一个单词
        }
    }
    return result;  // 返回反转后的字符串
}

int main() {
    string s = "the sky is blue";
    string reversed = reverseWords(s);
    cout << reversed << endl;  // 打印反转后的字符串

    s = "  hello world  ";
    reversed = reverseWords(s);
    cout << reversed << endl;

    s = "a good   example";
    reversed = reverseWords(s);
    cout << reversed << endl;

    return 0;
}
