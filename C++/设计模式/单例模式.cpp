//保证一个类仅有一个实例，并提供一个访问它的全局访问点，该实例被所有程序模块共享
#include <iostream>

class Singleton
{
private:
    //私有的构造函数，防止外部实例化
    Singleton()
    {
        //进行初始化操作
        data = 0;
    }

    static Singleton* instance;  //静态成员变量保存唯一实例
    int data;   //示例的数据成员

public:
    //获取唯一实例的静态方法
    //通过 getInstance() 方法，你可以获取唯一的 Singleton 实例，并使用它来存储和获取数据
    //无论何时调用 getInstance()，都会返回同一个实例。
    //该实例是在首次调用 getInstance() 时创建并保存在 instance 静态成员变量中的
    //确保在应用程序中只有一个实例，并且可以通过统一的访问点 Singleton::getInstance() 来获取该实例
    static Singleton* getInstance()
    {
        if (instance == nullptr)
        {
            instance = new Singleton();
        }
        return instance;
    }
    //示例方法，设置数据并打印
    void setData(int value)
    {
        data = value;
    }
    //获取数据并打印
    int getData()
    {
        return data;
    }
};

//在类外初始化静态成员变量
Singleton* Singleton::instance = nullptr;  //

int main()
{
    //获取单例实例 
    Singleton* singleton = Singleton::getInstance();

    //设置和获取数据
    singleton->setData(33);
    std::cout << "Data from Singleton" << singleton->getData() << std::endl;

    //在其他部分也可以获取相同的实例
    Singleton* anotherSingleton = Singleton::getInstance();
    std::cout << "Data from Another Singleton:" << anotherSingleton->getData() << std::endl;


    //构造函数是私有的，外部代码无法直接实例化对象，而只能通过 getInstance() 方法来获取实例，所以确保了只有一个对象（实例）存在
}
