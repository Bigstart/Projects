/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例 1：


输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
示例 2：

输入：l1 = [], l2 = []
输出：[]
示例 3：

输入：l1 = [], l2 = [0]
输出：[0]
 

提示：

两个链表的节点数目范围是 [0, 50]
-100 <= Node.val <= 100
l1 和 l2 均按 非递减顺序 排列
*/


#include <iostream>

// 定义链表节点结构体
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 打印链表的函数，用于调试
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        std::cout << curr->val;
        if (curr->next) {
            std::cout << " -> ";
        }
        curr = curr->next;
    }
    std::cout << std::endl;
}

// 合并两个升序链表的函数
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) {
        return list2;
    }
    else if (list2 == nullptr) {
        return list1;
    }
    else if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

int main() {
    // 创建示例链表 l1 = [1, 2, 4], l2 = [1, 3, 4]
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    // 调用合并函数
    ListNode* mergedList = mergeTwoLists(l1, l2);

    // 打印合并后的链表
    std::cout << "Merged List: ";
    printList(mergedList);

    // 释放链表节点的内存
    ListNode* curr = mergedList;
    while (curr) {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}
