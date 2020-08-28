//
//  CustomFloat.cpp
//  SE1FA15_SortingFloats
//
//  Created by Georgie Challis on 28/08/2020.
//  Copyright © 2020 Georgie Challis. All rights reserved.
//

#include "CustomFloat.h"

CustomFloat::CustomFloat() : name("-"){ //Default to -1
    myFloat.mantissa = 0;
    myFloat.exponent = 127;
    myFloat.sign = 1;
}

CustomFloat::CustomFloat(std::string name) : name(name){ //Default to -1
    myFloat.mantissa = 0;
    myFloat.exponent = 127;
    myFloat.sign = 1;
}

//Name, mantissa, exponent, sign
CustomFloat::CustomFloat(std::string n, unsigned int m, unsigned int e, unsigned int s)
    : name(n)
{
    myFloat.mantissa = m;
    myFloat.exponent = e;
    myFloat.sign = s;
}

void CustomFloat::SetName(std::string m){
    name = m;
}
void CustomFloat::SetMantissa(unsigned int m){
    myFloat.mantissa = m; // 1-4194303 qNan, 8388607 sNan, 0 and 8388608 inf
}
void CustomFloat::SetExponent(unsigned int e){
    myFloat.exponent = e; //0xff for NaN/inf
}
void CustomFloat::SetSign(unsigned int s){
    myFloat.sign = s;
}

float CustomFloat::GetFloat(){
    return myFloat.fl;
}
void CustomFloat::Print(){
    std::cout << "\n " << name  << " = " << myFloat.fl;
    std::cout << "\n\t Sign bit : " << myFloat.sign;
    std::cout << "\n\t Exponent : " << myFloat.exponent;
    std::cout << "\n\t Mantissa : " << myFloat.mantissa;
}
