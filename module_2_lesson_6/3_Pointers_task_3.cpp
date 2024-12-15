/*Массивы и Указатели в C++
Урок 6. Указатели*/

//Задача 3

#include <iostream>

bool substr(char* text, char* subText)
{
	bool found = false;
	for (int start = 0; start < *(text + start) != '\0'; ++start)
	{
		bool match = true;
		for (int i = 0; i < *(subText + i) != '\0'; ++i)
		{
			if (*(subText + i + start) == '\0' || *(subText + i) != *(text + i + start))
			{
				match = false;
				break;
			}
		}
		if (match)
		{
			found = true;
			break;
		}
	}
	return found;
}

int main()
{
	char a[] = "Hello, world!";
	char b[] = "world";
	char c[] = "friend";

	std::cout << std::boolalpha;

	std::cout << substr(a, b) << " " << substr(a, c);
	
	return 0;
}