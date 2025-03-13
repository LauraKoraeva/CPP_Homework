#include <iostream>
#include <cmath>
#include <cassert>
#include <iomanip>
#include <limits>
#include <numeric>

bool correctInput(int input)
{
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cerr << "Incorrect input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    else
        return true;
}

enum Colours
{
    RED = 1,
    GREEN,
    BLUE,
    NONE,
};

void printColour(int colourIndex)
{
    switch (colourIndex)
    {
    case RED:
        std::cout << "Colour: red\n";
        break;
    case GREEN:
        std::cout << "Colour: green\n";
        break;
    case BLUE:
        std::cout << "Colour: blue\n";
        break;
    case NONE:
        std::cout << "Colour: none\n";
        break;
    default:
        std::cout << "Colour: unknown\n";
        break;
    }
}



class BoundingBox
{
protected:
    double a_x = -1;
    double a_y = 1;
    double b_x = 1;
    double b_y = 1;
    double c_x = -1;
    double c_y = -1;
    double d_x = 1;
    double d_y = -1;
    double boundingBoxLength = 1;
    double boundingBoxWidth = 1;

public:
    BoundingBox() { }

    virtual void calculateBoundingBoxDimensions() = 0;

    void calculateBoundingBoxCoordinates(double inCentroid_x, double inCentroid_y)
    {
        a_x = inCentroid_x - boundingBoxLength / 2;
        a_y = inCentroid_y + boundingBoxWidth / 2;
        b_x = inCentroid_x + boundingBoxLength / 2;
        b_y = inCentroid_y + boundingBoxWidth / 2;
        c_x = inCentroid_x - boundingBoxLength / 2;
        c_y = inCentroid_y - boundingBoxWidth / 2;
        d_x = inCentroid_x + boundingBoxLength / 2;
        d_y = inCentroid_y - boundingBoxWidth / 2;
    }

    void printBoundingBoxInfo() const
    {
        std::cout << "Bounding box length: " << boundingBoxLength << '\n';
        std::cout << "Bounding box width: " << boundingBoxWidth << '\n';
        std::cout << "Bounding box coordinates:\n";
        std::cout << "(" << a_x << ", " << a_y << "), (" << b_x << ", " << b_y << "), " <<
            "(" << c_x << ", " << c_y << "), (" << d_x << ", " << d_y << ")\n";
    }

    virtual ~BoundingBox() { }
};



class Shape
{
protected:
    double centroid_x;
    double centroid_y;
    int colour;

public:
    Shape(double inCentroid_x = 0.0, double inCentroid_y = 0.0, int inColour = 4)
        : centroid_x(inCentroid_x), centroid_y(inCentroid_y), colour(inColour) 
    {
        assert(inColour >= 1 && inColour <= 4 && "colour option does not exist");
    }

    virtual double calculateSquare() = 0;

    virtual void printParameters()
    {
        std::cout << std::setprecision(2);
        std::cout << "Centroid: (" << centroid_x << ", " << centroid_y << ")\n";
        std::cout << "Area: " << calculateSquare() << '\n';
        printColour(colour);
    }

    virtual ~Shape() { }
};



class Circle final : public Shape, public BoundingBox
{
    double radius;

public:
    Circle(double inCentroid_x = 0, double inCentroid_y = 0, int inColour = 4, double inRadius = 1)
        : Shape(inCentroid_x, inCentroid_y, inColour), radius(inRadius)
    {
        assert(inRadius > 0);
        calculateBoundingBoxDimensions();
        calculateBoundingBoxCoordinates(inCentroid_x, inCentroid_y);
    }

    double calculateSquare() override
    {
        return std::atan(1) * 4 * radius;
    }

    void calculateBoundingBoxDimensions() override
    {
        boundingBoxLength = radius * 2;
        boundingBoxWidth = boundingBoxLength;
    }

    void printParameters() override
    {
        std::cout << "\n----------------------------------\n";
        std::cout << "---------SHAPE-PARAMETERS---------\n";
        std::cout << "----------------------------------\n";
        std::cout << "Shape: circle\n";
        Shape::printParameters();
        printBoundingBoxInfo();
        std::cout << "----------------------------------\n\n";
    }

    ~Circle() override { }
};



class Rectangle final : public Shape, public BoundingBox
{
    double length;
    double width;

public:
    Rectangle(double inCentroid_x = 0, double inCentroid_y = 0, int inColour = 4, double inLength = 2, double inWidth = 1)
        : Shape(inCentroid_x, inCentroid_y, inColour), length(inLength), width(inWidth)
    {
        assert(inLength > 0 && inWidth > 0);
        calculateBoundingBoxDimensions();
        calculateBoundingBoxCoordinates(inCentroid_x, inCentroid_y);
    }

    double calculateSquare() override
    {
        return length * width;
    }

    void calculateBoundingBoxDimensions() override
    {
        boundingBoxLength = length;
        boundingBoxWidth = width;
    }

    void printParameters() override
    {
        std::cout << "\n----------------------------------\n";
        std::cout << "---------SHAPE-PARAMETERS---------\n";
        std::cout << "----------------------------------\n";
        std::cout << "Shape: rectangle\n";
        Shape::printParameters();
        printBoundingBoxInfo();
        std::cout << "----------------------------------\n\n";
    }

    ~Rectangle() override { };
};



class Square final : public Shape, public BoundingBox
{
    double sideLength;

public:
    Square(double inCentroid_x = 0, double inCentroid_y = 0, int inColour = 4, double inSideLength = 1)
        : Shape(inCentroid_x, inCentroid_y, inColour), sideLength(inSideLength)
    {
        assert(inSideLength > 0);
        calculateBoundingBoxDimensions();
        calculateBoundingBoxCoordinates(inCentroid_x, inCentroid_y);
    }

    double calculateSquare() override
    {
        return sideLength * sideLength;
    }

    void calculateBoundingBoxDimensions() override
    {
        boundingBoxLength = sideLength;
        boundingBoxWidth = sideLength;
    }

    void printParameters() override
    {
        std::cout << "\n----------------------------------\n";
        std::cout << "---------SHAPE-PARAMETERS---------\n";
        std::cout << "----------------------------------\n";
        std::cout << "Shape: square\n";
        Shape::printParameters();
        printBoundingBoxInfo();
        std::cout << "----------------------------------\n\n";
    }

    ~Square() override { }
};



class Triangle final : public Shape, public BoundingBox
{
    double sideLength;

public:
    Triangle(double inCentroid_x = 0, double inCentroid_y = 0, int inColour = 4, double inSideLength = 1)
        : Shape(inCentroid_x, inCentroid_y, inColour), sideLength(inSideLength)
    {
        assert(inSideLength > 0);
        calculateBoundingBoxDimensions();
        calculateBoundingBoxCoordinates(inCentroid_x, inCentroid_y);
    }

    double calculateSquare() override
    {
        return sideLength * sideLength * std::sqrt(3) / 4;
    }

    void calculateBoundingBoxDimensions() override
    {
        boundingBoxLength = (std::pow(sideLength, 3) / (4 * calculateSquare())) * 2;
        boundingBoxWidth = boundingBoxLength;
    }

    void printParameters() override
    {
        std::cout << "\n----------------------------------\n";
        std::cout << "---------SHAPE-PARAMETERS---------\n";
        std::cout << "----------------------------------\n";
        std::cout << "Shape: triangle\n";
        Shape::printParameters();
        printBoundingBoxInfo();
        std::cout << "----------------------------------\n\n";
    }

    ~Triangle() override { }
};



void showMenu()
{
    std::cout << "Choose operation:\n";
    std::cout << "1 - create circle\n";
    std::cout << "2 - create triangle\n";
    std::cout << "3 - create square\n";
    std::cout << "4 - create rectangle\n";
    std::cout << "5 - exit\n\n";
}



void requestBasicParameters(double& centroid_x, double& centroid_y, int& colour)
{
    std::cout << "\n==================================\n";
    std::cout << "         Enter parameters         \n";
    std::cout << "==================================\n";
    do
    {
        std::cout << "Colour: ";
        std::cin >> colour;  
    } while (!correctInput(colour));
    do
    {
        std::cout << "Centroid x: ";
        std::cin >> centroid_x;  
    } while (!correctInput(centroid_x));
    do
    {
        std::cout << "Centroid y: ";
        std::cin >> centroid_y;  
    } while (!correctInput(centroid_y));
}



int main()
{
    double centroid_x, centroid_y;
    int colour;
    int choice; 

    while (true)
    {
        do
        {
            showMenu();
            std::cin >> choice;     
        } while (!correctInput(choice));

        if (choice == 1)
        {
            requestBasicParameters(centroid_x, centroid_y, colour);
            double radius;
            do
            {
                std::cout << "Radius: ";
                std::cin >> radius; 
            } while (!correctInput(radius));
            Circle shape(centroid_x, centroid_y, colour, radius);
            shape.printParameters();
        }
        else if (choice == 2)
        {
            requestBasicParameters(centroid_x, centroid_y, colour);
            double length;
            do
            {
                std::cout << "Length of the side: ";
                std::cin >> length;  
            } while (!correctInput(length));
            Triangle shape(centroid_x, centroid_y, colour, length);
            shape.printParameters();
        }
        else if (choice == 3)
        {
            requestBasicParameters(centroid_x, centroid_y, colour);
            double length;
            do
            {
                std::cout << "Length of the side: ";
                std::cin >> length; 
            } while (!correctInput(length));
            Square shape(centroid_x, centroid_y, colour, length);
            shape.printParameters();
        }
        else if (choice == 4)
        {
            requestBasicParameters(centroid_x, centroid_y, colour);
            double length, width;
            do
            {
                std::cout << "Length: ";
                std::cin >> length;
            } while (!correctInput(length));
            do
            {
                std::cout << "Width: ";
                std::cin >> width;  
            } while (!correctInput(width));
            Rectangle shape(centroid_x, centroid_y, colour, length, width);
            shape.printParameters();
        }
        else if (choice == 5)
            break;
        else
            std::cout << "No such operation.\n";
    }

    return 0;
}

