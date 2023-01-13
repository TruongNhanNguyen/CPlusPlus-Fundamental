#include <bits/stdc++.h>

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
