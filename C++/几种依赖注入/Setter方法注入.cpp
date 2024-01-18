//Setter方法注入
//setter 注入指的是在类的实例化后，通过调用一个 set 方法将依赖项注入到类中。
#include<iostream>
class Engine {
public:
    void Start() {
        std::cout << "Engine started." << std::endl;
        // 启动引擎
    }
};

class Car {
public:
    void SetEngine(Engine& engine) {   //Setter方法，接收一个Engine类的引用
        engine_ = engine;
    }

    void StartCar() {
        engine_.Start();
        // 启动汽车
    }

private:
    Engine engine_;
};
int main() {
    Engine engine;
    Car car;
    car.SetEngine(engine); // 使用 setter 方法注入 engine 对象
    car.StartCar();
    return 0;
}