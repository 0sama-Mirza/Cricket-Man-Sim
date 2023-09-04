#ifndef VIP_H
#define VIP_H

#include "Stadium.h" // Include the base class header
#include "CustomBST.h"     // Include the necessary header for bst (assuming it's a binary search tree)

class VIP : public Stadium {
protected:
    static bst<std::string> VIP_Data;

public:
    VIP();
    ~VIP();
    bst<std::string>& GetDataStructure();
    virtual std::string GetFileName() override;
    
};

#endif
