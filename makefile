.PHONY: all debug clean

all: list

list: list.c
	gcc list.c -Wall -o list

debug: a.out

a.out: list.c
	gcc -g list.c -Wall -o a.out

clean:
	rm -f list a.out