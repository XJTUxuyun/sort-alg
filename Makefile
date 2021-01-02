CC = gcc -g

CFLAGS=

LIBS=

.PHONY:	sort	clean

sort:	main.o sort.o
	$(CC)	$(LIBS)	-o sort main.o sort.o

clean:
	-rm *.o
	-rm sort

