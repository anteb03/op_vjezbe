#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

std::string fuja(const std::vector<std::string>& recenice) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    int random = std::rand() % recenice.size();
    std::string izabrana = recenice[random];
    std::cout << izabrana << std::endl;
    std::string piglatinrečenica = "";
    std::string word = "";
    for (char c : izabrana) {
        if (std::isalpha(c)) {
            word += c;
        }
        else {
            if (!word.empty()) {
                std::string piglatinword = "";
                char prvi = std::tolower(word[0]);
                if (prvi == 'a' || prvi == 'e' || prvi == 'i' || prvi == 'o' || prvi == 'u') {
                    piglatinword = word + "hay";
                }
                else {
                    int index = 0;
                    while (index < word.size() && !std::strchr("aeiouAEIOU", word[index])) {
                        index++;
                    }
                    if (index < word.size()) {
                        piglatinword = word.substr(index) + word.substr(0, index) + "ay";
                    }
                    else {
                        piglatinword = word + "ay";
                    }
                }
                piglatinrečenica += piglatinword + c;
                word = "";
            }
            else {
                piglatinrečenica += c;
            }
        }
    }
    if (!word.empty()) {
        std::string piglatinword = "";
        char prvi = std::tolower(word[0]);
        if (prvi == 'a' || prvi == 'e' || prvi == 'i' || prvi == 'o' || prvi == 'u') {
            piglatinword = word + "hay";
        }
        else {
            int index = 0;
            while (index < word.size() && !std::strchr("aeiouAEIOU", word[index])) {
                index++;
            }
            if (index < word.size()) {
                piglatinword = word.substr(index) + word.substr(0, index) + "ay";
            }
            else {
                piglatinword = word + "ay";
            }
        }
        piglatinrečenica += piglatinword;
    }
    return piglatinrečenica;
}
int main() {
    std::vector<std::string> recenice = { "Hhello, wrorld!","Wjjat time sis it?","This is a ttest sqentence." };
    std::string piglatin = fuja(recenice);
    std::cout << piglatin << std::endl;
    return 0;
}