GCC=gcc
SOURCES=$(wildcard *.c)
BINAIRES=$(patsubst %.c, %.o, ${SOURCES})

all: main

main: ${BINAIRES}
	${GCC} $^ -o $@

%.o: %.c %.h
	${GCC} -c $<

clean: main
	rm main
	rm *.o
