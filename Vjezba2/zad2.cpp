#include <iostream>

int& fuja(int niz[], int indeks) {
    return niz[indeks];
}

int main() {
    int niz[] = { 1, 5, 3, 8, 11 };
    int indeks = 2; 
    indeks--;
    fuja(niz, indeks)++;
    std::cout << niz[indeks] << std::endl;
    return 0;
}