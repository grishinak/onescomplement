#include "onescomplement.h"


template<typename T>
OnesComplement<T>::OnesComplement(T valueInput){
if (valueInput>=0){
value=valueInput;

binaryRepresent=value;
} else {
value=valueInput;

binaryRepresent=abs(value);
binaryRepresent.flip();
}
}


// Перегрузка оператора сложения
template<typename T>
OnesComplement<T> OnesComplement<T>::operator+(const OnesComplement& other) const {
    T resultValue = value + other.value;
    return OnesComplement<T>(resultValue);
}

// Перегрузка оператора вычитания
template<typename T>
OnesComplement<T> OnesComplement<T>::operator-(const OnesComplement& other) const {
    T resultValue = value - other.value;
    return OnesComplement(resultValue);
}

// Перегрузка оператора умножения
template<typename T>
OnesComplement<T> OnesComplement<T>::operator*(const OnesComplement& other) const {
    T resultValue = value * other.value;
    return OnesComplement(resultValue);
}

// Перегрузка оператора деления
template<typename T>
OnesComplement<T> OnesComplement<T>::operator/(const OnesComplement& other) const {
    T resultValue = value / other.value;
    return OnesComplement(resultValue);
}

// Перегрузка оператора <<
template<typename T>
std::ostream& operator<<(std::ostream& os, const OnesComplement<T>& oc) {
    os << "value: \t" << oc.value << "\t binary represent: " << oc.binaryRepresent;
    return os;
}



//Явная инстанциация оператора << , для используемых в программе типов данных для шаблона
template std::ostream& operator<<(std::ostream& os, const OnesComplement<uint32_t>& oc);
template std::ostream& operator<<(std::ostream& os, const OnesComplement<uint16_t>& oc);
template std::ostream& operator<<(std::ostream& os, const OnesComplement<int>& oc);

//Явная инстанциация класса, для используемых в программе типов данных для шаблона
template class OnesComplement<uint32_t>;
template class OnesComplement<uint16_t>;
template class OnesComplement<int>;