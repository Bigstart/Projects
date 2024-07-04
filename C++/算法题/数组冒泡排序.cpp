#include <iostream>


void bubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
	}
}

int main()
{
	int arr[] = { 64, 34, 25, 12, 22, 11, 90 }; //静态初始化数组

	/*动态分配数组，使用new关键字
	int size = 7;
	int* arr = new int[size];
	使用数组
	delete[] arr;  //释放内存*/

	/*使用std::vector 动态数组容器
	#include <vector>
	std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
	*/

	int n = sizeof(arr) / sizeof(arr[0]);
	std::cout << "排序前的数组:" << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	bubbleSort(arr, n);
	std::cout << "排序后的数组:" << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}

}
