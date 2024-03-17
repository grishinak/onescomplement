#include <iostream>
#include <vector>
#include <bitset>
#include <cstdint>
#include <stdexcept>

template<class T = uint32_t>
class OneComplement {
private:
    T value;
    std::vector<bool> binaryRepresentation;

    void convertToBinary() {
        binaryRepresentation.clear();
        for (int i = sizeof(T) * 8 - 1; i >= 0; --i) {
            binaryRepresentation.push_back((value >> i) & 1);
        }
    }

    T convertToDecimal() const {
        T result = 0;
        T multiplier = 1;
        for (int i = sizeof(T) * 8 - 1; i >= 0; --i) {
            result += binaryRepresentation[i] ? multiplier : 0;
            multiplier <<= 1;
        }
        return result;
    }

public:
    OneComplement(T val = 0) : value(val) {
        convertToBinary();
    }

    OneComplement(const std::vector<bool>& binary) : binaryRepresentation(binary) {
        value = convertToDecimal();
    }

    OneComplement operator+(const OneComplement& other) const {
        std::vector<bool> resultBinary;
        bool carry = false;
        for (int i = sizeof(T) * 8 - 1; i >= 0; --i) {
            bool sum = binaryRepresentation[i] ^ other.binaryRepresentation[i] ^ carry;
            carry = (binaryRepresentation[i] & other.binaryRepresentation[i]) | (binaryRepresentation[i] & carry) | (other.binaryRepresentation[i] & carry);
            resultBinary.insert(resultBinary.begin(), sum);
        }
        return OneComplement(resultBinary);
    }

    OneComplement operator-(const OneComplement& other) const {
        return *this + OneComplement(~other.value + 1);
    }

    OneComplement operator*(const OneComplement& other) const {
        T result = value * other.value;
        return OneComplement(result);
    }

    OneComplement operator/(const OneComplement& other) const {
        if (other.value == 0) {
            throw std::runtime_error("Division by zero");
        }
        T result = value / other.value;
        return OneComplement(result);
    }

    void printBinary() const {
        for (bool bit : binaryRepresentation) {
            std::cout << bit;
        }
        std::cout << std::endl;
    }
};

int main() {
    OneComplement<uint8_t> a(-5);
    OneComplement<uint8_t> b(3);

    OneComplement<uint8_t> sum = a + b;
    OneComplement<uint8_t> difference = a - b;
    OneComplement<uint8_t> product = a * b;
    OneComplement<uint8_t> quotient = a / b;

    std::cout << "Binary representation of a: ";
    a.printBinary();
    std::cout << "Binary representation of b: ";
    b.printBinary();
    std::cout << "Sum: ";
    sum.printBinary();
    std::cout << "Difference: ";
    difference.printBinary();
    std::cout << "Product: ";
    product.printBinary();
    std::cout << "Quotient: ";
    quotient.printBinary();

    return 0;
}
