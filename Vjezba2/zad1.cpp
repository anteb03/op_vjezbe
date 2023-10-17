#include <iostream>

void fuja(const int niz[], int velicina, int& najmanji, int& najveci) {
    najmanji = najveci = niz[0];
    for (int i = 0; i < velicina; i++) {
        if (niz[i] < najmanji) {
            najmanji = niz[i];
        }
        if (niz[i] > najveci) {
            najveci = niz[i];
        }
    }
}

int main() {
    int velicina;
    std::cout << "Koliko cete clanova niza:";
    std::cin >> velicina;
    if (velicina <= 0) {
        std::cerr << "Nemoguce je napravit niz." << std::endl;
        return 1;
    }
    int* niz = new int[velicina]; 
    std::cout << "Unesite " << velicina << " clana niza:" << std::endl;
    for (int i = 0; i < velicina; i++) {
        std::cin >> niz[i];
    }
    int najmanji, najveci;
    fuja(niz, velicina, najmanji, najveci);
    std::cout <<  najmanji << std::endl;
    std::cout <<  najveci << std::endl;
    delete[] niz; 
    return 0;
}

