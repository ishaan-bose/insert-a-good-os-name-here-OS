kmain()     //we do not use void or int or float or anything because it is already declared in kernel.asm
{
    char* videomemory = (char*)0xb8000; //the memory location in hich to write text to
    videomemory[0] = 'Y';   //the letter y will be printed out
    videomemory[1] = 0x02;  //green color, use 0x07 to use gray color
}