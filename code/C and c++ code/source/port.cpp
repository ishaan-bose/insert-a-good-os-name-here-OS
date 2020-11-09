#include "port.hpp"

Port::Port(uint16 portnumber);
Port::~Port();

Port8bit::Port8bit(uint16 portnumber);
Port8bit::~Port8bit();

Port8bitSlow::Port8bitSlow(uint16 portnumber);
Port8bitSlow::~Port8bitSlow();

Port16bit::Port16bit(uint16 portnumber);
Port16bit::~Port16bit();

Port32bit::Port32bit(uint16 portnumber);
Port32bit::~Port32bit();