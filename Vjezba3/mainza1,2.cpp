#include <iostream>
#include <vector>
#include "zadatak1.cpp"
#include "zadatak2.cpp"

int main() {
    std::vector<int> prvi;
    std::vector<int> drugi;
    unossabrojemel(prvi, 5);
    std::cout << "Prvi vektor: ";
    ispisvek(prvi);
    unosveksintervalom(drugi, 1, 10);
    std::cout << "Drugi vektor: ";
    ispisvek(drugi);
    std::vector<int> razlika;
    razlikavek(prvi, drugi, razlika);
    std::cout << "Razlika vektora: ";
    ispisvek(razlika);
    return 0;
}
