#ifndef SYSTEM_H
#define SYSTEM_H

#include "types.h"


//i dont understand this code cuz i am following an online tutorial
//i just know it takes in a memory address and returns the value it is holding
uint8 inportb(uint16 _port)
{
	uint8 rv;
	__asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
	return rv;
}

//dont know what this means either, just know it outputs to a memory address
void outportb(uint16 _port, uint8 _data)
{

}

#endif