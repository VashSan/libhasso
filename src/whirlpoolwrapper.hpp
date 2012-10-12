#ifndef WHIRLPOOLWRAPPER_HPP
#define WHIRLPOOLWRAPPER_HPP

#include <array>
#include <string>
#include "ihash.hpp"

namespace hasso
{

/// use this class for easy access to 
class Whirlpool : public IHash<64>
{
public:
    
    /// Calculates Hash from any data in memory.
    void GetHash( const unsigned char* const data, const size_t dataLength, Hash& result ) const;
    
    /// Calculates Hash from any string.
    void GetHash( const std::string& data, Hash& result) const; //override
    
    /// returns Hash in user friendly text
    std::string Friendly(const Hash& rawHash) const;
};

}

#endif // WHIRLPOOLWRAPPER_HPP
