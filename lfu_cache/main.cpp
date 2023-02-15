#include <iostream>
#include <string>
#include "cache.hpp"
#include "page.hpp"

int main(int argc, const char *argv[])
{
    cache::cache_t my_cache(3);
    std::cout << "Принято на вход " << argc << " параметров." << std::endl;

    for(int i = 1; i < argc; i++)
    {
        std::string str = argv[i];
        //my_cache.append(i, cache::page_t(str.length(), str.c_str()));
        my_cache.append(i, str);
        std::cout << "Этап " << i << ". Содержимое кэша:" << std::endl;
        for(int k = 0; k < i; k++)
        {
            auto data = my_cache.get(k + 1);
            std::cout << "Ключ: " << k + 1 << ", Содержимое: " << data << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
