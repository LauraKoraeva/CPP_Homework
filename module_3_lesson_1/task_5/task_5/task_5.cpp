// Продвинутые темы и техники C++
// Урок 1. Чтение из файлов

// Задание 5. Реализация игры «Что? Где? Когда?»

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <limits>
#include <numeric>

bool correctInput(int input)
{
    if (std::cin.fail() || std::cin.peek() != '\n' || input <= 0)
    {
        std::cerr << "Incorrect input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return false;
    }
    else
        return true;
}

void chooseSector(int& currentSector, bool* sectors, int length = 13)
{
    std::cout << "Enter the offset: ";
    int offset;
    do
    {
        std::cin >> offset;
    } while (!correctInput(offset));

    if (currentSector + offset <= 13)
        currentSector += offset;
    else
        currentSector = (currentSector + offset) % 13;

    while (!sectors[currentSector - 1])
    {
        if (currentSector == 13)
            currentSector = 1;
        ++currentSector;
    }
}

void readFile(std::ifstream& file, std::vector<std::string>& list)
{
    while (!file.eof())
    {
        std::string line;
        std::getline(file, line);
        list.push_back(line);
    }
}

int main()
{
    std::ifstream questionsList;
    std::ifstream answersList;
    questionsList.open("questions.txt");
    answersList.open("answers.txt");

    std::vector<std::string> question;
    readFile(questionsList, question);
    std::vector<std::string> answer;
    readFile(answersList, answer);

    bool sectors[13];
    std::memset(sectors, true, sizeof(sectors));

    std::cout << "Welcome to the game \"What? Where? When?\"!\n";
    int currentSector = 1;

    int playerScore = 0;
    int viewersScore = 0;
    while (playerScore != 6 && viewersScore != 6)
    {
        chooseSector(currentSector, sectors);

        std::cout << "Question: " << question[currentSector - 1] << '\n';
        std::cout << "Enter your answer: ";
        std::string playerAnswer;
        std::cin >> playerAnswer;

        if (playerAnswer == answer[currentSector - 1])
        {
            playerScore += 1;
            std::cout << "Correct answer.\n";
        }
        else
        {
            viewersScore += 1;
            std::cout << "Incorrect answer.\n";
        }

        sectors[currentSector - 1] = false;
    }

    if (playerScore > viewersScore)
        std::cout << "Player won!\n";
    else
        std::cout << "Viewers won!\n";

    questionsList.close();
    answersList.close();

    return 0;
}
