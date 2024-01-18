//构造函数注入,最常见的依赖注入方式，通过在类的构造函数中传递依赖项来实现。
#include <iostream>

class Engine {
public:
    void Start() {
        std::cout << "Engine started." << std::endl;
        // 启动引擎
    }
};

class Car {
public:
    Car(Engine& engine) : engine_(engine) {}

    void StartCar() {
        engine_.Start();
        std::cout << "Car started." << std::endl;
        // 启动汽车
    }

private:
    Engine& engine_;
};

int main() {
    Engine engqine;
    Car car(engqine);
    car.StartCar();
    return 0;
}