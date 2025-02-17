#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

class Branch 
{
public:
    std::string elfName;
    Branch* parent;
    std::vector<Branch*> children;

    Branch(Branch* inParent = nullptr) : elfName(""), parent(inParent) { }

    ~Branch() 
    {
        for (Branch* child : children) 
        {
            delete child;
        }
    }

    Branch* getTopBranch()
    {
        if (parent == nullptr)
            return nullptr;
        if (parent->parent == nullptr)
            return parent;
        return parent->getTopBranch();
    }

    Branch* lookForElf(std::string& inName) 
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

    int countNeighbors() 
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
};

Branch* createTree(int treeNumber) 
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> bigBranchCountRange(3, 5);
    std::uniform_int_distribution<> smallBranchCountRange(2, 3);

    Branch* tree = new Branch(); 
  
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

int main() 
{
    std::vector<Branch*> forest(5);

    for (int i = 0; i < 5; ++i) 
    {
        forest[i] = createTree(i);
    }

    for (int i = 0; i < 5; ++i) 
    {
        std::vector<Branch*> branches;
        branches.push_back(forest[i]);

        while (!branches.empty()) {
            Branch* current = branches.back();
            branches.pop_back();

            if (current->parent != nullptr) 
            { 
                std::cout << "Enter elf's name for the branch or 'None' if nobody lives here: ";
                std::string name;
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

    std::cout << "\nEnter elf's name to find: ";
    std::string name;
    std::getline(std::cin, name);

    Branch* foundElf = nullptr;
    for (const auto& tree : forest) 
    {
        foundElf = tree->lookForElf(name);
        if (foundElf != nullptr)
            break;
    }

    if (foundElf != nullptr) 
    {
        int neighbors = foundElf->countNeighbors();
        std::cout << name << " has " << neighbors << " neighbors.\n";
    }
    else 
        std::cout << "Elf " << name << " was not found in the forest.\n";

    for (const auto& tree : forest) 
    {
        delete tree;
    }

    return 0;
}

