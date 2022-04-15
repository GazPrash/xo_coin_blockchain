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
    // we can use apis to make database calls if it exists, since this is a protoype bchain
    // we are just going to return a reasonable balance b/w 0-1200;

    int balance = (rand() % 1200);
    return balance;

}

void user :: private_details(std::string pri_key){
    if (pri_key == primary_key){
        std::cout<<"$DETAILS FOR: "<<secondary_key<<"\n";
        std::cout<<"$PRIMARY KEY: "<<primary_key<<"\n";
        std::cout<<"WALLET BALANCE: "<<check_balance(secondary_key)<<"\n";
    }

}
