//Задача 1

#include <iostream>
#include <string>

void countMatches(const std::string& text, const std::string& word, int& matchesFound)
{
    for (int i = 0; i <= text.length() - word.length(); )
    {
        size_t position = text.find(word, i);

        if (position == std::string::npos)
            break;

        ++matchesFound;
        i = position + word.length();
    }
}

int main()
{
    std::string text;
    std::string word;
    std::cout << "Input the text and the word:\n";
    std::getline(std::cin, text);
    std::getline(std::cin, word);

    int matchesFound = 0;

    countMatches(text, word, matchesFound);

    std::cout << "Matches found: " << matchesFound << '\n';

    return 0;
}

