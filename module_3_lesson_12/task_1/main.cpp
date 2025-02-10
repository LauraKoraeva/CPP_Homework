// Продвинутые темы и техники C++
// Урок 12. HTTP запросы по сети

// Задание 1. Пользовательские запросы

#include <iostream>
#include <string>
#include <cpr/cpr.h>

class Request
{
private:
    cpr::Response response;    
public:
    void get()
    {
        response = cpr::Get(cpr::Url("http://httpbin.org/get"),
            cpr::Header({{"User-Agent", "Mozilla/5.0"}}));
        std::cout << response.text << '\n';
    }
    
    void post()
    {
        std::cout << "Message: ";
        std::string message;
        std::getline(std::cin, message);
        response = cpr::Post(cpr::Url("http://httpbin.org/post"),
            cpr::Body(message.c_str()),
            cpr::Header{{"Content-Type", "text/plain"}},
            cpr::Header({{"User-Agent", "Mozilla/5.0"}}));
        std::cout << response.text << '\n';
    }
    
    void put()
    {
        std::string name, surname;
        std::cout << "Name: ";
        std::getline(std::cin, name);
        std::cout << "Surname: ";
        std::getline(std::cin, surname);
        response = cpr::Put(cpr::Url("http://httpbin.org/put"),
            cpr::Payload{{"Name", name.c_str()}, {"Surname", surname.c_str()}},
            cpr::Header({{"User-Agent", "Mozilla/5.0"}}));
        std::cout << response.text << '\n';
    }
    
    void patch()
    {
        std::cout << "New email: ";
        std::string email;
        std::getline(std::cin, email);
        response = cpr::Patch(cpr::Url("http://httpbin.org/patch"),
            cpr::Payload{{"email", email}},
            cpr::Header({{"User-Agent", "Mozilla/5.0"}}));
        std::cout << response.text << '\n';
    }

    void del()
    {
        response = cpr::Delete(cpr::Url("http://httpbin.org/delete"));
        std::cout << response.text << '\n';
    }
};

int main()
{
    Request request;
    std::string operation;
    
    while (true)
    {
        std::cout << "Enter your HTTP request (get, post, put, patch, delete): ";
        std::getline(std::cin, operation);

        if (operation == "get")
            request.get();
        else if (operation == "post")
            request.post();
        else if (operation == "put")
            request.put();
        else if (operation == "patch")
            request.patch();
        else if (operation == "delete")
            request.del();
        else if (operation == "exit")
            return 0;
        else
            std::cout << "No such request.\n";
    }
}