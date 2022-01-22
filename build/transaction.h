#pragma once
#include "coin.h"
#include<iostream>
#include<vector>
#include<ctime>
#include<chrono>

class transaction{
    private:
        std::string timestamp_now();
    public:
        std::string hash_id;
        std:: string block_id;
        void start_transaction(std::string, std::string, int);

};

std::string transaction :: timestamp_now(){
    auto time_now = std::chrono::system_clock:: now();
    std:: time_t stamp = std::chrono::system_clock:: to_time_t(time_now);
    std::string timestamp = std::ctime(&stamp);

    return timestamp;
}

void transaction :: start_transaction(std::string trigger, std::string target, int exchange){
    std::string stamp = timestamp_now();
    coin *tcoin = new coin;
    tcoin->trade(exchange, trigger, target, stamp);

}