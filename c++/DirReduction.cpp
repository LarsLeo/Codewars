#include <vector>
#include <iostream>
#include <unordered_map>

class DirReduction
{
public:
    static std::vector<std::string> dirReduc(std::vector<std::string>& arr) {
        auto it = arr.begin();

        while(it < arr.end() - 1) {
            auto it2 = it + 1;
            if ((*it == "NORTH" && *it2 == "SOUTH") || (*it == "SOUTH" && *it2 == "NORTH") 
            || (*it == "EAST" && *it2 == "WEST") || (*it == "WEST" && *it2 == "EAST")) {
                arr.erase(it2);
                arr.erase(it);
                it = arr.begin();
            }
            else {
                ++it;
            }
        }
        
        return arr;
    }
};

int main() {
    std::vector<std::string> d1 = {"NORTH","SOUTH", "WEST"};
    std::vector<std::string> ans1 = DirReduction::dirReduc(d1);
    for (const auto direction: ans1) {
        std::cout << direction << std::endl;
    }
}