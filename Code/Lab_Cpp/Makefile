CC=gcc
CSRCS=02-main.cpp 02-stampa-lib/02-stampa.cpp
EXENAME=02-main
CFLAGS=-Wall
INCLUDE_DIRS=.
LIBS=stdc++

all:
	${CC} ${CSRCS} ${CFLAGS} -I ${INCLUDE_DIRS} -o ${EXENAME} -l ${LIBS}

clean:
	rm -rf ${EXENAME} *.o

run:
	./${EXENAME}