// Продвинутые темы и техники C++
// Урок 1. Чтение из файлов

// Задание 1. Разработка программы поиска слов в файле

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
	std::ifstream wordList;
	wordList.open("words.txt");

	std::vector<std::string> words;
	while (!wordList.eof())
	{
		std::string word;
		wordList >> word;
		words.push_back(word);
	}

	std::cout << "Enter a word: ";
	std::string userWord;
	std::getline(std::cin, userWord);

	int userWordCount = 0;
	for (int i = 0; i < words.size(); ++i)
	{
		if (words[i] == userWord)
			++userWordCount;
	}

	std::cout << "Matches found: " << userWordCount;

	wordList.close();

	return 0;
}