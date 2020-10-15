#ifndef MYSTDIO_H
#define MYSTDIO_H

#include "types.h"
#include "mystring.h"

void myprintf(string myString)
{
    string videomemory = (char*)0xb8000; //the memory location in which we have to write text to so the 
    //virtual machine bios can read from and output to screen
    
    for(uint16 i=0; i < stringlength(myString); i++)
    {
        videomemory[i*2] = myString[i];
        videomemory[i+((i+1)%2)] = 0x07;
    }
    
}

#endif