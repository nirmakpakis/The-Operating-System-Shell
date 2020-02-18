mykernal : shell.o interpreter.o shellmemory.o kernel.o cpu.o pcb.o ram.o
	gcc -o mykernel shell.o interpreter.o shellmemory.o kernel.o cpu.o pcb.o ram.o
shellmemory.o : shellmemory.c
	gcc -c shellmemory.c
interpreter.o : interpreter.c
	gcc -c interpreter.c
shell.o : shell.c
	gcc -c shell.c
kernal.o : kernal.c
	gcc -c kernal.c
cpu.o : cpu.c
	gcc -c cpu.c
ram.o : ram.c
	gcc -c ram.c
pcb.o : pcb.c
	gcc -c pcb.c

