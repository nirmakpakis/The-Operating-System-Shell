mysh : shell.o interpreter.o shellmemory.o
	gcc -o mysh shell.o interpreter.o shellmemory.o
shellmemory.o : shellmemory.c
	gcc -c shellmemory.c
interpreter.o : interpreter.c
	gcc -c interpreter.c
shell.o : shell.c
	gcc -c shell.c

