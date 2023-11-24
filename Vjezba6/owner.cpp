#include "owner.hpp"
using namespace std;

Owner::Owner(const std::string& name) : name(name) {}

Owner::Owner(const Owner& other) : name(other.name), pets(other.pets) {}

void Owner::addPet(const VirtualPet& pet) {
    pets.push_back(pet);
}

void Owner::performActions() {
    srand(static_cast<unsigned int>(time(NULL)));
    int numActions = 5;

    for (auto& pet : pets) {
        cout << "Glad: " << pet.getHunger() << ", Sreca: " << pet.getHappiness() << endl;

        for (int i = 0; i < numActions; ++i) {
            if (pet.isAwake()) {
                if (pet.getHunger() <= 5) {
                    cout << "Ljubimac " << pet.getName() << " je pojeo hranu jer je bio gladan." << endl;
                    pet.eat();
                }
                else {
                    int action = rand() % 2;
                    if (action == 0) {
                        cout << "Ljubimac " << pet.getName() << " je pojeo hranu." << endl;
                        pet.eat();
                    }
                    else {
                        cout << "Ljubimac " << pet.getName() << " se igrao." << endl;
                        pet.play();
                    }
                }
            }
            else {
                cout << "Ljubimac " << pet.getName() << " je zaspao." << endl;
                pet.sleep();
                pet.setAwake(true);
            }
        }

        cout << "Glad: " << pet.getHunger() << ", Sreca: " << pet.getHappiness() << endl;
        cout << endl;
    }
}

const VirtualPet& Owner::getHappiestPet() const {
    if (pets.empty()) {
        cout << "Vlasnik nema najsretnijeg ljubimca";
    }
    size_t happiestPetIndex = 0; 
    for (size_t i = 1; i < pets.size(); ++i) {
        if (pets[i].getHappiness() > pets[happiestPetIndex].getHappiness()) {
            happiestPetIndex = i; 
        }
    }
    return pets[happiestPetIndex];
}

string Owner::getOwnerName() const {
    return name;
}