/*
给你一个链表的头节点 head ，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。

如果链表中存在环 ，则返回 true 。 否则，返回 false 。

示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。
示例 2：



输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。
示例 3：



输入：head = [1], pos = -1
输出：false
解释：链表中没有环。
 

提示：

链表中节点的数目范围是 [0, 104]
-105 <= Node.val <= 105
pos 为 -1 或者链表中的一个 有效索引 。
*/




#include <iostream>
#include <vector>
#include <unordered_set>


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        std::unordered_set<ListNode*>seen;
        while (head != nullptr) {
            if (seen.count(head)) {
                return true;
            }
            seen.insert(head);
            head = head->next;
        }
        return false;
    }
};

// 辅助函数，用于创建带环链表并返回头节点
ListNode* createLinkedListWithCycle(std::vector<int>& values, int pos) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* tail = head;
    ListNode* cycleStart = nullptr;
    ListNode* cycleEnd = nullptr;

    // 创建链表
    for (int i = 1; i < values.size(); ++i) {
        tail->next = new ListNode(values[i]);
        tail = tail->next;
        if (i == pos) {
            cycleStart = tail; // 记录环的起始节点
        }
    }

    // 构成环
    if (cycleStart) {
        tail->next = cycleStart;
    }

    return head;
}

int main() {
    // 示例 1：有环的链表
    std::vector<int> values1 = { 3, 2, 0, -4 };
    ListNode* head1 = createLinkedListWithCycle(values1, 1);
    Solution sol;
    std::cout << "Example 1: " << (sol.hasCycle(head1) ? "true" : "false") << std::endl;

    // 示例 2：有环的链表
    std::vector<int> values2 = { 1, 2 };
    ListNode* head2 = createLinkedListWithCycle(values2, 0);
    std::cout << "Example 2: " << (sol.hasCycle(head2) ? "true" : "false") << std::endl;

    // 示例 3：无环的链表
    std::vector<int> values3 = { 1 };
    ListNode* head3 = createLinkedListWithCycle(values3, -1);
    std::cout << "Example 3: " << (sol.hasCycle(head3) ? "true" : "false") << std::endl;

    return 0;
}
