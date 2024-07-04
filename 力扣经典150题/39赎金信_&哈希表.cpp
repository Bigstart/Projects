/*
给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

如果可以，返回 true ；否则返回 false 。

magazine 中的每个字符只能在 ransomNote 中使用一次。



示例 1：

输入：ransomNote = "a", magazine = "b"
输出：false
示例 2：

输入：ransomNote = "aa", magazine = "ab"
输出：false
示例 3：

输入：ransomNote = "aa", magazine = "aab"
输出：true


提示：

1 <= ransomNote.length, magazine.length <= 105
ransomNote 和 magazine 由小写英文字母组成
*/

#include <iostream>
#include <unordered_map>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> charCount;

    // 统计 magazine 中每个字符的出现次数
    for (char ch : magazine) {
        charCount[ch]++;
    }

    // 遍历 ransomNote，逐个检查字符在 magazine 中是否足够
    for (char ch : ransomNote) {
        if (charCount[ch] > 0) {
            // 如果 magazine 中有足够的字符，则减少对应字符的数量
            charCount[ch]--;
        }
        else {
            // 如果 magazine 中没有足够的字符，则无法构成 ransomNote
            return false;
        }
    }

    // 如果遍历完 ransomNote 后仍然没有问题，则可以构成 ransomNote
    return true;
}

int main() {
    // 测试样例
    string ransomNote1 = "a", magazine1 = "b";
    cout << "Test Case 1: " << (canConstruct(ransomNote1, magazine1) ? "true" : "false") << endl;

    string ransomNote2 = "aa", magazine2 = "ab";
    cout << "Test Case 2: " << (canConstruct(ransomNote2, magazine2) ? "true" : "false") << endl;

    string ransomNote3 = "aa", magazine3 = "aab";
    cout << "Test Case 3: " << (canConstruct(ransomNote3, magazine3) ? "true" : "false") << endl;

    return 0;
}
