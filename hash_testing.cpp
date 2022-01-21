#include<iostream>
#include<vector>
#include<map>
#include<math.h>
#include<algorithm>
#include<bitset>
#include "utils/compression.h"

using namespace std;
// STEPS -------> 

/*
1. Convert string to Binary first;
2. Padding the bits of message to the nearest multiple of 512 as SHA-256 Works with 512 bit messages.
3. Layout for creating a MESSAGE BLOCK : 

    org_message -----> bin_message (< 512)
    bin_message.length() -------> binary (bin_len) (< 64)
    bin_message += (0)*(448 - len(bin_message)) ---> now bin_message is of len == 448 (push extra 0s on the right)

    now bin_len (push_forward (0s)) so that bin_len == 64 bits (push extra 0s on the left)
    bin_message += bin_len

    => final bin_message == MESSAGE_BLOCK;

*/

std::string to_bin(int n){
    std::string out;
    int i = 0;
    while (n > 0){
        out += (n%2 == 0 ? "0" : "1");
        n /= 2;
    }

    return out;
}


int main(){
    // int n = 300;
    // n = 300%((int)(pow(2, 7)));
    // std:: vector<int> bin;
    // std::cout<<n<<"\n";

    // while (n > 0){
    //     bin.push_back(n%2);
    //     n /= 2;
    // }
    // std::reverse(bin.begin(), bin.end());
    // for (int k: bin){
    //     std::cout<<k;
    // }

    // std::string inp = "Arbitrary string to be converted to binary sequence.";
    // std::vector<std::string> final_bin;
    // std::string fbit;

    // for (char c: inp){
    //     fbit += to_bin(c);
    // }

    // // std::cout<<fbit.length();
    // std::string wi = "010101111101010010100";
    // int shift = 5;
    // int new_ind = 0, sz = wi.length();
    // wi = wi.substr(0, sz-shift);

    // while (shift > 0){
    //     wi.insert(wi.begin(), '0');
    //     shift--;
    // }

    // std::cout<<wi;

    // std:: string x = "0110110101010";
    // std:: string y = "0000001111010";
    // std:: string z = "0110111111011"; // 01101 11111 010
    // std:: string res;

    // for (int i = 0; i < x.length(); i++){
    //     x[i] = ((x[i] & y[i]) | y[i] & z[i] | z[i] & x[i]);
    // }

    // std::cout<<x;

    // std::string wi = "hey yeah this is cool tho fuck off"; // hey yeah this is cool th
    
    // int new_ind = 0, sz = wi.length();
    // wi = wi.substr(0, sz-10);

    // std::cout<<wi;

    // string a = "00000000000000000000000000000000";
    // string b = "00000000000000000000000000000000";
    // string c = "10010111000110000001010011101110";
    // string d = "00010111010011001101100110111111";


    // unsigned long big = stoul(a, nullptr, 2) + stoul(b, nullptr, 2) + stoul(c, nullptr, 2) + stoul(d, nullptr, 2);
    // // cout<<big<<"\n"<<big%(int)(pow(2, 32));
    // big %= (int)(pow(2, 32));
    // cout<<big;
    // std::string bin_value = std::bitset<32>(big).to_string();

    // cout<<bin_value;

    hash_compression h1;

    for (string k: h1.state_registers_bin){
        std::cout<<k<<std::endl;
    }

    // int a = 311;

    // double aa = cbrt(a);
    // unsigned long mid_int = aa * (pow(2, 32));
    // string aaa = (std::bitset<32> (mid_int).to_string());

    // cout<<aaa;


    return 0;
}