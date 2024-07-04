/*
有 n 个人排成一个队列，从左到右 编号为 0 到 n - 1 。
给你以一个整数数组 heights ，每个整数 互不相同，heights[i] 表示第 i 个人的高度。

一个人能 看到 他右边另一个人的条件是这两人之间的所有人都比他们两人 矮 。
更正式的，第 i 个人能看到第 j 个人的条件是 i < j 且 min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], ..., heights[j-1]) 。

请你返回一个长度为 n 的数组 answer ，其中 answer[i] 是第 i 个人在他右侧队列中能 看到 的 人数 。


示例 1：
输入：heights = [10,6,8,5,11,9]
输出：[3,1,2,1,1,0]
解释：
第 0 个人能看到编号为 1 ，2 和 4 的人。
第 1 个人能看到编号为 2 的人。
第 2 个人能看到编号为 3 和 4 的人。
第 3 个人能看到编号为 4 的人。
第 4 个人能看到编号为 5 的人。
第 5 个人谁也看不到因为他右边没人。

示例 2：
输入：heights = [5,1,2,3,10]
输出：[4,1,1,1,0]

提示：
n == heights.length
1 <= n <= 105
1 <= heights[i] <= 105
heights 中所有数 互不相同 。
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 解决问题的函数，计算每个人右侧能看到的人数
vector<int> canSeePersonsCount(vector<int>& heights) {
	//先理解算法规则
	/*
	输入的数组为例子

	从右向左开始
	i=5 数是9，栈为空，没有人比9高，所以数组的对应位置i为0
	将9的索引(5)推入栈，现在栈中是{5}

	i=4 数说11，栈不为空，11比9大，栈顶位置被当前人看到并推出，
	9的位置的数组加1 result = {0, 0, 0, 0, 1, 0}
	现在栈顶索引是{4}

	i=3 数是5 栈不为空 5小于11，所以只能看到11一个人
	5的位置的数组加1  result = {0, 0, 0, 1, 1, 0}
	现在栈为{4,3}

	i=2 数是8 栈不为空 
	8>5，这个人被当前位置的人看到并弹出。
    下一个栈顶是索引4，heights[4]是11，8<11，因此当前循环结束，
	索引2的人能看到两个人，将身高8的人（索引2）推入栈中。
	result = {0, 0, 2, 1, 1, 0}
	当前栈为{4,2}

	i=1 数是6 栈不为空
	6<8 栈顶是索引2，heights[2]是8，6<8，因此当前循环结束
	将身高6的人（索引1）推入栈中。
	result = {0, 1, 2, 1, 1, 0}
	当前栈为{4,2,1}

	i=0 数是10
	栈顶是索引1，heights[1]是6，10>6，这个人被当前位置的人看到并弹出。
    下一个栈顶是索引2，heights[2]是8，10>8，这个人也被当前位置的人看到并弹出。
    下一个栈顶是索引4，heights[4]是11，10<11，因此当前循环结束，
	*/
	int n = heights.size();
	vector<int> result(n);
	stack<int> st;   //创建一个栈

	for (int i = n - 1; i >= 0; --i) {
		while (!st.empty() && heights[i] > heights[st.top()])
		{
			st.pop();    // 弹出栈顶元素，因为他被当前人挡住了
			result[i]++;  // 当前人能看到栈顶的这个人  位置索引上加1
		}

		//判断他身后的人比他高时
		if (!st.empty()) {
			result[i]++;
		}

		st.push(i);
	}
	return result;
}

int main() {
	// 在这里读取输入
	// 例如：读取 heights 数组
	vector<int> heights = { 10, 6, 8, 5, 11, 9 };

	// 调用解决问题的函数
	vector<int> answer = canSeePersonsCount(heights);

	// 输出结果
	cout << "输出：";
	for (int i = 0; i < answer.size(); ++i) {
		cout << answer[i] << " ";
	}
	cout << endl;

	return 0;
}
