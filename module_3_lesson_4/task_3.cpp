// Продвинутые темы и техники C++
// Урок 4. Словари std::map

// Задание 3. Анаграммы

#include <iostream>
#include <map>
#include <string>

void sortLetters(std::string& word, std::map<char, int>& letters)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (letters.find(word[i]) != letters.end())
            letters[word[i]]++;
        else
            letters.insert(std::make_pair(word[i], 1));
    }
}

bool isAnagram(std::string& word_1, std::string& word_2) 
{
    if (word_1.length() != word_2.length())
        return false;
    
    std::map<char, int> firstWord;
    std::map<char, int> secondWord;

    sortLetters(word_1, firstWord);
    sortLetters(word_2, secondWord);

    if (firstWord == secondWord)
        return true;
    else
        return false;
}

int main() 
{
    std::string word_1;
    std::string word_2;

    std::cout << "Enter two words:\n";
    std::cin >> word_1 >> word_2;

    if (isAnagram(word_1, word_2))
        std::cout << word_1 << " and " << word_2 << " are anagrams.\n";
    else
        std::cout << word_1 << " and " << word_2 << " are not anagrams.\n";

    return 0;
}