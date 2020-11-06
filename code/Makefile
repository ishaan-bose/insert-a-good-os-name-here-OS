all:
	#nasm -f elf64 'Assembly code'/kernel.asm -o binaries/kernelAssemblyCode.o
	g++ -fno-stack-protector  -m32  -c  'C and c++ code'/source/kernel.cpp  -I  'C and c++ code'/include/  -o  binaries/kernel_C_code.o
	g++  -fno-stack-protector  -m32  -c  'C and c++ code'/source/GlobalDescriptorTable.cpp  -I  'C and c++ code'/include/  -o  binaries/GlobalDescriptorTable.o
	ld  -m elf_i386 -T link.ld -o kernel.bin  binaries/kernelAssemblyCode.o  binaries/kernel_C_code.o binaries/GlobalDescriptorTable.o
	qemu-system-i386 -kernel kernel.bin
