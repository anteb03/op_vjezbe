#include <iostream>
#include <string>
#include <cctype>

std::string fun(const std::string& recenica) {
    std::string rez = recenica;
    for (size_t i = 0; i < rez.length(); ++i) {
        if (ispunct(rez[i])) {
            size_t j = i - 1;
            while (j > 0 && isspace(rez[j])) {
                rez.erase(j, 1);
                j--;
            }
            j = i + 1;
            while (j < rez.length() && isspace(rez[j])) {
                rez.erase(j, 1);
            }
        }
    }
    for (size_t i = 0; i < rez.length(); ++i) {
        if (ispunct(rez[i]) && i < rez.length() - 1 && rez[i + 1] != ' ') {
            rez.insert(i + 1, " ");
        }
    }
    return rez;
}

int main() {
    std::string recenica = "Ja bih ,      ako ikako mogu,    ovu recenicu napisao ispravno .";
    std::cout << recenica << std::endl;
    std::string rez = fun(recenica);
    std::cout << rez << std::endl;
    return 0;
}