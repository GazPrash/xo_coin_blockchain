#pragma once
#include<iostream>


class user{
    private:
        std::string primary_key;
    public:
        std::string secondary_key;
        int check_balance(std::string);
        void private_details(std::string);

};

int user :: check_balance(std::string sec_key){
    // read csv check if sec_key exists, return balance;
    return 152;
}

void user :: private_details(std::string pri_key){
    if (pri_key == primary_key){
        std::cout<<"$DETAILS FOR: "<<secondary_key<<"\n";
        std::cout<<"$PRIMARY KEY: "<<primary_key<<"\n";
        std::cout<<"WALLET BALANCE: "<<check_balance(secondary_key)<<"\n";
    }

}
