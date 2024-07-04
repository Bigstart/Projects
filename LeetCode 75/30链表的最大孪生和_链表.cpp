/*
在一个大小为 n 且 n 为 偶数 的链表中，对于 0 <= i <= (n / 2) - 1 的 i ，
第 i 个节点（下标从 0 开始）的孪生节点为第 (n-1-i) 个节点 。

比方说，n = 4 那么节点 0 是节点 3 的孪生节点，
节点 1 是节点 2 的孪生节点。这是长度为 n = 4 的链表中所有的孪生节点。
孪生和 定义为一个节点和它孪生节点两者值之和。

给你一个长度为偶数的链表的头节点 head ，请你返回链表的 最大孪生和 。


示例 1：
输入：head = [5,4,2,1]
输出：6
解释：
节点 0 和节点 1 分别是节点 3 和 2 的孪生节点。孪生和都为 6 。
链表中没有其他孪生节点。
所以，链表的最大孪生和是 6 。

示例 2：
输入：head = [4,2,2,3]
输出：7
解释：
链表中的孪生节点为：
- 节点 0 是节点 3 的孪生节点，孪生和为 4 + 3 = 7 。
- 节点 1 是节点 2 的孪生节点，孪生和为 2 + 2 = 4 。
所以，最大孪生和为 max(7, 4) = 7 。

示例 3：
输入：head = [1,100000]
输出：100001
解释：
链表中只有一对孪生节点，孪生和为 1 + 100000 = 100001 。

提示:
链表的节点数目是 [2, 105] 中的 偶数 。
1 <= Node.val <= 105
*/


#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

int pairSum(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // 反转链表
    ListNode* last = slow->next;
    while (last->next) {
        ListNode* cur = last->next;
        last->next = cur->next;
        cur->next = slow->next;
        slow->next = cur;
    }
    int ans = 0;
    ListNode* x = head;
    ListNode* y = slow->next;
    while (y) {
        ans = max(ans, x->val + y->val);
        x = x->next;
        y = y->next;
    }
    return ans;
}


// 补全 main 函数用于测试
int main() {
    // 创建链表 [5,4,2,1]
    ListNode* head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    // 调用函数计算最大孪生和
    int result = pairSum(head);

    // 输出结果
    std::cout << "最大孪生和为: " << result << std::endl;

    return 0;
}
