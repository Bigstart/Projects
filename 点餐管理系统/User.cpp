#include "User.h"
#include "Menu.h"
#include<vector>
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
fstream inout;

//用于输出日期
void printDate(Date date)
{
	cout << date.getYear() << "/" << date.getMonth() << "/" << date.getDay() << "-" << date.getHour() << "h";
}

//用于输出菜单
void printMenu(Menu m)
{
	cout << m.getDishID() << m.getDishName() << m.getPrice() << endl;
}

Buyer::Buyer()
{
	name = "no";
	adress = "no";
	num = 0;
}

void Buyer::bookOrder(vector<Menu>& myMenu, vector<Order>& order)
{
	int n, m = 0;
	int i, year, month, day, hour, appNum = 0;
	string str;
	char ch;
	n = myMenu.size();
	num = myOrder.size();
}

void Buyer::modifyOrder(vector<Order>&)
{
}

void Buyer::inquireOrder(vector<Order>&)
{
}

int Buyer::getNum()
{
	return num;
}

string Buyer::getName()
{
	return name;
}

void Buyer::setNum(int)
{
}

Seller::Seller()
{
	password = "888888";
}

void Seller::modifyOrder(vector<Order>&)
{
}

void Seller::inquireOrder(vector<Order>&)
{
}

void Seller::appendMenu(vector<Menu>&)
{
}

void Seller::cancelMenu(vector<Menu>&)
{
}

void Seller::setPassword(string p)
{
	password = p;
}

string Seller::getPassword()
{
	return password;
}
