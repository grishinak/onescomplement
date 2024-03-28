#include <iostream>
#include <cstdint>

template<typename T = uint32_t>
class OnesComplement {
private:   
    T value = 0;
    T binaryRepresent[sizeof(T)*8]; // Массив для хранения битового представления числа

public:
    OnesComplement(T valueInput) {
        if (valueInput >= 0) {
            value = valueInput;
            for (int i = 0; i < sizeof(T)*8; ++i) {
                binaryRepresent[i] = (value >> i) & 1; // Заполнение массива битов
            }
        } else {
            value = valueInput;
            T absValue = -value; // Получение абсолютного значения для беззнаковых типов данных
            for (int i = 0; i < sizeof(T)*8; ++i) {
                binaryRepresent[i] = !((absValue >> i) & 1); // Заполнение массива инвертированным битовым представлением
            }
        } 
    }
    
    void printBinaryRepresentation() {
        std::cout << "Binary Representation: ";
        for (int i = sizeof(T)*8 - 1; i >= 0; --i) {
            std::cout << static_cast<int>(binaryRepresent[i]);
        }
        std::cout << std::endl;
    }
};

int main() {
    OnesComplement<int> onesComp(-5);
    onesComp.printBinaryRepresentation();
    return 0;
}
