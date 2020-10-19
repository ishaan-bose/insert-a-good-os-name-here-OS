#include "include/mystdio.h"

//the extern c is there to tell the compiler that this is a c 
//function and not a cpp function, it wont compile without it
extern "C" void kernelmain()
{
    clearScreen(); //clear the screen first
    printf("hello world\n");
}
