#include "GlobalDescriptorTable.hpp"
#include "mystdio.hpp"

//the extern c is there to tell the compiler that this is a c 
//function and not a cpp function, it wont compile without it
extern "C" void kernelmain()
{
    GlobalDescriptorTable gdt;
    printf("It works!!, else this message wouldn't show up");  
}