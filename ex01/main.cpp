#include <iostream>
#include "iter.hpp"

template <typename T>
void print(T const& x)
{
    std::cout << x << std::endl;
}

void increment(int& x)
{
    x++;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    iter(arr, 5, print<int>);
    iter(arr, 5, increment);
    iter(arr, 5, print<int>);

    std::string strs[] = {"oi", "tudo", "bem"};

    iter(strs, 3, print<std::string>);

    return 0;
}