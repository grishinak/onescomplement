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
    //std::cout<<"created obj with value: "<<value;

    binaryRepresent=value;
   // std::cout<<"\t binary represent: "<<binaryRepresent<<std::endl;
    } else{
    value=valueInput;
    //std::cout<<"created obj with value: "<<value;

    binaryRepresent=abs(value);
    binaryRepresent.flip();
   // std::cout<<"\t binary represent: "<<binaryRepresent<<std::endl;
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

int main() {
    OnesComplement<int> a(-12);
    OnesComplement<int> b(5);

    std::cout << "a: \t\t" << a << std::endl;
    std::cout << "b: \t\t" << b << std::endl;

    OnesComplement<int> sum = a + b;
    std::cout << "Sum: \t\t" << sum << std::endl;

    OnesComplement<int> difference = a - b;
    std::cout << "Difference: \t" << difference << std::endl;

    OnesComplement<int> product = a * b;
    std::cout << "Product: \t" << product << std::endl;

    OnesComplement<int> quotient = a / b;
    std::cout << "Quotient: \t" << quotient << std::endl;

    return 0;
}