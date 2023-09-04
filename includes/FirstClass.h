#ifndef FIRSTCLASS_H
#define FIRSTCLASS_H

#include "Stadium.h" // Include the base class header
#include "CustomBST.h" // Include the necessary header for bst (assuming it's a binary search tree)

class FirstClass : public Stadium {
protected:
    static bst<std::string> FirstClass_Data;

public:
    FirstClass();
    ~FirstClass();
    virtual bst<std::string>& GetDataStructure() override;
    virtual std::string GetFileName() override;
};

#endif