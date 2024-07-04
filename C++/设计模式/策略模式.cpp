///策略模式（Strategy Pattern）是一种行为型设计模式，
///它允许你定义一系列算法，将每个算法封装成一个对象，并使它们可以相互替换//
//这里是简单的基础结构
 
///要点：

// 1. 策略接口:  定义了一组算法的接口，这些算法可以相互替换
// 2. 具体策略:  实现了策略接口的具体算法
// 3. 上下文:  上下文是策略模式的客户端，它包含一个策略接口的引用，并在运行时可以切换不同的具体策略对象


#include<iostream>

//策略接口：
class Strategy
{
public:
	virtual void execute() = 0;
};

//具体策略1：
class ConcreteStrategy1 :public Strategy
{
public:
	void execute() override
	{
		std::cout << "Executing Strategy 1" << std::endl;
	}
};

//具体策略2：
class ConcreteStrategy2 :public Strategy
{
public:
	void execute()override
	{
		std::cout << "Executing Strategy 2" << std::endl;
	}
};

//上下文：
class Context
{
private:
	Strategy* strategy;

public:                  //成员变量是一个指向 Strategy 接口的指针
	Context(Strategy* stra):strategy(stra){}
	//Context(Strategy* strategy) 是构造函数的声明,接受一个指向 Strategy 对象的指针作为参数

	void setStrategy(Strategy* newStrategy)
	{
		strategy = newStrategy;
	}

	void executeStrategy()
	{
		strategy->execute();
		//通过 strategy 成员变量来执行具体策略的 execute 方法。
		//这允许 Context 对象在运行时调用与当前策略对象关联的算法。
	}
};

int main()
{
	ConcreteStrategy1 strategy1;
	ConcreteStrategy2 strategy2;

	Context context(&strategy1);
	context.executeStrategy(); // 输出: Executing Strategy 1

	context.setStrategy(&strategy2);
	context.executeStrategy(); // 输出: Executing Strategy 2
}