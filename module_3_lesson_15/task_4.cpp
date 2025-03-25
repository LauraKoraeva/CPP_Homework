// Продвинутые темы и техники C++
// Урок 15. Использование исключений

// Задание 4. Среднее арифметическое число в массиве

#include <iostream>
#include <limits>
#include <numeric>
#include <iomanip>
#include <exception>

template<typename T>
bool correctInput(T input)
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


enum Types
{
    INT = 1,
    FLOAT,
    DOUBLE,
};

void printTypes()
{
    std::cout << "1 - int\n";
    std::cout << "2 - float\n";
    std::cout << "3 - double\n";
}


template<typename T>
T calculateMean(T* array, int length)
{
    if (length == 0)
    {
        throw std::invalid_argument("length = 0");
    }

    T sum = std::accumulate(array, array + length, static_cast<T>(0));
    return sum / static_cast<T>(length);
}


template<typename T>
void inputArray(T* array, int length)
{
    std::cout << "Fill the array:\n";
    for (int i = 0; i < length; ++i)
    {
        do
        {
            std::cin >> array[i];
        } while (!correctInput(array[i]));
    }
}


template<typename T>
 void inputArrayAndCalculateMean(T* array, int length)
 {
    inputArray(array, length);
    try
    {
        T mean = calculateMean(array, length);
        std::cout << std::setprecision(10); //
        std::cout << "\n==================================================\n";
        std::cout << "Mean: " << mean << '\n';
        std::cout << "==================================================\n";
    }
    catch(const std::invalid_argument& x)
    {
        std::cerr << "Invalid argument supplied: " << x.what() << '\n';
    }
}


int main()
{
    int length;
    do
    {
        std::cout << "Enter the number of elements in the array: ";
        std::cin >> length;
    } while (!correctInput(length));
    std::cout << '\n';

    int type;
    do
    {
        std::cout << "Choose the type of the array:\n";
        printTypes();
        std::cin >> type;
    } while (!correctInput(type));
    std::cout << '\n';

    if (type == INT)
    {
        int array[length];
        inputArrayAndCalculateMean(array, length);
    }
    else if (type == FLOAT)
    {
        float array[length];
        inputArrayAndCalculateMean(array, length);
    }
    else if (type == DOUBLE)
    {
        double array[length];
        inputArrayAndCalculateMean(array, length);
    }
    else
    {
        std::cout << "Unsupported type.\n";
    }

    return 0;
}

