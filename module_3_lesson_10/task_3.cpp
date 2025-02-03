// DRAFT

#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <map>
#include <vector>
#include <mutex>

void timeInterval()
{
    int time;
    std::srand(std::time(nullptr));
    time = std::rand() % 6 + 5;
    std::this_thread::sleep_for(std::chrono::seconds(time));
}

class Restaurant
{
    enum Menu
    {
        PIZZA = 1,
        SOUP,
        STEAK,
        SALAD,
        SUSHI,
    };

    std::vector<int> kitchen;
    std::mutex kitchen_access;
    std::vector<int> delivery;
    std::mutex delivery_access;
    std::map<int, int> orderList;
    std::mutex orderList_access;
    std::map<int, int> deliveryList;
    std::mutex deliveryList_access;

public:
    int getChoice()
    {
        std::srand(std::time(nullptr));
        int menuChoice = std::rand() % 6;
        return menuChoice;
    }

    void printChoice(int choiceNumber)
    {
        switch (choiceNumber)
        {
        case 1:
            std::cout << "Pizza";
        case 2:
            std::cout << "Soup";
        case 3:
            std::cout << "Steak";
        case 4:
            std::cout << "Salad";
        case 5:
            std::cout << "Sushi";
        }
    }

    void deliver(int orderID, int menuChoice)
    {
        if (!delivery.empty())
        {
            deliveryList_access.lock();
            deliveryList.emplace(orderID, menuChoice);
            deliveryList_access.unlock();
        }
        while (true)
        {
            if (delivery.empty() || (!deliveryList.empty() && deliveryList.begin()->first == orderID))
            {
                if (delivery_access.try_lock())
                {
                    std::cout << "Delivering\n";
                    std::this_thread::sleep_for(std::chrono::seconds(30));

                    delivery_access.unlock();
                    if (!deliveryList.empty() && deliveryList.begin()->first == orderID)
                    {
                        deliveryList_access.lock();
                        deliveryList.erase(orderList.begin());
                        deliveryList_access.unlock();
                    }
                    break;
                }
            }
        }
    }

    void cook(int orderID, int menuChoice)
    {
        while (true)
        {
            if (kitchen.empty() || (!orderList.empty() && orderList.begin()->first == orderID))
            {
                if (kitchen_access.try_lock())
                {
                    std::srand(std::time(nullptr));
                    std::cout << "Cooking\n";
                    std::this_thread::sleep_for(std::chrono::seconds(std::rand() % 11 + 5));

                    kitchen_access.unlock();
                    if (!orderList.empty() && orderList.begin()->first == orderID)
                    {
                        orderList_access.lock();
                        orderList.erase(orderList.begin());
                        orderList_access.unlock();
                    }
                    break;
                }
            }
        }
        deliver(orderID, menuChoice);
    }

    void order()
    {
        std::cout << "Ordering\n";
        int menuChoice = getChoice();
        int orderID = orderList.size() + 1;
        orderList_access.lock();
        orderList.emplace(orderID, menuChoice);
        orderList_access.unlock();
        cook(orderID, menuChoice);
    }
};

int main()
{
    Restaurant orders[10];

    std::thread order1(&Restaurant::order, &orders[1]);
    order1.detach();
    timeInterval();
    std::thread order2(&Restaurant::order, &orders[2]);
    order2.detach();
    timeInterval();
    std::thread order3(&Restaurant::order, &orders[3]);
    order3.detach();
    timeInterval();
    std::thread order4(&Restaurant::order, &orders[4]);
    order4.detach();
    timeInterval();
    std::thread order5(&Restaurant::order, &orders[5]);
    order5.detach();
    timeInterval();
    std::thread order6(&Restaurant::order, &orders[6]);
    order6.detach();
    timeInterval();
    std::thread order7(&Restaurant::order, &orders[7]);
    order7.detach();
    timeInterval();
    std::thread order8(&Restaurant::order, &orders[8]);
    order8.detach();
    timeInterval();
    std::thread order9(&Restaurant::order, &orders[9]);
    order9.detach();
    timeInterval();
    std::thread order10(&Restaurant::order, &orders[10]);
    order10.detach();

    if (order1.joinable()) order1.join();
    if (order2.joinable()) order2.join();
    if (order3.joinable()) order3.join();
    if (order4.joinable()) order4.join();
    if (order5.joinable()) order5.join();
    if (order6.joinable()) order6.join();
    if (order7.joinable()) order7.join();
    if (order8.joinable()) order8.join();
    if (order9.joinable()) order9.join();
    if (order10.joinable()) order10.join();

    return 0;
}

