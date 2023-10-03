CC=gcc
CSRCS=automata-1-solution.c runtime/unix/nextCharLib.c FSM/FSM_1.c
CFLAGS=
ALL_CFLAGS= -I runtime/ -I FSM/ ${CFLAGS}
#CFLAGS=-Wall
LDFLAGS=-l stdc++
EXENAME=automata-1

all: 
	${CC} ${CSRCS} -o ${EXENAME} ${ALL_CFLAGS} ${LDFLAGS}

clean:
	rm ${EXENAME}

run: all
	./${EXENAME}