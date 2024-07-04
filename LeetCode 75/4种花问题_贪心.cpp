/*
假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。
可是，花不能种植在相邻的地块上，它们会争夺水源，两者都会死去。

给你一个整数数组 flowerbed 表示花坛，由若干 0 和 1 组成，
其中 0 表示没种植花，1 表示种植了花。另有一个数 n ，
能否在不打破种植规则的情况下种入 n 朵花？能则返回 true ，不能则返回 false 。


示例 1：
输入：flowerbed = [1,0,0,0,1], n = 1
输出：true

示例 2：
输入：flowerbed = [1,0,0,0,1], n = 2
输出：false

提示：
1 <= flowerbed.length <= 2 * 104
flowerbed[i] 为 0 或 1
flowerbed 中不存在相邻的两朵花
0 <= n <= flowerbed.length
*/

/*这里列举一下  例如 1  0  0  0  1
可以种植花的位置数是 p=[j-i-3]=1
例如 1  0  0  0  0  1
可以种植花的位置数是 p=[j-i-3]=2  但是只能种一朵
所以可以求出无论p是奇数还是偶数，都是最多可以在该范围内种植(p+1)/2朵花
即最多可以在该范围内种植(j−i−2)/2朵花。
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int count = 0; //计数器，记录可以种植花的数量
		int m = flowerbed.size(); //花坛长度
		int prev = -1;//上一个已种花的位置
		for (int i = 0; i < m; i++) {
			if (flowerbed[i] == 1) {//如果当前位置已经种了
				if (prev < 0) {
					count += i / 2;
				}
				else {
					count += (i - prev - 2) / 2;  //在两朵花之间能种植的花的数量
				}
				if (count >= n) {
					return true;
				}
				prev = i;   //更新上一个已种花的位置
			}
		}
		if (prev < 0) {
			count += (m + 1) / 2;//如果花坛上没有已经种植的花
		}
		else {
			count += (m - prev - 1) / 2;//在最后一朵花之后能种的花
		}

		return count >= n; // 判断能否种入n朵花
	}
};

int main() {
	// 测试用例
	vector<int> flowerbed = { 1, 0, 0, 0, 1, 0, 0, 0 };
	int n = 3;
	Solution solution;
	bool result = solution.canPlaceFlowers(flowerbed, n);
	// 打印结果
	cout << (result ? "true" : "false") << endl;
	return 0;
}
