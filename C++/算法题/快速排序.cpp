#include <iostream>


//交换两个元素的函数
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//分区函数，将数组中的元素分为小于基准值和大于基准值的两部分
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];  //选择最后一个元素作为基准值
	int i = low - 1;  // 

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return i + 1;
}
//int arr[] = { 30, 10, 50, 20, 60, 40 };

//快速排序函数
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		//划分数组，并获取划分点
		int pi = partition(arr, low, high);

		//递归地对划分后的两部分进行排序
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int main() {
	int arr[] = { 30, 10, 50, 20, 60, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);

	quickSort(arr, 0, n-1);
	std::cout << "排序后的数组：";
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	return 0;
}
