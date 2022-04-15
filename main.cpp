#include<bits/stdc++.h>
#include "hashing/hashing.h"
#include "build/block.h"
#include "build/transaction.h"
#include "build/chain.h"
#include<random>

using std::string; 
using std::vector;

class control{
    public:
        enum mode{
            TRANSACTION,
            USER,
            CHAIN
        };
        void user_details(string);
        string make_transaction(string, string, int);
        vector<string> chain_status();

};


string control :: make_transaction(string trigger, string target, int funds){
    transaction* tsac = new transaction;
    std:: string tsaction_id = tsac->start_transaction(trigger, target, funds);

    return tsaction_id;

}

int main(){

    control c1;

    // lets assume we got this data from an api aquiring all the transactions that are 
    // going to be the part of the same block.
    vector<string> triggers;
    vector<string> targets;
    vector<int> funds;
    int pending_tsactions = 3;

    vector<string> tsaction_pofs;

    for (int i = 0 ; i < pending_tsactions; i++){
        string pof = c1.make_transaction(triggers[i], targets[i], funds[i]);
        tsaction_pofs.push_back(pof);
    }

    block* new_block = new block;
    new_block->initialize_block(tsaction_pofs);

    chain current_chain_instance;
    current_chain_instance.add_block(new_block);

    // update chain instance
    


    return 0;
}


// User1 (trigger) makes a transfer to User2 (target) of a given number of xo-coins.
// We check & verify the wallet (its creds and amount of funds) by first verifying user's private key
// After the verf. is complete and the user has enough funds to continue the transfer, a new block will
// be created to keep record of all the transactions that got verfied together.
// All these transaction slips & the time-stamp of the block creation will be then used to generate
// a hash value of the block. 
// Then the hash value of the previous block has to be stored in the newly created block, while the
// last valid block in the chain will get it's next block hash updated as well.
// After the reqrd. information of these blocks is updated, the chain can be finally updated, database
// entry is not required in the scope of this project.

