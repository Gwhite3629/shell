CC=gcc
LINK=gcc
TARGET=FuncS
OBJS=shell.o read.o eval.o print.o commands.o environment.o file.o
CFLAGS= -g -Wall -Wextra -O2
LFLAGS= -g -O2

all: ${TARGET}

${TARGET}: ${OBJS}
	${CC} ${LFLAGS} -o $@ $^

shell.o: shell.c
read.o: read.c
eval.o: eval.c
print.o: print.c
commands.o: commands.c
environment.o: environment.c
file.o: file.c

.PHONY : clean

clean:
	rm -f ${TARGET} core*
	rm -f *.o core*