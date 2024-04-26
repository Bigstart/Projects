#include<iostream>
#include<vector>


void merge(std::vector<int>& arr, int left, int middle, int right) //三个参数来确定要合并的子数组的范围
{
	//left 是左子数组的起始索引
	//middle是左子数组喝右子数组的分界索引
	//right是右子数组的结束索引

	//n1 是左子数组的长度  n2是右子数组的长度
	int n1 = middle - left + 1;
	int n2 = right - middle;

	//创建两个临时向量（数组），分别存储左子数组和右子数组的元素
	std::vector<int> leftArr(n1);
	std::vector<int> rightArr(n2);

	for (int i = 0; i < n1; ++i)
		leftArr[i] = arr[left + i];
	for (int j = 0; j < n2; ++j)
		rightArr[j] = arr[middle + 1 + j];

	//现在要将两个有序的子树组合并到原始数组中
	//i用于遍历左子数组
	//j用于遍历右子数组
	//k用于遍历原始数组
	int i = 0, j = 0, k = left;

	//在循环中比较左子数组和右子数组的元素，根据大小将元素复制到原始数组中
	while (i < n1 && j < n2)
	{
		if (leftArr[i] <= rightArr[j])
		{
			arr[k] = leftArr[i];
			++i;
		}
		else
		{
			arr[k] = rightArr[j];
			++j;
		}
		++k;
	}

	//处理可能剩余的元素，将它们复制到原始数组中
	while (i < n1)
	{
		arr[k] = leftArr[i];
		++i; ++k;
	}

	while (j < n2) {
		arr[k] = rightArr[j];
		++j;
		++k;
	}
}

void mergeSort(std::vector<int>& arr, int left, int right)
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;

		//递归地对左半部分进行排序
		mergeSort(arr, left, middle);

		//递归地对右半部分进行排序
		mergeSort(arr, middle+1, right);

		//合并两个有序子数组
		merge(arr, left, middle, right);
	}
}

int main()
{
	std::vector<int> arr = { 12, 11, 13, 5, 6, 7, 45, 2, 67, 100, 0, 2, 6, 8, 97 };

	std::cout << "原始数组:" << std::endl;
	for (int num : arr)
	{
		std::cout << num << " ";

	}
	std::cout << std::endl;
	int arrSize = arr.size();
	mergeSort(arr, 0, arrSize - 1);

	std::cout << "排序后的数组:" << std::endl;
	for (int num : arr)
	{
		std::cout << num << " ";

	}
	std::cout << std::endl;
	return 0;

}