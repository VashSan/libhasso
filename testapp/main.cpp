#include <iostream>
#include <iomanip>
#include <array>
#include "../src/whirlpoolwrapper.hpp"

using namespace std;

int main()
{   
    hasso::Whirlpool whirlpool;
    hasso::Whirlpool::Hash digest;
  
    unsigned char data[3];
    data[0] = 'a';
    data[1] = 'b';
    data[2] = 'c';
    
    whirlpool.GetHash(data, sizeof(data), digest);
    
    std::string whirlpoolHash = whirlpool.Friendly(digest);
    cout << whirlpoolHash << "\n\n";
    
    whirlpool.GetHash("abc", digest);
    
    std::string whirlpoolHash2 = whirlpool.Friendly(digest);
    cout << whirlpoolHash2 << "\n\n";
    
// both results should match (without linebreak):     
//     4E2448A4C6F486BB 16B6562C73B4020B F3043E3A731BCE72 1AE1B303D97E6D4C
//     7181EEBDB6C57E27 7D0E34957114CBD6 C797FC9D95D8B582 D225292076D4EEF5
    
    return 0;
}
