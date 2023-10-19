#include <iostream>
#include <vector>

void fuja(std::vector<int>& vector, int element) {
    for (int i = 0; i < vector.size(); ++i) {
        if (vector[i] == element) {
            vector[i] = vector.back();
            vector.pop_back();    
            break;
        }
    }
}
int main() {
    std::vector<int> vector = {5, 3, 9, 1, 7};
    fuja(vector, 5); 
    for (int num : vector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}

