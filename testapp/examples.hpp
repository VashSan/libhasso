#ifndef EXAMPLES_HPP
#define EXAMPLES_HPP

#include "../src/whirlpoolwrapper.hpp"
#include "../src/ihash.hpp"
#include <iomanip>
#include <iostream>

/// this functions is an example on how to use the IHash interface
template<int N>
void calculate_hash_by_interface(typename hasso::IHash<N>& hashalgo,  typename hasso::IHash<N>::Hash& result)
{
    using namespace std;
    
    unsigned char data[3];
    data[0] = 'a';
    data[1] = 'b';
    data[2] = 'c';
    
    hashalgo.GetHash(data, sizeof(data), result);
    
    // results should match  
    //     4E2448A4C6F486BB 16B6562C73B4020B F3043E3A731BCE72 1AE1B303D97E6D4C
    //     7181EEBDB6C57E27 7D0E34957114CBD6 C797FC9D95D8B582 D225292076D4EEF5
    
    for (int i = 0; i < result.size(); i++)
    {
        unsigned int r = static_cast<unsigned int>(result[i]);
        cout << hex << setw(2) << setfill('0') << r;
    }
}

/// the libhasso provided hash function whirlpool is used to invoke the 
/// generic calculate_hash_by_interface function
void whirlpool_example()
{   
    hasso::Whirlpool whirlpool;
    hasso::Whirlpool::Hash digest;
    
    calculate_hash_by_interface(whirlpool, digest);
}

#endif //EXAMPLES_HPP