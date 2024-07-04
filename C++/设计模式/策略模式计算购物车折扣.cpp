// 1. 策略接口:  定义了一组算法的接口，这些算法可以相互替换
// 2. 具体策略:  实现了策略接口的具体算法
// 3. 上下文:  上下文是策略模式的客户端，它包含一个策略接口的引用，并在运行时可以切换不同的具体策略对象
//我总结的要点是 策略模式就是看传入的对象是什么，然后根据对象调用它的函数

//例子：电商网站的购物车系统，策略模式用于计算购物车中不同商品的总价，而不同商品可以享受不同的折扣策略。

#include<iostream>
#include<vector>

//策略接口：
class DiscountStrategy  //Discount 折扣
{
public:
	virtual double applyDiscount(double amount) = 0;
};

//具体策略1：没有折扣
class NoDiscount :public DiscountStrategy
{
public:
	double applyDiscount(double amount)override
	{
		return amount;
	}
};

//具体策略2：10% 折扣
class TenPercentDiscount :public DiscountStrategy
{
private:
	double discountAmount;
public:
	TenPercentDiscount(double amount) :discountAmount(amount){}
	double applyDiscount(double amount)override
	{
		return discountAmount * amount;
	}
};

// 具体策略3：固定折扣金额
class FixedDiscount :public DiscountStrategy
{
private:
	double discountAmount;

public:
	FixedDiscount(double amount) :discountAmount(amount) {}

	double applyDiscount(double amount)override
	{
		return amount - discountAmount;
	}
};

//上下文：购物车类
class ShoppingCart
{
private:
	DiscountStrategy* discountStrategy;   // 储存当前的折扣策略
	std::vector<double> items;     //商品价格列表

public:
	ShoppingCart(DiscountStrategy* strategy):discountStrategy(strategy){}

	void addItem(double price)
	{
		items.push_back(price);
	}

	double calculateTotal()
	{
		double total = 0;
		for (const double& price : items)
		{
			total += price;
		}
		return discountStrategy->applyDiscount(total);
	}

	void setDiscountStrategy(DiscountStrategy* strategy)
	{
		discountStrategy = strategy;
	}
};


int main()
{
	NoDiscount noDiscount;
	TenPercentDiscount tenPercentDiscount(0.7);
	FixedDiscount fixedDiscount(220);

	ShoppingCart cart(&noDiscount);
	cart.addItem(1000.0);


	std::cout << "Total without discount: " << cart.calculateTotal() << std::endl;

	cart.setDiscountStrategy(&tenPercentDiscount);
	std::cout << "Total with 10% discount: " << cart.calculateTotal() << std::endl;

	cart.setDiscountStrategy(&fixedDiscount);
	std::cout << "Total with $20 discount: " << cart.calculateTotal() << std::endl;
}