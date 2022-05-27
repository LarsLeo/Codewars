#include <iostream>

#include <vector>
#include <sstream>

class Fracts
{
public:
    static std::string convertFrac(std::vector<std::vector<unsigned long long>> &lst) {
        unsigned long long lcm = 1;
        std::stringstream result("");
        for (const auto denomVec : lst) {
            const auto denom = denomVec.at(1);
            lcm = Fracts::lcm(lcm, denom);
        }
        for (const auto denomVec : lst) {
            const auto num = denomVec.at(0);
            const auto denom = denomVec.at(1);
            const auto multResult = num * lcm / denom;
            result << "(" << multResult << "," << lcm << ")";
        }

        return result.str();
    }

    static long long gcd(unsigned long long a, unsigned long long b)
    {
        if (b == 0)
            return a;
        return Fracts::gcd(b, a % b);
    }
 
    static long long lcm(unsigned long long a, unsigned long long b)
    {
        return (a / Fracts::gcd(a, b)) * b;
    }
};

int main() {
    std::vector<std::vector<unsigned long long>> lst { {1, 2}, {1, 3}, {1, 4} };
    std::cout << Fracts::convertFrac(lst) << std::endl;
}