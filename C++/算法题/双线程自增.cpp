#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>


std::mutex mtx;
std::condition_variable cv;
int sum = 0;
bool isThread1Turn = true;

void increment() {
	for (int i = 0; i < 50; i++) {
		std::unique_lock<std::mutex> lock(mtx);
		cv.wait(lock, [] { return isThread1Turn; });
		//然后使用 cv.wait 等待条件变量满足，即 isThread1Turn 为 true。
		//一旦条件满足，线程执行递增操作，
		//通过 cv.notify_one() 通知另一个线程可以执行。
		sum++;
		std::cout << "Thread 1: " << sum << std::endl;
		isThread1Turn = false;
		cv.notify_one();
	}
}

void decrement() {
	for (int i = 0; i < 50; i++) {
		std::unique_lock<std::mutex> lock(mtx);    //对互斥锁进行上锁
		cv.wait(lock, [] { return !isThread1Turn; });

		sum++;
		std::cout << "Thread 2: " << sum << std::endl;
		isThread1Turn = true;
		cv.notify_one();
	}
}

int main() {
	std::thread t1(increment);
	std::thread t2(decrement);

	t1.join();
	t2.join();

	// 添加一次通知，以确保两个线程在退出之前都有机会执行一次
	cv.notify_one();


	std::cout << "Final sum: " << sum << std::endl;

	return 0;
}