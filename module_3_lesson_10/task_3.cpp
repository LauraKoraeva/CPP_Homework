// Продвинутые темы и техники C++
// Урок 10. Введение в многопоточность

// Задание 3. Симуляция работы кухни онлайн-ресторана

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <chrono>
#include <random>
#include <thread>
#include <mutex>
#include <condition_variable>

struct Order 
{
    int id;
    std::string dish;
};


std::mutex kitchenAccess;
std::mutex deliveryAccess;
std::condition_variable kitchenCV;
std::condition_variable deliveryCV;
std::queue<Order> orderQueue;
std::queue<Order> readyQueue;
bool kitchenBusy = false;
int deliveriesCompleted = 0;        
const int totalDeliveries = 10;     


int getRandomNumber(int min, int max) 
{
    static std::random_device rd;
    static std::mt19937 mt(rd());
    std::uniform_int_distribution<> distribution(min, max);
    return distribution(mt);
}


void takeOrder() 
{
    while (deliveriesCompleted < totalDeliveries)                                   
    {
        std::this_thread::sleep_for(std::chrono::seconds(getRandomNumber(5, 10)));

        std::string dish;
        int dishIndex = getRandomNumber(1, 5);
        switch (dishIndex) 
        {
        case 1: dish = "pizza"; break;
        case 2: dish = "soup"; break;
        case 3: dish = "steak"; break;
        case 4: dish = "salad"; break;
        case 5: dish = "sushi"; break;
        }

        static int orderID = 1;
        Order newOrder{ orderID++, dish };

        std::cout << "---------------------------------------------\n";
        std::cout << "WAITER: order #" << newOrder.id << " for " << newOrder.dish << '\n';
        std::cout << "---------------------------------------------\n";

        {
            std::lock_guard<std::mutex> lock(kitchenAccess);
            orderQueue.push(newOrder);
        }
        kitchenCV.notify_one();
    }
}


void prepareOrder() 
{
    while (deliveriesCompleted < totalDeliveries)                     
    {
        std::unique_lock<std::mutex> lock(kitchenAccess);
        kitchenCV.wait(lock, [&] { return !orderQueue.empty() || deliveriesCompleted >= totalDeliveries; });   

        if (deliveriesCompleted >= totalDeliveries && orderQueue.empty())                  
        {
            return;
        }

        Order currentOrder = orderQueue.front();
        orderQueue.pop();
        kitchenBusy = true;

        std::cout << "=============================================\n";
        std::cout << "KITCHEN: cooking order #" << currentOrder.id << " for " << currentOrder.dish << '\n';
        std::cout << "=============================================\n";

        lock.unlock(); 
        std::this_thread::sleep_for(std::chrono::seconds(getRandomNumber(5, 15)));
        lock.lock();

        readyQueue.push(currentOrder);
        kitchenBusy = false;

        std::cout << "=============================================\n";
        std::cout << "KITCHEN: order #" << currentOrder.id << " for " << currentOrder.dish << " is ready\n";
        std::cout << "=============================================\n";

        deliveryCV.notify_one();
    }
}


void deliverOrder() 
{
    while (deliveriesCompleted < totalDeliveries)            
    {
        std::this_thread::sleep_for(std::chrono::seconds(30));

        std::unique_lock<std::mutex> lock(deliveryAccess);
        deliveryCV.wait(lock, [&] { return !readyQueue.empty() || deliveriesCompleted >= totalDeliveries; });      

        if (deliveriesCompleted >= totalDeliveries && readyQueue.empty())             
        {
            return;
        }

        std::vector<Order> currentDeliveries;
        while (!readyQueue.empty()) 
        {
            currentDeliveries.push_back(readyQueue.front());
            readyQueue.pop();
        }

        if (!currentDeliveries.empty()) 
        {
            std::cout << "`````````````````````````````````````````````\n";
            std::cout << "DELIVERY: picking up orders: ";
            for (const auto& order : currentDeliveries) 
            {
                std::cout << "#" << order.id << " ";
            }
            std::cout << "\n`````````````````````````````````````````````\n";

            std::this_thread::sleep_for(std::chrono::seconds(5)); 

            std::cout << "`````````````````````````````````````````````\n";
            std::cout << "DELIVERY: orders delivered: ";
            for (const auto& order : currentDeliveries) 
            {
                std::cout << "#" << order.id << " ";
                
            }
            std::cout << "\n`````````````````````````````````````````````\n";

            deliveriesCompleted++;

            std::cout << "\n*********************************************\n";
            std::cout << "COMPLETED " << deliveriesCompleted << " OUT OF " << totalDeliveries << " DELIVERIES.\n";    
            std::cout << "*********************************************\n\n";
        }
        else 
        {
            std::cout << "`````````````````````````````````````````````\n";
            std::cout << "DELIVERY: no new orders for delivery.\n";
            std::cout << "`````````````````````````````````````````````\n";
        }
    }
}

int main() 
{
    std::thread waiter(takeOrder);
    std::thread kitchen(prepareOrder);
    std::thread courier(deliverOrder);

    waiter.join();
    kitchen.join();
    courier.join();

    return 0;
}