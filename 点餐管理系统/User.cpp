#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
#include<vector>
#include<string>
#include "Menu.h"
#include "User.h"
using namespace std;
fstream inout;

//用于输出日期 
void printDate(Date date)
{
	cout << left;
	cout << date.getYear() << '/' << date.getMonth() << '/' << date.getDay() << "-" << date.getHour() << 'h';
}

//用于输出菜单 
void printMenu(Menu m)
{
	cout << left;
	cout << setw(20) << m.getDishID() << setw(20) << m.getDishName() << setw(20) << m.getPrice() << endl;
}


//用于输出订单 
void printOrder(Order myOrder)
{
	cout << left;
	cout << setw(7) << myOrder.getDishID() << setw(10) << myOrder.getDishName() << setw(6) << myOrder.getPrice() << setw(4) << myOrder.getNum();
	cout << setw(8) << myOrder.getCustomerName() << setw(8) << myOrder.getPhone() << setw(12) << myOrder.getAdress();
	cout << " "; printDate(myOrder.getBookDate()); cout << "  ";
	if (myOrder.getModify())
	{
		cout << setw(10) << "New" << endl;
	}
	else cout << setw(10) << "Approved" << endl;
}

//用于将菜单写入文件 
void outputMenu(Menu& iMenu)
{
	inout << iMenu.getDishID() << ' ' << iMenu.getDishName() << ' ' << iMenu.getPrice() << endl;
}

//用于将订单写入文件 
void outputOrder(Order& iOrder)
{
	Date date = iOrder.getBookDate();
	int modify = iOrder.getModify() ? 1 : 0;
	inout << iOrder.getDishID() << ' ' << iOrder.getDishName() << ' ' << iOrder.getPrice() << ' ' << iOrder.getNum() << endl;
	inout << iOrder.getCustomerName() << ' ' << iOrder.getAdress() << ' ' << iOrder.getPhone() << endl;
	inout << date.getYear() << ' ' << date.getMonth() << ' ' << date.getDay() << ' ' << date.getHour() << ' ' << modify << endl;
}

Buyer::Buyer()
{
	name = "no";
	adress = "no";
	num = 0;
}

string Buyer::getName()
{
	return name;
}

//买家订菜 
void Buyer::bookOrder(vector<Menu>& myMenu, vector<Order>& order)
{
	int n, m = 0, i, year, month, day, hour, appNum = 0;
	string str;
	char ch;
	n = myMenu.size();
	num = myOrder.size();
	bool can = 1;
	//判断菜单是否为空 
	if (!n)
	{
		cout << endl << "对不起！没有可供您选择的菜品！" << endl;
		return;
	}
	cout << left;
	cout << endl << "这是菜单：" << endl;
	cout << endl << "        " << setw(20) << "菜品编号" << setw(20) << "菜品名称" << setw(20) << "价格" << endl;
	for (i = 0; i < n; ++i)
	{
		cout << "        ";
		printMenu(myMenu[i]);
	}
	//1为继续，2返回上一层 
	cout << right;
	cout << endl << setw(30) << "1.继续" << setw(20) << "2.返回" << endl;
	while (cin >> str)
	{
		can = 1;
		if (str == "2") break;
		cout << "请输入菜品编号：";
		cin >> str;
		for (i = 0; i < n; ++i)
		{
			if (myMenu[i].getDishID() == str)
			{
				myOrder.push_back(Order(myMenu[i], m));
				break;
			}
			//判断该编号是否存在 
			if (i == n - 1)
			{
				cout << endl << "没有这道菜！" << endl;
				cout << endl << setw(30) << "1. 继续" << setw(20) << "2. 返回" << endl;
				can = 0;
			}

		}
		if (!can) continue;
		appNum++;
		cout << endl << "请输入您想要的数量：";
		cin >> m;
		myOrder[myOrder.size() - 1].setnum(m);
		cout << endl << setw(30) << "1. 继续" << setw(20) << "2. 返回" << endl;
	}
	//判断有无新增菜单 
	if (appNum == 0)
	{
		cout << endl << "您还没有下单！" << endl;
		return;
	}
	//输出所有用户已预定的菜 
	cout << left;
	cout << endl << "以下是您已经下单的菜品：" << endl;
	cout << endl << setw(20) << "菜品编号" << setw(20) << "菜品名称" << setw(20) << "价格" << endl;
	for (i = 0; i < myOrder.size(); ++i)
	{
		printMenu(myOrder[i]);
	}
	//判断此时买家是否为匿名状态，是则跳过输入姓名，地址，电话 
	if (name == "no" || adress == "no")
	{
		cout << endl << "请输入您的姓名：";
		cin >> name;
		cout << endl << "请输入您的地址：";
		cin >> adress;
		cout << endl << "请输入您的电话：";
		cin >> phone;
	}
	cout << endl << "请输入您希望用餐的日期，格式如 2013/5/2 14（年/月/日 小时）：" << endl;
	cin >> year >> ch >> month >> ch >> day >> hour;
	bookDate.setYear(year);
	bookDate.setMonth(month);
	bookDate.setDay(day);
	bookDate.setHour(hour);
	for (int i = num; i < myOrder.size(); ++i) {
		myOrder[i].setCustomerName(name);
		myOrder[i].setAdress(adress);
		myOrder[i].setPhone(phone);
		myOrder[i].setBookDate(bookDate);
	}
	inout.open("order.txt", ios::app);
	if (inout.fail())
	{
		cout << endl << "系统找不到order文件！" << endl;
		return;
	}
	for (i = num; i < myOrder.size(); ++i)
	{
		outputOrder(myOrder[i]);
	}
	inout.close();
	num = myOrder.size();
}

//买家查询订单 
void Buyer::inquireOrder(vector<Order>& order)
{
	//名字是否为空 
	if (name == "no") {
		cout << endl << "请输入姓名 : ";
		cin >> name;
	}
	myOrder.clear();
	for (int i = 0; i < order.size(); ++i)
	{
		if (order[i].getCustomerName() == name)
		{
			myOrder.push_back(order[i]);
		}
	}
	num = myOrder.size();
	if (num == 0)
	{
		cout << endl << "您还没有下单任何菜品！" << endl;
		return;
	}
	cout << left;
	cout << endl << "以下是您已下单的菜品：" << endl;
	cout << endl << setw(7) << "菜品编号" << setw(10) << "菜品名称" << setw(6) << "价格" << setw(4) << "数量" << setw(8) << "姓名";
	cout << setw(8) << "电话" << setw(12) << "地址" << setw(15) << "日期" << setw(10) << "状态" << endl;
	for (int i = 0; i < num; ++i) {
		printOrder(myOrder[i]);
	}
	return;
}

//买家取消订单 
void Buyer::modifyOrder(vector<Order>& order)
{
	num = myOrder.size();
	if (num == 0)
	{
		cout << endl << "您还没有下单任何菜品！" << endl;
		return;
	}
	// 输出买家自己的所有订单
	cout << left;
	cout << endl << "您已下单的菜品如下：" << endl;
	cout << endl << setw(7) << "菜品编号" << setw(10) << "菜品名称" << setw(6) << "价格" << setw(4) << "数量" << setw(8) << "姓名";
	cout << setw(8) << "电话" << setw(12) << "地址" << setw(15) << "日期" << setw(10) << "状态" << endl;
	for (int i = 0; i < num; ++i)
	{
		printOrder(myOrder[i]);
	}
	//选择1-继续或2-返回上一层 
	cout << right;
	cout << endl << setw(30) << "1.继续" << setw(20) << "2.返回" << endl;
	string str;
	int pos = -1, n = 0;
	Order iOrder;
	int* cancleDish = new int[num + 1], * cancle = new int[order.size()];
	memset(cancleDish, 0, 4 * (num + 1));
	memset(cancle, 0, 4 * (order.size()));
	while (cin >> str)
	{
		if (str == "2") break;
		//判断无效输入 
		if (str != "1") {
			cout << endl << "无效的输入!" << endl;
			cout << endl << setw(30) << "1.继续" << setw(20) << "2.返回" << endl;
			continue;
		}
		cout << endl << "请输入菜品编号 : ";
		cin >> str;
		for (int i = 0; i < num; ++i)
		{
			if (myOrder[i].getDishID() == str)
			{
				//该订单是否已确认 
				if (myOrder[i].getModify()) {
					cout << endl << "订单已取消！" << endl;
					pos = i;
					break;
				}
				else {
					cout << endl << "订单已经确认！您无法取消它！" << endl;
					pos = -2;
					break;
				}
			}
		}
		//查看该买家想取消的编号是否存在 
		if (pos < 0) {
			if (pos == -1)
				cout << endl << "您没有下单过这道菜！" << endl;
		}
		else {
			cancleDish[pos] = 1;
			n++;
		}
		pos = -1;
		cout << right;
		cout << endl << setw(30) << "1.继续" << setw(20) << "2.返回" << endl;
	}
	//将更新的订单写入文件 
	inout.open("order.txt", ios::out);
	if (inout.fail())
	{
		cout << endl << "系统找不到order文件!" << endl;
		delete cancleDish; delete cancle;
		return;
	}
	for (int i = 0; i < num; ++i)
	{
		if (cancleDish[i]) {
			for (int j = 0; j < order.size(); ++j)
			{
				if (order[j] == myOrder[i])
				{
					cancle[j] = 1;
					break;
				}
			}
		}
	}
	for (int i = 0; i < order.size(); ++i)
	{
		if (cancle[i]) {
			continue;
		}
		outputOrder(order[i]);
	}
	inout.close();
	num -= n;
	delete cancleDish; delete cancle;
}

int Buyer::getNum()
{
	return num;
}

Seller::Seller()
{
	password = "888888";
}

void Seller::appendMenu(vector<Menu>& myMenu)
{
	cout << endl << "Do you want to append Menu?  Y/N" << endl;
	string ch;
	int k = myMenu.size();
	while (cin >> ch)
	{
		// 判断无效输入
		if (ch != "Y" && ch != "y") break;
		cout << endl << "请输入菜品名称：";
		string str;
		Menu iMenu;
		double d;
		cin >> str;
		iMenu.setDishName(str);
		cout << endl << "请输入菜品编号：";
		cin >> str;
		iMenu.setDishID(str);
		cout << endl << "请输入菜品价格：";
		cin >> d;
		iMenu.setPrice(d);
		myMenu.push_back(iMenu);
		cout << endl << "菜品已添加到菜单！" << endl;
		cout << endl << "是否继续添加菜品？ Y/N" << endl;
	}
	//将新增菜单写入文件 
	inout.open("menu.txt", ios::app);
	if (inout.fail())
	{
		cout << endl << "系统找不到menu文件!" << endl;
		return;
	}
	for (int i = k; i < myMenu.size(); ++i)
	{
		outputMenu(myMenu[i]);
	}
	inout.close();
	return;
}

void Seller::cancelMenu(vector<Menu>& myMenu)
{
	cout << endl << "你想要删除菜单吗? Y/N" << endl;
	string str;
	string ch;
	Menu iMenu;
	vector<Menu>::iterator it = myMenu.begin();
	while (cin >> ch)
	{
		it = myMenu.begin();
		if (ch == "N" || ch == "n") break;
		//判断无效输入 
		if (ch != "Y" && ch != "y")
		{
			cout << endl << "无效输入！请重新输入！" << endl;
			cout << endl << "是否要取消菜单？ Y/N" << endl;
			continue;
		}
		//输出所有菜单 
		cout << left;
		cout << endl << "这是菜单：" << endl;
		cout << endl << "        " << setw(20) << "菜品编号" << setw(20) << "菜品名称" << setw(20) << "价格" << endl;
		for (int i = 0; i < myMenu.size(); ++i)
		{
			cout << "        ";
			printMenu(myMenu[i]);
		}
		cout << endl << "请输入您要取消的菜品编号：";
		cin >> str;
		for (int i = 0; i < myMenu.size(); ++i)
		{
			if (myMenu[i].getDishID() == str)
			{
				myMenu.erase(it + i);
				cout << endl << "菜品已取消！" << endl;
				break;
			}
			//找不到该编号 
			if (i == myMenu.size() - 1)
			{
				cout << endl << "没有找到这道菜品！请重新输入！" << endl;
			}
		}
		cout << endl << "是否继续取消菜单？ Y/N" << endl;
	}
	//将修改后菜单写入文件 
	inout.open("menu.txt", ios::out);
	if (inout.fail())
	{
		cout << endl << "系统找不到menu文件!" << endl;
		return;
	}
	for (int i = 0; i < myMenu.size(); ++i)
	{
		outputMenu(myMenu[i]);
	}
	inout.close();
}

//卖家查询订单 
void Seller::inquireOrder(vector<Order>& order)
{
	//没有订单则输出提示并返回上一层 
	if (order.size() == 0)
	{
		cout << endl << "没有任何订单！" << endl;
		return;
	}
	cout << left;
	cout << endl << "以下是订单详情：" << endl;
	cout << endl << setw(7) << "菜品编号" << setw(10) << "菜品名称" << setw(6) << "价格" << setw(4) << "数量" << setw(8) << "姓名";
	cout << setw(8) << "电话" << setw(12) << "地址" << setw(15) << "日期" << setw(10) << "状态" << endl;
	for (int i = 0; i < order.size(); ++i)
	{
		printOrder(order[i]);
	}
	return;
}

//卖家确认订单 
void Seller::modifyOrder(vector<Order>& order)
{
	int* pos = new int[order.size() + 1], count = 0;
	memset(pos, 0, sizeof(pos));
	for (int i = 0; i < order.size(); ++i)
	{
		if (order[i].getModify())
		{
			count++;
			pos[i] = 1;
		}
	}
	//没有未确认订单则提示后返回上一层 
	if (count == 0)
	{
		cout << endl << "所有订单已经确认！" << endl;
		return;
	}
	cout << left;
	cout << endl << "以下是您尚未确认的订单：" << endl;
	cout << endl << setw(7) << "菜品编号" << setw(10) << "菜品名称" << setw(6) << "价格" << setw(4) << "数量" << setw(8) << "姓名";
	cout << setw(8) << "电话" << setw(12) << "地址" << setw(15) << "日期" << setw(10) << "状态" << endl;
	count = 0;
	for (int i = 0; i < order.size(); ++i)
	{
		if (pos[i] && order[i].getModify())
		{
			count++;
			cout << count << endl;
			printOrder(order[i]);
		}
	}
	//卖家可选择 1-全部确认 或 2-逐个确认 或 3-返回 
	cout << right;
	cout << endl << setw(20) << "1. 全部确认" << setw(25) << "2. 逐个确认" << setw(20) << "3. 返回" << endl;
	string n;
	while (cin >> n)
	{
		if (n == "1" || n == "2" || n == "3") break;
		else {
			cout << endl << "无效输入！" << endl;
			cout << endl << setw(20) << "1. 全部确认" << setw(25) << "2. 逐个确认" << setw(20) << "3. 返回" << endl;
		}
	}
	if (n == "3") return;
	if (n == "1")
	{
		for (int i = 0; i < order.size(); ++i)
		{
			if (pos[i])
				order[i].setModify();
		}
	}
	else
	{
		cout << right;
		cout << endl << setw(30) << "1. 继续" << setw(20) << "2. 返回" << endl;
		int k, m;
		while (cin >> m)
		{
			if (m == 2) return;
			if (m != 1) {
				cout << endl << "无效输入!" << endl;
				return;
			}
			cout << endl << "请输入订单编号:";
			cin >> m;
			//检验输入正确性 
			if (m > count)
			{
				cout << endl << "只有 " << count << " 个订单！" << endl;
				cout << endl << "请重新输入！" << endl;
			}
			else if (m <= 0)
			{
				cout << endl << "数字必须为正数！" << endl;
			}
			else
			{
				k = 0;
				for (int i = 0; i < order.size(); ++i)
				{
					if (pos[i])
					{
						k++;
						if (k == m)
						{
							order[i].setModify();
							cout << endl << "订单已确认！" << endl;
						}
					}
				}
			}
			cout << right;
			cout << endl << setw(30) << "1. 继续" << setw(20) << "2. 返回" << endl;
		}
	}
	//将修改后的订单写入文件 
	inout.open("order.txt", ios::out);
	if (inout.fail())
	{
		cout << endl << "系统找不到order文件!" << endl;
		return;
	}
	for (int i = 0; i < order.size(); ++i)
	{
		outputOrder(order[i]);
	}
	inout.close();

}

void Seller::setPassword(string p)
{
	password = p;
}

string Seller::getPassword()
{
	return password;
}
