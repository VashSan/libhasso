#ifndef WHIRLPOOLWRAPPER_HPP
#define WHIRLPOOLWRAPPER_HPP

#include <stddef.h>
#include <array>
#include <string>

namespace hasso
{
    
class Whirlpool
{
   
public:
    typedef std::array<unsigned char, 64> Hash;
    
    Whirlpool();
    ~Whirlpool();
    
    /// Calculates Hash from any data in memory.
    void GetHash( const unsigned char* data, const size_t dataLength, Hash& result ) const;
    
    /// Calculates Hash from any string.
    void GetHash( const std::string& data, Hash& result) const;
    
    /// returns Hash in user friendly text
    std::string Friendly(const Hash& rawHash) const;
};

}

#endif // WHIRLPOOLWRAPPER_HPP
