#include <iostream>

class Animal
{
protected:
    std::string name;

public:
    Animal(std::string name) : name(name) {}
    virtual void speak() const
    {
        std::cout << name << " makes a generic animal sound." << std::endl;
    }
};

class Cat : public Animal
{
public:
    Cat(std::string name) : Animal(name) {}
    void speak() const override
    {
        std::cout << name << " meows." << std::endl;
    }
};

class Dog : public Animal
{
public:
    Dog(std::string name) : Animal(name) {}
    void speak() const override
    {
        std::cout << name << " barks." << std::endl;
    }
};

int main()
{
    Cat cat("Fluffy");
    Dog dog("Buddy");
    Animal *animals[] = {&cat, &dog};

    for (Animal *animal : animals)
    {
        animal->speak(); // Calls the appropriate speak function for each animal
    }

    return 0;
}
