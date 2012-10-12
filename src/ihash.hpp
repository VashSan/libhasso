#ifndef IHASH_HPP
#define IHASH_HPP

#include <cstddef>

namespace hasso
{

/// Interface for hash algorithms where NHashBytes is the size of the calculated hash.
template <int NHashBytes>
class IHash
{
public:
    typedef std::array<unsigned char, NHashBytes> Hash;
    
    /// Calculates a hash from any data pointed to by p_data with the length of dataLength.
    virtual void GetHash( const unsigned char* const p_data, const std::size_t dataLength, Hash& result ) const = 0;
};

}
#endif // IHASH_HPP