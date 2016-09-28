
all:
	gcc md5c.c main.c -o main
	./main

clean:
	rm -rf md5c.o main.o
