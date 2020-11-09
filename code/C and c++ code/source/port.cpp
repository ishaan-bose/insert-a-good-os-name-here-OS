#include "port.hpp"

Port::Port(uint16 portnumber)
{
    this->portnumber = portnumber;
}

Port::~Port()
{}

//=================================

Port8bit::Port8bit(uint16 portnumber)
: Port(portnumber)
{}

Port8bit::~Port8bit()
{}
    
void Port8bit::Write(uint8 data)
{
    __asm__ volatile("outb %0, %1" : : "a" (data), "Nd" (portnumber));
}

uint8 Port8bit::Read()
{
    uint8 result;
    __asm__ volatile("inb %1, %0" : : "=a" (result) : "Nd" (portnumber));
    return result;
}

//================================

Port8bitSlow::Port8bitSlow(uint16 portnumber)
: Port8bit(portnumber)
{}

Port8bitSlow::~Port8bitSlow()
{}
    
void Port8bitSlow::Write(uint8 data)
{
    __asm__ volatile("outb %0, %1\njmp 1f\n1: jmp 1f\n1:" : : "a" (data), "Nd" (portnumber));
}

//===============================

Port16bit::Port16bit(uint16 portnumber)
: Port(portnumber)
{}

Port16bit::~Port16bit()
{}

void Port16bit::Write(uint16 data)
{
    __asm__ volatile("outw %0, %1" : : "a" (data), "Nd" (portnumber));
}

uint16 Port16bit::Read()
{
    __asm__ volatile("inw %1, %0" : : "=a" (result) : "Nd" (portnumber));
}

//==============================

Port32bit::Port32bit(uint16 portnumber)
: Port(portnumber)
{}

Port32bit::~Port32bit()
{}

void Port32bit::Write(uint32 data)
{
    __asm__ volatile("outl %0, %1" : : "a" (data), "Nd" (portnumber));
}

uint32 Port32bit::Read()
{
    __asm__ volatile("inl %1, %0" : : "=a" (result) : "Nd" (portnumber));
}