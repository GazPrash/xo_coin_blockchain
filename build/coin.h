#pragma once
#include "wallet.h"
#include "../hashing/hashing.h"
#include<iostream>
#include<vector>

class coin{
    public:
        std::string proof_of_work; // giver-monet-timestamp-reciver
        void trade(int, std::string, std::string, std::string);

};

void coin :: trade(int exchange, std::string trigger, std::string target, std::string timestamp){
    user userw;
    
    if (exchange <= userw.check_balance(trigger)){
        std::string info_string  = trigger+
                                    std::to_string(exchange)+
                                    timestamp+
                                    target;

        hashing h1c;
        h1c.object = info_string;
        proof_of_work = h1c.get_hash();

        // add this proof of work to the block, 
        // we'll assume that it's already mined // skipping the mining part.

        std::cout<<"Transaction was successfull for {"<<trigger<<"} -- {"<<target<<"} for: $XO "<<exchange;
    }

    std::cout<<"Trade was not successfull due to insufficient funds in the Trigger Wallet.";
    return;
    // hash this and then return the hash which should be stored in a block inside a tchain.

}