#pragma once
#include "wallet.h"
#include "../hashing/hashing.h"
#include<iostream>
#include<vector>

class coin{
    public:
        std::string proof_of_work; // giver-monet-timestamp-reciver
        std::string trade(int, std::string, std::string, std::string);

};

std::string coin :: trade(int exchange, std::string trigger, std::string target, std::string timestamp){
    user user_wallet;
    
    if (exchange <= user_wallet.check_balance(trigger)){
        std::string info_string  =  trigger+
                                    std::to_string(exchange)+
                                    timestamp+
                                    target;

        hashing h1c;
        h1c.object = info_string;
        proof_of_work = h1c.get_hash();

        // add this proof of work to the block, 
        // we'll assume that it's already mined // skipping the mining part.

        std::cout<<"Transaction was successfull for {"<<trigger<<"} -- {"<<target<<"} for: $XO "<<exchange;
        return proof_of_work;
    }

    std::cout<<"Trade was not successfull due to insufficient funds in the Trigger Wallet.";
    return "-1";
    // define a custom exception for this if possible.

}