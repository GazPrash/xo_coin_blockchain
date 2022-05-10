#include "hashing/hashing.h"
#include<iostream>

using std::string;


int main(int argc, char *argv[]){
	hashing h;

	string obj(argv[1]);
	h.object = obj;

	cout<< h.get_hash();
}