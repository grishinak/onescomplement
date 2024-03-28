#include <iostream>
#include "onescomplement.h"

template<typename T> void runTest(T a_, T b_);


//Арифметика в обратном коде.
//при тестировании иных типов данных необходимо 
//явно инстанцировать тип в файле с реализацией класса.


int main() {

std::cout << "____________running uint32_t test____________ "<< "\n";
uint32_t a1=7, b1=2;
    runTest(a1, b1);

std::cout << "____________running int test____________ "<< "\n";
int a2=-12, b2=7;
    runTest(a2, b2);

std::cout << "____________running uint16_t test____________ "<< "\n";
uint16_t a3=7, b3=2;
    runTest(a3, b3);


    return 0;
}

template<typename T> void runTest(T a_, T b_) {
    OnesComplement<T> oc_a_(a_);
    OnesComplement<T> oc_b_(b_);

    std::cout << "First : \t" << oc_a_ << "\n";
    std::cout << "Second: \t" << oc_b_ << "\n";

    OnesComplement<T> sum = oc_a_ + oc_b_;
    std::cout << "Sum: \t\t" << sum << "\n";

    OnesComplement<T> difference = oc_a_ - oc_b_;
    std::cout << "Difference: \t" << difference << "\n";

    OnesComplement<T> product = oc_a_ * oc_b_;
    std::cout << "Product: \t" << product << "\n";

    OnesComplement<T> quotient = oc_a_ / oc_b_;
    std::cout << "Quotient: \t" << quotient << "\n\n";
}