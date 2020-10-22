#nasm -f elf32 'Assembly code'/kernel.asm -o binaries/kernelAssemblyCode.o
gcc -m32 -c 'C and c++ code'/source/kernel.cpp -I 'C and c++ code'/include/ -o binaries/kernel_C_code.o
ld -m elf_i386 -T link.ld -o kernel.bin  binaries/kernelAssemblyCode.o  binaries/kernel_C_code.o
qemu- system-i386 -kernel kernel.bin
