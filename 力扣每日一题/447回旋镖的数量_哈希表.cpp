/*
给定平面上 n 对 互不相同 的点 points ，其中 points[i] = [xi, yi] 。
回旋镖 是由点 (i, j, k) 表示的元组 ，
其中 i 和 j 之间的距离和 i 和 k 之间的欧式距离相等（需要考虑元组的顺序）。

返回平面上所有回旋镖的数量。

示例 1：
输入：points = [[0,0],[1,0],[2,0]]
输出：2
解释：两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]

示例 2：
输入：points = [[1,1],[2,2],[3,3]]
输出：2

示例 3：
输入：points = [[1,1]]
输出：0

提示：
n == points.length
1 <= n <= 500
points[i].length == 2
-104 <= xi, yi <= 104
所有点都 互不相同
*/

#include <vector>
#include <unordered_map>
#include <iostream>

// 计算回旋镖数量
int numberOfBoomerangs(std::vector<std::vector<int>>& points) {
	int boomerangs = 0;
	for (auto& p : points) {
		// 存储距离和频次的哈希表
		std::unordered_map<int, int> distances;
		for (auto& q : points) {
			// 计算点之间的距离
			int dist = (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
			distances[dist]++;
		}
		// 遍历哈希表计算回旋镖数量
		for (auto& dist_count : distances) {
			boomerangs += dist_count.second * (dist_count.second - 1);
		}
	}
	return boomerangs;
}




// 上面的函数

int main() {
	std::vector<std::vector<int>> points = { {0,0},{1,0},{2,0} };

	int result = numberOfBoomerangs(points);

	std::cout << "Number of boomerangs: " << result << std::endl;

	return 0;
}
