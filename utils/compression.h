#pragma once
#include "sha256_algorithm.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <bitset>
#include <sstream>

using namespace std;

class hash_compression{
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
                unsigned long mid_int = diff * (long long)(pow(2, 32));
                state_registers_bin.push_back(std::bitset<32>(mid_int).to_string());
            }

            for (int j : k_constants_int){
                double cube_root = cbrt(j);
                unsigned long mid_intt = cube_root * (long long)(pow(2, 32));
                k_constants_bin.push_back(std::bitset<32> (mid_intt).to_string());
            }
        }

        void prepare_states(vector<std::string> &message_schedule);
        std::string hex_digest();
};

void hash_compression :: prepare_states(vector<std::string> &message_schedule){
    // t1 = sigma_1 (e) + ch(e, f, g) + h + k0 + wo
    // t2 = sigma_0 (a) + maj(a, b c)
    
    sha256 algorithm;
    int rounds = 0;

    // t1 & t2 calculation 
    while (rounds <= 63){
        std::string s1_e = algorithm.sigma_1(state_registers_bin[4]);
        std::string ch_efg =  algorithm.ch_func(state_registers_bin[4],
                                                state_registers_bin[5],
                                                state_registers_bin[6]);
            
        std::string s0_a = algorithm.sigma_0(state_registers_bin[0]);
        std::string maj_abc= algorithm.maj_func(state_registers_bin[0],
                                                state_registers_bin[1],
                                                state_registers_bin[2]);
        
        unsigned long mid_int1= stoul(s1_e, nullptr, 2)+
                                stoul(ch_efg, nullptr, 2)+
                                stoul(state_registers_bin[5], nullptr, 2)+
                                stoul(k_constants_bin[rounds], nullptr, 2)+
                                stoul(message_schedule[rounds], nullptr, 2);

        unsigned long mid_int2= stoul(s0_a, nullptr, 2)+
                                stoul(maj_abc, nullptr, 2);

        unsigned long mid_int = mid_int1 + mid_int2;
        mid_int %= (long long)(pow(2, 32));
        std::string new_state = std::bitset<32>(mid_int).to_string();
        state_registers_bin.pop_back();
        state_registers_bin.insert(state_registers_bin.begin(), new_state);

        rounds++;
    }

}

std::string hash_compression :: hex_digest(){
    std::string hash;
    unsigned long mid_intt = 0; 
    int temp = 0; 
    for (std::string state : state_registers_bin){
        mid_intt = stoul(state, nullptr, 2);
        std::stringstream ss;
        ss << std::hex << mid_intt;
        hash += ss.str();
    }

    return hash;
}