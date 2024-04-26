//在多个线程中递增一个共享变量
//确保递增操作没有数据竞争

#include<iostream>
#include<mutex>	
#include<thread>
#include<vector>

std::mutex mtx;
int shared_value = 0;

void increment(int num_itrtations)
{
	for (int i = 0; i < num_itrtations; ++i)
	{
		std::unique_lock<std::mutex> lock(mtx);//锁住互斥锁，一次只能有一个线程访问
		++shared_value;
		lock.unlock();  //解锁了互斥锁，允许其他线程访问共享资源
	}
}

int main()
{
	const int num_threads = 10;  //使用const一是为了确保可读性，二是防止函数意外更改变量
	const int num_interations_per_thread = 326;
	std::vector<std::thread> threads;  //存储线程对象 std::thread 的集合

	for (int i = 0; i < num_threads; ++i)
	{
		threads.push_back(std::thread(increment, num_interations_per_thread));
	}
	for (std::thread &t:threads)
	{
		t.join();
	}

	std::cout << "最后的值是：" <<shared_value<< std::endl;
	return 0;
}