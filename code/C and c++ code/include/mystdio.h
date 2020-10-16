#ifndef MYSTDIO_H
#define MYSTDIO_H

#include "types.h"
#include "mystring.h"


//===========Variable declarations====================
int cursorX = 0, cursorY = 0;

//						
const uint8 screenWidth = 80, screenHeight = 25, screenDepth = 2;	//screen Depth is set to 2 cuz 1 byte is for the letter and the other byte is the color of the character
//===========Variable declarations====================

void clearScreen()
{
	string videomemory = (string)0xb8000;

	for(uint16 i=0; i < screenWidth*screenHeight*screenDepth; i++)
		videomemory[i] = 0x0;
}


void myprintf(string myString)
{
    string videomemory = (string)0xb8000; //the memory location in which we have to write text to so the 
    //virtual machine bios can read from and output to screen
    
    for(uint16 i=0; i < stringlength(myString); i++)
    {
        videomemory[i*2] = myString[i];

        videomemory[(i*2)+1] = 0x07;
    }
    
}

#endif
