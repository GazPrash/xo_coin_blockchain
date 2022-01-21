#include <iostream>
#include <vector>
#include <math.h>
#include <bitset>

using namespace std;

class hash_compression
{
private:
public:
    std::vector<int> state_registers_int = {2, 3, 5, 7, 11, 13, 17, 19};
    std::vector<std::string> state_registers_bin;
    std::vector<int> k_constants_int = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 
        37, 41, 43, 47, 53, 59, 61, 67, 71, 73,
        79, 83, 89, 97, 101, 103, 107, 109, 113,    
        127, 131, 137, 139, 149, 151, 157, 163,
        167, 173, 179, 181, 191, 193, 197, 199,
        211, 223, 227, 229, 233, 239, 241, 251,
        257, 263, 269, 271, 277, 281, 283, 293,
        307, 311
    };
    std::vector<std::string> k_constants_bin;
    hash_compression()
    {
        for (int k : state_registers_int)
        {
            double diff = abs(long(sqrt(k)) - double(sqrt(k)));
            unsigned long mid_int = diff * (pow(2, 32));
            state_registers_bin.push_back(std::bitset<32>(mid_int).to_string());
        }

        for (int j : k_constants_int){
            double cube_root = cbrt(j);
            unsigned long mid_intt = cube_root * (pow(2, 32));
            k_constants_bin.push_back(std::bitset<32> (mid_intt).to_string());
        }
    }
};
