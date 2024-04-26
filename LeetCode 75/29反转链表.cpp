#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        /*
        我们有两个指针：prev 和 current。

        prev 指向已经反转好的部分，初始时为 nullptr。
        current 指向当前需要反转的节点。
        我们要做的就是将 current 指向的节点反转，
        并移动指针，不断重复直到遍历完整个链表。

        例如，链表是 1 -> 2 -> 3。

        初始时，prev 是空的，current 指向节点 1。
        我们需要将 1 反转，所以首先把 1 的 next 指向 prev，也就是空的，
        所以变成 1 -> nullptr，此时 prev 变成 1，current 变成 2。

        然后，我们继续，把 2 的 next 指向 prev，也就是 1，
        变成 2 -> 1 -> nullptr，此时 prev 变成 2，current 变成 3。

        最后，把 3 的 next 指向 prev，也就是 2，
        变成 3 -> 2 -> 1 -> nullptr，此时 prev 变成 3，current 变成 nullptr。


        最重要的是  上一个是谁  我是谁   下一个是谁
        */


        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current != nullptr) {
            ListNode* nextTemp = current->next; // 暂存当前节点的下一个节点
            current->next = prev; // 当前节点指向前一个节点，实现反转
            prev = current; // 更新前一个节点为当前节点
            current = nextTemp; // 更新当前节点为下一个节点
        }

        return prev; // 返回新的头节点
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;

    // Creating a sample linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original List: ";
    printList(head);

    head = solution.reverseList(head);

    std::cout << "Reversed List: ";
    printList(head);

    return 0;
}
