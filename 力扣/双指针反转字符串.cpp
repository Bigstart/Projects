//双指针原地反转字符串，不开辟新的内存空间
#include <iostream>
#include <vector>

using namespace std;

void reverseString(vector<char>& s) {
    int left = 0;
    int right = s.size() - 1;

    while (left<right)
    {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

int main() {
    vector<char> s1 = { 'h', 'e', 'l', 'l', 'o' };
    vector<char> s2 = { 'H', 'a', 'n', 'n', 'a', 'h' };

    reverseString(s1);
    reverseString(s2);

    cout << "反转后的字符串1: ";
    for (char c : s1) {
        cout << c << " ";
    }
    cout << endl;

    cout << "反转后的字符串2: ";
    for (char c : s2) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
