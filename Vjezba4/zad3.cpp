#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void fuja() {
    int broj = 3;
    std::vector<std::string> stringovi;
    for (int i = 0; i < broj; i++) {
        std::string unos;
        std::cout << "Unesite string" << i + 1 << ": ";
        std::cin >> unos;
        stringovi.push_back(unos);
    }
    for (std::string& str : stringovi) {
        std::reverse(str.begin(), str.end());
    }
    std::sort(stringovi.begin(), stringovi.end());
    for (const std::string& str : stringovi) {
        std::cout << str << std::endl;
    }
}

int main() {
    fuja();
    return 0;
}