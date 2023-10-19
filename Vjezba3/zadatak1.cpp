#include "zadatak1.hpp"
#include <iostream>

void unossabrojemel(std::vector<int>& vektor, int brojElemenata) {
    vektor.clear();
    vektor.reserve(brojElemenata);
    for (int i = 0; i < brojElemenata; ++i) {
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


void unosveksintervalom(std::vector<int>& vektor, int donjaGranica, int gornjaGranica) {
    vektor.clear();
    while (true) {
        int element;
        std::cout << "Unesite element (izmedu " << donjaGranica << " i " << gornjaGranica << "): ";
        std::cin >> element;
        if (element <= donjaGranica || element >= gornjaGranica) {
            break;
        }
        vektor.push_back(element);
    }
}