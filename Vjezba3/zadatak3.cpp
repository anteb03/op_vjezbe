#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vector = {18,23,117,23,1};
    int min = *std::min_element(vector.begin(), vector.end());
    auto i = std::find(vector.begin(), vector.end(), min);
    vector.insert(i, 0);
    int max = *std::max_element(vector.begin(), vector.end());
    int sum = 0;
    bool maxx = false;
    for (auto i = vector.begin(); i != vector.end(); i++) {
        if (*i == max) {
            maxx = true;
            continue;
        }
        if (maxx) {
            sum += *i;
        }
    }
    for (int num : vector) {
        std::cout << num << " ";
    }
    std::cout << "\n" << sum << std::endl;
    return 0;
}

