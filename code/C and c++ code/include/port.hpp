#pragma once

#include "types.hpp"

class Port
{
protected:
    uint16 portnumber;
    Port(uint16 portnumber);
    ~Port();
};

class Port8bit : public Port
{
protected:
    Port8bit(uint16 portnumber);
    ~Port8bit();
    virtual void Write(uint8 data);
};

class Port8bitSlow : public Port
{
protected:
    Port8bitSlow(uint16 portnumber);
    ~Port8bitSlow();
    virtual void Write(uint8 data);
    virtual uint8 Read();
};

class Port16bit : public Port
{
protected:
    Port16bit(uint16 portnumber);
    ~Port16bit();
    virtual void Write(uint16 data);
    virtual uint16 Read();
};
 
class Port32bit : public Port
{
protected:
    Port32bit(uint16 portnumber);
    ~Port32bit();
    virtual void Write(uint32 data);
    virtual uint32 Read();
};