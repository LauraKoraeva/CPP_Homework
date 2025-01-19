// Продвинутые темы и техники C++
// Урок 5. Макросы и препроцессор

//Задание 2. Вывод времени года

#include <iostream> 

#define WINTER 1
#define SPRING 2
#define SUMMER 3
#define AUTUMN 4
#define CURRENT_SEASON 3

int main()
{
#if CURRENT_SEASON == WINTER
    std::cout << "Winter";
#elif CURRENT_SEASON == SPRING
    std::cout << "Spring"; 
#elif CURRENT_SEASON == SUMMER
    std::cout << "Summer";
#elif CURRENT_SEASON == AUTUMN 
    std::cout << "Autumn";
#endif
}