#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class Set {
private:
    vector<T> elements;

public:
    void add(T element) {
        if (!contains(element)) {
            elements.push_back(element);
        }
    }

    void remove(T element) {
        elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
    }

    bool contains(T element) const {
        return find(elements.begin(), elements.end(), element) != elements.end();
    }
};

int main() {
    Set<int> intSet;
    intSet.add(5);
    intSet.add(10);
    int broj = 5; 
    if (intSet.contains(broj)) {
        cout << "Ima "  << broj << endl;
    }
    else {
        cout << "Nema " << broj << endl;
    }

    intSet.remove(5);

    if (intSet.contains(5)) {
        cout << "Ima " << broj << endl;
    }
    else {
        cout << "Nema " << broj << endl;
    }

    Set<string> strSet;
    strSet.add("apple");
    strSet.add("orange");
    strSet.add("banana");
    string str = "banan";
    cout << "Sadrzi "<< str << ":" << strSet.contains(str) << endl;

    return 0;
}

