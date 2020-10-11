kmain()     //we do not use void or int or float or anything because it is already declared in kernel.asm
{
    char* videomemory = (char*)0xb8000;
    videomemory[0] = 'Y';
    videomemory[1] = 0x02;  //green color
}