#include "owner.hpp"
#include "virtualpet.hpp"
#include<iostream>
#include<vector>
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    int numberofowners;
    cout << "Unesi broj vlasnika: ";
    cin >> numberofowners;
    vector<Owner> owners; 
    for (int i = 0; i < numberofowners; ++i) {
        string ownerName;
        cout << "Unesi ime vlasnika " << i + 1 << ": ";
        cin >> ownerName;

        Owner newOwner(ownerName);
        owners.push_back(newOwner);

        int numberofpets;
        cout << "Koliko ljubimaca zelite dodati vlasniku " << ownerName << " ? ";
        cin >> numberofpets;

        for (int j = 0; j < numberofpets; ++j) {
            string petName, petType;
       
            cout << "Unesite ime ljubimca: ";
            cin >> petName;
            cout << "Unesite vrstu ljubimca: ";
            cin >> petType;
     
            VirtualPet newPet(petName, petType);
            owners[i].addPet(newPet);
        }
        Owner copiedOwner = owners[0]; 
        owners.push_back(copiedOwner);
    }
    for (int i = 0; i < owners.size(); ++i) {
        owners[i].performActions();
    }
    for (int i = 0; i < owners.size(); ++i) {
        VirtualPet happiestPet = owners[i].getHappiestPet();
        cout << "Najsretniji ljubimac vlasnika " << owners[i].getOwnerName() << " je: " << happiestPet.getName() << endl;
    }
    return 0;
}
