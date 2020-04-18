mykernel: shell.o memorymanager.o interpreter.o shellmemory.o kernel.o cpu.o pcb.o ram.o
	gcc -o mykernel memorymanager.o shell.o interpreter.o shellmemory.o kernel.o cpu.o pcb.o ram.o 
memorymanager.o: memorymanager.c
	gcc -c memorymanager.c
shellmemory.o: shellmemory.c
	gcc -c shellmemory.c
interpreter.o: interpreter.c
	gcc -c interpreter.c
shell.o: shell.c
	gcc -c shell.c
kernel.o : kernel.c
	gcc -c kernel.c
cpu.o: cpu.c
	gcc -c cpu.c
ram.o: ram.c
	gcc -c ram.c
pcb.o: pcb.c
	gcc -c pcb.c
clean:
	rm *.o mykernel
