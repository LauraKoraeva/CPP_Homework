// Продвинутые темы и техники C++
// Урок 2. Запись в файлы

// Задание 4. Реализация симуляции банкомата

#include <iostream>
#include <fstream>
#include <limits>
#include <numeric>
#include <cstring>

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

void updateBank(int* bank, int size)
{
    std::ofstream out("bank.bin", std::ios::binary);
    out.write((char*)bank, size);
    out.close();
}

void addMoney(int* bank, int size, int* bills, int billsLength)
{
    std::srand(std::time(nullptr));
    for (int i = 0; i < 1000; ++i)
    {
        if (bank[i] == 0)
        {
            bank[i] = bills[std::rand() % 5];
        }
    }

    updateBank(bank, size);
    std::cout << "The operation has been completed successfully.\n";
}

int withdrawMoney(int* bank, int size, int* bills, int billsLength)
{
    int amount;
    do
    {
        std::cout << "Enter the amount: ";
        std::cin >> amount;
    } while (!correctInput(amount));

    if (((amount % 100) != 0) || amount < 100)
    {
        std::cerr << "Invalid amount.\n";
        return 1;
    }

    for (int i = 4; i >= 0; --i)
    {
        int bill = bills[i];
        for (int j = 0; j < 1000; ++j)
        {
            if (bank[j] == bill)
            {
                if (amount >= bill)
                {
                    bank[j] = 0;
                    amount -= bill;
                    if (amount == 0)
                    {
                        updateBank(bank, size);
                        std::cout << "The operation has been completed successfully.\n";
                        return 0;
                    }
                }
            }
        }
    }
    std::cerr << "Not enough compatible bills.\n";
    return 1;
}

int main()
{
    int bills[5] = { 100, 200, 500, 1000, 5000 };
    int bank[1000];
    int size = sizeof(bank);

    std::string operation;
    do
    {
        std::cout << "+  - refill ATM machine.\n";
        std::cout << "-  - withdraw money.\n";
        std::cout << "Choose the operation: ";
        std::cin >> operation;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (operation != "+" && operation != "-");

    std::ifstream in("bank.bin", std::ios::binary);
    if (in.is_open())
    {
        in.read((char*)bank, sizeof(bank));
        in.close();
    }
    else
        std::memset(bank, 0, sizeof(bank));

    if (operation == "+")
        addMoney(bank, size, bills, 5);
    else if (operation == "-")
        withdrawMoney(bank, size, bills, 5);

    return 0;
}
