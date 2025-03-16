#pragma once
#include <string>
class Branch
{
private:
    std::string elfName;
    Branch* parent;
    std::vector<Branch*> children;

public:                                                               
    Branch(Branch* inParent = nullptr);

    Branch* getTopBranch() const;

    Branch* lookForElf(std::string& inName);

    int countNeighbours() const;

    ~Branch();


    friend Branch* createTree();

    friend void populateTree(Branch* tree);

};
