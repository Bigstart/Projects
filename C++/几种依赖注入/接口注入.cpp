#include <iostream>

class IEngine {
public:
    virtual ~IEngine() = default;
    virtual void Start() = 0;
};

class GasEngine : public IEngine {
public:
    virtual void Start() {
        std::cout << "Gas engine started.\n";
    }
};

class Car {
public:
    void SetEngine(IEngine* engine) {
        engine_ = engine;
    }

    void StartCar() {
        if (engine_) {
            engine_->Start();
            std::cout << "Car started.\n";
        } else {
            std::cout << "No engine provided. Can't start car.\n";
        }
    }

private:
    IEngine* engine_ = nullptr;
};

int main() {
    GasEngine engine;
    Car car;
    car.SetEngine(&engine);
    car.StartCar();
    return 0;
}
