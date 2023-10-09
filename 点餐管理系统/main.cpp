#include <iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include <windows.h>
#include "Menu.h"
#include "User.h"
using namespace std;

std::fstream finout;

vector<Order>order;
vector<Menu>menu;

void seviceForSeller();
void seviceForBuyer();

int main()
{
	string n;
	bool success = 0;
	cout << setw(50) << "欢迎进入菊园点餐系统" << endl;
	cout << "          ----------------------------------------------------------" << endl;
	//1为买家，2为卖家，3为退出系统 
	cout << right;
	cout << endl << setw(25) << "1.买家入口" << setw(15) << "2.商家入口" << setw(15) << "3.退出" << endl;
	while (cin >> n)
	{
		order.clear();
		menu.clear();
		if (n == "3") break;
		//处理错误输入 
		if (n != "1" && n != "2")
		{
			cout << endl << "无效的数字，请重新输入 :" << endl;
			cout << endl << setw(25) << "1.买家入口" << setw(15) << "2.商家入口" << setw(15) << "3.退出" << endl;
			continue;
		}
		if (n == "1") seviceForBuyer();
		else seviceForSeller();
		cout << right;
		cout << endl << setw(25) << "1.买家入口" << setw(15) << "2.商家入口" << setw(15) << "3.退出" << endl;
	}
	return 0;
}

//用于读取文件中的菜单 
Menu inputMenu()
{
	Menu iMenu;
	string dishID, dishName;
	double price = -1;
	finout >> dishID;
	if (dishID == " " || dishID == "\n") {
		iMenu.setDishID("-1");
		return iMenu;
	}
	finout >> dishName >> price;
	if (price < 0 || price > 100000) {
		iMenu.setDishID("-1");
		return iMenu;
	}
	iMenu.setDishID(dishID);
	iMenu.setDishName(dishName);
	iMenu.setPrice(price);
	return iMenu;
}

//用于读取文件中的订单 
Order inputOrder()
{
	string dishID, dishName, name, adress, phone;
	double price = -1;
	int year, month, day, hour, modify, num;
	finout >> dishID;
	if (dishID == " " || dishID == "\n")
	{
		Order iOrder;
		iOrder.setDishID("-1");
		return iOrder;
	}
	finout >> dishName >> price >> num >> name >> adress >> phone;
	if (price < 0 || price > 100000) {
		Order iOrder;
		iOrder.setDishID("-1");
		return iOrder;
	}
	finout >> year >> month >> day >> hour >> modify;
	Date date(year, month, day, hour);
	Order iOrder(dishName, dishID, price, name, adress, phone, date);
	iOrder.setnum(num);
	if (!modify) iOrder.setModify();
	return iOrder;
}

//卖家 
void seviceForSeller()
{
	Seller iSeller;
	Order iOrder;
	Menu iMenu;
	//验证密码 
	string password;
	finout.open("password.txt", ios::in);
	if (finout.fail())
	{
		cout << endl << "系统无法找到password文件" << endl;
		return;
	}
	finout >> password;
	finout.close();
	iSeller.setPassword(password);
	cout << endl << "请输入密码 ( 默认密码为 is 888888 ) :";
	string str;
	int num = 5;
	cin >> str;
	while (num-- && str != iSeller.getPassword())
	{
		cout << endl << "密码错误\n请重新输入 : ";
		cin >> str;
	}
	if (num <= 0)
	{
		cout << endl << "你输入了五次错误的密码!" << endl;
		return;
	}
	//1为增加菜单，2为删除菜单，3为查询订单，4为确认订单，5为设置密码，6返回主菜单 
	cout << endl << "请根据序号选择功能 :" << endl;
	cout << left;
	cout << endl << "           " << setw(30) << "1. 增加菜单" << setw(20) << "2. 删除菜单" << endl;
	cout << "           " << setw(30) << "3. 查询订单" << setw(20) << "4.确认订单" << endl;
	cout << "           " << setw(30) << "5.设置密码" << setw(20) << "6.返回主菜单" << endl;
	string choice;
	while (cin >> choice)
	{
		if (choice == "6")
		{
			return;
		}
		//处理错误输入 
		if (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5")
		{
			cout << endl << "无效的输入，请重新输入" << endl;
			cout << endl << "           " << setw(30) << "1. 增加菜单" << setw(20) << "2. 删除菜单" << endl;
			cout << "           " << setw(30) << "3. 查询订单" << setw(20) << "4.确认订单" << endl;
			cout << "           " << setw(30) << "5.设置密码" << setw(20) << "6.返回主菜单" << endl;
			continue;
		}
		//从文件读取以初始化菜单信息和订单信息 
		order.clear();
		finout.open("order.txt", ios::in);
		if (finout.fail())
		{
			cout << endl << "系统找不到order文件！" << endl;
			break;
		}
		while (!finout.eof())
		{
			iOrder = inputOrder();
			if (iOrder.getDishID() == "-1") break;
			order.push_back(iOrder);
		}
		finout.close();
		menu.clear();
		finout.open("menu.txt", ios::in);
		if (finout.fail())
		{
			cout << endl << "系统找不到menu文件！" << endl;
			break;
		}
		while (!finout.eof())
		{
			iMenu = inputMenu();
			if (iMenu.getDishID() == "-1") break;
			menu.push_back(iMenu);
		}
		finout.close();
		if (choice == "1")
			iSeller.appendMenu(menu);
		else if (choice == "2")
			iSeller.cancelMenu(menu);
		else if (choice == "3")
			iSeller.inquireOrder(order);
		else if (choice == "4")
			iSeller.modifyOrder(order);
		else
		{
			//修改密码 
			string str1, str2;
			cout << right;
			cout << endl << setw(35) << "1.继续" << setw(20) << "2.返回" << endl;
			while (cin >> str1)
			{
				if (str1 == "2") break;
				//处理错误输入 
				if (str1 != "1")
				{
					cout << "无效的输入！" << endl;
					cout << endl << setw(35) << "1.继续" << setw(20) << "2.返回" << endl;
					continue;
				}
				cout << "请输入旧密码 : ";
				cin >> str1;
				if (str1 == iSeller.getPassword()) break;
				else
				{
					cout << right;
					cout << endl << "密码错误！" << endl;
					cout << endl << setw(35) << "1.继续" << setw(20) << "2.返回" << endl;
				}
			}
			if (str1 == "2")
			{
				cout << left;
				cout << endl << "           " << setw(30) << "1. 增加菜单" << setw(20) << "2. 删除菜单" << endl;
				cout << "           " << setw(30) << "3. 查询订单" << setw(20) << "4.确认订单" << endl;
				cout << "           " << setw(30) << "5.设置密码" << setw(20) << "6.返回主菜单" << endl;
				continue;
			}
			cout << endl << "请输入新密码 : ";
			cin >> str1;
			cout << endl << "再次输入新密码 :";
			cin >> str2;
			//两次输入的新密码一样，则修改密码，写入文件 
			if (str1 == str2) {
				finout.open("password.txt", ios::out);
				if (finout.fail())
				{
					cout << endl << "系统无法找到password文件!" << endl;
					return;
				}
				finout << str1;
				finout.close();
				iSeller.setPassword(str1);
				cout << endl << "新密码已设置！" << endl;
			}
			else
			{
				cout << endl << "您两次输入的新密码不一致！" << endl;
			}
		}
		cout << left;
		cout << endl << "           " << setw(30) << "1. 增加菜单" << setw(20) << "2. 删除菜单" << endl;
		cout << "           " << setw(30) << "3. 查询订单" << setw(20) << "4.确认订单" << endl;
		cout << "           " << setw(30) << "5.设置密码" << setw(20) << "6.返回主菜单" << endl;
	}
	if (choice == "6")
	{
		return;
	}
}


void seviceForBuyer()
{
	Buyer ibuyer;
	Menu iMenu;
	Order iOrder;
	string n;
	// 1为点菜，2为查询订单，3为修改订单 ，4返回主菜单 
	cout << left;
	cout << endl << "请继续选择您需要的功能：" << endl;
	cout << endl << "           " << setw(20) << "1. 下单" << setw(20) << "2. 查询" << endl;
	cout << "           " << setw(20) << "3. 取消" << setw(20) << "4. 主菜单" << endl;
	cin >> n;
	while (n != "4")
	{
		//处理错误输入 
		if (n != "1" && n != "2" && n != "3")
		{
			cout << endl << "无效的输入！请重新输入：" << endl;
			cin >> n;
			continue;
		}
		//从文件读取以初始化菜单信息和订单信息 
		order.clear();
		finout.open("order.txt", ios::in);
		if (finout.fail())
		{
			cout << endl << "系统找不到order文件" << endl;
			break;
		}
		while (!finout.eof())
		{
			iOrder = inputOrder();
			if (iOrder.getDishID() == "-1") break;
			order.push_back(iOrder);
		}
		finout.close();
		menu.clear();
		finout.open("menu.txt", ios::in);
		if (finout.fail())
		{
			cout << endl << "系统找不到menu文件!" << endl;
			break;
		}
		while (!finout.eof())
		{
			iMenu = inputMenu();
			if (iMenu.getDishID() == "-1") break;
			menu.push_back(iMenu);
		}
		finout.close();
		if (n == "1")
			ibuyer.bookOrder(menu, order);
		else if (n == "2")
			ibuyer.inquireOrder(order);
		else if (n == "3")
			ibuyer.modifyOrder(order);
		cout << left;
		cout << endl << "请继续选择你需要的功能:" << endl;
		cout << endl << "           " << setw(20) << "1. 下单" << setw(20) << "2. 查询" << endl;
		cout << "           " << setw(20) << "3. 取消" << setw(20) << "4. 返回主菜单" << endl;
		cin >> n;
	}
	if (n == "4") return;
}
