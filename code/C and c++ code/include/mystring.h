#ifndef STRING_H
#define STRING_H

#include "types.h"

uint16 stringlength(string myString)
{
    uint16 length = 1;
    while (myString[length++]);
    return length;
}

#endif