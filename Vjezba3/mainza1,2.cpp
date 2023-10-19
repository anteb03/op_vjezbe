#include <iostream>
#include <vector>
#include "zadatak1.cpp"
#include "zadatak2.cpp"

int main() {
    std::vector<int> prviVektor;
    std::vector<int> drugiVektor;
    unossabrojemel(prviVektor, 5);
    std::cout << "Prvi vektor: ";
    ispisvek(prviVektor);
    unosveksintervalom(drugiVektor, 1, 10);
    std::cout << "Drugi vektor: ";
    ispisvek(drugiVektor);
    std::vector<int> razlika;
    razlikavek(prviVektor, drugiVektor, razlika);
    std::cout << "Razlika vektora: ";
    ispisvek(razlika);
    return 0;
}
