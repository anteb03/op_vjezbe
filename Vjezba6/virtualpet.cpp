#include "virtualpet.hpp"
using namespace std;
VirtualPet::VirtualPet(const string& name, const string& type) : petName(name), petType(type) {
    srand(static_cast<unsigned int>(time(NULL)));
    hungerLevel = rand() % 100;
    happinessLevel = 0;
    awake = rand() % 2 == 1;
}

void VirtualPet::sleep() {
    happinessLevel += 15; 
    hungerLevel -= 20; 
}

void VirtualPet::eat() {
    happinessLevel += 10;
    hungerLevel += 10;
}

void VirtualPet::play() {
    happinessLevel += 20; 
    hungerLevel -= 20;
}


string VirtualPet::getName() const {
    return petName;
}

string VirtualPet::getType() const {
    return petType;
}

int VirtualPet::getHunger() const {
    if (hungerLevel > 100) {
        return 100;
    }
    if (hungerLevel < 0) {
        return 0;
    }
    else{ 
        return hungerLevel;
    }
}

int VirtualPet::getHappiness() const {
    if (happinessLevel > 100) {
        return 100;
    }
    else if (happinessLevel < 0) {
        return 0;
    }
    else {
        return happinessLevel;
    }
}

bool VirtualPet::isAwake() const {
    return awake;
}
