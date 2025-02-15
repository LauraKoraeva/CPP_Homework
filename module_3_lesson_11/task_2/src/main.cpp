#include <iostream>
#include <iomanip>
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

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
