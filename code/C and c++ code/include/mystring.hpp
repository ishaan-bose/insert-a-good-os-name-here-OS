#ifndef STRING_H
#define STRING_H

#include "types.hpp"

const uint8 maxLettersInALine = 80;

uint16 stringlength(string myString)
{
    uint16 length = 0;
    
    for(length; myString[length] != '\n'; length++);
    
    return length;
}

#endif