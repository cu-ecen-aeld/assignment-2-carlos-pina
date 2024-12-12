default: writer

CROSS_COMPILE ?=
CC := ${CROSS_COMPILE}gcc

writer: writer.c
	${CC} -o writer writer.c

clean:
	rm -rf writer writer.o
