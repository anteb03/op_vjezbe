#include "zadatak1.hpp"
#include <iostream>

void unossabrojemel(std::vector<int>& vektor, int brojel) {
    vektor.clear();
    vektor.reserve(brojel);
    for (int i = 0; i < brojel; ++i) {
        int element;
        std::cout << "Unesite element " << i + 1 << ": ";
        std::cin >> element;
        vektor.push_back(element);
    }
}

void ispisvek(const std::vector<int>& vektor) {
    for (const int& element : vektor) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}


void unosveksintervalom(std::vector<int>& vektor, int donja, int gornja) {
    vektor.clear();
    while (true) {
        int element;
        std::cout << "Unesite element (izmedu " << donja << " i " << gornja << "): ";
        std::cin >> element;
        if (element <= donja || element >= gornja) {
            break;
        }
        vektor.push_back(element);
    }
}