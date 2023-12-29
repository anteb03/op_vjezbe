#include <iostream>
#include <algorithm>
#include <cstring> 

using namespace std;

template <typename T>
void sortArray(T arr[], int size) {
    sort(arr, arr + size);
}

template <>
void sortArray<char>(char arr[], int size) {
    sort(arr, arr + size, [](char a, char b) {
        return tolower(a) < tolower(b);
        });
}

int main() {
    int intArray[] = { 3, 1, 4, 2, 5 };
    int size1 = sizeof(intArray) / sizeof(intArray[0]);
    sortArray(intArray, size1);

    char charArray[] = { 'B', 'a', 'D', 'c' };
    int size2 = sizeof(charArray) / sizeof(charArray[0]);
    sortArray(charArray, size2);

    for (int i = 0; i < 5; ++i) {
        cout << intArray[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 4; ++i) {
        cout << charArray[i] << " ";
    }
    cout << endl;

    return 0;
}
