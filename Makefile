CC=gcc
LIBS = -lmysqlclient

main: main.c
	$(CC) -o zpmd.bin main.c $(LIBS)

all: main

clean:
	rm -f *.o zpmd.bin

