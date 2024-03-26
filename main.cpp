#include <iostream>
#include "onescomplement.h"


int main() {
//для int
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


//для uint32_t = по умолчанию
OnesComplement<> x(1);
OnesComplement<> y(0);

std::cout << "x: \t\t" << x << std::endl;
std::cout << "y: \t\t" << y << std::endl;

OnesComplement<> sum2 = x + y;
std::cout << "Sum: \t\t" << sum2 << std::endl;

OnesComplement<> difference2 = x - y;
std::cout << "Difference: \t" << difference2 << std::endl;

OnesComplement<> product2 = x * y;
std::cout << "Product: \t" << product2 << std::endl;

OnesComplement<> quotient2 = x / y;
std::cout << "Quotient: \t" << quotient2 << std::endl;

return 0;
}