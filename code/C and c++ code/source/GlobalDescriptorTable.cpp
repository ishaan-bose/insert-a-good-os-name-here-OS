#include "GlobalDescriptorTable.hpp"
#include "types.hpp"

/*
Most of the code you see will not be commented because i am blindly following
the tutorial. I will still try to comment the most i can and understand 
the most i can. if you understand pls write the comments over the line(s) of code

Also there are a lot of signs i am seeing the first time in my life like 'x|=y;'
which is 'or equals to' which stands for 'x = x | y;'

Note that I understand the code but i dont understand its purpose

*/

GlobalDescriptorTable::GlobalDescriptorTable()
: nullSegmentSelector(0,0,0),
unusedSegmentSelector(0,0,0),
codeSegmentSelector(0, 64*1024*1024, 0x9A),
dataSegmentSelector(0, 64*1024*1024, 0x92)
{
    uint32 i[2];
    i[0] = (uint32)this;
    i[1] = sizeof(GlobalDescriptorTable) << 16;
    
    //lgdt is an assembly instruction that stands for load global descriptor table
    asm volatile("lgdt (%0)": :"p" (((uint8 *) i)+2));
    
}

GlobalDescriptorTable::~GlobalDescriptorTable()
{}

uint16 GlobalDescriptorTable::DataSegmentSelector()
{
    return (uint8*)&dataSegmentSelector - (uint8*)this;
}

uint16 GlobalDescriptorTable::CodeSegmentSelector()
{
    return (uint8*)&codeSegmentSelector - (uint8*)this;
}

GlobalDescriptorTable::SegmentDescriptor::SegmentDescriptor(uint32 base, uint32 limit, uint8 flags)
{
    uint8* target = (uint8*)this;
    
    if(limit <= 65536)
    {
        target[6] = 0x40;
    }
    else
    {
        //0xFFF in binary is 11111111 so i think this checks if all the two bits are 1's
         if((limit & 0xFFF) != 0xFFF)
            limit = (limit >> 12)-1;
        else
            limit = (limit >> 12);
            
        target[6] = 0xC0;
    }
    
    target[0] = limit & 0xFF;
    target[1] = (limit >> 8) & 0xFF;
    target[6] |= (limit >> 16) & 0xF;
    
    target[2] = base & 0xFF;
    target[3] = (base >> 8) & 0xFF;
    target[4] = (base >> 16) & 0xFF;
    target[7] = (base >> 24) & 0xFF;
    
    target[5] = flags;
}

uint32 GlobalDescriptorTable::SegmentDescriptor::Base()
{
    uint8* target = (uint8*)this;
    uint32 result = target[7];
    result = (result << 8) + target[4];
    result = (result << 8) + target[3];
    result = (result << 8) + target[2];
    
    return result;
}

uint32 GlobalDescriptorTable::SegmentDescriptor::Limit()
{
    uint8* target = (uint8*)this;
    uint32 result = target[6] & 0xF;
    
    result = (result << 8) + target[1];
    result = (result << 8) + target[0];
    
    //0xC0 in binary is 11000000 so i think this checks if the upper two bits are 1
    if((target[6] & 0xC0) == 0xC0)
        result = (result << 12) | 0xFFF;
    
    return result;
}