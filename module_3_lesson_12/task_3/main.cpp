// Продвинутые темы и техники C++
// Урок 12. HTTP запросы по сети

// 

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cpr/cpr.h>

void get()
{

}

void post(cpr::Payload& payload)
{
    cpr::Response response = cpr::Post(cpr::Url("http://httpbin.org/post"), payload);
    std::cout << response.text << '\n';
}

cpr::Payload createPayload(std::vector<cpr::Pair>& pairs, std::map<std::string, std::string>& keyValue)
{
    for (const auto& pair : keyValue)
    {
        pairs.push_back({(std::string)pair.first, (std::string)pair.second});
    }
    cpr::Payload payload = cpr::Payload(pairs.begin(), pairs.end());
    return payload;
}

int main()
{
    std::vector<cpr::Pair> pairs;
    std::map<std::string, std::string> keyValue;
    std::string key, value;
    while (true)
    {
        std::cout << "Key: ";
        std::getline(std::cin, key);
        if (key == "get" || key == "Get" || key == "GET")
        {

            get();
            break;
        }
        else if (key == "post" || key == "Post" || key == "POST")
        {
            cpr::Payload payload = createPayload(pairs, keyValue);
            post(payload);
            break;
        }  
        std::cout << "Value: ";
        std::getline(std::cin, value);
        keyValue.insert(std::pair<std::string, std::string>(key, value));
    }

    return 0;
}