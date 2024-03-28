#include "onescomplement.h"

    template<typename T>
    OnesComplement<T>::OnesComplement(T valueInput) {
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
    
    template<typename T>
    void OnesComplement<T>::printBinaryRepresentation() {
        std::cout << "Binary Representation: ";
        for (int i = sizeof(T)*8 - 1; i >= 0; --i) {
            std::cout << static_cast<int>(binaryRepresent[i]);
        }
        std::cout << std::endl;
    }

//Явная инстанциация класса, для используемых в программе типов данных для шаблона
template class OnesComplement<uint32_t>;
template class OnesComplement<int>;