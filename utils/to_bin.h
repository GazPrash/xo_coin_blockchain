// Program to convert strings to binary based on the ASCII Conversion Chart.

class to_bin{
    public:
        std::string int_to_bit(int);
        std::string message;
        std::string encode_message();
};

std::string to_bin :: int_to_bit(int x){
    std::string out;
    while ( x != 0){
        out += (x%2 == 0 ? "0" : "1");
        x /= 2;
    }

    return out;
}

std::string to_bin :: encode_message(){
    std::string out_stream;
    for (char ch : message){
        out_stream += int_to_bit(ch);
    }

    return out_stream;

}