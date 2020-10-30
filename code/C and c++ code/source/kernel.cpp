#include "mystdio.h"

//the extern c is there to tell the compiler that this is a c 
//function and not a cpp function, it wont compile without it
extern "C" void kernelmain()
{
    clearScreen(); //clear the screen first
    //the (string) part is not needed but avoids a warning the compiler gives
    //printf((string)"hello world\n");
    string vidmem = (string)0xb8000;
    vidmem[0] = 'H';
    vidmem[1] = 0x03; // gray
}