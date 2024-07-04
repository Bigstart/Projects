# const用法:

## 1.用const修饰变量，定义时就必须初始化，以后不能再更改。

可以使用const\_cast来修改const修饰的变量

const int a = 10;
int* p=const_cast<int*>(&a); //将\&a的类型转换成int\*，然后赋值给p
*p = 20;
//此时输出a，的值为10，*p的值为20
//注意事项：使用const_cast操作符转换之前，编译器觉得变量a被const关键词修饰，
//一般不会被修改，为了提升效率，直接将变量a对应的值保存到寄存器，每次cpu要用的时候无需去内存取值。
//但尽管内存中的值已经被修改成20，但是CPU屏蔽了变量a的变化，直接从寄存器取值，读到的值依然是10

//可以使用volatile关键字，让cpu每次都从内存中读值
volatile const int a = 10;
int* p=const_cast<int*>(&a); 
*p = 20;
//此时输出a，的值为20，*p的值为20


## 2.用const修饰形参，该形参再函数里不能被改变


void printNumber(const int num)
{
    std::cout << "Number:" << num << std::endl;
    num = num + 5;  //这里报错，num被声明为const int即它是一个常量形参。
    //因此，函数内部不能修改 num 的值。
}
int main()
{
    int x = 42;
    const int y = 100;
    printNumber(x);// 可以传递非常量实参给常量形参
    printNumber(y); // 同样可以传递常量实参给常量形参
}




## 3.用const修饰指针

常量指针 const int\* p;  指向的内存空间可以改，不能修改指向内存的值


#include<iostream>
int main()
{
    const int value = 5;
    const int* p = &value;//常量指针，指向常量整数
    //*p=10;   错误！不能通过指针修改指向内存的值
    int x = 10;
    p=&x;  //正确！可以改变指针指向其他内存地址
}


指针常量 int\* const p;  指向的内存空间不能改，值可以改


#include<iostream>
int main()
{
    int value = 5;
    int* const p = &value;  //指针常量，指向整数
    *p = 10;    // 正确，可以通过指针修改指向内存的值
    //p=nullptr;  //错误！不能改变指针指向的内存地址
    return 0;
}


既修饰指针又修饰常量 const int\* const p; 都不能改

## 4.修饰引用

1.const修饰常量引用：

使用const修饰引用，表示引用所绑定的变量是一个常量，不能通过引用修改其值。


#include <iostream>

int main() {
    int value = 5;
    const int& ref = value; // const修饰常量引用
    // ref = 10; // 错误！不能通过引用修改value的值
    value = 10; // 正确！可以直接修改value的值，ref也会跟着变化
    std::cout << "value: " << value << ", ref: " << ref << std::endl; // 输出 value: 10, ref: 10
    return 0;
}



2.const修饰指向常量的引用：使用const修饰引用，表示引用所绑定的是指向常量的指针，不能通过引用修改指向的内存值。


#include <iostream>

int main() {
    int value = 5;
    const int* p = &value; // 指向常量的指针
    // *p = 10; // 错误！不能通过指针修改指向内存的值
    value = 10; // 正确！可以直接修改value的值，p指向的内存值不变
    std::cout << "value: " << value << ", *p: " << *p << std::endl; // 输出 value: 10, *p: 5
    return 0;
}



3.const修饰常量引用和指向常量的引用组合：同时使用const修饰引用，表示引用是一个指向常量的常量引用，既不能通过引用修改其值，也不能通过引用修改指向的内存值。


#include <iostream>

int main() {
    int value = 5;
    const int* const p = &value; // 指向常量的常量指针
    // *p = 10; // 错误！不能通过指针修改指向内存的值
    // p = nullptr; // 错误！不能改变指针指向的内存地址
    value = 10; // 正确！可以直接修改value的值，p指向的内存值不变
    std::cout << "value: " << value << ", *p: " << *p << std::endl; // 输出 value: 10, *p: 5
    return 0;
}


## 5.修饰成员函数

在C++中，我们可以使用const关键字来修饰成员函数。通过在成员函数的参数列表后加上const，可以将该成员函数声明为一个常量成员函数。常量成员函数表示在该函数内部不会修改类的成员变量。这种修饰使得常量对象也能够调用这个函数，而不会改变对象的状态。

常量成员函数的定义和声明必须匹配。如果在类的声明中将函数声明为常量成员函数，那么在类的定义中也必须使用const来修饰该函数。

下面是一个简单的示例代码，演示了如何在C++中定义和使用常量成员函数：


#include <iostream>

class MyClass {
public:
    // 常量成员函数
    void print() const {
        // 在常量成员函数中，不能修改类的成员变量
        // someValue = 10; // 错误！不能修改成员变量
        std::cout << "Print function of MyClass" << std::endl;
    }

    // 普通成员函数
    void modify() {
        // 在普通成员函数中，可以修改类的成员变量
        someValue = 10;
    }

private:
    int someValue = 5;
};

int main() {
    const MyClass obj1; // 常量对象
    obj1.print(); // 可以调用常量成员函数
    // obj1.modify(); // 错误！不能调用普通成员函数，因为obj1是常量对象

    MyClass obj2; // 非常量对象
    obj2.print(); // 可以调用常量成员函数
    obj2.modify(); // 可以调用普通成员函数

    return 0;
}



