//Задание 3. Реализация симуляции игры «Рыбалка»

#include <iostream>
#include <fstream>

int main()
{
	std::ifstream river;
	river.open("C:\\Users\\Acer\\Desktop\\river.txt");

	std::ofstream basket("C:\\Users\\Acer\\Desktop\\basket.txt", std::ios::app);

	std::cout << "Which fish do you want to catch today? ";
	std::string fish;
	std::cin >> fish;
	if (fish != "sunfish" && fish != "shad" && fish != "carp" && fish != "bass" && fish != "bullhead" && fish != "catfish" && fish != "walleye")
		std::cout << "Sorry! No such fish in this lake!";
	else
	{
		int countFish = 0;
		std::string fishCaught;
		while (!river.eof())
		{
			river >> fishCaught;
			if (fish == fishCaught)
			{
				basket << fish << std::endl;
				++countFish;
			}
		}
		std::cout << "Congratulations! You've caught " << countFish << " " << fish << " today.";
	}

	
	river.close();
	basket.close();

	return 0;
}
