#include <vector>
#include <cstdint>
#include <cstdio>

int main()
{
    std::vector<std::uint8_t> v1{1U, 2U, 3U};
    
    //  a) Index. 
    for (std::size_t i = 0; i < v1.size(); ++i) 
    {
        std::printf("0x%02X\n", v1[i]);
    }
   
    // b) Range-baserad for-loop med hexadecimal utskrift
    for (auto val : v1) 
    {
        std::printf("0x%02X\n", val);
    }

    // c) Iteration via C++-iterator med hexadecimal utskrift
    for (auto it = v1.begin(); it != v1.end(); ++it)
    {
        std::printf("0x%02X\n", *it);
    } 
    return 0;
}


