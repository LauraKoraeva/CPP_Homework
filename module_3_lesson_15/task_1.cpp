// Продвинутые темы и техники C++
// Урок 15. Использование исключений

// Задание 1. Работа корзины с покупками

#include <iostream>
#include <string>
#include <map>
#include <exception>
#include <limits>
#include <numeric>

bool correctInput(int input)
{
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cerr << "Incorrect input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    else
        return true;
}


class QuantityNotAvailableException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Required quantity is not available";
    }
};

class ItemNotFoundException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Item was not found";
    }
};




class Store
{
protected:
    static std::map<std::string, int> stock;
    
public:
    Store() { }
    ~Store() { }



    void fillInStock()
    {
        std::cout << "Enter item code and quantity to the stock database.\n";

        int next = 1;
        while (next != 0)
        {
            std::string itemCode;
            int quantity;
            std::cout << "----------------------------------------------------\n";
            std::cout << "Item code: ";
            std::getline(std::cin, itemCode);
            do
            {
                std::cout << "Quantity: ";
                std::cin >> quantity;
            } while (!correctInput(quantity));
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "----------------------------------------------------\n";

            stock.emplace(itemCode, quantity);

            do
            {
                std::cout << "\nEnter '1' to continue or '0' to finish: ";
                std::cin >> next;
            } while (!correctInput(next));
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    virtual std::map<std::string, int>::iterator getItem(std::string itemCode, int quantity)
    {
        auto it = stock.find(itemCode);
        if (it == stock.end())
        {
            throw ItemNotFoundException();
        }
        else
        {
            if (it->second < quantity)
            {
                throw QuantityNotAvailableException();
            }
        }
        return it;
    }

    void openStock() const
    {
        std::cout << "-----------------------STOCK------------------------\n";
        for (auto i = stock.begin(); i != stock.end(); ++i)
        {
            std::cout << "Item code: " << i->first << "\tQuantity: " << i->second << '\n';
        }
    }
        
    
};

std::map<std::string, int> Store::stock;

class Cart : public Store
{
    std::map<std::string, int> cart;

    public:
    Cart() { }
    ~Cart() { }

    std::map<std::string, int>::iterator getItem(std::string itemCode, int quantity) override
    {
        auto it = cart.find(itemCode);
        if (it == cart.end())
        {
            throw ItemNotFoundException();
        }
        else
        {
            if (it->second < quantity)
            {
                throw QuantityNotAvailableException();
            }
        }
        return it;
    }
    
    void add(std::string itemCode, int quantity)
    {
        try
        {
            std::map<std::string, int>::iterator it = Store::getItem(itemCode, quantity);
            
            if (cart.find(itemCode) != cart.end())
            {
                cart.at(itemCode) += quantity;
            }
            else
            {
                cart.emplace(it->first, quantity);
            }
            it->second -= quantity;
            std::cout << "\n````````````````````````````````````````````````````\n";
            std::cout << "Item \'" << itemCode << "\' was added to your cart.\n";
            std::cout << "````````````````````````````````````````````````````\n";
        }
        catch (const ItemNotFoundException& x)
        {
            std::cerr << "Caught exception: " << x.what() << '\n';
        }
        catch (const QuantityNotAvailableException& x)
        {
            std::cerr << "Caught exception: " << x.what() << '\n';
        }
        
        
    }

    void remove(std::string itemCode, int quantity)
    {
        try
        {
            std::map<std::string, int>::iterator it = Cart::getItem(itemCode, quantity);
            if (cart.find(itemCode) != cart.end())
            {
                cart.at(itemCode) -= quantity;
            }
            else
            {
                cart.erase(it->first);
            }
            stock.at(it->first) += quantity;
            std::cout << "\n````````````````````````````````````````````````````\n";
            std::cout << "Item \'" << itemCode << "\' was deleted from your cart.\n";
            std::cout << "````````````````````````````````````````````````````\n";
        }
        catch (const ItemNotFoundException& x)
        {
            std::cerr << "Caught exception: " << x.what() << '\n';
        }
        catch (const QuantityNotAvailableException& x)
        {
            std::cerr << "Caught exception: " << x.what() << '\n';
        }
    }
    
    void openCart() const
    {
        std::cout << "------------------------CART------------------------\n";
        for (auto i = cart.begin(); i != cart.end(); ++i)
        {
            std::cout << i->first << "\t" << i->second << '\n';
        }
    }
};





void showMenu()
{
    std::cout << "========================MENU========================\n";
    std::cout << "1 - show products\n";
    std::cout << "2 - open cart\n";
    std::cout << "3 - add item\n";
    std::cout << "4 - remove item\n";
    std::cout << "5 - exit store\n";
    std::cout << "====================================================\n";
}

void getItemCodeAndQuantity(std::string& itemCode, int &quantity)
{
    std::cout << "----------------------------------------------------\n";
    std::cout << "Item code: ";
    std::getline(std::cin, itemCode);
    do
    {
    std::cout << "Quantity: ";                
    std::cin >> quantity;   
    } while (!correctInput(quantity));
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');     
    std::cout << "----------------------------------------------------\n";
}        
        



int main()
{
    Store store;
    store.fillInStock();

    Cart cart;

    std::string itemCode; 
    int quantity;

    int operation;
    while(true)
    {
        showMenu();
        do
        {
            std::cout << "\nChoose operation: ";
            std::cin >> operation;
        } while (!correctInput(operation));
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(operation)
        {
        case 1: store.openStock(); break;
        case 2: cart.openCart(); break;
        case 3: getItemCodeAndQuantity(itemCode, quantity); cart.add(itemCode, quantity); break;
        case 4: getItemCodeAndQuantity(itemCode, quantity); cart.remove(itemCode, quantity); break;
        case 5: return 0;  
        }
    }

    
    return 0;

}