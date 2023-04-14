#include <iostream>
#include <string>

bool IsKPeriodic(const std::string& str, size_t k)
{
    const size_t sizeStr = str.size();

    if (0 == k || sizeStr <= k)
    {
        std::cout << "Incorrect multiplicity value" << std::endl;
        return false;
    }
    if (0 != (sizeStr % k))
    {
        std::cout << "The string is not a multiple " << k << std::endl;
        return false;
    }
    std::string pat = str.substr(0, k);

    size_t j = 0;
    const size_t size_ = k - 1;
    for (size_t i = k; i < sizeStr; i++)
    {
        if (pat[j] != str[i])
        {
            std::cout << "The string is not a multiple " << k << std::endl;
            return false;
        }
        size_ > j ? ++j : j = 0;
    }
    std::cout << "The string is a multiple " << k << std::endl;
    return true;
}


int main()
{
    do
    {
        std::cout << "Enter text: ";
        std::string str;
        std::cin >> str;

        std::cout << "Enter the multiplicity value: ";
        size_t k = 12;
        std::cin >> k;

        IsKPeriodic(str, k);

        std::string key;
        do
        {   // runs until an available value is entered (0 or 1)
            std::cout << "Enter: 1 - repeat input  /  0 - exit: ";
            std::cin >> key;
        } while (!("0" == key || "1" == key));

        if ("0" == key)
        {
            return 0;
        }
    } while (true);

    return 0;
}