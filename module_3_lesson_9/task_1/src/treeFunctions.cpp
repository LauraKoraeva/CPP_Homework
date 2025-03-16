#include <iostream>
#include <random>
#include <algorithm>
#include "treeFunctions.h"
#include "Branch.h"

Branch* createTree()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> bigBranchCountRange(3, 5);
    std::uniform_int_distribution<> smallBranchCountRange(2, 3);

    Branch* tree = new Branch;

    int bigBranchCount = bigBranchCountRange(mt);
    for (int i = 0; i < bigBranchCount; ++i)
    {
        Branch* bigBranch = new Branch(tree);
        tree->children.push_back(bigBranch);

        int smallBranchCount = smallBranchCountRange(mt);
        for (int j = 0; j < smallBranchCount; ++j)
        {
            Branch* smallBranch = new Branch(bigBranch);
            bigBranch->children.push_back(smallBranch);
        }
    }
    return tree;
}

void populateTree(Branch* tree)
{
    std::vector<Branch*> branches;
    branches.push_back(tree);

    int count = 1;                                                                         
    std::cout << "Enter elf's name for each branch or 'None' if nobody lives there.\n\n";     
    while (!branches.empty())
    {
        Branch* current = branches.back();
        branches.pop_back();
        
        if (current->parent != nullptr)
        {
            std::string name;
            std::cout << "Branch " << count++ << ": ";   
            std::getline(std::cin, name);

            if (name != "None")
            {
                current->elfName = name;
            }
        }

        for (Branch* child : current->children)
        {
            branches.push_back(child);
        }
    }
}