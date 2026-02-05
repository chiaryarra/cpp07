#include "Array.hpp"
#include <iostream>

int main()
{
    try
    {
        Array<int> a(5);

        for (int i = 0; i < 5; i++)
            a[i] = i * 10;

        for (int i = 0; i < 5; i++)
            std::cout << a[i] << std::endl;

        std::cout << "Tentando acessar fora do limite..." << std::endl;
        std::cout << a[10] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Erro: " << e.what() << std::endl;
    }
}