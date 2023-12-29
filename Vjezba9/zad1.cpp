#include <iostream>
#include <string>

using namespace std;

template <typename T>
T mymin(T a, T b) {
    return (a < b) ? a : b;
}

int main() {
    int intMin = mymin(5, 10);
    cout << intMin << endl;

    string strMin = mymin("kokos", "broj");
    cout << strMin << endl;

    return 0;
}