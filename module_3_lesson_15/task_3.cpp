// Продвинутые темы и техники C++
// Урок 15. Использование исключений

// Задание 3. Реестр данных на шаблонах

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <numeric>

template<typename T>
bool correctInput(T input)
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


enum Commands
{
    ADD = 1,
    REMOVE,
    PRINT,
    FIND,
    EXIT,
};

void showCommands()
{
    std::cout << "\n=====================COMMANDS=====================\n";
    std::cout << "1 - add\n";
    std::cout << "2 - remove\n";
    std::cout << "3 - print\n";
    std::cout << "4 - find\n";
    std::cout << "5 - exit\n";
    std::cout << "==================================================\n\n";
}


enum Types
{
    INT = 1,
    DOUBLE,
    STRING,
};

void printTypes()
{
    std::cout << "1 - int\n";
    std::cout << "2 - double\n";
    std::cout << "3 - string\n";
}


template <typename KeyType, typename ValueType>
class Registry
{
private:
    struct Entry
    {
        KeyType key;
        ValueType value;
    };

    std::vector<Entry> entries;

public:
    void add(const KeyType& key, const ValueType& value)
    {
        entries.push_back({key, value});
    }

    void remove(const KeyType& key)
    {
        bool found = false;
        for (auto it = entries.begin(); it != entries.end(); )
        {
            if (it->key == key)
            {
                it = entries.erase(it);
                found = true;
                std::cout << "\n==================================================\n";
                std::cout << "The entry was removed from the registry.\n";
                std::cout << "==================================================\n\n";
            }
            else
            {
                ++it;
            }
        }
        if (!found)
        {
            std::cout << "\n==================================================\n";
            std::cout << "\"" << key << "\" was not found." << std::endl;
            std::cout << "==================================================\n\n";
        }
    }

    void print() const
    {
        if (entries.empty())
        {
            std::cout << "\n==================================================\n";
            std::cout << "Registry is empty." << std::endl;
            std::cout << "==================================================\n\n";
            return;
        }
        std::cout << "\n==================================================\n";
        std::cout << "CONTENTS OF THE REGISTRY:" << '\n';
        std::cout << "==================================================\n";
        for (const auto& entry : entries)
        {
            std::cout << "Key: " << entry.key << "\tValue: " << entry.value << std::endl;
        }
        std::cout << "==================================================\n\n";
    }

    void find(const KeyType& key) const
    {
        bool found = false;
        for (const auto& entry : entries)
        {
            if (entry.key == key)
            {
                std::cout << "\n==================================================\n";
                std::cout << "Key: " << entry.key << "\tValue: " << entry.value << std::endl;
                std::cout << "==================================================\n\n";
                found = true;
            }
        }
        if (!found)
        {
            std::cout << "\n==================================================\n";
            std::cout << "\"" << key << "\" was not found." << std::endl;
            std::cout << "==================================================\n\n";
        }
    }
};


template <typename KeyType, typename ValueType>
void processCommands(Registry<KeyType, ValueType>& registry)
{
    int command;
    while (true)
    {
        do
        {
            showCommands();
            std::cout << "Choose the command: ";
            std::cin >> command;
        } while (!correctInput(command));

        KeyType key;
        ValueType value;

        switch (command)
        {
        case ADD:
            do
            {
                std::cout << "Enter the key: ";
                std::cin >> key;
            } while (!correctInput(key));
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            do
            {
                std::cout << "Enter the value: ";
                std::cin >> value;
            } while (!correctInput(value));
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            registry.add(key, value);
            std::cout << "\n==================================================\n";
            std::cout << "A new entry was added to the registry.\n";
            std::cout << "==================================================\n\n";
            break;
        case REMOVE:
            do
            {
                std::cout << "Enter the key: ";
                std::cin >> key;
            } while (!correctInput(key));
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            registry.remove(key);
            break;

        case PRINT:
            registry.print();
            break;
        case FIND:
            do
            {
                std::cout << "Enter the key: ";
                std::cin >> key;
            } while (!correctInput(key));
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            registry.find(key);
            break;
        case EXIT:
            return;
        default:
            std::cout << "Unknown command.\n";
            break;
        }
    }
}


int main()
{
    int keyType, valueType;
    do
    {
        std::cout << "Choose the type of the key:\n";
        printTypes();
        std::cin >> keyType;
    } while (!correctInput(keyType));

    do
    {
        std::cout << "Choose the type of the value:\n";
        printTypes();
        std::cin >> valueType;
    } while (!correctInput(valueType));


    if (keyType == INT && valueType == INT)
    {
        Registry<int, int> registry;
        processCommands(registry);
    }
    else if (keyType == INT && valueType == DOUBLE)
    {
        Registry<int, double> registry;
        processCommands(registry);
    }
    else if (keyType == INT && valueType == STRING)
    {
        Registry<int, std::string> registry;
        processCommands(registry);
    } else if (keyType == DOUBLE && valueType == INT)
    {
        Registry<double, int> registry;
        processCommands(registry);
    }
    else if (keyType == DOUBLE && valueType == DOUBLE)
    {
        Registry<double, double> registry;
        processCommands(registry);
    }
    else if (keyType == DOUBLE && valueType == STRING)
    {
        Registry<double, std::string> registry;
        processCommands(registry);
    }
    else if (keyType == STRING && valueType == INT)
    {
        Registry<std::string, int> registry;
        processCommands(registry);
    }
    else if (keyType == STRING && valueType == DOUBLE)
    {
        Registry<std::string, double> registry;
        processCommands(registry);
    }
    else if (keyType == STRING && valueType == STRING)
    {
        Registry<std::string, std::string> registry;
        processCommands(registry);
    }
    else
    {
        std::cout << "Unsupported key or value type." << std::endl;
    }

    return 0;
}

