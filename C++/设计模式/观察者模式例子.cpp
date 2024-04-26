//观察者模式定义一种一对多的依赖关系，让多个观察者对象同时监听某一个主题对象
//当主题对象状态发生变化时，所有依赖与它的观察者都会得到通知并更新自己的状态
#include <iostream>
#include <vector>

//观察者基类
class Observer
{
public:
	//// 观察者必须实现的更新方法，用于接收主题状态的变化                                                            
	virtual void update(const std::string& message) = 0;
};

//具体观察者类
class ConcreteObserver :public Observer
{
public:
	ConcreteObserver(const std::string& name) :name_(name) {}
	// 具体观察者的更新方法实现
	void update(const std::string& message)override
	{
		std::cout << name_ << "收到消息" << message << std::endl;
	}

private:
	std::string name_;
};

//主题类，维护观察者列表并通知它们
class Subject
{
public:
	//注册观察者。将其添加到观察者列表中
	void attach(Observer* observer)
	{
		observers_.push_back(observer);
		//将一个观察者对象指针添加到观察者列表 observers_ 中
	}
	void detach(Observer* observer)
	{
		// 在实际应用中可能需要实现移除观察者的逻辑
	}
	// 通知所有观察者，传递消息
	void notify(const std::string& message)
	{
		for (Observer* observer : observers_)
		{
			observer->update(message);
		}
	}
private:
	std::vector<Observer*>observers_;
};

int main()
{
	//创建观察者
	ConcreteObserver observer1("观察者1");
	ConcreteObserver observer2("观察者2");

	//创建主题
	Subject subject;

	//将观察者注册到主题
	subject.attach(&observer1);
	subject.attach(&observer2);


	// 主题状态发生变化，通知观察者
	subject.notify("这是一个重要消息");

	return 0;
}

//使用场景 
/*当涉及到需要实现对象之间松耦合、解耦合的场景，
并且一个对象的状态变化需要通知其他多个对象时，观察者模式就非常有用。

以下是观察者模式的一些常见使用场景：
事件处理：图形用户界面(GUI)框架是观察者模式的一个典型应用场景。
在GUI中，用户与界面元素（如按钮、文本框等）进行交互，
这些界面元素可以视为主题，而用户的操作可以看作是状态的变化。
当用户点击按钮时，按钮作为主题通知所有已注册的观察者（事件处理器），以执行相应的操作。

消息通知：在应用程序中，当一个对象的状态变化需要通知其他多个对象时，
可以使用观察者模式。例如，在一个即时消息应用中，当一个用户发送消息时，
该消息可以作为主题通知所有已注册的用户（观察者），以便实时更新他们的聊天界面。

发布-订阅系统：观察者模式也用于实现发布-订阅系统，
其中发布者（发布主题）发布事件，而订阅者（观察者）订阅事件。
当事件发生时，发布者通知所有订阅者执行相应操作。
这在消息队列、事件总线等系统中很常见。

数据绑定：在前端开发中，观察者模式用于实现数据绑定。
当数据模型发生变化时，绑定的视图会自动更新以反映这些变化，
而无需手动编写更新逻辑。

库和框架：许多编程库和框架使用观察者模式来实现自定义事件和回调功能。
开发者可以注册回调函数（观察者），以便在特定事件发生时执行自定义逻辑。

总之，观察者模式是一种强大的设计模式，
可用于处理对象之间的松耦合通信和状态变化通知。
它有助于提高代码的可维护性和可扩展性，
使不同组件之间的交互更加灵活和可定制。
*/