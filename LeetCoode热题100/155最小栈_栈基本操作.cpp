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
#include <limits>

class MinStack {
private:
	std::stack<int> data_stack; // 主栈，存储栈的元素
	std::stack<int> min_stack;  // 辅助栈，存储当前的最小元素

public:
	/** initialize your data structure here. */
	MinStack() {
		// 构造函数，初始化栈
	}

	void push(int val) {
		data_stack.push(val);  // 将元素压入主栈

		// 更新最小栈
		if (min_stack.empty() || val <= min_stack.top()) {
			min_stack.push(val);  // 如果辅助栈为空或者 val <= 当前最小栈顶，则压入最小栈
		}
	}

	void pop() {
		if (!data_stack.empty()) {
			int top_val = data_stack.top();  // 获取主栈顶部元素
			data_stack.pop();  // 弹出主栈顶部元素

			// 如果弹出的元素是当前最小元素，则同时从最小栈中弹出
			if (top_val == min_stack.top()) {
				min_stack.pop();
			}
		}
	}

	int top() {
		if (!data_stack.empty()) {
			return data_stack.top();  // 返回主栈顶部元素
		}
		return std::numeric_limits<int>::min();  // 栈为空时返回一个最小值
	}

	int getMin() {
		if (!min_stack.empty()) {
			return min_stack.top();  // 返回当前最小元素
		}
		return std::numeric_limits<int>::min();  // 栈为空时返回一个最小值
	}
};

int main() {
	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	std::cout << "getMin: " << minStack.getMin() << std::endl; // 输出 -3
	minStack.pop();
	std::cout << "top: " << minStack.top() << std::endl; // 输出 0
	std::cout << "getMin: " << minStack.getMin() << std::endl; // 输出 -2

	return 0;
}
