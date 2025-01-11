//Задание 4. Разработка детектора PNG-файла

#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ifstream file;
    std::string path;
    std::cout << "Enter path: ";
    std::getline(std::cin, path);
    file.open(path, std::ios::binary);

    if (file.is_open())
    {
        char buffer[5];
        file.read(buffer, sizeof(buffer));
        if (buffer[0] == -119 && buffer[1] == 'P' && buffer[2] == 'N' && buffer[3] == 'G' && path.substr(path.length() - 4, 4) == ".png")
            std::cout << "It's a png-file.\n";
        else
            std::cout << "It's not a png-file.\n";

        file.close();
    }
    else
        std::cout << "Path is not valid.\n";

    return 0;
}