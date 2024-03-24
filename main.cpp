#include <iostream>
#include <cstdint>
#include <bitset>
#include <cmath>

template<typename T = uint32_t>
class OnesComplement{
    private:
    
T value=0 ;
std::bitset<(sizeof(T)*8)> binaryRepresent;
    public:

OnesComplement(T valueInput){
    if (valueInput>=0){
    value=valueInput;
    std::cout<<"created obj with value: "<<value;

    binaryRepresent=value;
    std::cout<<"\t binary represent: "<<binaryRepresent<<std::endl;
    } else{
    value=valueInput;
    std::cout<<"created obj with value: "<<value;

    binaryRepresent=abs(value);
    binaryRepresent.flip();
    std::cout<<"\t binary represent: "<<binaryRepresent<<std::endl;
    } 
}

     OnesComplement operator+()
    {}
};

int main(){

    OnesComplement<int> a (-1);
    OnesComplement<int> b (1);

    return 0;
}