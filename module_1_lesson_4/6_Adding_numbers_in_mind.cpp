/*Основы программирования на C++
Урок 4. Конструкция условия if
*/

//Практическая работа

//Задание 2. Складываем в уме

#include <iostream>

int main()
{
  std::cout << "Can you add numbers in your mind? Test yourself!\n";
  std::cout << "Enter the first number: ";
  int number1;
  std::cin >> number1;
  std::cout << "Enter the second number: ";
  int number2;
  std::cin >> number2;
  std::cout << "Enter the sum: ";
  int sum;
  std::cin >> sum;
  std::cout << "-----Checking-----\n";
  int correctAnswer = number1 + number2;
  if (sum == correctAnswer)
  {
    std::cout << "Correct!\n";
  }
  else
  {
    std::cout << "Error! Correct answer: " << correctAnswer << "\n";
  }

  return 0;
}