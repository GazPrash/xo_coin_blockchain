#include<bits/stdc++.h>
#include "hashing/hashing.h"

using namespace std;


int main(){

    hashing h1;
    h1.object = "welcome";
    cout<<h1.get_hash()<<endl;
    cout<<h1.get_hash().length();
    
    return 0;
}