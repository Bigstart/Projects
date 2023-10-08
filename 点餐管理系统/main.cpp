#include <iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include <windows.h>
#include "Menu.h"
#include "User.h"
using namespace std;

std::fstream finout;

void seviceForSeller();
void seviceForBuyer();

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	string n;
	bool success = 0;
	cout << " " << endl;
	cout << setw(50) << "欢迎进入eva预定餐系统" << endl;
	cout << "          ----------------------------------------------------------" << endl;
	//1为买家，2为卖家，3为退出系统 
	cout << endl << setw(25) << "1.我是买家，买点吃的" << setw(15) << "2.卖家" << setw(25) << "3.臣这一退，就是一辈子" << endl;
	while (cin >> n)
	{
		if (n == "3")
		{
			break;
		}
		//处理错误输入 
		if (n != "1" && n != "2")
		{
			system("cls");

			cout << " " << endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);  // 设置文本颜色为红色
			cout << endl << "无效的输入，请重新按照序号输入：" << endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);			// 恢复默认文本颜色
			cout << " " << endl;
			cout << setw(50) << "欢迎进入eva预定餐系统" << endl;
			cout << "          ----------------------------------------------------------" << endl;
			cout << endl << setw(25) << "1.我是买家，买点吃的" << setw(15) << "2.卖家" << setw(25) << "3.臣这一退，就是一辈子" << endl;
			continue;
		}
		if (n == "1")
		{
			seviceForBuyer();
		}
	}
}


void seviceForBuyer()
{
	cout << "Asdfasdfasdf" << endl;
	return;
}

void seviceForSeller()
{
	return;

}