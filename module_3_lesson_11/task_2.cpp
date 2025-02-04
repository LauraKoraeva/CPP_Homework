#include <iostream>
#include <cmath>
#include <iomanip>

struct BoundingBoxDimensions
    {
        double width;   
        double height; 
    };

class Shape
{ 
public:
    virtual double calculateSquare() = 0;
    
    virtual BoundingBoxDimensions calculateDimensions() = 0;
    
    virtual std::string defineType() = 0;
    
};

class Circle : public Shape
{
private:
    double radius;
    
public:
    Circle(double inRadius)
    {
        if (inRadius <= 0)
            std::cout << "Incorrect input.\n";
        else
            radius = inRadius;
    }
    
    virtual double calculateSquare()
    {
        const double pi = 3.14159;
        double square = pi * (pow(radius, 2));
        return square; 
    }
    
    virtual BoundingBoxDimensions calculateDimensions()
    {
        BoundingBoxDimensions dimensions;
        dimensions.height = radius * 2;
        dimensions.width = dimensions.height;
        return dimensions; 
    }
    
    virtual std::string defineType()
    {
        return "Circle";
    }
};

class Rectangle : public Shape
{
private:
    double length;
    double width;
    
public:
    Rectangle(double inLength, double inWidth)
    {
        if (inLength <= 0 || inWidth <= 0)
            std::cout << "Incorrect input\n";
        else
            {
                length = inLength;
                width = inWidth;
            }
    }
    
    virtual double calculateSquare()
    {
        double square = length * width;
        return square;
    }
    
    virtual BoundingBoxDimensions calculateDimensions()
    {
        BoundingBoxDimensions dimensions;
        dimensions.height = length;
        dimensions.width = width;
        return dimensions; 
    }
    
    virtual std::string defineType()
    {
        return "Rectangle";
    }
};

class Triangle : public Shape
{
private:
    double sideA;
    double sideB;
    double sideC;
    
public:
    Triangle(double inSideA, double inSideB, double inSideC)
    {
        if (inSideA <= 0 || inSideB <= 0 || inSideC <= 0)
            std::cout << "Incorrect input\n";
        else
            {
                sideA = inSideA;
                sideB = inSideB;
                sideC = inSideC;
            }
    }
    
    virtual double calculateSquare()
    {
        double p = (sideA + sideB + sideC) / 2;
        double square = sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
        return square;
    }
    
    virtual BoundingBoxDimensions calculateDimensions()
    {
        BoundingBoxDimensions dimensions;
        dimensions.height = (sideA * sideB * sideC / (4 * calculateSquare())) * 2;
        dimensions.width = dimensions.height;
        return dimensions; 
    }
    
    virtual std::string defineType()
    {
        return "Triangle";
    } 
};

void printParams(Shape *shape)
    {
        std::cout << "Type: " << shape->defineType() << '\n';
        std::cout << std::setprecision(3);
        std::cout << "Square: " << shape->calculateSquare() << '\n';
        std::cout << "Width: " << shape->calculateDimensions().width << '\n';
        std::cout << "Height: " << shape->calculateDimensions().height << "\n\n";
    }

int main()
{
    Circle c(5);
    printParams(&c);
    
    Rectangle r(5, 7);
    printParams(&r);
    
    Triangle t(3, 4, 5);
    printParams(&t);
    
    return 0;
}
