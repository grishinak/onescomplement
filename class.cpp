#include <iostream>
#include <cstdint>

template <typename T = uint32_t> 
class OnesComplement
{
public:
    OnesComplement operator+()
    {}
private:
    T value;
};