#pragma once
#include "../hashing/hashing.h"
#include<vector>
#include<map>


class block{
    private:
        int nonce;
    public:
        std::string phash;
        std::string chash;
        std::string initialize_block(std::vector<std::string>);
};

std::string block :: initialize_block(std::vector<std::string> transactions){
    hashing h2c;
    string tsaction_data;

    for (std::string tsaction: transactions){
        // h2c.object = tsaction;
        // chash += h2c.get_hash();
        tsaction_data += tsaction;
    }

    h2c.object = tsaction_data;
    chash = h2c.get_hash();
    // plan : concatenate all the tsaction data --> convert to binary --> then decimal take the modulo 232
    // and then convert to binary again....maybe that'll define a set size or maybe not.

    return chash;
}
