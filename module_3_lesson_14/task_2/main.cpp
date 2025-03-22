#include <iostream>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
#include "createDatabase.h"

int main() 
{
    createDatabase();


    std::ifstream file("movies.json"); 
    if (!file.is_open()) 
    {
        std::cerr << "Unable to open file movies.json" << '\n';
        return 1;
    }

    nlohmann::json movieDatabase;
    file >> movieDatabase;
    

    std::string actorName;
    std::cout << "Enter the actor's name to search: ";
    std::getline(std::cin, actorName); 


    bool found = false; 
    for (auto& [movieTitle, movieData] : movieDatabase.items()) 
    {
        for (auto& actorInfo : movieData["actors"]) 
        {
            std::string actor = actorInfo["actor"].get<std::string>();
            
            std::string actorLower = actor;
            std::transform(actorLower.begin(), actorLower.end(), actorLower.begin(), ::tolower);
            std::string searchNameLower = actorName;
            std::transform(searchNameLower.begin(), searchNameLower.end(), searchNameLower.begin(), ::tolower);

            if (actorLower.find(searchNameLower) != std::string::npos) 
            {
                std::string character = actorInfo["character"].get<std::string>();
                std::cout << "Actor: " << actor << ", Film: " << movieTitle << ", Character: " << character << '\n';
                found = true;
            }
        }
    }

    if (!found) 
    {
        std::cout << "Actor \"" << actorName << "\" was not found in any of the films." << '\n';
    }

    return 0;
}