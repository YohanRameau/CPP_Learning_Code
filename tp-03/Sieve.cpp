#include <vector>
#include <iostream>
#define SIZE 25
int main()
{
    std::vector<unsigned long> vec(SIZE-1,0);
    for (size_t i = 0; i < vec.size(); i++)
    {
        vec[i] = i + 2;
    }

    
    for (auto it = vec.begin(); (*it * (*it) <= SIZE); ++it)
    {
        for (auto it2 = vec.begin(); it2 != vec.end();)
        {
            if ( *it2 % *it == 0 && *it != *it2)
            {
                it2 = vec.erase(it2);
            }
            else
            {
                ++it2;
            }
        }
    }
    
    for(auto v: vec)
    {
        std::cout << v << std::endl;
    }
    

    return 0;
}
