#ifndef ONESCOMPLEMENT_H
#define ONESCOMPLEMENT_H

#include <iostream>
#include <cstdint>

template<typename T = uint32_t>
class OnesComplement {
private:   
    T value = 0;
    T binaryRepresent[sizeof(T)*8]; // Массив для хранения битового представления числа

public:
    OnesComplement(T valueInput);
    void printBinaryRepresentation();
};

#endif //ONESCOMPLEMENT_H