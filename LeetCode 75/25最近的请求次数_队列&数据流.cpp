/*
写一个 RecentCounter 类来计算特定时间范围内最近的请求。
请你实现 RecentCounter 类
RecentCounter() 初始化计数器，请求数为 0 。
int ping(int t) 在时间 t 添加一个新请求，
其中 t 表示以毫秒为单位的某个时间，
并返回过去 3000 毫秒内发生的所有请求数（包括新请求）。确切地说，返回在 [t-3000, t] 内发生的请求数。
保证 每次对 ping 的调用都使用比之前更大的 t 值。

重点是   并返回过去 3000 毫秒内发生的所有请求数！！！！！！！

示例 1：

输入：
["RecentCounter", "ping", "ping", "ping", "ping"]
[[], [1], [100], [3001], [3002]]
输出：
[null, 1, 2, 3, 3]

解释：
RecentCounter recentCounter = new RecentCounter();
recentCounter.ping(1);     // requests = [1]，范围是 [-2999,1]，返回 1
recentCounter.ping(100);   // requests = [1, 100]，范围是 [-2900,100]，返回 2
recentCounter.ping(3001);  // requests = [1, 100, 3001]，范围是 [1,3001]，返回 3
recentCounter.ping(3002);  // requests = [1, 100, 3001, 3002]，范围是 [2,3002]，返回 3


提示：

1 <= t <= 109
保证每次对 ping 调用所使用的 t 值都 严格递增
至多调用 ping 方法 104 次
*/


#include <queue>
#include<iostream>
using namespace std;

class RecentCounter {
public:
    std::queue<int> q;

    RecentCounter() {}

    int ping(int t) {
        q.push(t); // 将当前请求时间加入队列
        while (!q.empty() && q.front() < t - 3000) {
            // 移除超出时间范围的请求
            q.pop();
        }
        return q.size(); // 返回仍在时间范围内的请求总数
    }
};

/*
recentCounter.ping(1) 返回 1，因为时间范围是 [-2999,1]，只有一个请求发生在这个时间范围内。
recentCounter.ping(100) 返回 2，因为时间范围是 [-2900,100]，有两个请求发生在这个时间范围内（1 和 100）。
recentCounter.ping(3001) 返回 3，因为时间范围是 [1,3001]，有三个请求发生在这个时间范围内（1、100、3001）。
recentCounter.ping(3002) 返回 3，因为时间范围是 [2,3002]，有三个请求发生在这个时间范围内（100、3001、3002）。
*/


int main() {
    RecentCounter recentCounter;

    // 调用 ping 方法并输出结果
    std::cout << recentCounter.ping(1) << std::endl;
    std::cout << recentCounter.ping(100) << std::endl;
    std::cout << recentCounter.ping(3001) << std::endl;
    std::cout << recentCounter.ping(3002) << std::endl;

    return 0;
}
