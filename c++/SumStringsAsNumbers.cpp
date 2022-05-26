#include <string>

#include <iostream>

std::string sum_strings(const std::string &a, const std::string &b)
{
    std::string result;
    bool carry = false;
    size_t indexA = a.size();
    size_t indexB = b.size();

    int valueA = 0;
    int valueB = 0;
    int curResult = 0;

    while (indexA > 0 || indexB > 0)
    {
        valueA = indexA > 0 ? a.at(indexA - 1) - '0' : 0;
        valueB = indexB > 0 ? b.at(indexB - 1) - '0' : 0;
        curResult = valueA + valueB;
        if (carry) curResult += 1;
        carry = curResult > 9;
        result += std::to_string(curResult % 10);
        indexA = indexA > 0 ? indexA -= 1 : 0;
        indexB = indexB > 0 ? indexB -= 1 : 0;
    }
    if (carry)
    {
        result += "1";
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    std::cout << sum_strings("100", "19") << std::endl;
}