#include<vector>
#include<iostream>

//旋转矩阵
//给一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。将图像旋转 90 度。
/*示例 1:

给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
*/

void rotate(std::vector<std::vector<int>>& matrix) {
	int n = matrix.size();
	//转置矩阵
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n ; ++j)
		{
			std::swap(matrix[i][j], matrix[j][i]);
		}
	}
	//交换矩阵的左右行
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n / 2; j++)
		{
			std::swap(matrix[i][j], matrix[i][n - j - 1]);
		}
	}
}


void print_matrix(const std::vector<std::vector<int>>& matrix) {
	for (const auto& row : matrix) {
		for (int val : row) {
			std::cout << val << "\t";
		}
		std::cout << std::endl;
	}
}

int main()
{
	std::vector<std::vector<int>> matrixs{
		{1, 2, 3, 4},
		{ 5,6,7,8 },
		{ 9,10,11,12 },
		{ 13,14,15,16 }
	};

	std::cout << "Original matrix:" << std::endl;
	print_matrix(matrixs);

	rotate(matrixs);

	std::cout << "Rotated matrix:" << std::endl;
	print_matrix(matrixs);

	return 0;
}