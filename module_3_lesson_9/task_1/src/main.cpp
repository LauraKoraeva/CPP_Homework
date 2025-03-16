#include <iostream>
#include <vector>
#include <string>
#include "Branch.h"
#include "treeFunctions.h"

int main()
{
    std::vector<Branch*> forest(5);

    std::cout << "====================================================================\n";
    std::cout << "                             ELF FOREST                             \n";
    std::cout << "====================================================================\n";

    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Tree " << i + 1 << '\n';
        forest[i] = createTree();
        populateTree(forest[i]);
        std::cout << '\n';
    }

    std::cout << "Enter elf's name to find: ";
    std::string name;
    std::getline(std::cin, name);

    Branch* foundElf = nullptr;
    for (const auto& tree : forest)
    {
        foundElf = tree->lookForElf(name);
        if (foundElf != nullptr)
            break;
    }

    std::cout << '\n';

    if (foundElf != nullptr)
    {
        int neighbours = foundElf->countNeighbours();
        std::cout << name << " has " << neighbours << " neighbours.\n";
    }
    else
        std::cout << "Elf " << name << " was not found in the forest.\n";


    for (const auto& tree : forest)
    {
        delete tree;
    }
    forest.clear();

    return 0;
}

