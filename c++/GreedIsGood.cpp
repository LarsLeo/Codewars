#include <vector>
#include <iostream>
#include <unordered_map>

int score(const std::vector<int>& dice) {
    std::unordered_map<int, int> hits;
    int result = 0;

    for (const auto hit : dice) {
        hits[hit] += 1;
    }

    if (hits[1] > 2) {
        result += 1000;
        hits[1] -= 3;
    } 

    if(hits[1] > 0) {
        result += hits[1] * 100;
    }

    for (int i = 2; i < 7; i++) {
        if (hits[i] > 2) {
            result += i * 100;
            hits[i] -= 3;
        }
    }

    if(hits[5] > 0) {
        result += hits[5] * 50;
    }

    return result;
}

int main() {
    int answ1 = score({2, 3, 4, 6, 2});
    int answ2 = score({2, 4, 4, 5, 4});
    std::cout << answ1 << std::endl;
    std::cout << answ2 << std::endl;
}