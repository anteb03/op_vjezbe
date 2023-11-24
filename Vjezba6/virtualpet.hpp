#ifndef VIRTUALPET_H
#define VIRTUALPET_H

#include <iostream>
using namespace std;
class VirtualPet {
public:
    VirtualPet(const string& name, const string& type);
    void eat();
    void sleep();
    void play();
    string getName() const;
    string getType() const;
    int getHunger() const;
    int getHappiness() const;
    bool isAwake() const;
    void setAwake(bool value) {
        awake = value;
    }

private:
    string petName;
    string petType;
    int hungerLevel;
    int happinessLevel;
    bool awake;
};

#endif