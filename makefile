.PHONY: all debug clean

SRC=src/list.c

all: list

list: $(SRC)
	gcc $(SRC) -Wall -o list

debug: a.out

a.out: $(SRC)
	gcc -g $(SRC) -Wall -o a.out

clean:
	rm -f list a.out