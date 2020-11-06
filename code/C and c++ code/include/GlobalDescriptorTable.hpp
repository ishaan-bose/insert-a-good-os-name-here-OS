#pragma once
#include "types.hpp"


class GlobalDescriptorTable
{
public:
    class SegmentDescriptor
    {
    private:
        uint16 limit_low;
        uint16 base_low;
        uint8 base_high;
        uint8 type;
        uint8 flags_limit_high;
        uint8 base_vhigh;
    public:
        SegmentDescriptor(uint32 base, uint32 limit, uint8 type);
        uint32 Base();
        uint32 Limit();
        
    }; __attribute__((packed)); //the __attribute__((packed)) just means to define variables in the order we defined it
    
    SegmentDescriptor nullSegmentSelector;
    SegmentDescriptor unusedSegmentSelector;
    SegmentDescriptor codeSegmentSelector;
    SegmentDescriptor dataSegmentSelector;
    
public:
    GlobalDescriptorTable();
    ~GlobalDescriptorTable();
    
    uint16 CodeSegmentSelector();
    uint16 DataSegmentSelector();


};