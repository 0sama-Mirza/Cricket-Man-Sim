#ifndef GENERAL_H
#define GENERAL_H

#include "Stadium.h" // Include the base class header
#include "CustomBST.h" // Include the necessary header for bst (assuming it's a binary search tree)

class General : public Stadium {
protected:
    static bst<std::string> General_Data;

public:
    General();
    ~General();
    virtual bst<std::string>& GetDataStructure() override;
    virtual std::string GetFileName() override;
};

#endif
