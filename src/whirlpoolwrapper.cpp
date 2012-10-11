#include "whirlpoolwrapper.hpp"
#include "whirlpool.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <array>

using namespace std;

namespace hasso
{

Whirlpool::Whirlpool()
{

}

Whirlpool::~Whirlpool()
{

}

void Whirlpool::GetHash(const string& data, Whirlpool::Hash& result) const
{
    const unsigned char* stringData = reinterpret_cast<const unsigned char*>(data.c_str());
    GetHash(stringData, data.size(), result);
}

void Whirlpool::GetHash( const unsigned char* data, const size_t dataLength, Hash& result ) const
{
    NESSIEstruct nessie;
    WHIRLPOOL_init(&nessie);
    WHIRLPOOL_add(data, 8 * dataLength, &nessie);
    WHIRLPOOL_finalize(&nessie, result.data());
}

string Whirlpool::Friendly(const Whirlpool::Hash& rawHash) const
{
    stringstream hash;
    for (int i = 0; i < 64; i++)
    {
        if ( (i+1) % 8 == 0 && i != 63)
        {
            hash << '.';
        }
        hash << hex << setw(2) << setfill('0') << (unsigned int)rawHash[i];
    }
    return hash.str();
}



}