// Implementation of the X0-COIN Cryptocurrency in C++ ---> With SHA-256 

#include<iostream>
#include<istream>
#include<vector>
#include<unordered_map>
using namespace std;

class XOBlock{
    private:
        string block_primary_id;
        int chain_rank;
    public:
        string block_secondary_id;
        vector<unordered_map<string, string>> transactions;
        vector<string> public_transaction_ledger;

        // methods

        int block_level();
        string fetch_transaction(string);
        void set_block_id(string);

};

string XOBlock :: fetch_transaction(string pub_tsaction_id){
    // sign in <---> verify user first TODO;

    for (int i = 0; i < transactions.size(); i++){
        unordered_map<string, string> cmap = transactions[i];

        for (auto iter1 = cmap.begin(); iter1 != cmap.end(); iter1++){
            if (iter1->first == pub_tsaction_id) return iter1->second;
        }

    }

}


class Transaction{
    private:
        string tsaction_primary_id;
        string certificate_of_proof_hash;
    public:
        string tsaction_secondary_id;
        vector<string> tsaction_public_records;

        // methods

        string new_transaction(string holder_sk, string receiver_sk, int ticker);
        bool confirm_transaction(string trust);

};

class hashing{
    private: 
        string private_usage_data;
    public:
        string hash;
        int serial;

        // methods

        string hash_sha256(string data, string user_creds, int time_info);
        string hash_md5(string data, string user_creds, int time_info);

};

// string hashing :: hash_sha256(){
// and so on well have to write a function to calculate the hash and blah blah blah
// }




int main(){
    

    return 0;
}