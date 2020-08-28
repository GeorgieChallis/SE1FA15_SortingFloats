//
//  CustomFloat.h
//  SE1FA15_SortingFloats
//
//  Created by Georgie Challis on 28/08/2020.
//  Copyright © 2020 Georgie Challis. All rights reserved.
//

#ifndef CustomFloat_h
#define CustomFloat_h

#include <iostream>
#include <string>

class CustomFloat{
    std::string name;
    union makeFloat { //Union to change parts of float via ints
        struct {
            unsigned int mantissa : 23;
            unsigned int exponent : 8;
            unsigned int sign : 1;
        };
        float fl;
    } myFloat;
    
    public:
        CustomFloat();
        CustomFloat(std::string name);
        CustomFloat(std::string n, unsigned int m, unsigned int e, unsigned int s);
        void SetName(std::string n);
        void SetMantissa(unsigned int m);
        void SetExponent(unsigned int e);
        void SetSign(unsigned int s);
        void Print();
};


#endif /* CustomFloat_h */
