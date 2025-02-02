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
