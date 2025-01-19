// Продвинутые темы и техники C++
// Урок 3. Структуры данных

// 3. Математический вектор

#include <iostream>
#include <string>
#include <cmath>
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

enum Operation
{
    OPERATION_ADD = 1,
    OPERATION_SUBSTRACT,
    OPERATION_SCALE,
    OPERATION_LENGTH,
    OPERATION_NORMALIZE,
};

struct Vector
{
    double x;
    double y;
    std::string name;
};

void getInfo(Vector& v)
{
    std::cout << "Name: ";
    std::cin >> v.name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    do
    {
        std::cout << "x: ";
        std::cin >> v.x;
    } while (!correctInput(v.x));
    do
    {
        std::cout << "y: ";
        std::cin >> v.y;
    } while (!correctInput(v.y));
}

void add(Vector& v_1, Vector& v_2, Vector& v_result)
{
    v_result.name = v_1.name + v_2.name;
    v_result.x = v_1.x + v_2.x;
    v_result.y = v_1.y + v_2.y;
}

void substract(Vector& v_1, Vector& v_2, Vector& v_result)
{
    v_result.name = v_1.name + v_2.name;
    v_result.x = v_1.x - v_2.x;
    v_result.y = v_1.y - v_2.y;
}

void scale(Vector& v, double scalar)
{
    v.x *= scalar;
    v.y *= scalar;
}

double length(Vector& v)
{
    return sqrt(v.x * v.x + v.y * v.y);
}

void normalize(Vector& v)
{
    double len = length(v);
    v.x /= len;
    v.y /= len;
}

void printResult(Vector& v)
{
    std::cout << "\nResult\n";
    std::cout << "Name: " << v.name << '\n';
    std::cout << "x: " << v.x << '\n';
    std::cout << "y: " << v.y << '\n';
}

int main()
{
    std::cout << "1 - add\n";
    std::cout << "2 - substract\n";
    std::cout << "3 - scale\n";
    std::cout << "4 - length\n";
    std::cout << "5 - normalize\n";
    int operation;
    do
    {
        std::cout << "Choose the operation: ";
        std::cin >> operation;
    } while (!correctInput(operation));

    Vector vec_1;
    Vector vec_2;
    Vector vec_result;
    switch (operation)
    {
    case OPERATION_ADD:
        std::cout << "Enter the name and the coordinates of the first vector:\n";
        getInfo(vec_1);
        std::cout << "Enter the name and the coordinates of the second vector:\n";
        getInfo(vec_2);
        add(vec_1, vec_2, vec_result);
        printResult(vec_result);
        break;
    case OPERATION_SUBSTRACT:
        std::cout << "Enter the name and the coordinates of the first vector:\n";
        getInfo(vec_1);
        std::cout << "Enter the name and the coordinates of the second vector:\n";
        getInfo(vec_2);
        substract(vec_1, vec_2, vec_result);
        printResult(vec_result);
        break;
    case OPERATION_SCALE:
        double scalar;
        std::cout << "Enter the name and the coordinates of the vector:\n";
        getInfo(vec_1);
        std::cout << "Enter the scalar: ";
        std::cin >> scalar;
        scale(vec_1, scalar);
        printResult(vec_1);
        break;
    case OPERATION_LENGTH:
        std::cout << "Enter the name and the coordinates of the vector:\n";
        getInfo(vec_1);
        double len;
        len = length(vec_1);
        std::cout << "\nResult\n";
        std::cout << "Name: " << vec_1.name << '\n';
        std::cout << "Length: " << len << '\n';
        break;
    case OPERATION_NORMALIZE:
        std::cout << "Enter the name and the coordinates of the vector:\n";
        getInfo(vec_1);
        normalize(vec_1);
        printResult(vec_1);
        break;
    default:
        std::cerr << "No such operation.\n";
        break;
    }

    return 0;
}
