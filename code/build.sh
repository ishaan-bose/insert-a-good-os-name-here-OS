nasm -f elf32 kernel.asm -o binaries/kernelAssemblyCode.o
gcc -m32 -c kernel.c -o binaries/kernel_C_code.o
ld -m elf_i386 -T link.ld -o kernel.bin  binaries/kernelAssemblyCode.o  binaries/kernel_C_code.o
qemu-system-i386 -kernel kernel.bin