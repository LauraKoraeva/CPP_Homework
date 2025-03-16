#include <vector>
#include <string>
#include "Branch.h"

Branch::Branch(Branch* inParent) : elfName(""), parent(inParent) { } 

Branch* Branch::getTopBranch() const
{
    if (parent == nullptr)
        return nullptr;
    if (parent->parent == nullptr)
        return parent;
    return parent->getTopBranch();
}

Branch* Branch::lookForElf(std::string& inName)
{
    if (elfName == inName)
    {
        return this;
    }

    for (const auto& child : children)
    {
        Branch* found = child->lookForElf(inName);
        if (found != nullptr)
        {
            return found;
        }
    }
    return nullptr;
}

int Branch::countNeighbours() const
{
    Branch* topBranch = getTopBranch();
    if (topBranch == nullptr)
    {
        return 0;
    }

    int count = 0;
    std::vector<Branch*> branches;
    branches.push_back(topBranch);

    while (!branches.empty())
    {
        Branch* current = branches.back();
        branches.pop_back();

        if (!current->elfName.empty())
        {
            count++;
        }

        for (const auto& child : current->children)
        {
            branches.push_back(child);
        }
    }

    if (!elfName.empty())                       
    {
        --count;
    }

    return count;
}

Branch::~Branch()
{
    for (Branch* child : children)
    {
        delete child;
    }
    children.clear();
}