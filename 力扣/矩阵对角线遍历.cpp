//传进去一个数组，按照对焦线的方式遍历完 输出出来
//具体方法是行和列同时向右上角移动，如果出界就修正值并且掉头移动
#include <iostream>
#include <vector>

using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<int> result(m * n);    //存储结果的数组
    int row = 0, col = 0;         //初始位置
    int direction = 1;   //初始方向。1表示向上，-1表示向下

    for (int i = 0; i < m * n; ++i)
    {
        result[i] = mat[row][col];
        //计算下一个位置的行列坐标
        row = row-direction;
        col = col+ direction;

        if (row >= m)
        {
            row = m - 1;
            col += 2;
            direction = -direction;
        }
        if (col >= n)
        {
            col = n - 1;
            row += 2;
            direction = -direction;
        }
        if (row < 0)
        {
            row = 0;
            direction = -direction;
        }
        if (col < 0)
        {
            col = 0;
            direction = -direction;
        }
    }
    return result;
}

int main() {
    vector<vector<int>> mat1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result1 = findDiagonalOrder(mat1);

    cout << "矩阵1对角线遍历结果：" << endl;
    for (int val : result1) {
        cout << val << " ";
    }
    cout << endl;

    vector<vector<int>> mat2 = {
        {1, 2},
        {3, 4}
    };

    vector<int> result2 = findDiagonalOrder(mat2);

    cout << "矩阵2对角线遍历结果：" << endl;
    for (int val : result2) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
