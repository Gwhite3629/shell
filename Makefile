CC=gcc
LINK=gcc
TARGET=FuncS.exe
OBJS=shell.o read.o eval.o print.o commands.o
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

.PHONY : clean

clean:
	del -f ${TARGET} core*
	del -f *.o core*