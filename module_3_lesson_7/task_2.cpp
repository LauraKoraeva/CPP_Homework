// DRAFT

#include <iostream>
#include <fstream>

int main()
{
    int buffer[8] = { 0 };


    std::cout << "Enter 8 integers:\n";
    for (int i = 0; i < 8; ++i)
    {
        std::cin >> buffer[i];
    }

    
    std::cout << "Contents of RAM:\n";
    for (int i = 0; i < 8; ++i)
    {
        std::cout << buffer[i] << " ";
    }
    std::cout << '\n';


    

    int sum = 0;
    for (int i = 0; i < 8; ++i)
    {
        sum += buffer[i];
    }
    std::cout << "The sum of 8 numbers from RAM: " << sum << '\n';




    std::ofstream out_data("data.txt");
    for (int i = 0; i < 8; ++i)
    {
        out_data << buffer[i] << " ";
    }
    std::cout << "Data has been saved.\n";



    std::ifstream in_data;
    in_data.open("data.txt");
    for (int i = 0; i < 8; ++i)
    {
        in_data >> buffer[i];
    }
    in_data.close();
    std::cout << "Data has been loaded to RAM.\n";




}

































#include <iostream>
#include <fstream>

int buffer[8] = { 0 };

void input(int buffer[8])
{
    std::cout << "Enter 8 integers:\n";
    for (int i = 0; i < 8; ++i)
    {
        std::cin >> buffer[i];
    }
}

void compute(int buffer[8])
{
    int sum = 0;
    for (int i = 0; i < 8; ++i)
    {
        sum += buffer[i];
    }
    std::cout << "The sum of 8 numbers from RAM: " << sum << '\n';
}

void display(int buffer[8])
{
    std::cout << "Contents of RAM:\n";
    for (int i = 0; i < 8; ++i)
    {
        std::cout << buffer[i] << " ";
    }
    std::cout << '\n';
}

void save(int buffer[8])
{
    for (int i = 0; i < 8; ++i)
    {
        std::cout << buffer[i] << " ";
    }
    std::cout << "HERE\n";
    std::ofstream out_data("data.txt");
    if (out_data.is_open())
    {
        for (int i = 0; i < 8; ++i)
        {
            out_data << buffer[i] << " ";
        }
        out_data.close();
        std::cout << "Data has been saved.\n";
    }
    else
        std::cout << "oops";
}

void load(int buffer[8])
{
    std::ifstream in_data;
    in_data.open("data.txt");
    for (int i = 0; i < 8; ++i)
    {
        in_data >> buffer[i];
    }
    in_data.close();
    std::cout << "Data has been loaded to RAM.\n";
}


int main()
{

    

    while (true)
    {
        std::cout << "Choose the command:\n";
        std::cout << "1 - input numbers\n";
        std::cout << "2 - display numbers\n";
        std::cout << "3 - add up numbers\n";
        std::cout << "4 - save numbers\n";
        std::cout << "5 - load numbers\n";
        std::cout << "6 - exit\n";

        int choice;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            input(&buffer[8]);
            break;
        case 2:
            display(&buffer[8]);
            break;
        case 3:
            compute(&buffer[8]);
            break;
        case 4:
            save(&buffer[8]);
            break;
        case 5:
            load(&buffer[8]);
            break;
        case 6:
            return 0;
        }
    }
    
  

}
