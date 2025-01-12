#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <limits>
#include <numeric>

bool correctInput(int input)
{
    if (std::cin.fail() || std::cin.peek() != '\n' || input < 100)
    {
        std::cerr << "Incorrect input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return false;
    }
    else
        return true;
}

void readBank(int *bank, int length)
{
    std::ifstream in("C:\\Users\\Acer\\Desktop\\moneyDraft.txt");  //
    for (int i = 0; i < 1000; ++i)
    {
        in >> bank[i];
    }
}

void writeBank(int* bank, int bankLength, int* bills, int billsLength)
{
    std::ofstream out("C:\\Users\\Acer\\Desktop\\moneyDraft.txt");  //
    for (int i = 1; i <= 1000; ++i)
    {
        out << bank[i - 1] << " ";
        if (i % 25 == 0)
            out << std::endl;
    }
}

void addMoney(int* bank, int bankLength, int* bills, int billsLength)
{
    std::srand(std::time(nullptr));
    for (int i = 0; i < 1000; ++i)
    {
        if (bank[i] == 0)
        {
            bank[i] = bills[std::rand() % 5];
        }
    }

    writeBank(bank, 1000, bills, 5);
    std::cout << "The operation has been completed successfully.\n";
}

bool checkAvailability(int* bank, int bankLength, int* bills, int billsLength, int amount)
{   
    for (int i = 4; i >= 0; --i)
    {
        int bill = bills[i];
        if (amount >= bill)
        {
            for (int j = 0; j < 1000; ++j)
            {
                if (bank[j] == bill)
                {
                    bank[j] = 0;
                    amount -= bill;
                    if (amount == 0)
                    {
                        return true;
                    }
                }
            }
        }
    }
    if (amount != 0)
        return false;
}

void withdrawMoney(int* bank, int bankLength, int* bills, int billsLength)
{
    int amount;
    do
    {
        std::cout << "Enter the withdrawal amount: ";
        std::cin >> amount;  
    } while (!correctInput(amount));
    if (checkAvailability(bank, 1000, bills, 5, amount))
    {
        for (int i = 4; i >= 0; --i)
        {
            int bill = bills[i];
            if (amount >= bill)
            {
                for (int j = 0; j < 1000; ++j)
                {
                    if (bank[j] == bill)
                    {
                        bank[j] = 0;
                        amount -= bill;
                        if (amount == 0)
                        {
                            writeBank(bank, 1000, bills, 5);
                            std::cout << "The operation has been completed successfully.\n";
                            return;
                        }
                    }
                }
            }
        }
    }
    else
        std::cout << "Not enough compatible bills!\n";
         
}

int main()
{
	int bills[5] = { 100, 200, 500, 1000, 5000 };
    int bank[1000];

    readBank(bank, 1000);

    std::string operation;
    do
    {
        std::cout << "+  - refill ATM machine.\n";
        std::cout << "-  - withdraw money.\n";
        std::cout << "Choose the operation: ";
        std::getline(std::cin, operation);
    } while (operation != "+" && operation != "-"); 

    if (operation == "+")
        addMoney(bank, 1000, bills, 5);
    else if (operation == "-")
        withdrawMoney(bank, 1000, bills, 5);
    
    return 0;
   
}