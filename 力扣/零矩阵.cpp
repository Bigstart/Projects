#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    //创建两个标记数组，用于标记哪些行和列需要清零
    vector<int> rowFlag(rows, 0);
    vector<int> colFlag(cols, 0);

    //遍历矩阵，标记需要清零的行和列
    for(int i = 0;i<rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (matrix[i][j] == 0)
            {
                rowFlag[i] = 1;
                colFlag[j] = 1;
            }
        }
    }

    //根据标记，将对应的行和列清零
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (rowFlag[i] == 1 || colFlag[j] == 1)
            {
                matrix[i][j] = 0;
            }
        }
    }   
}

void print(vector<vector<int>>& a)
{
    for (const auto& row : a)
    {
        for (int num : row)
        {
            cout << num<<" ";
        }
        cout << endl;
    }
}

int main() {
    // 示例输入
    vector<vector<int>> matrix1 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    vector<vector<int>> matrix2 = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };

    print(matrix1);
    cout << endl;
    print(matrix2);
    cout << endl;

    // 调用函数清零矩阵
    setZeroes(matrix1);
    setZeroes(matrix2);

    print(matrix1);
    cout << endl;
    print(matrix2);
    return 0;
}
