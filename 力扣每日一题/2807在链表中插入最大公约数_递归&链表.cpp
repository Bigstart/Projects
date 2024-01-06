/*
给你一个链表的头 head ，每个结点包含一个整数值。
在相邻结点之间，请你插入一个新的结点，结点值为这两个相邻结点值的 最大公约数 。
请你返回插入之后的链表。
两个数的 最大公约数 是可以被两个数字整除的最大正整数。

示例 1：
输入：head = [18,6,10,3]
输出：[18,6,6,2,10,1,3]
- 18 和 6 的最大公约数为 6 ，插入第一和第二个结点之间。
- 6 和 10 的最大公约数为 2 ，插入第二和第三个结点之间。
- 10 和 3 的最大公约数为 1 ，插入第三和第四个结点之间。
所有相邻结点之间都插入完毕，返回链表。

示例 2：
输入：head = [7]
输出：[7]
没有相邻结点，所以返回初始链表。

提示：

链表中结点数目在 [1, 5000] 之间。
1 <= Node.val <= 1000
*/


#include <iostream>
#include <cmath>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* insertGreatestCommonDivisors(ListNode* head) {
    ListNode* current = head;
    while (current && current->next) { // 遍历链表，确保当前结点及下一个结点都存在
        int num1 = current->val; // 获取当前结点值
        int num2 = current->next->val; // 获取下一个结点值

        int great = 0;
        while (num2) { // 使用辗转相除法计算最大公约数
            int temp = num1 % num2;
            num1 = num2;
            num2 = temp;
        }
        great = num1; // 计算结果是最大公约数

        ListNode* newNode = new ListNode(great); // 创建新结点
        newNode->next = current->next; // 将新结点插入到当前结点和下一个结点之间
        current->next = newNode; // 更新当前结点的 next 指针指向新结点
        current = current->next->next; // 移动到下一个结点位置（因为插入了一个结点，所以需要指两次向下）
    }
    return head;
}

// 释放链表内存
void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // 创建链表
    ListNode* head = new ListNode(18);
    head->next = new ListNode(6);
    head->next->next = new ListNode(10);
    head->next->next->next = new ListNode(3);

    // 插入最大公约数并输出链表
    ListNode* updatedHead = insertGreatestCommonDivisors(head);
    ListNode* current = updatedHead;
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // 释放链表内存
    deleteList(updatedHead);

    return 0;
}
