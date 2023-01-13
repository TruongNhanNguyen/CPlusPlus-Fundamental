#include <bits/stdc++.h>

#include <iostream>
#include <string>

class Engine
{
private:
    double horsepower;
    double volume;

public:
    Engine(double horsepower, double volume) : horsepower(horsepower), volume(volume) {}
    double get_horsepower() const
    {
        return horsepower;
    }
    double get_volume() const
    {
        return volume;
    }
};

class Car
{
private:
    std::string make;
    std::string model;
    Engine engine;

public:
    Car(std::string make, std::string model, const Engine &engine) : make(make), model(model), engine(engine) {}
    std::string get_make() const
    {
        return make;
    }
    std::string get_model() const
    {
        return model;
    }
    double get_horsepower() const
    {
        return engine.get_horsepower();
    }
    double get_volume() const
    {
        return engine.get_volume();
    }
};

int main()
{
    Engine engine(200, 2.5);
    Car car("Ford", "Mustang", engine);
    std::cout << car.get_make() << " " << car.get_model() << std::endl; // Prints "Ford Mustang"
    std::cout << "Horsepower: " << car.get_horsepower() << std::endl;   // Prints "Horsepower: 200"
    std::cout << "Volume: " << car.get_volume() << std::endl;           // Prints "Volume: 2.5"

    return 0;
}
