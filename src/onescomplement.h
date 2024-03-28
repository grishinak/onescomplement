#ifndef ONESCOMPLEMENT_H
#define ONESCOMPLEMENT_H

#include <iostream>
#include <cstdint>
#include <bitset>
#include <cmath>

template<typename T = uint32_t>
class OnesComplement{

private:   
    T value = 0 ;
    std::bitset<(sizeof(T)*8)> binaryRepresent;

public:
    OnesComplement(T valueInput);

// Перегрузка арифметических операторов 
    OnesComplement operator+(const OnesComplement& other) const;
    OnesComplement operator-(const OnesComplement& other) const;
    OnesComplement operator*(const OnesComplement& other) const;
    OnesComplement operator/(const OnesComplement& other) const;

// Перегрузка оператора вывода <<
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const OnesComplement<U>& oc);
};

#endif //ONESCOMPLEMENT