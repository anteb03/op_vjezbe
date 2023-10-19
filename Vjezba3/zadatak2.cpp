#include "zadatak2.hpp"
#include <algorithm>

void razlikavek(const std::vector<int>& vektor1, const std::vector<int>& vektor2, std::vector<int>& rezultat) {
    for (const int& element : vektor1) {
        if (std::find(vektor2.begin(), vektor2.end(), element) == vektor2.end()) {
            rezultat.push_back(element);
        }
    }
}

