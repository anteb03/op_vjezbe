#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

std::string convertToPigLatin(const std::string& word) {
    std::string pigLatinWord = word;
    char first = tolower(pigLatinWord[0]);

    if (isVowel(first)) {
        pigLatinWord += "hay";
    }
    else {
        size_t firstVowelPos = 0;
        for (size_t i = 1; i < pigLatinWord.length(); i++) {
            if (isVowel(pigLatinWord[i])) {
                firstVowelPos = i;
                break;
            }
        }
        pigLatinWord = pigLatinWord.substr(firstVowelPos) + pigLatinWord.substr(0, firstVowelPos) + "ay";
    }
    return pigLatinWord;
}

int main() {
    std::vector<std::string> sentences = {
        "Ovo ej prv recenica.",
        "Evo druge recenice za prijevod.",
        "Treća recenica za testiranje programa."
    };
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int randomIndex = std::rand() % sentences.size();
    std::string randomstring = sentences[randomIndex];
    std::string pigLatinResult;
    size_t start = 0;
    size_t end = 0;
    while (end != std::string::npos) {
        end = randomstring.find_first_of(" .,!?;:", start);
        std::string word = randomstring.substr(start, end - start);
        if (!word.empty()) {
            std::string pigLatinWord = convertToPigLatin(word);
            pigLatinResult += pigLatinWord +  " ";
        }
        start = end + 1;
    }
    std::cout << "Izabrana: " << randomstring << std::endl;
    std::cout << "Prijevod: " << pigLatinResult << std::endl;
    return 0;
}
