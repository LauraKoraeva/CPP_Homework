// Продвинутые темы и техники C++
// Урок 12. HTTP запросы по сети

// Задание 2. Захват заголовка веб-страницы

#include <iostream>
#include <string>
#include <cpr/cpr.h>

int main()
{
    cpr::Response response = cpr::Get(cpr::Url("http://httpbin.org/html"),
            cpr::Header({{"User-Agent", "Mozilla/5.0"}, {"Accept", "text/html"}}));

    int i_1 = response.text.find("<h1>", 4);
    int i_2 = response.text.find("</h1>", 5);
    std::string heading = response.text.substr((i_1 + 4), i_2 - (i_1 + 4));
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "Title: " << heading << '\n';

    return 0;
}