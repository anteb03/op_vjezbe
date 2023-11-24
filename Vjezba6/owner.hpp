#ifndef OWNER_H
#define OWNER_H

#include <iostream>
#include <vector>
#include "virtualpet.hpp"
using namespace std;
class Owner {
public:
    Owner(const std::string& name);
    Owner(const Owner& other);
    void addPet(const VirtualPet& pet);
    void performActions();
    const VirtualPet& getHappiestPet() const;
    string getOwnerName() const;

private:
    string name;
    vector<VirtualPet> pets;
};

#endif 
