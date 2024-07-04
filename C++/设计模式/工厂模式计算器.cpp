//工厂模式是一种创建型设计模式
//旨在提供一种创建对象的方式，将对象的实例化过程与客户端代码分离
//刻意根据特定的条件或参数创建不同类型的对象，无需在客户端代码中直接实例化具体的类
#include <iostream>


//操作接口
class Operation
{
public:
    virtual double calculate(double a, double b) = 0;
};


//加法操作
class AddOperation :public Operation
{
public:
    double calculate(double a, double b)override
    {
        return a + b;
    }
};

// 减法操作
class SubtractOperation : public Operation {
public:
    double calculate(double a, double b) override {
        return a - b;
    }
};

// 乘法操作
class MultiplyOperation : public Operation {
public:
    double calculate(double a, double b) override {
        return a * b;
    }
};

// 除法操作
class DivideOperation : public Operation {
public:
    double calculate(double a, double b) override {
        if (b != 0) {
            return a / b;
        }
        else {
            std::cerr << "Error: Division by zero" << std::endl;
            return 0.0;
        }
    }
};

//操作工厂
class OperationFactory
{
public:
    static Operation* createOperation(char op)
    {
        switch (op)
        {
        case '+':
            return new AddOperation();
        case'-':
            return new SubtractOperation();
        case'*':
            return new MultiplyOperation();
        case'/':
            return new DivideOperation();
        default:
            std::cerr << "不正确的输入" << std::endl;
            return nullptr;
        }
    }
};

int main()
{
    char op;
    double a, b;

    std::cout << "请输入操作（+, -, *, /）:";

    std::cin >> op;
    std::cout << "请输入两个数字:" << std::endl;
    std::cin >> a >> b;

    Operation* operation = OperationFactory::createOperation(op);
    if (operation)
    {
        double result = operation->calculate(a, b);
        std::cout << "结果是：  " << result << std::endl;
        delete operation;
    }
    return 0;

}
