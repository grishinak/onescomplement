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
OnesComplement(T valueInput){
if (valueInput>=0){
value=valueInput;

binaryRepresent=value;
} else{
value=valueInput;

binaryRepresent=abs(value);
binaryRepresent.flip();
} 

}

// Перегрузка оператора сложения
OnesComplement operator+(const OnesComplement& other) const {
    T resultValue = value + other.value;
    return OnesComplement(resultValue);
}

// Перегрузка оператора вычитания
OnesComplement operator-(const OnesComplement& other) const {
    T resultValue = value - other.value;
    return OnesComplement(resultValue);
}

// Перегрузка оператора умножения
OnesComplement operator*(const OnesComplement& other) const {
    T resultValue = value * other.value;
    return OnesComplement(resultValue);
}

// Перегрузка оператора деления
OnesComplement operator/(const OnesComplement& other) const {
    T resultValue = value / other.value;
    return OnesComplement(resultValue);
}

// Перегрузка оператора вывода <<
friend std::ostream& operator<<(std::ostream& os, const OnesComplement& oc) {
    os << "value: \t" << oc.value << "\t binary represent: " << oc.binaryRepresent;
    return os;
}
};