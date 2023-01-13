# Object Oriented Programming

Object-oriented programming (OOP) is a programming paradigm that is based on the concept of "objects", which are data structures that contain both data and methods that operate on that data. OOP allows you to create reusable code by organizing it into classes and objects.

Here are some key features of OOP in C++:

1. **Classes**: A class is a blueprint for an object. It defines the data and methods that an object will have. You can declare a class in C++ using the `class` keyword, followed by the name of the class and a pair of curly braces. For example:
    
    ```cpp
    class Student {
        public:
            std::string name;
            int age;
            void print_info() {
                std::cout << "Name: " << name << std::endl;
                std::cout << "Age: " << age << std::endl;
            }
    };
    ```

2. **Objects**: An object is an instance of a class. You can create an object by using the `new` operator to dynamically allocate memory for it. For example:

    ```cpp
    Student* student = new Student;  // Create a new object of type Student
    student->name = "John";  // Set the name of the student
    student->age = 20;  // Set the age of the student
    student->print_info();  // Call the print_info method of the student object
    delete student;  // Deallocate the memory that was dynamically allocated for the student object
    ```

3. **Inheritance**: Inheritance is a way to create a new class that is a modified version of an existing class. The new class is called a subclass, and the existing class is the superclass. The subclass inherits the data and methods of the superclass and can also have its own data and methods. You can use the `:` operator to specify inheritance in C++. For example:

    ```cpp
    class Student {
        public:
            std::string name;
            int age;
            void print_info() {
                std::cout << "Name: " << name << std::endl;
                std::cout << "Age: " << age << std::endl;
            }
    };

    class GraduateStudent : public Student {
        public:
            std::string research_area;
            void print_info() {
                Student::print_info();  // Call the print_info method of the superclass
                std::cout << "Research area: " << research_area << std::endl;
            }
    };
    ```

## Key-concepts of OOP

Here are some key concepts of object-oriented programming (OOP) that you should be familiar with:

1. **Encapsulation**: Encapsulation is the process of bundling data and methods that operate on that data within a single unit, or object. It allows you to hide the implementation details of a class from other parts of the program and exposes a clear interface for interacting with the object.

2. **Abstraction**: Abstraction is the process of hiding the implementation details of a class and exposing only the essential features to the user. It allows you to focus on the functionality of an object and not its internal details.

3. **Polymorphism**: Polymorphism is the ability of a class to have multiple forms. It allows you to create multiple classes with the same interface, so that they can be used interchangeably. In C++, you can use inheritance and virtual functions to achieve polymorphism.

4. **Inheritance**: Inheritance is a way to create a new class that is a modified version of an existing class. The new class is called a subclass, and the existing class is the superclass. The subclass inherits the data and methods of the superclass and can also have its own data and methods.

5. **Composition**: Composition is a way to create a new class that is composed of one or more existing classes. The new class has access to the data and methods of the composing classes and can also have its own data and methods.

## Examples of key-concepts in OOP

### Encapsulations

Encapsulation is the process of bundling data and methods that operate on that data within a single unit, or object. It allows you to hide the implementation details of a class from other parts of the program and exposes a clear interface for interacting with the object.

```cpp
class BankAccount {
    private:
        std::string owner;
        double balance;
        void deposit(double amount) {
            balance += amount;
        }
        void withdraw(double amount) {
            balance -= amount;
        }

    public:
        BankAccount(std::string owner, double balance) : owner(owner), balance(balance) {}
        std::string get_owner() {
            return owner;
        }
        double get_balance() {
            return balance;
        }
        void add_funds(double amount) {
            deposit(amount);
        }
        void remove_funds(double amount) {
            withdraw(amount);
        }
};

int main() {
    BankAccount account("John", 1000);
    std::cout << "Owner: " << account.get_owner() << std::endl;  // Prints "Owner: John"
    std::cout << "Balance: " << account.get_balance() << std::endl;  // Prints "Balance: 1000"
    account.add_funds(500);
    std::cout << "Balance: " << account.get_balance() << std::endl;  // Prints "Balance: 1500"
    account.remove_funds(250);
    std::cout << "Balance: " << account.get_balance() << std::endl;  // Prints "Balance: 1250"
    return 0;
}
```

In this example, the `BankAccount` class encapsulates the data (`owner` and `balance`) and the methods (`deposit` and `withdraw`) that operate on that data. The data and methods are declared as `private`, so they are not accessible from outside the class. Instead, the class exposes a clear interface for interacting with the object through the `public` methods (`get_owner`, `get_balance`, `add_funds`, and `remove_funds`).

### Abstraction

Abstraction is the process of hiding the implementation details of a class and exposing only the essential features to the user. It allows you to focus on the functionality of an object and not its internal details.

```cpp

#include <iostream>
#include <string>

class BankAccount
{
public:
    virtual double get_balance() = 0;             // Pure virtual function
    virtual void add_funds(double amount) = 0;    // Pure virtual function
    virtual void remove_funds(double amount) = 0; // Pure virtual function
};

class CheckingAccount : public BankAccount
{
private:
    std::string owner;
    double balance;
    static double interest_rate;

    void deposit(double amount)
    {
        balance += amount;
    }
    void withdraw(double amount)
    {
        balance -= amount;
    }

public:
    CheckingAccount(std::string owner, double balance) : owner(owner), balance(balance) {}
    double get_balance() override
    {
        return balance;
    }
    void add_funds(double amount) override
    {
        deposit(amount);
    }
    void remove_funds(double amount) override
    {
        withdraw(amount);
    }
    static void set_interest_rate(double rate)
    {
        interest_rate = rate;
    }
    static double get_interest_rate()
    {
        return interest_rate;
    }
};

double CheckingAccount::interest_rate = 0.01; // Initialize the static member variable

int main()
{
    CheckingAccount account("John", 1000);
    std::cout << "Balance: " << account.get_balance() << std::endl; // Prints "Balance: 1000"
    account.add_funds(500);
    std::cout << "Balance: " << account.get_balance() << std::endl; // Prints "Balance: 1500"
    account.remove_funds(250);
    std::cout << "Balance: " << account.get_balance() << std::endl;                      // Prints "Balance: 1250"
    CheckingAccount::set_interest_rate(0.03);                                            // Set the interest rate for all checking accounts to 3%
    std::cout << "Interest rate: " << CheckingAccount::get_interest_rate() << std::endl; // Prints "Interest rate: 0.03"

    return 0;
}
```

In this example, the `BankAccount` class defines a pure virtual function for each essential feature of a bank account (`get_balance`, `add_funds`, and `remove_funds`). This makes the BankAccount class an abstract class, which cannot be instantiated but can be used as a base class for derived classes.

The `CheckingAccount` class is a derived class of `BankAccount` that provides an implementation for the pure virtual functions. It also has its own data (`owner` and `balance`) and methods (`deposit` and `withdraw`) to manage the account. The `CheckingAccount` class also has a static member variable (`interest_rate`) and two static member functions (`set_interest_rate` and `get_interest_rate`) to set and get the interest rate for all checking accounts.

By using abstraction, the user of the `CheckingAccount` class only needs to know about the essential features of the account and not its internal details.

### Polymorphism

Polymorphism is the ability of an object to take on multiple forms. It allows you to define multiple implementations for a single interface and to use those implementations interchangeably at runtime.

There are two main types of polymorphism in C++:

1. **Static polymorphism**, also known as overloading, allows you to define multiple functions or operators with the same name but different parameters. The compiler selects the appropriate implementation at compile-time based on the type and number of arguments.

2. **Dynamic polymorphism**, also known as virtual functions, allows you to define a base class with one or more virtual functions and to provide different implementations for those functions in derived classes. The correct implementation is selected at runtime based on the type of the object.

```cpp
#include <bits/stdc++.h>

#include <iostream>

class Shape
{
public:
    virtual double area() const = 0; // Pure virtual function
    virtual void print() const = 0;  // Pure virtual function
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}
    double area() const override
    {
        return 3.14 * radius * radius;
    }
    void print() const override
    {
        std::cout << "Circle with radius " << radius << std::endl;
    }
};

class Rectangle : public Shape
{
private:
    double width;
    double height;

public:
    Rectangle(double width, double height) : width(width), height(height) {}
    double area() const override
    {
        return width * height;
    }
    void print() const override
    {
        std::cout << "Rectangle with width " << width << " and height " << height << std::endl;
    }
};

int main()
{
    Circle circle(10);
    Rectangle rectangle(20, 30);
    Shape *shapes[] = {&circle, &rectangle};

    for (Shape *shape : shapes)
    {
        std::cout << "Area: " << shape->area() << std::endl; // Calls the appropriate area function for each shape
        shape->print();                                      // Calls the appropriate print function for each shape
    }

    return 0;
}
```

The `Circle` and `Rectangle` classes are derived from the `Shape` class and provide an implementation for the virtual functions. The main function creates an array of pointers to `Shape` objects, which can be either a `Circle` or a `Rectangle`, and calls the `area` and `print` functions for each object.

At runtime, the correct implementation of the `area` and `print` functions is selected based on the type of the object. For example, when the `area` function is called for the circle object, it calls the area function of the `Circle` class. When it is called for the rectangle object, it calls the `area` function of the `Rectangle` class. This is an example of dynamic polymorphism.

### Inheritance

Inheritance is a mechanism in object-oriented programming that allows you to create a new class (derived class) by inheriting properties and behaviors from an existing class (base class). The derived class can override or extend the inherited properties and behaviors to create a specialized version of the base class.

```cpp
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
```

In this example, the `Animal` class is the base class and the `Cat` and `Dog` classes are derived classes. The `Animal` class has a single protected member variable (`name`) and a virtual function (`speak`) that prints a generic animal sound. The `Cat` and `Dog` classes override the `speak` function to provide a specialized implementation for each animal.

The main function creates an array of pointers to `Animal` objects, which can be either a `Cat` or a `Dog`, and calls the `speak` function for each object. At runtime, the correct implementation of the `speak` function is selected based on the type of the object. For example, when the `speak` function is called for the cat object, it calls the speak function of the `Cat` class. When it is called for the dog object, it calls the `speak` function of the `Dog` class.

### Composition

Composition is a design pattern in object-oriented programming that allows you to create complex objects by combining simpler objects. It allows you to achieve code reuse and flexibility by creating relationships between objects at runtime.

```cpp
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
```

In this example, the `Engine` class represents an engine with a `horsepower` and a `volume`. The `Car` class represents a car with a make, a model, and an `Engine` object. The `Car` class uses the `Engine` object to get the `horsepower` and `volume` of the car.

The main function creates an `Engine` object and a `Car` object and initializes the `Car` object with the `Engine` object. The `Car` object has a reference to the `Engine` object, but it does not own it. This means that the `Car` object can use the `Engine` object to get its properties, but it does not have to worry about creating or destroying it.