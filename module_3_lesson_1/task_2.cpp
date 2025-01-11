//Задание 2. Разработка просмотрщика текстовых файлов

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ifstream file;
	std::string path;
	std::cout << "Enter path: ";
	std::getline(std::cin, path);
	file.open(path, std::ios::binary);

	if (file.is_open())
	{
		char buffer[20];
		while (!file.eof())
		{
			file.read(buffer, sizeof(buffer) - 1);
			buffer[file.gcount()] = 0;
			std::cout << buffer;
		}
	}
	else
		std::cout << "Path is not valid.\n";

	file.close();

	return 0;
}