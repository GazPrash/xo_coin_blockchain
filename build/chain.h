#pragma once
#include "../hashing/hashing.h"
#include "block.h"
#include<vector>
#include<map>

using std::string;
using std::vector;

class chain{
    private:

    public:
        // load the chain instance based on the input signature/id
        // and then set the instance to chain_instance variable.
        vector<block*> block_ledger;
        string recent_block_id;
        void add_block(block*);

};

void chain :: add_block(block* block_obj){
    block_obj->phash = recent_block_id;
    block_ledger.push_back(block_obj);
    recent_block_id = block_obj->chash;

}

