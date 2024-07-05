/*
在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。

你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。
你从其中的一个加油站出发，开始时油箱为空。

给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1 。
如果存在解，则 保证 它是 唯一 的。

 
示例 1:
输入: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
输出: 3
解释:
从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
因此，3 可为起始索引。

示例 2:
输入: gas = [2,3,4], cost = [3,4,3]
输出: -1
解释:
你不能从 0 号或 1 号加油站出发，因为没有足够的汽油可以让你行驶到下一个加油站。
我们从 2 号加油站出发，可以获得 4 升汽油。 此时油箱有 = 0 + 4 = 4 升汽油
开往 0 号加油站，此时油箱有 4 - 3 + 2 = 3 升汽油
开往 1 号加油站，此时油箱有 3 - 3 + 3 = 3 升汽油
你无法返回 2 号加油站，因为返程需要消耗 4 升汽油，但是你的油箱只有 3 升汽油。
因此，无论怎样，你都不可能绕环路行驶一周。
 

提示:
gas.length == n
cost.length == n
1 <= n <= 105
0 <= gas[i], cost[i] <= 104
*/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();  // 获取加油站的数量
        int i = 0;  // 从第 0 个加油站开始

        // 外层循环用于遍历每一个加油站作为起点
        while (i < n) {
            int sumOfGas = 0;  // 当前累计的汽油量
            int sumOfCost = 0;  // 当前累计的消耗量
            int cnt = 0;  // 记录走过的加油站数量

            // 内层循环用于计算从第 i 个加油站开始能否走完一圈
            while (cnt < n) {
                int j = (i + cnt) % n;  // 当前加油站的索引，取模是为了处理环路
                sumOfGas += gas[j];  // 累加当前加油站的汽油量
                sumOfCost += cost[j];  // 累加当前加油站的消耗量

                // 如果累计的消耗量大于汽油量，说明无法继续前进
                if (sumOfCost > sumOfGas) {
                    break;  // 退出内层循环
                }
                cnt++;  // 继续前进到下一个加油站
            }

            // 如果走完了一圈，返回起点索引
            if (cnt == n) {
                return i;
            }
            else {
                // 如果没走完一圈，从下一个加油站开始重新尝试
                i = i + cnt + 1;
            }
        }

        return -1;  // 如果所有加油站都无法完成一圈，返回 -1
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> gas1 = { 1, 2, 3, 4, 5 };
    vector<int> cost1 = { 3, 4, 5, 1, 2 };
    int result1 = solution.canCompleteCircuit(gas1, cost1);
    cout << "示例 1 的输出: " << result1 << endl;  // 应该输出 3

    // 示例 2
    vector<int> gas2 = { 2, 3, 4 };
    vector<int> cost2 = { 3, 4, 3 };
    int result2 = solution.canCompleteCircuit(gas2, cost2);
    cout << "示例 2 的输出: " << result2 << endl;  // 应该输出 -1

    return 0;
}
