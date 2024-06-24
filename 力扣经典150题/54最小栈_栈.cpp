/*
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

实现 MinStack 类:

MinStack() 初始化堆栈对象。
void push(int val) 将元素val推入堆栈。
void pop() 删除堆栈顶部的元素。
int top() 获取堆栈顶部的元素。
int getMin() 获取堆栈中的最小元素。
 

示例 1:

输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

输出：
[null,null,null,null,-3,null,0,-2]

解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
 

提示：

-231 <= val <= 231 - 1
pop、top 和 getMin 操作总是在 非空栈 上调用
push, pop, top, and getMin最多被调用 3 * 104 次
*/



#include <iostream>
#include <stack>

class MinStack {
private:
    std::stack<int> stack;
    std::stack<int> min_stack;

public:
    /** initialize your data structure here. */
    MinStack() {}

    // 将元素val推入堆栈
    void push(int val) {
        stack.push(val);
        if (min_stack.empty() || val <= min_stack.top()) {
            min_stack.push(val);
        }
    }

    // 删除堆栈顶部的元素
    void pop() {
        if (stack.top() == min_stack.top()) {
            min_stack.pop();
        }
        stack.pop();
    }

    // 获取堆栈顶部的元素
    int top() {
        return stack.top();
    }

    // 获取堆栈中的最小元素
    int getMin() {
        return min_stack.top();
    }
};

int main() {
    MinStack minStack;

    // 按照示例进行操作
    minStack.push(-2);
    std::cout << "push(-2)" << std::endl;

    minStack.push(0);
    std::cout << "push(0)" << std::endl;

    minStack.push(-3);
    std::cout << "push(-3)" << std::endl;

    std::cout << "getMin() -> " << minStack.getMin() << std::endl; // 返回 -3

    minStack.pop();
    std::cout << "pop()" << std::endl;

    std::cout << "top() -> " << minStack.top() << std::endl; // 返回 0

    std::cout << "getMin() -> " << minStack.getMin() << std::endl; // 返回 -2

    return 0;
}
