#include<vector>
#include<iostream>
#include<math.h>


class sha256{
    private:
    public:
        // sigma family functions
        std::string sigma_0(std::string);
        std:: string sigma_1(std:: string);

        // bits shift and rotatatory functions
        std::string right_shift(std::string, int);
        std::string right_rotate_shift(std::string, int);

        // xor implementation
        std::string re_xor(std::string, std::string);

        // other functions
        std::string ch_func(std::string, std::string, std::string);
        std::string maj_func(std::string, std::string, std::string);
};


std::string sha256 :: sigma_0(std::string wi){
    // right rotate 7 <--> right rotate 18 <--> right shift 3 ------> XOR ALL

    std::string w1 = right_rotate_shift(wi, 7);
    std::string w2 = right_rotate_shift(wi, 18);
    std::string w3 = right_shift(wi, 3);

    return (re_xor(w3, re_xor(w1, w2)));

}

std::string sha256 :: sigma_1(std:: string wi){
    // right rotate 17 <--> right rotate 19 <--> right shift 10 ------> XOR ALL

    std::string w1 = right_rotate_shift(wi, 17);
    std::string w2 = right_rotate_shift(wi, 19);
    std::string w3 = right_shift(wi, 10);

    return (re_xor(w3, re_xor(w1, w2)));
}

std::string sha256 :: right_shift(std::string wi, int shift){
    int new_ind = 0, sz = wi.length();
    wi = wi.substr(0, sz-shift);

    while (shift > 0){
        wi.insert(wi.begin(), '0');
        shift--;
    }

    return wi;
}

std::string sha256 :: right_rotate_shift(std::string wi, int shift){
    int new_ind = 0, sz = wi.length();
    std::string out(sz, '0');
    
    for (int i = 0; i < sz; i++){
        new_ind = (i + shift)%sz;
        out[new_ind] = wi[i];
    }

    return out;
};

std::string sha256 :: re_xor(std::string s1, std::string s2){
    for (int i = 0; i < s1.length(); i++){
        if (s1[i] == s2[i]) s1[i] = '0';
        else s1[i] = '1'; 
    }

    return s1;
}

std::string sha256 :: ch_func(std::string x, std::string y, std::string z){

    for (int i = 0; i < x.length(); i++){
        if (i == '1') x[i] = y[i];
        else x[i] = z[i];
    }

    return x;
}

std:: string sha256 :: maj_func(std::string x, std::string y, std::string z){
    
    for (int i = 0; i < x.length(); i++){
        x[i] = ((x[i] & y[i]) | y[i] & z[i] | z[i] & x[i]);
    }

    return x;
}